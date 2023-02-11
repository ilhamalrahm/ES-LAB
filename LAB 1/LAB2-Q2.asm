	AREA RESET, DATA, READONLY
	EXPORT __Vectors
	
__Vectors
	DCD	0X10000100
	DCD Reset_Handler
	ALIGN
	AREA MY_CODE, CODE, READONLY				
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R9,=SUM
	LDR R0,=n1
	LDR R1,=n2
	MOV R2,#4

BACK
	LDR R3,[R0],#4
	LDR R4,[R1],#4
	ADCS R5,R3,R4
	STR R5,[R9],#4
	SUB R2,#1
	TEQ R2,#0
	BNE BACK
	ADC R5,#0
	STR R5,[R9]
	
	
STOP B STOP
	
n1 DCD 0x11223344,0x12345678,0xFFFF5533,0x189ACD22
n2 DCD 0X67676788,0XABCDEF11,0X449AEF11,0XFFABCD33
	AREA MY_DATA, DATA, READWRITE	


SUM DCD 0,0,0,0
CARRY DCD 0
	END
