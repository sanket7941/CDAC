MEMORY
{
	FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 0x00010000
	SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00002000
}
SECTIONS 
{
	.text : {
		* (.vectors);
		* (.text);
		etext = .;
	} > FLASH

	.data : {
		sdata = .;
		* (.data);
		edata = .;
	} > SRAM AT> FLASH

	.bss : {
		sbss = .;
		* (.bss);
		ebss = .;
	} > SRAM

	.rodata : {
		* (.rodata);
	} > FLASH
}

