//#include "../defs.h"
#include "../defs_mpw-two-mfix.h"

// --------------------------------------------------------
// Firmware routines
// --------------------------------------------------------

void main() {
  int i, j;
  i = 1;

  // Configure just one of our "user" IOs
  reg_mprj_io_0 = GPIO_MODE_MGMT_STD_OUTPUT;

  // FIXME: Not totally clear what these two do.
  reg_mprj_datal = 0;
  reg_mprj_datah = 0;

  // Set the `xfer` register to transfer configuration,
  // then sit and spin until it completes.
  reg_mprj_xfer = 1;
  while (reg_mprj_xfer == 1)
    ;

  // Enable GPIO (all output, ena = 0)
  reg_gpio_ena = 0x0;
  reg_gpio_pu = 0x0;
  reg_gpio_pd = 0x0;
  reg_gpio_data = 0x1;

  while (1) {
    reg_gpio_data = 0x0;
    //        reg_mprj_datal = 0x00000000;
    //        reg_mprj_datah = 0x00000000;
    for (j = 0; j < 25000; j++)
      ;

    reg_gpio_data = 0x1;
    //        reg_mprj_datal = 0xffff0000;
    //        reg_mprj_datal = 0xffffff00;
    //        reg_mprj_datah = 0xffffffff;
    for (j = 0; j < 25000; j++)
      ;
  }
}
