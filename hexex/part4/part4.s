/*Jose Maciel Torres
part 4 hw2
block move program of n bytes
move a block of N consecutive bytes of data starting at offset address BLK1 
in memory to another block of memory locations starting at offset address BLK2.
*/

.equ HEX7, 0x00002000
.equ BLK1, 0x00003000
.equ BLK2, 0x00004000
.equ COUNTER, 0x000A

.global _start

_start:

movia r2, BLK1 # block of data start
movia r3, BLK2 # block of data end
movi r4, COUNTER # N bytes to move

BLOCKMOV:
beq r4, r0, LOOPEND
ldb r5, 0(r2)
stb r5, 0(r3)
addi r2, r0, 0x02
addi r3, r0, 0x02

br BLOCKMOV

LOOPEND:
 br LOOPEND

.end
