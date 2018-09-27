
char stack[1024];

extern char sdata;
extern char edata;
extern char etext;
extern char sbss;
extern char ebss;
static char *bssp = (char *)0xDEADBEEF;

void start()
{
	char *from, *to;
	/* Initialize .data */
	from = &etext;
	to = &sdata;
	while (to != &edata) {
		*to++ = *from++;
	}
	/* Clear .bss */
	bssp = &sbss;
	while (bssp != &ebss) {
		*bssp++ = 0;
	}
	main();
	while (1);
}

__attribute__ ((section(".vectors")))
void *vectors[] = {
	stack + sizeof(stack),	// initial msp
	start,		// reset handler
};

