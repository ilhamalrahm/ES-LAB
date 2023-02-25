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
	LDR R1,=V2
	LDR R2,=ANS
	LDR R3,[R0];HAS VALUE OF V1
	LDR R4,[R1];HAS VALUE OF V2
	MOV R5,#0;TO STORE V1%V2
	MOV R6,#0;i variable
	MOV R7,#0;STORE i*v1
	MOV R8,#0; STORE REMAINDER
	MOV R9,#0; STORE FINAL RETURN VALUE
LOOP
	ADD R6,#1
	MUL R7,R6,R3
	MOV R9,R7
MODULUS
	CMP R7,R4
	SUBGE R7,R7,R4
	CMP R7,R4
	BGE MODULUS
	MOV R8,R7
	CMP R8,#0
	BNE LOOP
	STR R9,[R2]
	
	
	
STOP B STOP

V1 DCD 10
V2 DCD 6
	AREA MY_DATA, DATA, READWRITE	

ANS DCD 0

	END