# TEXT_BASE is set in top-level Makefile -- don't override here

## ROM version
#ifdef BOOT_FROM_NAND
#TEXT_BASE = 0xa0100000
#else
#ifeq ($(COMPRESSED_UBOOT),1)
#TEXT_BASE = 0x80010000
#BOOTSTRAP_TEXT_BASE = 0x9f000000
#else
#TEXT_BASE = 0x9f000000
#endif
#endif
## TEXT_BASE = 0xbf000000

# SDRAM version
# TEXT_BASE = 0x80000000

# RAM version
# TEXT_BASE = 0x83fc0000
# TEXT_BASE = 0x80100000
