/*
** For memory configurations that don't incorporate Serial Presence
** Detect (SPD) the SPD EEPROM can be simulated using a static table
** in memory.  This capability is enabled by defining
** STATIC_DRAM_CONFIG_TABLE to point to this array which contains the
** simulated SPD data that will be used to configure each DIMM
** interface.
*/

/* Serial Presence Detect (SPD) for DDR2 SDRAM - JEDEC Standard No. 21-C */
/* ===================================================================== */

/* Notes: "*" indicates which bytes are REQUIRED to configure the
   Octeon DDR2 Controller. */

/*
** Example: Micron MT47H32M16BT3B based on datasheet found
** at http://download.micron.com/pdf/datasheets/dram/ddr2/512MbDDR2.pdf
** 1-Rank Unbuffered ECC
*/
const unsigned char static_ddr2_spd_data[] = {
/* Byte                                                                              */   
/* Number  Function                                                          Notes   */   
/* ======  ==============================================================    ======  */
/*  0      Number of Serial PD Bytes written during module production                */   0x80,
/*  1      Total number of Bytes in Serial PD device                                 */   0x08,
/*  2      Fundamental Memory Type (FPM, EDO, SDRAM, DDR, DDR2)               *      */   0x08,
/*  3      Number of Row Addresses on this assembly                           *      */   0x0d,
/*  4      Number of Column Addresses on this assembly                        *      */   0x0a,
/*  5      Number of DIMM Ranks                                               *      */   0x00,
/*  6      Data Width of this assembly                                               */   0x48,
/*  7      Reserved                                                                  */   0x00,
/*  8      Voltage Interface Level of this assembly                                  */   0x05,
/*  9      SDRAM Cycle time at Maximum Supported CAS Latency (CL), CL=X       *      */   0x30,
/* 10      SDRAM Access from Clock                                                   */   0x45,
/* 11      DIMM configuration type (Non-parity, Parity or ECC)                *      */   0x02,
/* 12      Refresh Rate/Type                                                  *      */   0x82,
/* 13      Primary SDRAM Width                                                *      */   0x10,
/* 14      Error Checking SDRAM Width                                                */   0x08,
/* 15      Reserved                                                                  */   0x00,
/* 16      SDRAM Device Attributes: Burst Lengths Supported                   *      */   0x0c,
/* 17      SDRAM Device Attributes: Number of Banks on SDRAM Device           *      */   0x04,
/* 18      SDRAM Device Attributes: CAS Latency                               *      */   0x38,
/* 19      Reserved                                                                  */   0x00,
/* 20      DIMM Type Information                                              *      */   0x02,
/* 21      SDRAM Module Attributes                                                   */   0x00,
/* 22      SDRAM Device Attributes: General                                          */   0x03,
/* 23      Minimum Clock Cycle at CLX-1                                       *      */   0x3d,
/* 24      Maximum Data Access Time (tAC) from Clock at CLX-1                        */   0x50,
/* 25      Minimum Clock Cycle at CLX-2                                       *      */   0x50,
/* 26      Maximum Data Access Time (tAC) from Clock at CLX-2                        */   0x60,
/* 27      Minimum Row Precharge Time (tRP)                                   *      */   0x3c,
/* 28      Minimum Row Active to Row Active delay (tRRD)                      *      */   0x28,
/* 29      Minimum RAS to CAS delay (tRCD)                                    *      */   0x3c,
/* 30      Minimum Active to Precharge Time (tRAS)                            *      */   0x28,
/* 31      Module Rank Density                                                       */   0x80,
/* 32      Address and Command Input Setup Time Before Clock (tIS)                   */   0x40,
/* 33      Address and Command Input Hold Time After Clock (tIH)                     */   0x40,
/* 34      Data Input Setup Time Before Clock (tDS)                                  */   0x30,
/* 35      Data Input Hold Time After Clock (tDH)                                    */   0x30,
/* 36      Write recovery time (tWR)                                          *      */   0x3c,
/* 37      Internal write to read command delay (tWTR)                        *      */   0x1e,
/* 38      Internal read to precharge command delay (tRTP)                           */   0x1e,
/* 39      Memory Analysis Probe Characteristics                                     */   0x00,
/* 40      Extension of Byte 41 tRC and Byte 42 tRFC                          *      */   0x00,
/* 41      SDRAM Device Minimum Active to Active/Auto Refresh Time (tRC)             */   0x37,
/* 42      SDRAM Min Auto-Ref to Active/Auto-Ref Command Period (tRFC)        *      */   0x69,
/* 43      SDRAM Device Maximum device cycle time (tCKmax)                           */   0x80,
/* 44      SDRAM Device maximum skew between DQS and DQ signals (tDQSQ)              */   0x18,
/* 45      SDRAM Device Maximum Read DataHold Skew Facktor (tQHS)                    */   0x22,
/* 46      PLL Relock Time                                                           */   0x00,
/* 47-xx   IDD in SPD - To be defined                                                */   0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
/*         Reserved                                                                  */   0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
/* xx-61   Reserved                                                                  */   0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
/* 62      SPD Revision                                                              */   0x12,
/* 63      Checksum for Bytes 0-62                                                   */   0xf5,
/* 64-71   Manufacturers JEDEC ID Code                                               */   0x7f,
                                                                                          0x61,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
/* 72      Module Manufacturing Location                                             */   0x00,
/* 73-90   Module Part Number                                                 *      */   0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
/* 91-92   Module Revision Code                                                      */   0x00,
                                                                                          0x00,
/* 93-94   Module Manufacturing Date                                                 */   0x00,
                                                                                          0x00,
/* 95-98   Module Serial Number                                                      */   0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
/* 99-127  Manufacturers Specific Data                                               */   0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
                                                                                          0x00,
};
