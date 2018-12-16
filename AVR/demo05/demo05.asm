; ******************************************************
; ATMEGA32 Assembly Code Template
; DESD AUG18 @ Sunbeam Infotech
; ******************************************************

.include "C:\VMLAB\include\m32def.inc"

; Define here the variables
;
.def  TEMP  =r16

; Define here Reset and interrupt vectors, if any
;
.ORG 0000
	JMP main					;0
	JMP default_handler	;1
	JMP default_handler  ;2
	JMP default_handler  ;3
	JMP default_handler  ;4
	JMP default_handler  ;5
	JMP default_handler  ;6
	JMP timer1_oc1a_isr  ;7
	JMP default_handler  ;8
	JMP default_handler  ;9
	JMP default_handler  ;10
	JMP default_handler  ;11
	JMP default_handler  ;12
	JMP default_handler  ;13
	JMP default_handler  ;14
	JMP default_handler  ;15
	JMP default_handler  ;16
	JMP default_handler  ;17
	JMP default_handler  ;18
	JMP default_handler  ;19
	JMP default_handler  ;20
	
; Program starts here after Reset
main:
	; setup stack pointer
	LDI TEMP, LOW(RAMEND)
	OUT SPL, TEMP
	LDI TEMP, HIGH(RAMEND)
	OUT SPH, TEMP
	
	;timer1_init();
	RCALL timer1_init
	
	;DDRD |= BV(5);	//PD.5 as output
	SBI DDRD, 5
	;PORTD &= ~BV(5); //PD.5 = 0
	CBI PORTD, 5
		
	;while(1);
end:
	RJMP end

; Timer1 Init function -- timer1_init() -- periodic interrupt
timer1_init:
	;OCR1A = 3906-1; -- delay of 1 sec
	LDI TEMP, LOW(3905)
	OUT OCR1AL, TEMP
	LDI TEMP, HIGH(3905)
	OUT OCR1AH, TEMP
	
	;TIMSK = BV(OCIE1A); -- enable OCF1A intr
	LDI TEMP, (1 << OCIE1A)
	OUT TIMSK, TEMP
		
	;TCCR1A = BV(COM1A0); -- toggle on compare
	LDI TEMP, (1 << COM1A0)
	OUT TCCR1A, TEMP
	
	;sei(); -- enable global intr
	SEI
		
	;TCCR1B = BV(WGM12) | BV(CS12) | BV(CS10); --ctc & prescalar=1024
	LDI TEMP, ((1 << 3) | (1 << CS12) | (1 << CS10))
	OUT TCCR1B, TEMP
	
	;return
	RET
	
	
; Timer1 OC1A match interrupt ISR
;ISR -- Timer1 OCF1A -- IVT slot = 7
timer1_oc1a_isr:
	;return;
	RETI

default_handler:
	RETI
