/*Jose Maciel Torres
part 5 hw2

*/

.equ HEX7, 0x00002000
.equ BLK1, 0x0500
.global _start

_start:

movia r2, BLK1 # block of data 
addi r6, r0, 0xFF
stb r6, 0(r2)
ldb r5, 0(r2)

srli r3, r5, 0x04
xori r3, r5, 0x0F
slli  r4, r3, 0x04
addi r4, r4, 0x0F

stb r4, 0(r2)


LOOPEND:
 br LOOPEND
 
.org  0x500

.end
