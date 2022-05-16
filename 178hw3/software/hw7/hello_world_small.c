#include <stdio.h>
#include <stdlib.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "altera_avalon_timer_regs.h"
#include <sys/alt_irq.h>

#define HEXVAL_0 0b11000000 /*0*/
#define HEXVAL_1 0b11111001 /*1*/
#define HEXVAL_2 0b10100100 /*2*/
#define HEXVAL_3 0b10110000 /*3*/
#define HEXVAL_4 0b10011001 /*4*/
#define HEXVAL_5 0b10010010 /*5*/
#define HEXVAL_6 0b10000010 /*6*/
#define HEXVAL_7 0b11111000 /*7*/
#define HEXVAL_8 0b10000000 /*8*/
#define HEXVAL_9 0b10011000 /*9*/
#define HEXVAL_NEG 0b0111111 /*-*/
#define HEXVAL_CLEAR 0b11111111 /*Clear*/


int hextable[] = {HEXVAL_0, HEXVAL_1, HEXVAL_2, HEXVAL_3, HEXVAL_4,
					HEXVAL_5, HEXVAL_6, HEXVAL_7, HEXVAL_8, HEXVAL_9};


alt_u32 n = 0;
alt_u32 p3 = 0;
alt_u8 direction = 1;

// volatile indicates that this variable may be changed
// by an external program or hardware device
volatile int keys_edge_capture;

void decimal_to_hex(alt_u8 uhex);
void clearhex();
static void keys_int_init();
static void timer_int_init();
void keys_isr(void* context);
void timer_isr();


void toggle_timer();
void directionchange();
void directionchange2();
void part1();
void part2();
void part3();

int main() {
    keys_int_init();
    timer_int_init();
    IOWR_ALTERA_AVALON_PIO_DATA(LEDR_BASE, 0);
    clearhex();

    part3();

    return 0;
}

void part1(){
	while(1){
		decimal_to_hex(n);
	}
}

void part2(){
	while(1){
		IOWR_ALTERA_AVALON_PIO_DATA(LEDR_BASE, n);
		if(!n)
		  n++;
	}
}

void part3(){
	while(1){
		IOWR_ALTERA_AVALON_PIO_DATA(LEDR_BASE, n);
		if(!n)
		  n++;
	}
}

static void keys_int_init() {
    void* keys_edge_capture_ptr = (void*) &keys_edge_capture;
    // Enable all three keys as interrupt
    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PUSH_BUTTONS_BASE, 0x0F);
    // Reset edge capture register
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PUSH_BUTTONS_BASE, 0x00);
    // Register ISR and place it on the interrupt table
	#ifdef ALT_ENHANCED_INTERRUPT_API_PRESENT
	   alt_ic_isr_register(PUSH_BUTTONS_IRQ_INTERRUPT_CONTROLLER_ID, PUSH_BUTTONS_IRQ,
	            keys_isr, keys_edge_capture_ptr, 0x00);
	 #else

	   alt_irq_register(PUSH_BUTTONS_IRQ,
			   keys_edge_capture_ptr,
						keys_isr);
	 #endif
}

void keys_isr(void* context) {
    // Recast context to keys_edge_capture type
    volatile int* keys_edge_capture_ptr = (volatile int*) context;
    // Read the edge capture to determine what triggered the interrupt
    *keys_edge_capture_ptr = IORD_ALTERA_AVALON_PIO_EDGE_CAP(PUSH_BUTTONS_BASE);

    if (*keys_edge_capture_ptr & 0b0001)// key2
	{
    	toggle_timer();

    	//part 3
    	if((alt_u16)IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE) == (alt_u16)IORD_ALTERA_AVALON_PIO_DATA(LEDR_BASE)){
    		IOWR_ALTERA_AVALON_PIO_DATA(HEX_0_BASE, hextable[++p3]);
    		if(p3 >= 0xf)
    		    p3 = 0;
    	}
    	else
    		IOWR_ALTERA_AVALON_PIO_DATA(HEX_0_BASE, hextable[0]);

	}
	else if(*keys_edge_capture_ptr & 0b0010) //key 2
	{
		// set the period to 125 ms, TIMER_LOAD_VALUE is scalar for 1ms in the native clk freq
		int period = 125 * TIMER_0_LOAD_VALUE;
		int periodlo = period & 0xffff;
		int periodhi = period >> 16;
		IOWR_ALTERA_AVALON_TIMER_PERIODL(TIMER_0_BASE, periodlo);
		IOWR_ALTERA_AVALON_TIMER_PERIODH(TIMER_0_BASE, periodhi);
	} else if(*keys_edge_capture_ptr & 0b0100) //key 3
	{
		// set the period to 250 ms, TIMER_LOAD_VALUE is scalar for 1ms in the native clk freq
		int period = 250 * TIMER_0_LOAD_VALUE;
		int periodlo = period & 0xffff;
		int periodhi = period >> 16;
		IOWR_ALTERA_AVALON_TIMER_PERIODL(TIMER_0_BASE, periodlo);
		IOWR_ALTERA_AVALON_TIMER_PERIODH(TIMER_0_BASE, periodhi);
	}else if(*keys_edge_capture_ptr & 0b1000) //key 4
	{
		// set the period to 1000 ms, TIMER_LOAD_VALUE is scalar for 1ms in the native clk freq
		int period = 1000 * TIMER_0_LOAD_VALUE;
		int periodlo = period & 0xffff;
		int periodhi = period >> 16;
		IOWR_ALTERA_AVALON_TIMER_PERIODL(TIMER_0_BASE, periodlo);
		IOWR_ALTERA_AVALON_TIMER_PERIODH(TIMER_0_BASE, periodhi);
	}

    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PUSH_BUTTONS_BASE, 0x00);

    IORD_ALTERA_AVALON_PIO_EDGE_CAP(PUSH_BUTTONS_BASE);
    return;
}

static void timer_int_init() {
    // stop the timer first
    IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE, 0x8);

    // set the period to 1000 ms, TIMER_LOAD_VALUE is scalar for 1ms in the native clk freq
    int period = 1000 * TIMER_0_LOAD_VALUE;
    int periodlo = period & 0xffff;
    int periodhi = period >> 16;
    IOWR_ALTERA_AVALON_TIMER_PERIODL(TIMER_0_BASE, periodlo);
    IOWR_ALTERA_AVALON_TIMER_PERIODH(TIMER_0_BASE, periodhi);

    //enable ITO, CONT, and START bits
    IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE, 0b111);


	#ifdef ALT_ENHANCED_INTERRUPT_API_PRESENT
	   alt_ic_isr_register(TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID, TIMER_0_IRQ,
               timer_isr, NULL, NULL);
	 #else

	   alt_irq_register(TIMER_0_IRQ,
						NULL,
						timer_isr);
	 #endif
}

void timer_isr() {
    // clear the TO bit
    IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0);

    directionchange2();

    // dummy instruction to synchronize
    IORD_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE);
    return;
}

void toggle_timer() {
    int is_running = IORD_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE) & 0b10;
    if (is_running) // stop the timer
        IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE, 0b1000);
    else // enable START, CONT, and ITO
        IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE, 0b111);
}

void directionchange() {
    if (n == 0)
        direction = 1;
    else if (n == 0xf)
        direction = 0;

    if (direction)
        n++;
    else
        n--;
}

void directionchange2() {
    if (n <= 1)
    	direction = 1;
    else if (n >= 0x3FFFF)
        direction = 0;

    if (direction){
    	n = n << 0b1;
    	n++;
    }
    else
        n = n >> 0b1;
}

void decimal_to_hex(alt_u8 uhex)
{
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_0_BASE, hextable[(uhex)%10]);
	uhex /= 10;

	IOWR_ALTERA_AVALON_PIO_DATA(HEX_1_BASE, hextable[(uhex)%10]);
	uhex /= 10;

	IOWR_ALTERA_AVALON_PIO_DATA(HEX_2_BASE, HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_3_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_4_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_5_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_6_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_7_BASE,HEXVAL_CLEAR);
}

void clearhex()
{
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_0_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_1_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_2_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_3_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_4_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_5_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_6_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_7_BASE,HEXVAL_CLEAR);
}
