
#GCC_BASE=/opt/gcc-arm-none-eabi-5_4-2016q2/
#GCC_BIN=$(GCC_BASE)/bin/
GCC_BIN=

CC=$(GCC_BIN)arm-none-eabi-gcc
AS=$(GCC_BIN)arm-none-eabi-as
LD=$(GCC_BIN)arm-none-eabi-ld
NM=$(GCC_BIN)arm-none-eabi-nm
DB=$(GCC_BIN)arm-none-eabi-gdb
OBJCOPY=$(GCC_BIN)arm-none-eabi-objcopy

TARGET=demo12
CPU=cortex-m3
STATE=thumb
DBG=warf2
ARCH=armv7

TEXT=0x00000000
DATA=0x20000000

EMU=qemu-system-arm
EMUMACH=lm3s811evb
EMUDBGPORT=1234

ASFLAGS=-mcpu=$(CPU) -m$(STATE) -g$(DBG)
CCFLAGS=-mcpu=$(CPU) -m$(STATE) -g2 -gdwarf
#LDFLAGS=-Ttext=$(TEXT) -Tdata=$(DATA)
LDFLAGS=-T lm3.ld

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@ 

$(TARGET).elf: startup.o $(TARGET).o
	$(LD) $(LDFLAGS) -o $@ $^

$(TARGET).o: $(TARGET).s
	$(AS) $(ASFLAGS) -o $@ $<

startup.o: startup.c
	$(CC) $(CCFLAGS) -c -o $@ $<

run:
	$(EMU) -machine $(EMUMACH) -cpu $(CPU) -S -gdb tcp::$(EMUDBGPORT) -nographic -kernel $(TARGET).elf

debug:
	$(DB) $(TARGET).elf -ex "target remote localhost:$(EMUDBGPORT)"

stop:
	pkill qemu-system-arm

clean:
	rm -f $(TARGET).bin $(TARGET).elf $(TARGET).o startup.o

version:
	$(CC) -v

.PHONY: clean run debug version


