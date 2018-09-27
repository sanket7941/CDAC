@ collatz conjure

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

	mov r0, #5

loop_start:

	@ r0 == 1
	subs r2, r0, #1
	beq loop_end

	mov r1, r0

	@ r1 & 1 -- 0 is even | 1 is odd
	ands r2, r1, #1

	@ r0 = 3*r1 + 1 (odd)
	addne r0, r1, r1, lsl #1
	addne r0, r0, #1
	
	@ r0 = r1 / 2 (even)
	moveq r0, r1, lsr #1		

	b loop_start

loop_end:
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

