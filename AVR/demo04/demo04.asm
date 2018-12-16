; ******************************************************
; ATMEGA32 Assembly Code Template
; DESD AUG18 @ Sunbeam Infotech
; ******************************************************

.include "C:\VMLAB\include\m32def.inc"

; Define here the variables
;
.DEF  TEMP  =R16
.DEF  LEDV  =R17

.DEF	v1		=R20
.DEF	v2		=R21
.DEF	v3		=R22

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
	; init SP to RAMEND
	LDI TEMP, LOW(RAMEND)
	OUT SPL, TEMP
	LDI TEMP, HIGH(RAMEND)
	OUT SPH, TEMP
	; PUSH 10, 20, 30
	LDI TEMP, 10
	PUSH TEMP
	LDI TEMP, 20
	PUSH TEMP
	LDI TEMP, 30
	PUSH TEMP
		
	; POP 30, 20, 10
	POP R2 ; 30
	POP R1 ; 20
	POP R0 ; 10		
	
	; R0 = SUM(11, 22, 33);
	LDI TEMP, 11
	MOV R0, TEMP
	LDI TEMP, 22
	MOV R1, TEMP
	LDI TEMP, 33
	MOV R2, TEMP
	CALL sum
	MOV TEMP, R0
	
	; LED on/off after 1 sec.
	LDI TEMP, 0xFF
	OUT DDRC, TEMP	; make all ports as output
	
	LDI LEDV, 0x55
repeat:
	OUT PORTC, LEDV
	COM LEDV
	RCALL delay
	RJMP repeat
	
end:
	RJMP end

; sum(R0,R1,R3) -- R0
sum:
	ADD R0, R1
	ADD R0, R2
	RET
	
; delay() -- void
delay:
	LDI v3, 16 ; 1
loop3:
   LDI v2, 250 ; 1
loop2:
	LDI v1, 250 ; 1
loop1:
	NOP			; 1
	DEC v1		; 1
	BRNE loop1	; 2
	DEC v2		; 1
	BRNE loop2	; 2	
	DEC v3		; 1
	BRNE loop3	; 2	

	RET
	
	
default_handler:
	RETI
	
