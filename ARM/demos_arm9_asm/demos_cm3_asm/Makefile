
GCC_BIN=/home/sunbeam/ARM/Toolchain/gcc-arm-none-eabi-5_4-2016q2/bin/

CC=$(GCC_BIN)arm-none-eabi-gcc
AS=$(GCC_BIN)arm-none-eabi-as
LD=$(GCC_BIN)arm-none-eabi-ld
NM=$(GCC_BIN)arm-none-eabi-nm
DB=$(GCC_BIN)arm-none-eabi-gdb
OBJCOPY=$(GCC_BIN)arm-none-eabi-objcopy

TARGET=demo05
CPU=cortex-m3
STATE=thumb
DBG=warf2
ARCH=armv7

EMU=qemu-system-arm
EMUMACH=lm3s6965evb
EMUDBGPORT=1234

ASFLAGS=-mcpu=$(CPU) -march=$(ARCH) -m$(STATE) -g$(DBG)
LDFLAGS=-T./lm3.ld

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

$(TARGET).elf: $(TARGET).o
	$(LD) $(LDFLAGS) -o $@ $<

$(TARGET).o: $(TARGET).s
	$(AS) $(ASFLAGS) -o $@ $<

run:
	$(EMU) -machine $(EMUMACH) -cpu $(CPU) -S -gdb tcp::$(EMUDBGPORT) -nographic -kernel $(TARGET).bin

debug:
	$(DB) $(TARGET).elf -ex "target remote localhost:$(EMUDBGPORT)"

stop:
	pkill qemu-system-arm

clean:
	rm -f $(TARGET).bin $(TARGET).elf $(TARGET).o

version:
	$(CC) -v

.PHONY: clean run debug version
