	AREA RESET, DATA, READONLY
    EXPORT  __Vectors

__Vectors 
	DCD  0x40001000     ; stack pointer value when stack is empty
    DCD  Reset_Handler  ; reset vector
  
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
		
Reset_Handler
	LDR R0,=V1
	LDR R5,=ANS
	LDR R3,[R0]
	MOV R1,#0
	MOV R2,#0
	MLA R1,R3,R3,R3
	LSR R1,#1
	MOV R2,R1
	STR R2,[R5]
STOP B STOP

V1 DCD 6
	AREA MY_DATA, DATA, READWRITE	

ANS DCD 0

	END