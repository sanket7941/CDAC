.text
.arm
.balign 4

.global _reset
_reset:
	b reset_handler
	b undef_handler
	b swi_handler
	b pabt_handler
	b dabt_handler
	nop
	b irq_handler
	b fiq_handler

main:
	
	mov pc, lr
	
	
reset_handler:
	ldr sp, =stack_top
	bl main
	end:	b end
	
undef_handler:
	b undef_handler
	
swi_handler:
	b swi_handler
	
pabt_handler:
	b pabt_handler

dabt_handler:
	b dabt_handler

irq_handler:
	b irq_handler

fiq_handler:
	b fiq_handler

