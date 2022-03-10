
module joseproc (
	clk_clk,
	hex0_export,
	hex1_export,
	hex2_export,
	hex3_export,
	hex4_export,
	hex5_export,
	hex6_export,
	hex7_export,
	reset_reset_n);	

	input		clk_clk;
	output	[6:0]	hex0_export;
	output	[6:0]	hex1_export;
	output	[6:0]	hex2_export;
	output	[6:0]	hex3_export;
	output	[6:0]	hex4_export;
	output	[6:0]	hex5_export;
	output	[6:0]	hex6_export;
	output	[6:0]	hex7_export;
	input		reset_reset_n;
endmodule
