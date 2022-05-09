#include "system.h"
#include "io.h"
#include "sys/alt_stdio.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_irq.h"
#include "alt_types.h"
#include "altera_avalon_timer_regs.h"
#include "altera_up_avalon_rs232.h"
#include "altera_up_avalon_rs232_regs.h"

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

#define FIFO_EMPTY 0x0

int hextable[] = {HEXVAL_0, HEXVAL_1, HEXVAL_2, HEXVAL_3, HEXVAL_4,
					HEXVAL_5, HEXVAL_6, HEXVAL_7, HEXVAL_8, HEXVAL_9};



void clearhex();
void decimal_to_hex(alt_u8);

/*UART read bluetooth*/
void taskRS232();

int main()
{

	alt_printf("Testing GPIO\n");
	IOWR_ALTERA_AVALON_PIO_DATA(MOT_0_BASE,0b0000);
	IOWR_ALTERA_AVALON_PIO_DATA(MOT_1_BASE,0b0000);

	taskRS232();

  return 0;
}

void taskRS232()
{
	alt_u32 FIFO_write;
	alt_u16 FIFO_read;
	char data_r8;
	char data_w8;
	unsigned p_error;

	alt_up_rs232_dev* rs232dev;

	/*Open serial port*/
	rs232dev = alt_up_rs232_open_dev("/dev/uart");
	if (rs232dev == NULL)
		alt_printf("Error: could not open RS232 UART\n");
	else
		alt_printf("Opened RS232 UART device\n");

	alt_up_rs232_enable_read_interrupt(rs232dev);

	char temp;

	alt_printf("To Read enter a, else will write");


	while(1){

		temp = alt_getchar();

			alt_up_rs232_disable_read_interrupt(rs232dev);
			data_w8 = 'a';
			FIFO_write = alt_up_rs232_get_available_space_in_write_FIFO(rs232dev);
			if(FIFO_write == 0x80){
				alt_up_rs232_write_data(rs232dev,data_w8);
				alt_printf("Wrote %c to RS232 UART", data_w8);
			}
	}
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

	IOWR_ALTERA_AVALON_PIO_DATA(HEX_2_BASE, hextable[uhex%10]);


	IOWR_ALTERA_AVALON_PIO_DATA(HEX_3_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_4_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_5_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_6_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_7_BASE,HEXVAL_CLEAR);
}
