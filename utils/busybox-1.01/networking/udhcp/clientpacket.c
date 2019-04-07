/* clientpacket.c
 *
 * Packet generation and dispatching functions for the DHCP client.
 *
 * Russ Dill <Russ.Dill@asu.edu> July 2001
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <string.h>
#include <sys/socket.h>
#include <features.h>
#if __GLIBC__ >=2 && __GLIBC_MINOR >= 1
#include <netpacket/packet.h>
#include <net/ethernet.h>
#else
#include <asm/types.h>
#include <linux/if_packet.h>
#include <linux/if_ether.h>
#endif
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>


#include "dhcpd.h"
#include "clientpacket.h"
#include "options.h"
#include "dhcpc.h"
#include "common.h"


/* Create a random xid */
unsigned long random_xid(void)
{
	static int initialized;
	if (!initialized) {
		int fd;
		unsigned long seed;

		fd = open("/dev/urandom", 0);
		if (fd < 0 || read(fd, &seed, sizeof(seed)) < 0) {
			LOG(LOG_WARNING, "Could not load seed from /dev/urandom: %m");
			seed = time(0);
		}
		if (fd >= 0) close(fd);
		srand(seed);
		initialized++;
	}
	return rand();
}

#if defined(AP_PLATFORM)
#include <sys/stat.h>
#define HOST_NAME_FILE "/tmp/dhcp_hostname"
#define MAX_HNAME_LEN  128
#endif

#ifdef AP_PLATFORM
static unsigned monotonic_sec(void)
{
	struct timespec ts;
	int r;

	r = clock_gettime(CLOCK_MONOTONIC, &ts);
	if (r == 0) {
		return ts.tv_sec;
	}
	return 0;
}
#endif

/* initialize a packet with the proper defaults */
static void init_packet(struct dhcpMessage *packet, char type)
{
#ifdef AP_PLATFORM
	uint16_t secs;
#endif
	struct vendor  {
		char vendor, length;
#if defined(AP_PLATFORM)
        char str[32];
#ifdef __FAT_AP__
	} vendor_id = { DHCP_VENDOR,  sizeof("ArubaInstantAP") - 1, "ArubaInstantAP"};
#else
	} vendor_id = { DHCP_VENDOR,  sizeof("ArubaAP") - 1, "ArubaAP"};
#endif
	struct stat st ;
	FILE *fp ;
	char host_name[MAX_HNAME_LEN] ;
#else
		char str[sizeof("udhcp "VERSION)];
	} vendor_id = { DHCP_VENDOR,  sizeof("udhcp "VERSION) - 1, "udhcp "VERSION};
#endif

	init_header(packet, type);

#ifdef AP_PLATFORM
	client_config.last_secs = monotonic_sec();
	if (client_config.first_secs == 0)
		client_config.first_secs = client_config.last_secs;
	secs = client_config.last_secs - client_config.first_secs;
	packet->secs = htons(secs);
#endif

	memcpy(packet->chaddr, client_config.arp, 6);
	if (client_config.clientid)
	    add_option_string(packet->options, client_config.clientid);
#if defined(AP_PLATFORM)
	if (!stat(HOST_NAME_FILE, &st) && (fp = fopen(HOST_NAME_FILE, "r"))) {
	  if (fgets(&host_name[2], MAX_HNAME_LEN-1, fp)) {
	    host_name[0] = DHCP_HOST_NAME ;
	    host_name[1] = strlen(&host_name[2]) ;
	    add_option_string(packet->options, host_name);
	  }
	  fclose(fp);
	}
#else
	if (client_config.hostname) add_option_string(packet->options, client_config.hostname);
#endif
	add_option_string(packet->options, (uint8_t *) &vendor_id);
}


/* Add a parameter request list for stubborn DHCP servers. Pull the data
 * from the struct in options.c. Don't do bounds checking here because it
 * goes towards the head of the packet. */
static void add_requests(struct dhcpMessage *packet)
{
	int end = end_option(packet->options);
	int i, len = 0;

	packet->options[end + OPT_CODE] = DHCP_PARAM_REQ;
	for (i = 0; dhcp_options[i].code; i++)
		if (dhcp_options[i].flags & OPTION_REQ)
			packet->options[end + OPT_DATA + len++] = dhcp_options[i].code;
	packet->options[end + OPT_LEN] = len;
	packet->options[end + OPT_DATA + len] = DHCP_END;

}


/* Broadcast a DHCP discover packet to the network, with an optionally requested IP */
int send_discover(unsigned long xid, unsigned long requested)
{
	struct dhcpMessage packet;

	init_packet(&packet, DHCPDISCOVER);
	packet.xid = xid;
#ifdef __FAT_AP__
    LOG(LOG_INFO, "%s: pkt num %d, secs %d", __func__, packet_num, packet.secs);
#endif
	if (requested)
		add_simple_option(packet.options, DHCP_REQUESTED_IP, requested);

	add_requests(&packet);
	LOG(LOG_DEBUG, "Sending discover...");
	return raw_packet(&packet, INADDR_ANY, CLIENT_PORT, INADDR_BROADCAST,
				SERVER_PORT, MAC_BCAST_ADDR, client_config.ifindex);
}


/* Broadcasts a DHCP request message */
int send_selecting(unsigned long xid, unsigned long server, unsigned long requested)
{
	struct dhcpMessage packet;
	struct in_addr addr;

	init_packet(&packet, DHCPREQUEST);
	packet.xid = xid;
#ifdef __FAT_AP__
    LOG(LOG_INFO, "%s: pkt num %d, secs %d", __func__, packet_num, packet.secs);
#endif
	add_simple_option(packet.options, DHCP_REQUESTED_IP, requested);
	add_simple_option(packet.options, DHCP_SERVER_ID, server);

	add_requests(&packet);
	addr.s_addr = requested;
	LOG(LOG_DEBUG, "Sending select for %s...", inet_ntoa(addr));
	return raw_packet(&packet, INADDR_ANY, CLIENT_PORT, INADDR_BROADCAST,
				SERVER_PORT, MAC_BCAST_ADDR, client_config.ifindex);
}


/* Unicasts or broadcasts a DHCP renew message */
int send_renew(unsigned long xid, unsigned long server, unsigned long ciaddr)
{
	struct dhcpMessage packet;
	int ret = 0;

	init_packet(&packet, DHCPREQUEST);
	packet.xid = xid;
#ifdef __FAT_AP__
    LOG(LOG_INFO, "%s: pkt num %d, secs %d", __func__, packet_num, packet.secs);
#endif
	packet.ciaddr = ciaddr;

	add_requests(&packet);
	LOG(LOG_DEBUG, "Sending renew...");
	if (server)
		ret = kernel_packet(&packet, ciaddr, CLIENT_PORT, server, SERVER_PORT);
	else ret = raw_packet(&packet, INADDR_ANY, CLIENT_PORT, INADDR_BROADCAST,
				SERVER_PORT, MAC_BCAST_ADDR, client_config.ifindex);
	return ret;
}


/* Unicasts a DHCP release message */
int send_release(unsigned long server, unsigned long ciaddr)
{
	struct dhcpMessage packet;

	init_packet(&packet, DHCPRELEASE);
	packet.xid = random_xid();
	packet.ciaddr = ciaddr;

	add_simple_option(packet.options, DHCP_REQUESTED_IP, ciaddr);
	add_simple_option(packet.options, DHCP_SERVER_ID, server);

	LOG(LOG_DEBUG, "Sending release...");
	return kernel_packet(&packet, ciaddr, CLIENT_PORT, server, SERVER_PORT);
}


/* return -1 on errors that are fatal for the socket, -2 for those that aren't */
int get_raw_packet(struct dhcpMessage *payload, int fd)
{
	int bytes;
	struct udp_dhcp_packet packet;
	uint32_t source, dest;
	uint16_t check;
#ifdef __FAT_AP__
    int payload_len;

	memset(payload, 0, sizeof(struct dhcpMessage));
#endif
	memset(&packet, 0, sizeof(struct udp_dhcp_packet));
	bytes = read(fd, &packet, sizeof(struct udp_dhcp_packet));
	if (bytes < 0) {
		DEBUG(LOG_INFO, "couldn't read on raw listening socket -- ignoring");
		usleep(500000); /* possible down interface, looping condition */
		return -1;
	}

	if (bytes < (int) (sizeof(struct iphdr) + sizeof(struct udphdr))) {
		DEBUG(LOG_INFO, "message too short, ignoring");
		return -2;
	}

	if (bytes < ntohs(packet.ip.tot_len)) {
		DEBUG(LOG_INFO, "Truncated packet");
		return -2;
	}

	/* ignore any extra garbage bytes */
	bytes = ntohs(packet.ip.tot_len);

	/* Make sure its the right packet for us, and that it passes sanity checks */
	if (packet.ip.protocol != IPPROTO_UDP || packet.ip.version != IPVERSION ||
	    packet.ip.ihl != sizeof(packet.ip) >> 2 || packet.udp.dest != htons(CLIENT_PORT) ||
	    bytes > (int) sizeof(struct udp_dhcp_packet) ||
	    ntohs(packet.udp.len) > (uint16_t) (bytes - sizeof(packet.ip))) {
	    	DEBUG(LOG_INFO, "unrelated/bogus packet");
	    	return -2;
	}

	/* check IP checksum */
	check = packet.ip.check;
	packet.ip.check = 0;
	if (check != checksum(&(packet.ip), sizeof(packet.ip))) {
		DEBUG(LOG_INFO, "bad IP header checksum, ignoring");
		return -1;
	}

	/* verify the UDP checksum by replacing the header with a psuedo header */
	source = packet.ip.saddr;
	dest = packet.ip.daddr;
	check = packet.udp.check;
	packet.udp.check = 0;
	memset(&packet.ip, 0, sizeof(packet.ip));

	packet.ip.protocol = IPPROTO_UDP;
	packet.ip.saddr = source;
	packet.ip.daddr = dest;
	packet.ip.tot_len = packet.udp.len; /* cheat on the psuedo-header */
	if (check && check != checksum(&packet, bytes)) {
		DEBUG(LOG_ERR, "packet with bad UDP checksum received, ignoring");
		return -2;
	}
#ifdef __FAT_AP__
    payload_len = bytes - (sizeof(packet.ip) + sizeof(packet.udp));
	memcpy(payload, &(packet.data), payload_len);

    /* sometime DHCP reply packet is not END option field in option piece,
     * this packets is not complete, so lead to abnormal when process it */
    *((uint8_t *)payload + payload_len) = DHCP_END;
#else
	memcpy(payload, &(packet.data), bytes - (sizeof(packet.ip) + sizeof(packet.udp)));
#endif

	if (ntohl(payload->cookie) != DHCP_MAGIC) {
		LOG(LOG_ERR, "received bogus message (bad magic) -- ignoring");
		return -2;
	}
	DEBUG(LOG_INFO, "oooooh!!! got some!");
#ifdef __FAT_AP__
	return (payload_len + 1);
#else
	return bytes - (sizeof(packet.ip) + sizeof(packet.udp));
#endif

}

/* Broadcast a DHCP decline message */
int send_decline(unsigned long xid, uint32_t server, uint32_t requested)
{
	struct dhcpMessage packet;

	/* Fill in: op, htype, hlen, cookie, chaddr, random xid fields,
	 * client-id option (unless -C), message type option:
	 */
	init_packet(&packet, DHCPDECLINE);

	/* RFC 2131 says DHCPDECLINE's xid is randomly selected by client,
	 * but in case the server is buggy and wants DHCPDECLINE's xid
	 * to match the xid which started entire handshake,
	 * we use the same xid we used in initial DHCPDISCOVER:
	 */
	packet.xid = xid;
	/* DHCPDECLINE uses "requested ip", not ciaddr, to store offered IP */
	add_simple_option(packet.options, DHCP_REQUESTED_IP, requested);

	LOG(LOG_DEBUG, "Sending decline...");
	return raw_packet(&packet, INADDR_ANY, CLIENT_PORT, INADDR_BROADCAST,
				SERVER_PORT, MAC_BCAST_ADDR, client_config.ifindex);
}
