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
	LDR R1,[R0]
	MOV R2,#1
FACT 
	CMP R1,#1
	BEQ EXIT
	PUSH {R1,LR}
	SUB R1,#1
	BL FACT
EXIT
	POP {R1,LR}
	MUL R2,R1
	BX LR
	
	

	
STOP B STOP

V1 DCD 4

	AREA MY_DATA, DATA, READWRITE	

ANS DCD 0

	END