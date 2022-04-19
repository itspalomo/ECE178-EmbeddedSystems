/* 
 * "Small Hello World" example. 
 * 
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example 
 * designs. It requires a STDOUT  device in your system's hardware. 
 *
 * The purpose of this example is to demonstrate the smallest possible Hello 
 * World application, using the Nios II HAL library.  The memory footprint
 * of this hosted application is ~332 bytes by default using the standard 
 * reference design.  For a more fully featured Hello World application
 * example, see the example titled "Hello World".
 *
 * The memory footprint of this example has been reduced by making the
 * following changes to the normal "Hello World" example.
 * Check in the Nios II Software Developers Manual for a more complete 
 * description.
 * 
 * In the SW Application project (small_hello_world):
 *
 *  - In the C/C++ Build page
 * 
 *    - Set the Optimization Level to -Os
 * 
 * In System Library project (small_hello_world_syslib):
 *  - In the C/C++ Build page
 * 
 *    - Set the Optimization Level to -Os
 * 
 *    - Define the preprocessor option ALT_NO_INSTRUCTION_EMULATION 
 *      This removes software exception handling, which means that you cannot 
 *      run code compiled for Nios II cpu with a hardware multiplier on a core 
 *      without a the multiply unit. Check the Nios II Software Developers 
 *      Manual for more details.
 *
 *  - In the System Library page:
 *    - Set Periodic system timer and Timestamp timer to none
 *      This prevents the automatic inclusion of the timer driver.
 *
 *    - Set Max file descriptors to 4
 *      This reduces the size of the file handle pool.
 *
 *    - Check Main function does not exit
 *    - Uncheck Clean exit (flush buffers)
 *      This removes the unneeded call to exit when main returns, since it
 *      won't.
 *
 *    - Check Don't use C++
 *      This builds without the C++ support code.
 *
 *    - Check Small C library
 *      This uses a reduced functionality C library, which lacks  
 *      support for buffering, file IO, floating point and getch(), etc. 
 *      Check the Nios II Software Developers Manual for a complete list.
 *
 *    - Check Reduced device drivers
 *      This uses reduced functionality drivers if they're available. For the
 *      standard design this means you get polled UART and JTAG UART drivers,
 *      no support for the LCD driver and you lose the ability to program 
 *      CFI compliant flash devices.
 *
 *    - Check Access device drivers directly
 *      This bypasses the device file system to access device drivers directly.
 *      This eliminates the space required for the device file system services.
 *      It also provides a HAL version of libc services that access the drivers
 *      directly, further reducing space. Only a limited number of libc
 *      functions are available in this configuration.
 *
 *    - Use ALT versions of stdio routines:
 *
 *           Function                  Description
 *        ===============  =====================================
 *        alt_printf       Only supports %s, %x, and %c ( < 1 Kbyte)
 *        alt_putstr       Smaller overhead than puts with direct drivers
 *                         Note this function doesn't add a newline.
 *        alt_putchar      Smaller overhead than putchar with direct drivers
 *        alt_getchar      Smaller overhead than getchar with direct drivers
 *
 */
#include <stdio.h>
#include "system.h"
#include "io.h"
#include "sys/alt_stdio.h"
#include "altera_avalon_pio_regs.h"
#include "alt_types.h"
#include "sys/alt_irq.h"

volatile int edge_capture;

volatile int hex0 = 0x000020c0;
volatile int hex1 = 0x000020b0;
volatile int hex2 = 0x000020a0;
volatile int hex3 = 0x00002090;
volatile int hex4 = 0x00002080;
volatile int hex5 = 0x00002070;
volatile int hex6 = 0x00002060;
volatile int hex7 = 0x00002050;


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
#define HEXVAL_9 0b10011000 /*A*/
#define HEXVAL_9 0b10011000 /*b*/
#define HEXVAL_9 0b10011000 /*c*/
#define HEXVAL_9 0b10011000 /*d*/
#define HEXVAL_NEG 0b0111111 /*d*/
#define HEXVAL_CLEAR 0b11111111 /*Clear*/

int hextable[] = {HEXVAL_0, HEXVAL_1, HEXVAL_2, HEXVAL_3, HEXVAL_4,
					HEXVAL_5, HEXVAL_6, HEXVAL_7, HEXVAL_8, HEXVAL_9};

void clearhex();


static void init_button_pio();
static void button_isr(void* context, alt_u32 id);
static void handle_button_interrupt(int capped);
static void initial_message()
{
    alt_printf("* Hello from Nios II!    *\n");
}



int main()
{ 
	initial_message();
	init_button_pio();
    while (1)
    {
    }
    return 0;
}

static void init_button_pio()
{
	/* Recast the edge_capture pointer to match the alt_irq_register() function
	     * prototype. */
	    void* edge_capture_ptr = (void*) &edge_capture;
	    /* Enable all 4 button interrupts. */
	    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PUSH_BUTTONS_BASE, 0x0f);
	    /* Reset the edge capture register. */
	    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PUSH_BUTTONS_BASE, 0x00);
	    /* Register the interrupt handler. */
	    alt_ic_isr_register(PUSH_BUTTONS_IRQ_INTERRUPT_CONTROLLER_ID, PUSH_BUTTONS_IRQ,
	               button_isr, edge_capture_ptr, 0x00);
}



static void button_isr(void* context, alt_u32 id)
{
	/* Cast context to edge_capture's type. It is important that this be
	     * declared volatile to avoid unwanted compiler optimization.
	     */
	    volatile int* edge_capture_ptr = (volatile int*) context;
	    /* Store the value in the Button's edge capture register in *context. */
	    *edge_capture_ptr = IORD_ALTERA_AVALON_PIO_EDGE_CAP(PUSH_BUTTONS_BASE);

	    alt_printf("Interrupt occurred\n");
	    alt_printf("ISR Reached!\n");

		 if (*edge_capture_ptr & 0b0010)
			 IOWR_ALTERA_AVALON_PIO_DATA(LEDG_BASE,0b0001);
		 else if(*edge_capture_ptr & 0b0100) //key 3
		 {

			 IOWR_ALTERA_AVALON_PIO_DATA(LEDG_BASE,0b1001);
		 }


		clearhex();
	    /* Reset the Button's edge capture register. */
	    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PUSH_BUTTONS_BASE, 0);
	    IORD_ALTERA_AVALON_PIO_EDGE_CAP(PUSH_BUTTONS_BASE);
}




void clearhex()
{
	IOWR_ALTERA_AVALON_PIO_DATA(hex0,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(hex1,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(hex2,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(hex3,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(hex4,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(hex5,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(hex6,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(hex7,HEXVAL_CLEAR);
}
