
.text
.equ switches, 0x00002050
.equ ledr, 0x00002040
.equ hex0, 0x00002010
.equ hex1, 0x00001080

    .global _start
_start:
    movia r1, DISP_LUT #moves the address of LUT (8-bit addresss)
    movia r2, switches #moves the address of switches into r2
    movia r3, ledr #moves the address of LEDR into r3
    movia r4, hex0 #moves the address of 7-segment display to r4
    movia r5, hex1 #moves the address of 7-segment display to r8
    movia r7, DISP_OFF #moves the value of address of 0xFFFFFFFF value
    ldw r7, 0(r7) #with 0 offset, load value of 0xFFFFFFFF
    stwio r7, 0(r4) # turn off displays
    stwio r7, 0(r5) # turn off displays
LOOP:
    movi r8, 0 #move 0 into r8 to clear
    ldbio r6, 0(r2) #read switches
    andi r6, r6, 0xF #mask LSBs to read switches
    add r8, r1, r6 #add the switch state value at LUT address and put value in r8
    ldb r8, 0(r8) #load 7-segment display value
    stwio r8, 0(r4) #stores the value in display to hex0
    call DELAY #jump to DELAY subroutine
    call SQUARE #jump to SQUARE subroutine
    stwio r13, 0(r3) #displays the square on red LED
    br LOOP #infinite loop
END:
    br END
    #SUBROUTINE for Delay
DELAY:
    movi r10, 0 #clear r10
    movi r11, 0x1FFF #equivalent to 8191
    slli r11, r11, 8 #shift to left by 8
DELAY_LOOP:
    addi r10, r10, 1 #add 1 to empty register
    bne r10, r11, DELAY_LOOP # if r10, r11 not equal, go to Delay Loop
DELAY_END:
    ret
    #SUBROUTINE for Square
SQUARE:
    movi r12, 0 #clear counter
    movi r13, 0 #clear answer
SQUARE_LOOP:
    beq r12, r6, SQUARE_END #check if done
    add r13, r13, r6 #add original value
    addi r12, r12, 1 #increment counter
    br SQUARE_LOOP #jump back for more iterations
SQUARE_END:
    ret
DISP_LUT: .byte 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x98, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E
DISP_OFF: .word 0xFFFFFFFF
.end