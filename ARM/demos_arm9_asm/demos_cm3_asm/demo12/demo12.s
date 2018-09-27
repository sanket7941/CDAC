/*
  *************************************************************************
**  Target      : Cortex-M3
**  Environment : GNU Tools
 *************************************************************************
*/
.syntax unified
.thumb

.text

.global main
.type main, %function
main:                              
	stmfd sp!, {lr}
	stmfd sp!, {r4-r11}

	mov r0, #5
	bl fact
	mov r1, r0		@ result

	ldmfd sp!, {r4-r11}
	ldmfd sp!, {lr}
	mov pc, lr
stop:   b stop

.global fact
.type fact, %function
fact:
	cmp r0, #0
	itt eq
	moveq r0, #1
	moveq pc, lr

	stmfd sp!, {lr}
	stmfd sp!, {r4-r11}

	mov r4, r0		@ save n
	sub r0, r0, #1	@ calc n-1 for arg
	bl fact			@ call fact(n-1)
	mul r5, r4, r0	@ r5 = n * res of fact(n-1)
	mov r0, r5		@ get res in r0 for return

	ldmfd sp!, {r4-r11}
	ldmfd sp!, {lr}

	mov pc, lr




