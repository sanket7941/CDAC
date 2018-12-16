; ******************************************************
; ATMEGA32 Assembly Code Template
; DESD AUG18 @ Sunbeam Infotech
; ******************************************************

.include "C:\VMLAB\include\m32def.inc"


.DSEG
num1:	.BYTE 1
num2:	.BYTE 1
res : .BYTE 1

arr:	.BYTE 5	

.CSEG
; Define here the variables
;
.DEF  TEMP  =R16
.DEF	VAL	=R17
.DEF	CNT	=R18

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
	;num1=10, num2=20, res=num1+num2
	LDI TEMP, 10
	STS num1, TEMP
	LDI TEMP, 20
	STS num2, TEMP

	LDI XL, LOW(num1)	
	LDI XH, HIGH(num1)
	LD R0, X
	
	LDI YL, LOW(num2)	
	LDI YH, HIGH(num2)
	LD R1, Y
	
	ADD R0, R1
	
	LDI ZL, LOW(res)	
	LDI ZH, HIGH(res)
	ST Z, R0
	
	; arr[0] = 10, arr[1] = 20, arr[2] = 30, arr[3] = 40, arr[4] = 50
	LDI TEMP, 10
	LDI VAL, 10
	LDI XL, LOW(arr)
	LDI XH, HIGH(arr)
	CLR CNT
wr:
	CPI CNT, 5
	BRSH wr_end
	
	ST X+, VAL
	ADD VAL, TEMP
	
	INC CNT
	RJMP wr
wr_end:
	
   ; R0 = arr[0] + arr[1] + arr[2] + arr[3] + arr[4]
   CLR R0
	CLR CNT
rd:
	CPI CNT, 5
	BRSH rd_end

	LD R1, -X
	ADD R0, R1
	
	INC CNT
	RJMP rd
rd_end:

end:
	RJMP end

default_handler:
	RETI

