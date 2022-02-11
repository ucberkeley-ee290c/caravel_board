
# OsciBear-Targeted Control-Processor Firmware 

Image for eFabless's control-processor on the MPW2/ ChipIgnite OsciBear SoC.  
Configures IOs to OsciBear's liking, then spins in a loop blinking an LED. 

To build and flash a USB-connected Caravel board: 

```
make clean flash
```

Note all instructions provided in the [repo-level docs](../../README.md) apply here. 

Environment options:

* `TOOLCHAIN_PREFIX` sets the prefix to executables such as `riscv64-unknown-elf-gcc`. This will generally either be `riscv32` (the default) or `riscv64` for "combo" installations.
* `TOOLCHAIN_PATH` sets the path to the toolchain. The default empty value requires `riscvXX-*` be on the path.

