
/*	Program	that	converts	a	binary	number	to	decimal,	you	can	modify	the	program */
.text
.global _start

_start:
    movia r4, N #move value of N in r4
    addi r8, r4, 4 #r8 points to storage location
    ldw r4, (r4) #r4 loads N
    movi r5, 1000
    mov r2, r4 # DIVIDE is moved to r2
    call DIVIDE
    stb r3, 3(r8) #stores value 1000
    movi r5, 100 #divisor parameter changed to 100
    call DIVIDE
    stb r3, 2(r8) #stores value 100
    movi r5, 10 #divisor parameter changed to 10
    call DIVIDE
    stb r3, 1(r8) #stores value 10
    stb r2, (r8) #stores value 1

END: br END 

/*	Subroutine	can	be	modified	if	needed*/
/*	Subroutine	to	perform	the	integer	division	r4	/	10	*/
/*	Returns:	quotient	in	r3,	and	remainder	in	r2 */

DIVIDE: #subroutine
    movi r3, 0 #r3 is quotient which will be incremented later

CONT:
    blt r2, r5, DIV_END
    sub r2, r2, r5
    addi r3, r3, 1
    br CONT
DIV_END:
    ret

N: .word 9876 #the decimal number to be converted
Digits: .space 4 #space for storage location
.end
