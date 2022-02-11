//#include "../defs.h"
#include "../defs_mpw-two-mfix.h"

void sit_and_blink();
void setup_ios();

// --------------------------------------------------------
// # Main Entry Point
//
// * Set up IOs to OsciBear's liking, and
// * Sit, spin, and blink an LED
// --------------------------------------------------------
void main()
{
	setup_ios();
	sit_and_blink();
}

// --------------------------------------------------------
// # IO Setup
//
// The overwhelming majority of the work performed by the control processor.
// Largely derived from
// https://github.com/ucberkeley-ee290c/OsciBear/blob/dd116b95357baff68f42357d2454ad6beabc51db/verilog/rtl/user_analog_project_wrapper.v#L172
// IOs are configured as inputs coming out of reset. Only outputs and bi-directional signals must be configured.
// --------------------------------------------------------
void setup_ios()
{
	reg_mprj_io_0 = GPIO_MODE_MGMT_STD_OUTPUT;		   // .serial_tl_clock(io_out[0]),
	reg_mprj_io_1 = GPIO_MODE_MGMT_STD_OUTPUT;		   // .serial_tl_bits_in_ready(io_out[1]),
													   // .serial_tl_bits_in_valid(io_in[2]),
													   // .serial_tl_bits_in_bits(io_in[3]),
													   // .serial_tl_bits_out_ready(io_in[4]),
	reg_mprj_io_5 = GPIO_MODE_MGMT_STD_OUTPUT;		   // .serial_tl_bits_out_valid(io_out[5]),
	reg_mprj_io_6 = GPIO_MODE_MGMT_STD_OUTPUT;		   // .serial_tl_bits_out_bits(io_out[6]),
	reg_mprj_io_7 = GPIO_MODE_USER_STD_BIDIRECTIONAL;  // .gpio_0_0_i(io_in[7]),
													   // .gpio_0_0_o(io_out[7]),
													   // .gpio_0_0_oe(io_oeb[7]),
	reg_mprj_io_8 = GPIO_MODE_USER_STD_BIDIRECTIONAL;  // .gpio_0_1_i(io_in[8]),
													   // .gpio_0_1_o(io_out[8]),
													   // .gpio_0_1_oe(io_oeb[8]),
	reg_mprj_io_9 = GPIO_MODE_USER_STD_BIDIRECTIONAL;  // .gpio_0_2_i(io_in[9]),
													   // .gpio_0_2_o(io_out[9]),
													   // .gpio_0_2_oe(io_oeb[9]),
													   // .reset(io_in[10]),
													   // .clock(io_in[11]),
	reg_mprj_io_14 = GPIO_MODE_MGMT_STD_OUTPUT;		   // .spi_0_sck(io_out[14]),
	reg_mprj_io_15 = GPIO_MODE_MGMT_STD_OUTPUT;		   // .spi_0_cs_0(io_out[15]),
	reg_mprj_io_16 = GPIO_MODE_USER_STD_BIDIRECTIONAL; // .spi_0_dq_0_i(io_in[16]),
													   // .spi_0_dq_0_o(io_out[16]),
													   // .spi_0_dq_0_oe(io_oeb[16]),
	reg_mprj_io_17 = GPIO_MODE_USER_STD_BIDIRECTIONAL; // .spi_0_dq_1_i(io_in[17]),
													   // .spi_0_dq_1_o(io_out[17]),
													   // .spi_0_dq_1_oe(io_oeb[17]),
	reg_mprj_io_18 = GPIO_MODE_USER_STD_BIDIRECTIONAL; // .spi_0_dq_2_i(io_in[18]),
													   // .spi_0_dq_2_o(io_out[18]),
													   // .spi_0_dq_2_oe(io_oeb[18]),
	reg_mprj_io_19 = GPIO_MODE_USER_STD_BIDIRECTIONAL; // .spi_0_dq_3_i(io_in[19]),
													   // .spi_0_dq_3_o(io_out[19]),
													   // .spi_0_dq_3_oe(io_oeb[19]),
													   // .bsel(io_in[20]),
													   // .jtag_TCK(io_in[21]),
													   // .jtag_TMS(io_in[22]),
													   // .jtag_TDI(io_in[23]),
	reg_mprj_io_24 = GPIO_MODE_MGMT_STD_OUTPUT;		   // .jtag_TDO_data(io_out[24]),
	reg_mprj_io_25 = GPIO_MODE_MGMT_STD_OUTPUT;		   // .uart_0_txd(io_out[25]),
													   // .uart_0_rxd(io_in[26]),
}

// --------------------------------------------------------
// # Sit and Blink
//
// Blink the board-level LED, let the people know we're alive. 
// --------------------------------------------------------
void sit_and_blink()
{
	// Parameters for the blinking
	int LO_TIME = 10 * 1000;
	int HI_TIME = 10 * 1000;

	// Enable GPIO (all output, ena = 0)
	reg_gpio_ena = 0x0;
	reg_gpio_pu = 0x0;
	reg_gpio_pd = 0x0;
	reg_gpio_data = 0x1;

	while (1)
	{
		reg_gpio_data = 0x0;
		for (int j = 0; j < LO_TIME; j++)
			; // Do nothing

		reg_gpio_data = 0x1;
		for (int j = 0; j < HI_TIME; j++)
			; // Do nothing
	}
}
