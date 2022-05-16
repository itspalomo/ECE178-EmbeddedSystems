
module niosdramproc (
	buzzer_export,
	clk_clk,
	hcecho_export,
	hctrig_export,
	hex0_export,
	hex1_export,
	hex2_export,
	hex3_export,
	hex4_export,
	hex5_export,
	hex6_export,
	hex7_export,
	ledg_export,
	ledr_export,
	mot_0_export,
	mot_1_export,
	pushbutton_export,
	reset_reset,
	sdram_clk_clk,
	sdram_wire_addr,
	sdram_wire_ba,
	sdram_wire_cas_n,
	sdram_wire_cke,
	sdram_wire_cs_n,
	sdram_wire_dq,
	sdram_wire_dqm,
	sdram_wire_ras_n,
	sdram_wire_we_n,
	switches_export,
	uart_RXD,
	uart_TXD);	

	output		buzzer_export;
	input		clk_clk;
	input		hcecho_export;
	output		hctrig_export;
	output	[6:0]	hex0_export;
	output	[6:0]	hex1_export;
	output	[6:0]	hex2_export;
	output	[6:0]	hex3_export;
	output	[6:0]	hex4_export;
	output	[6:0]	hex5_export;
	output	[6:0]	hex6_export;
	output	[6:0]	hex7_export;
	output	[8:0]	ledg_export;
	output	[17:0]	ledr_export;
	output	[3:0]	mot_0_export;
	output	[3:0]	mot_1_export;
	input	[3:0]	pushbutton_export;
	input		reset_reset;
	output		sdram_clk_clk;
	output	[12:0]	sdram_wire_addr;
	output	[1:0]	sdram_wire_ba;
	output		sdram_wire_cas_n;
	output		sdram_wire_cke;
	output		sdram_wire_cs_n;
	inout	[31:0]	sdram_wire_dq;
	output	[3:0]	sdram_wire_dqm;
	output		sdram_wire_ras_n;
	output		sdram_wire_we_n;
	input	[17:0]	switches_export;
	input		uart_RXD;
	output		uart_TXD;
endmodule
