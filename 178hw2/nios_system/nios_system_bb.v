
module nios_system (
	clk_clk,
	reset_reset_n,
	seg0_export,
	seg1_export,
	seg2_export,
	seg3_export,
	seg4_export,
	seg5_export,
	seg6_export,
	seg7_export);	

	input		clk_clk;
	input		reset_reset_n;
	output	[6:0]	seg0_export;
	output	[6:0]	seg1_export;
	output	[6:0]	seg2_export;
	output	[6:0]	seg3_export;
	output	[6:0]	seg4_export;
	output	[6:0]	seg5_export;
	output	[6:0]	seg6_export;
	output	[6:0]	seg7_export;
endmodule
