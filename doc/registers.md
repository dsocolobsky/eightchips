Registers
============

CHIP-8 has 16 general purpose registers, of 8-bit each. Usually referred as Vx, where x is
a hexadecimal digit (0 to F).

There's a 16-bit register called I. This is used to store memory addresses, thus only the
lowest (rightmost) 12 bits are usually used.

CHIP-8 also has two special purpose 8-bit registers, for delay and sound timers. When these
registers are non-zero, they are automatically decremented at a rate of 60Hz.

The Program Counter (PC) is 16-bit, and it's used to store the currently executing address.
The Stack Pointer (SP) can be 8-bit, it points to the top of the stack.

The Stack is an array of 16 16-bit values, it's used to store the address to return in a
subroutine. CHIP-8 allows up to 16 leves of nested subroutines.
