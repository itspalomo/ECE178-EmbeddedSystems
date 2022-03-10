/*
Program iterated through an array and finds the larges element to put at the 
result 
Modifying pc after execution does not modify the result as 8 is the greatest already

*/

.equ LIST, 0x500       
.global _start 

_start: 
    movia  r4, LIST# load  0x500 address to r4
    ldw  r5, 4(r4) # load the N, size of list
    addi  r6, r4, 8 # address of list
    ldw  r7, (r6) # load 7

LOOP: 
    subi  r5, r5, 1 # decrement starts 4
    beq  r5, r0, DONE # has it reached 0?
    addi  r6, r6, 4 # go to next byte
    ldw  r8, (r6) # load next element in array
    bge  r7, r8, LOOP # is is r7>r8?
    add  r7, r8, r0 # i moves to next element if true
    br  LOOP 

DONE: 
    stw  r7, (r4)     

STOP:   
    br  STOP       
.org  0x500 

RESULT: 
.skip  4         

N: 
.word 7        

NUMBERS: 
.word  7, 8, 3, 6 ,7, 6, 2 
.end 
