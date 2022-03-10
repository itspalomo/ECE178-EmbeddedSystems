/*
Jose Maciel Torres
Loading values into the 7 segment displays
a. Translate the following hex digits to Nios II assembly code 
993FF915 
42D5883A part3b
b. Convert the following assembly instruction into its corresponding machine code. Your 
answer should be an 8-digit hex number 
Add r10, r8, r11 
*/

.equ hex_7, 0x00002040


.global _start
_start:

add r10, r8, r11

movia r3, hex_7 #hrdware address of hex 7 

addi r4, r0, 0x00000018  #will display 9 
stbio r4, 0(r3) # write value to hex7

addi r4, r0, 0x00000018  #will display 9 
stbio r4, 0x10(r3) # write value to hex6

addi r4, r0, 0x00000030  #will display 3 
stbio r4, 0x20(r3) # write value to hex5

addi r4, r0, 0b0001110  #will display f
stbio r4, 0x30(r3) # write value to hex4

addi r4, r0, 0b0001110  #will display f 
stbio r4, 0x40(r3) # write value to hex3

addi r4, r0, 0x00000018  #will display 9 
stbio r4, 0x50(r3) # write value to hex2

addi r4, r0, 0x00000079  #will display 1 
stbio r4, 0x60(r3) # write value to hex1

addi r4, r0, 0x00000012  #will display 5 
stbio r4, 0x70(r3) # write value to hex0


LOOP: 
br LOOP



.end
