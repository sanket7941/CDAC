; ******************************************************
; ATMEGA32 Assembly Code Template
; DESD AUG18 @ Sunbeam Infotech
; ******************************************************

.include "C:\VMLAB\include\m32def.inc"

; Define here the variables
;
.def  temp  =r16

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
	JMP default_handler  ;7
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
	; Make PORTC as OUTPUT -- DDRC=0xFF
	;LDI R16, 0xFF		; R16=0xFF
;	CLR R1				; R1=0x00
;	COM R1				; R1=~R1 (0xFF)
;	STS 0x0034, R1		; DDRC=R1	
	
	; Glow LEDs -- PORTC=0x00
;	CLR R0				; R0=0x00
;	STS 0x0035, R0		; PORTC=R0


	; Make PORTB as OUTPUT -- DDRB=0xFF
	;LDI R16, 0xFF		; R16=0xFF
	CLR R1				; R1=0x00
	COM R1				; R1=~R1 (0xFF)
	OUT DDRB, R1		; DDRB=R1	
	
	; Glow LEDs -- PORTB=0x00
	CLR R0				; R0=0x00
	OUT PORTB, R0		; PORTB=R0
		
end:
	RJMP end

default_handler:
	RETI
