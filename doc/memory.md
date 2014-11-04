Memory
=======

A CHIP-8 system consists of 4KB (4094 bytes) of RAM, from location 0x000 (0) to 0xFFF (4095).

The first 512 bytes (0x000 -> 0x1FF) are where the interpreted is located, thus can't be used
by programs.

Programs usually start at location 0x200 (512) although some begin at 0x600 (1536)
