Display
=========

The CHIP-8 Systems had a 64x32-pixel monochrome display, with this format:

---------------------
| (0,0)	    (63,0)  |
|                   |
|                   |
| (0,31)	(63,31) |
---------------------

Other interpreters had 64x48 or 64x64 modes. Super Chip-48 adds a 128x64 display.

CHIP-8 programs draw to the screen through sprites. A sprite is a group of bytes
which are binary representations of the picture. CHIP-8 Sprites may be up to
15 bytes, with a maximum dimension of 8x15.

Programs can refer to a group of sprites representing the hexadecimal digits 0
throught F. These sprites are 5 bytes long, or 8x5 pixels. This data should be
stored in the interpreter area of CHIP-8's memory (0x000 -> 0x1FF).

Below is a list of each character's bytes, in binary and hexadecimal:

**TODO:** Add tables, I'm too lazy.
