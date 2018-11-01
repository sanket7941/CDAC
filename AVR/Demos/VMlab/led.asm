; ******************************************************
; BASIC .ASM template file for AVR
; ******************************************************

.include "C:\VMLAB\include\m32def.inc"

; Define here the variables
;
.def  temp  =r16

; Define here Reset and interrupt vectors, if any
;
reset:
   rjmp start
   reti      ; Addr $01
   reti      ; Addr $02
   reti      ; Addr $03
   reti      ; Addr $04
   reti      ; Addr $05
   reti      ; Addr $06        Use 'rjmp myVector'
   reti      ; Addr $07        to define a interrupt vector
   reti      ; Addr $08
   reti      ; Addr $09
   reti      ; Addr $0A
   reti      ; Addr $0B        This is just an example
   reti      ; Addr $0C        Not all MCUs have the same
   reti      ; Addr $0D        number of interrupt vectors
   reti      ; Addr $0E
   reti      ; Addr $0F
   reti      ; Addr $10

; Program starts here after Reset
;
start:

LDI R16, 0XFF
CLR R1
COM R1
OUT DDRB,R1


CLR R0
mov R16,R0
OUT PORTB , R16
end:
   nop       ; Initialize here ports, stack pointer,
   nop       ; cleanup RAM, etc.
   nop       ;
   nop       ;

forever:
   nop
   nop       ; Infinite loop.
   nop       ; Define your main system
   nop       ; behaviour here
rjmp forever

