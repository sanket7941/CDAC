GCC_BASE=/opt/setup/gcc-arm-none-eabi-5_4-2016q2
GCC_BIN=$(GCC_BASE)/bin/

CC=$(GCC_BIN)arm-none-eabi-gcc
AS=$(GCC_BIN)arm-none-eabi-as
LD=$(GCC_BIN)arm-none-eabi-ld
NM=$(GCC_BIN)arm-none-eabi-nm
DB=$(GCC_BIN)arm-none-eabi-gdb
OBJCOPY=$(GCC_BIN)arm-none-eabi-objcopy

TARGET=demo02
CPU=arm926ej-s
#STATE=thumb
DBG=warf2
ARCH=armv4

#TEXT=0x00000000
#DATA=0x20000000

EMU=qemu-system-arm
EMUMACH=versatilepb
EMUDBGPORT=1234

#ASFLAGS=-mcpu=$(CPU) -march=$(ARCH) -m$(STATE) -g$(DBG)
ASFLAGS=-mcpu=$(CPU) -march=$(ARCH) -g$(DBG)
#LDFLAGS=-Ttext=$(TEXT) -Tdata=$(DATA)
LDFLAGS=-T arm9.ld

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@ 

$(TARGET).elf: $(TARGET).o
	$(LD) $(LDFLAGS) -o $@ $<

$(TARGET).o: $(TARGET).s
	$(AS) $(ASFLAGS) -o $@ $<

run:
	$(EMU) -machine $(EMUMACH) -m 128M -S -gdb tcp::$(EMUDBGPORT) -nographic -kernel $(TARGET).elf

debug:
	$(DB) $(TARGET).elf -ex "target remote localhost:$(EMUDBGPORT)"

stop:
	pkill qemu-system-arm

clean:
	rm -f $(TARGET).bin $(TARGET).elf $(TARGET).o

version:
	$(CC) -v

.PHONY: clean run debug version


