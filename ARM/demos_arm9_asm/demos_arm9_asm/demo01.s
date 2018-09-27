
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
	mov r1, #11		@r1 = 11
	mov r2, #8		@r2 = 8
	
	add r0, r1, r2	@r0 = r1 + r2

	sub r3, r1, r2	@r3 = r1 - r2
	
	sub r3, r2, r1	@r3 = r2 - r1

	subs r4, r2, r1	@r3 = r2 - r1

	movs r5, #0

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

