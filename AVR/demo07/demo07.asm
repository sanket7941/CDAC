; ******************************************************
; ATMEGA32 Assembly Code Template
; DESD AUG18 @ Sunbeam Infotech
; ******************************************************

.include "C:\VMLAB\include\m32def.inc"

.CSEG
; Define here the variables
;
.def  TEMP  =R16
.def  CNT   =R17

.ORG 0x0500
arr1:	.DB 10,20,30,40,50

.ORG 0x0600
arr2:	.DW 11,22,33,44,55


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

	CLR R0
	LDI ZL, LOW(arr1 << 1)
	LDI ZH, HIGH(arr1 << 1)
	CLR CNT
loop1:
	CPI CNT, 5
	BRSH loop1_end

	LPM R1, Z+
	ADD R0, R1
		
	INC CNT
	RJMP loop1
loop1_end:



	CLR R0
	LDI ZL, LOW(arr2 << 1)
	LDI ZH, HIGH(arr2 << 1)
	CLR CNT
loop2:
	CPI CNT, 5
	BRSH loop2_end

	LPM R1, Z+
	ADD R0, R1
	INC ZL
		
	INC CNT
	RJMP loop2
loop2_end:
	
	
end:
	RJMP end

default_handler:
	RETI


