/*
Jose Maciel Torres
Loading values into the 7 segment displays
a. Translate the following hex digits to Nios II assembly code 
993FF915 
b. Convert the following assembly instruction into its corresponding machine code. Your 
answer should be an 8-digit hex number 
Add r10, r8, r11 
*/

.equ HEX0, 0x00002010


.global _start
_start: 

addi r4, r0, 0b01111111
movia r2, HEX0

stbio r4, 0(r2)
stbio r4, 0x10(r2)
stbio r4, 0x20(r2)
stbio r4, 0x30(r2)
stbio r4, 0x40(r2)
stbio r4, 0x50(r2)
stbio r4, 0x60(r2)
LOOP: 
br LOOP

.end
