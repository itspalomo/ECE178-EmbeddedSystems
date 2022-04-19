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
#include "sys/alt_stdio.h"
#include "altera_avalon_pio_regs.h"
#include "alt_types.h"
#include "sys/alt_irq.h"

volatile int edge_capture;

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
#define HEXVAL_NEG 0b0111111 /*d*/
#define HEXVAL_CLEAR 0b11111111 /*Clear*/

int hextable[] = {HEXVAL_0, HEXVAL_1, HEXVAL_2, HEXVAL_3, HEXVAL_4,
					HEXVAL_5, HEXVAL_6, HEXVAL_7, HEXVAL_8, HEXVAL_9};

void clearhex();

void decimal_to_hex(alt_u8 uhex);
alt_u8 concatenate(alt_u8 x, alt_u8 y);
alt_u8 get_hex();
static void init_button_pio();
alt_u8 hextableplace(alt_u8 place);
static void button_isr(void* context, alt_u32 id);
static void button_isr2(void* context, alt_u32 id);
static void initial_message()
{
    alt_printf("* Hello from Nios II!    *\n");
}



int main()
{ 
	initial_message();
	init_button_pio();
	clearhex();
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

		 if (*edge_capture_ptr & 0b0010)// key2
		 {
			 IOWR_ALTERA_AVALON_PIO_DATA(LEDG_BASE,0b0001);
			 decimal_to_hex((alt_u8)IORD_ALTERA_AVALON_PIO_DATA(LEDG_BASE));
		 }
		 else if(*edge_capture_ptr & 0b0100) //key 3
		 {
			 int temp = (int)IORD_ALTERA_AVALON_PIO_DATA(LEDG_BASE);
			 if((IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE) & 0b000000000000000001))
			 {
				 ++temp;
				 while (temp%2 == 0)
				 {
					temp = (temp > 127 ? 1 : ++temp);
					if (temp == 1)
						break;
				 }

				 IOWR_ALTERA_AVALON_PIO_DATA(LEDG_BASE,temp);
				 decimal_to_hex((alt_u8)temp);
			 }
			 else if (!(IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE) & 0b000000000000000000))
			 {
				temp = (temp <= 1 ? 1 : --temp);
				 while (temp%2 == 0)
				 {
					temp = (temp <= 1 ? 1 : --temp);
					if (temp == 1)
						break;
				 }

				 IOWR_ALTERA_AVALON_PIO_DATA(LEDG_BASE,temp);
				 decimal_to_hex((alt_u8)temp);
			 }
		 }


	    /* Reset the Button's edge capture register. */
	    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PUSH_BUTTONS_BASE, 0);
	    IORD_ALTERA_AVALON_PIO_EDGE_CAP(PUSH_BUTTONS_BASE);
}

static void button_isr2(void* context, alt_u32 id)
{
	/* Cast context to edge_capture's type. It is important that this be
	     * declared volatile to avoid unwanted compiler optimization.
	     */
	    volatile int* edge_capture_ptr = (volatile int*) context;
	    /* Store the value in the Button's edge capture register in *context. */
	    *edge_capture_ptr = IORD_ALTERA_AVALON_PIO_EDGE_CAP(PUSH_BUTTONS_BASE);


	    alt_printf("Interrupt occurred\n");
	    alt_printf("ISR Reached!\n");



		 if (*edge_capture_ptr & 0b0001)// key1
		 {
			 IOWR_ALTERA_AVALON_PIO_DATA(LEDG_BASE,0b0000);
			 decimal_to_hex((alt_u8)0b01);
		 }
		 else if(*edge_capture_ptr & 0b0010) //key 2
		 {

				 alt_u8 temp = get_hex();
				 alt_printf("\nIncrement %x", temp);

				 if (temp >= 99)
					 temp = 1;
				 else
					 temp++;

				 alt_printf("\nIncremented %x", temp);
				 decimal_to_hex(temp);

		 }
		 else if(*edge_capture_ptr & 0b0100) //key 3
		 {

				 alt_u8 temp = get_hex();
				 alt_printf("\nDecrement %x", temp);

				 if (temp <= 1)
					 temp = 1;
				 else
					 temp--;
				 alt_printf("\nIncremented %x", temp);
				 decimal_to_hex((alt_u8)temp);

		 }


	    /* Reset the Button's edge capture register. */
	    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PUSH_BUTTONS_BASE, 0);
	    IORD_ALTERA_AVALON_PIO_EDGE_CAP(PUSH_BUTTONS_BASE);
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

void decimal_to_hex(alt_u8 uhex)
{
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_0_BASE, hextable[(uhex)%10]);
	uhex /= 10;

	IOWR_ALTERA_AVALON_PIO_DATA(HEX_1_BASE, hextable[(uhex)%10]);
	uhex /= 10;

	IOWR_ALTERA_AVALON_PIO_DATA(HEX_2_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_3_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_4_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_5_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_6_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_7_BASE,HEXVAL_CLEAR);
}

alt_u8 get_hex()
{

	alt_u8 x = ((alt_u8)IORD_ALTERA_AVALON_PIO_DATA(HEX_1_BASE)&0b01111111);
	x+= 0b10000000;
	x = hextableplace(x);
	alt_printf("\nX val = %x", x);
	alt_u8 y = ((alt_u8)IORD_ALTERA_AVALON_PIO_DATA(HEX_0_BASE)&0b01111111);
	y+= 0b10000000;
	y = hextableplace(y);


	alt_printf("\nY val = %x", y);

	if(x == 0xff || y == 0xff){
		return 0b01;
	}

	alt_printf("\nConcatenation = %x\n", concatenate(x,y));

	return concatenate(x,y);

}

alt_u8 hextableplace(alt_u8 place)
{
	switch(place){
		case HEXVAL_0:
			place = 0;
				break;
		case HEXVAL_1:
			place = 1;
				break;
		case HEXVAL_2:
			place = 2;
				break;
		case HEXVAL_3:
			place = 3;
				break;
		case HEXVAL_4:
			place = 4;
				break;
		case HEXVAL_5:
			place = 5;
				break;
		case HEXVAL_6:
			place = 6;
				break;
		case HEXVAL_7:
			place = 7;
				break;
		case HEXVAL_8:
			place = 8;
				break;
		case HEXVAL_9:
			place = 9;
				break;
	}
	return place;
}


alt_u8 concatenate(alt_u8 x, alt_u8 y) {
	alt_u8 pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;
}
