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
	; R16=23, R17=5, R0 = R16+R17
	LDI R16, 23
	LDI R17, 5
	MOV R0, R16
	ADD R0, R17
		
	; R16=35, R17=35, R0 = R16-R17
	LDI R16, 35
	LDI R17, 35
	MOV R0, R16
	SUB R0, R17

   ; [0x0060] = 15, [0x0061] = 4, [0x0062]= 15+4
   LDI R16, 15
   STS 0x0060, R16
   LDI R16, 4
   STS 0x0061, R16

	LDS R4, 0x0060
	LDS R5, 0x0061
	ADD R4, R5
	
	STS 0x0062, R4
	
	; R4=19, R5=4, [R1:R0] = R4 * R5
	MUL R4, R5
	STS 0x0063, R0	
	
end:
	RJMP end

default_handler:
	RETI
