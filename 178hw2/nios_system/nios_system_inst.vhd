	component nios_system is
		port (
			clk_clk       : in  std_logic                    := 'X'; -- clk
			reset_reset_n : in  std_logic                    := 'X'; -- reset_n
			seg0_export   : out std_logic_vector(6 downto 0);        -- export
			seg1_export   : out std_logic_vector(6 downto 0);        -- export
			seg2_export   : out std_logic_vector(6 downto 0);        -- export
			seg3_export   : out std_logic_vector(6 downto 0);        -- export
			seg4_export   : out std_logic_vector(6 downto 0);        -- export
			seg5_export   : out std_logic_vector(6 downto 0);        -- export
			seg6_export   : out std_logic_vector(6 downto 0);        -- export
			seg7_export   : out std_logic_vector(6 downto 0)         -- export
		);
	end component nios_system;

	u0 : component nios_system
		port map (
			clk_clk       => CONNECTED_TO_clk_clk,       --   clk.clk
			reset_reset_n => CONNECTED_TO_reset_reset_n, -- reset.reset_n
			seg0_export   => CONNECTED_TO_seg0_export,   --  seg0.export
			seg1_export   => CONNECTED_TO_seg1_export,   --  seg1.export
			seg2_export   => CONNECTED_TO_seg2_export,   --  seg2.export
			seg3_export   => CONNECTED_TO_seg3_export,   --  seg3.export
			seg4_export   => CONNECTED_TO_seg4_export,   --  seg4.export
			seg5_export   => CONNECTED_TO_seg5_export,   --  seg5.export
			seg6_export   => CONNECTED_TO_seg6_export,   --  seg6.export
			seg7_export   => CONNECTED_TO_seg7_export    --  seg7.export
		);

