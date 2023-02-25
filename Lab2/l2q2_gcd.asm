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
	LDR R3,[R0]
	LDR R4,[R1]
LOOP
	CMP R3,R4
	SUBGT R3,R3,R4
	SUBLE R4,R4,R3
	CMP R3,R4
	BNE LOOP
	STR R3,[R2]
	
	
STOP B STOP

V1 DCD 178
V2 DCD 1246
	AREA MY_DATA, DATA, READWRITE	

ANS DCD 0

	END