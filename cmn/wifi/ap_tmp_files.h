#ifndef _AP_TMP_FILES_H
#define _AP_TMP_FILES_H

// following files are generated directly from flash

#define NAME_FILE	"/tmp/name"
#define GROUP_FILE	"/tmp/group"
#define MASTER_FILE	"/tmp/master"
#define LOC_FILE	"/tmp/location"
#define SRV_IP_FILE	"/tmp/serverip"
#define SRV_NAME_FILE	"/tmp/servername"
#define OCSP_DEFAULT_FILE "/tmp/ocsp_default"
#define OUTPUT_FILE	"/tmp/fl_cfg"
#define IMAGE_NUM_FILE	"/tmp/image.log"
#define BOARDNAME_FILE	"/tmp/boardname"
#define BOOTCMD_FILE	"/tmp/bootcmd"
#define WATCHDOG_FILE	"/tmp/watchdog"
#define A_ANT_GAIN_FILE	"/tmp/a_ant_gain"
#define A_ANT_GAIN_FILE_10x	"/tmp/a_ant_gain_10x"
#define A_SPUR_IMMUNITY_FILE "/tmp/a_spur_immunity"
#define G_ANT_GAIN_FILE	"/tmp/g_ant_gain"
#define G_ANT_GAIN_FILE_10x	"/tmp/g_ant_gain_10x"
#define SCH_MODE_RADIO_0_FILE	"/tmp/sch_mode_radio_0"
#define SCH_MODE_RADIO_1_FILE	"/tmp/sch_mode_radio_1"
#define AP70_EXT_ANT_FILE "/tmp/ap70_ext_ant"
#define IKEPSK_FILE	"/tmp/ikepsk"
#define PAPUSER_FILE	"/tmp/papuser"
#define PAPPASSWD_FILE	"/tmp/pappasswd"
#define PPPOEUSER_FILE	"/tmp/pppoe_user"
#define PPPOEPASSWD_FILE	"/tmp/pppoe_passwd"
#define PPPOESVCNAME_FILE	"/tmp/pppoe_svcname"
#define PPPOECHAPSECRET_FILE    "/tmp/pppoe_chap_secret"
#define PPPOEUNNUMBERED_L_FILE    "/tmp/pppoe_unnumbered_lip"
#define ETHCHNL_FILE	"/tmp/etherchannel"
#define ENET1MODE_FILE	"/tmp/enet1mode"
#define A_ANTENNA_FILE	"/tmp/a_antenna"
#define G_ANTENNA_FILE	"/tmp/g_antenna"
#define AP1200_FILE	"/tmp/ap1200"
#define AP_TYPE_FILE	"/tmp/ap_type"
#define AP1200_SNUM_FILE	"/tmp/ap1200_snum"
#define SAPD_DEBUG_FILE "/tmp/sapd_debug"
#define ASAP_DEBUG_FILE "/tmp/asap_debug"
#define EVDOUSER_FILE   "/tmp/evdo_user"  /* backwards compatibility */
#define USB_CARRIER_FILE   "/tmp/usb_carrier"
#define USB_MODEL_FILE   "/tmp/usb_model"
#define USB_TYPE_FILE   "/tmp/usb_type"
#define USB_USER_FILE   "/tmp/usb_user"
#define USB_PASSWD_FILE "/tmp/usb_passwd"
#define USB_DEV_FILE    "/tmp/usb_dev"
#define USB_DIAL_FILE   "/tmp/usb_dial"
#define USB_INIT_FILE   "/tmp/usb_init"
#define USB_TTY_FILE    "/tmp/usb_tty"
#define USB_TTY_CONTROL_FILE    "/tmp/usb_tty_control"
#define USB_MODESWITCH_FILE    "/tmp/usb_modeswitch"
#define NOUPGRADE_FILE  "/tmp/no_upgrade"
#define DNSLOG_FILE     "/tmp/dns_log"
#define MESH_ROLE_FILE "/tmp/mesh_role"
#define MESH_AUTO_ENABLE_FILE "/tmp/mesh_auto_enable"
#define LONGITUDE_FILE      "/tmp/longitude"
#define LATITUDE_FILE       "/tmp/latitude"
#define ALTITUDE_FILE       "/tmp/altitude"
#define A_ANT_BEARING_FILE    "/tmp/a_ant_bearing"
#define G_ANT_BEARING_FILE    "/tmp/g_ant_bearing"
#define A_ANT_TILT_ANGLE_FILE "/tmp/a_ant_tilt_angle"
#define G_ANT_TILT_ANGLE_FILE "/tmp/g_ant_tilt_angle"
#define REMOTE_AP_FILE "/tmp/remote_ap"
#define TEMP_MASTER_FILE "/tmp/temp_master"
#define PRIORITY_ETHERNET_FILE "/tmp/priority_ethernet"
#define PRIORITY_CELLULAR_FILE "/tmp/priority_cellular"
#define FOURG_USB_TYPE_FILE "/tmp/fourg_usb_type"
#define CELLULAR_NW_PREF_FILE "/tmp/cellular_nw_preference"
#define CERT_CAP_FILE "/tmp/cert_cap"
#define MESH_SAE_FILE         "/tmp/mesh_sae"
#define INSTALLATION_FILE "/tmp/installation"
#define AP_SINGLE_CHAIN_MODE_FILE "/tmp/sch_mode"
#define MEMLOG_DEBUG_FILE "/tmp/memlog_debug"
#define PREVIOUS_LMS_FILE "/tmp/previous_lms"
#define RFPROTECTSTANDALONE_FILE "/tmp/rfprotectstandalone"
#define FATAP_FILE "/tmp/fatap"
#define UPLINK_VLAN_FILE "/tmp/uplink_vlan"
#define EPIC_VLAN_ID_FILE "/tmp/epic_vlan_id"
#define NUM_IPSEC_RETRY_FILE "/tmp/num_ipsec_retry"
#define SECONDARY_MASTER_FILE "/tmp/secondary_master"
#define ENET0_BRIDGING_FILE "/tmp/enet0_bridging"
#ifdef __FAT_AP__
#define USB_PORT_DISABLE_FILE "/tmp/usb_port_disable"
#define USB_POWER_OVERRIDE_FILE "/tmp/usb_power_override"
#define USB_PIN_LOCK_FILE "/tmp/pin_lock"
#define IAP_INSTALLATION_TYPE_FILE "/tmp/installation_type"
#define IAP_DUAL_5G_FILE  "/tmp/dual_5g_mode"
#endif
#define FIPS_FORCE_FAILURE_FILE  "/tmp/fips_force_failure"
#define FIPS_FAIL_AES_OPENSSL_FILE  "/tmp/fips_force_fail_aes_openssl"
#define FIPS_FAIL_3DES_OPENSSL_FILE  "/tmp/fips_force_fail_3des_openssl"
#define FIPS_FAIL_HMAC_OPENSSL_FILE  "/tmp/fips_force_fail_hmac_openssl"
#define FIPS_FAIL_RNG_OPENSSL_FILE  "/tmp/fips_force_fail_rng_openssl"
#define FIPS_FAIL_RSA_OPENSSL_FILE  "/tmp/fips_force_fail_rsa_openssl"
#define FIPS_FAIL_SHA_OPENSSL_FILE  "/tmp/fips_force_fail_sha_openssl"
#define AP1XUSER_FILE		"/tmp/ap1xuser"
#define AP1XPASSWD_FILE		"/tmp/ap1xpasswd"
#define AP1XTLS_FILE        "/tmp/ap1xtls"
#define AP1XCERT_FILE       "/tmp/ap1xcert"
#define AP1XTLS_SUFFIX_ENABLE_FILE "/tmp/ap1xtls_suffix_enable"
#define AP1XTLS_SUFFIX_STRING_FILE "/tmp/ap1xtls_suffix_domain"
#define USB_POWER_MODE_FILE     "/tmp/usb_power_type"
#define AP_POWER_MODE_FILE     "/tmp/ap_power_mode"
#define AP_LLDP_PSE_DETECT_FILE "/tmp/ap_lldp_pse_detect"
#define PKCS12PASSPHRASE_FILE	"/tmp/pkcs12_passphrase"
#define USB_CSR_FILE            "/tmp/usb_csr"
#define IKEPSK_HEX_FILE         "/tmp/ikepsk_hex"
#define BLE_DEBUG_FILE                   "/tmp/ble_debug"
#define BLE_BLUOS_UPG_OVERRIDE_FILE      "/tmp/ble_bluos_upg_override"
#define BLE_OPMODE_FILE                  "/tmp/ble_opmode"
#define LACP_MODE_FILE          "/tmp/lacp_mode"
#define BOOTENV_BACKUP_DISABLE_FILE "/tmp/disable_bootenv_backup"
#define TOTAL_BOOTSTRAP_NUM     "/tmp/total_bootstrap_num"
#define REBOOT_NUM              "/tmp/reboot_num"
#define IKEP1_LIFETIME_FILE     "/tmp/ikep1_lifetime"
#define IKEP2_LIFETIME_FILE     "/tmp/ikep2_lifetime"

// following files are generated by processes. 
// There might be more than those listed here

#define SERIAL_FILE             "/tmp/serial"
#define ETH0_MAC_FILE           "/tmp/eth0_mac"
#define ARUBA_VERSION_FILE      "/tmp/aruba_version"
#define LMS_FILE                "/tmp/lms"
#define IS_RAP                  "/tmp/is_rap"
#define CERT_DN_FILE 			"/tmp/cert_DN"
#define AP_TUNNEL_IP            "/tmp/apip"
#define LD_CONN_LOG_FILE        "/tmp/ld_conn_log"
#define LD_CONN_STATE_FILE      "/tmp/ld_conn_state"
#define LD_DELAY_REBOOT         "/tmp/ld_delay_reboot"
#define REBOOT_REASON           "/tmp/reboot_reason"
#define USB_PRESENT             "/tmp/usb_present"
#define USB_PROVISIONED         "/tmp/usb_provisioned"
#define LD_REBOOT_AFTER         "/tmp/ld_reboot_after"
#define SDN_AP_FILE             "/tmp/sdn_ap"
#define RAP_TFTP_UPGRADE            "/tmp/rap_tftp_upgrade"
#define SDN_SERVER_FILE         "/tmp/sdn_server"
#define ENV_DUMP_FILE           "/tmp/envdump"
#define A_ANT_POL_FILE        "/tmp/a_ant_pol"
#define G_ANT_POL_FILE        "/tmp/g_ant_pol"
#define RADIO_0_5GHZ_ANT_POL "/tmp/radio_0_5g_ant_pol"
#define RADIO_1_5GHZ_ANT_POL "/tmp/radio_1_5g_ant_pol"
#define AP_HAS_TPM_FILE       "/tmp/ap_has_tpm"
#define TRUST_ANCHOR_FILE       "/tmp/TrustAnchor"
#define BOOTSTRAP_NUM           "/tmp/bootstrap_num"
#define REBOOTSTRAP_LMS_FILE "/tmp/rebootstrap_lms"
#define REBOOTSTRAP_REASON_FILE "/tmp/rebootstrap_reason"

/*ap stm and sapd log file size*/
#define STM_LOG_FILE_SIZE       "/tmp/stm_log_size"
#define SAPD_LOG_FILE_SIZE      "/tmp/sapd_log_size"

#define PREFUPLINK_FILE         "/tmp/preferred_uplink"

#endif // _AP_TMP_FILES_H
