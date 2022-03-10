/*
Jose Maciel Torres
Loading values into the 7 segment displays
a. Translate the following hex digits to Nios II assembly code 
993FF915 
b. Convert the following assembly instruction into its corresponding machine code. Your 
answer should be an 8-digit hex number 
Add r10, r8, r11 
*/

.equ HEX0, 0x00002070


.global _start
_start: 

addi r4, r0, 0x05
movia r2, HEX0

LOOP: 
stbio r2, 0(r4)
br LOOP

.end
