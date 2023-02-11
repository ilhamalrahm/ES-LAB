
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

	LDR R0,=arr
	LDR R2,=SUM
	MOV R3,#5
	LDR R4,=CARRY
	MOV R6,#0

BACK
	LDR R5,[R0],#4
	ADDS R6,R5
	ADCS R7,#0
	SUBS R3,#1
	BNE BACK
	
	STR R6,[R2],#4
	STR R7,[R2]
	;STR R7,[R4]
	
STOP B STOP
	
arr DCD 0xFF000000,0x00000001,0x34000002,0x00DD0003,0x00AA0004,0x00000005,0x00000006,0x00000007,0x00000008,0x00000010
	AREA MY_DATA, DATA, READWRITE	


SUM DCD 0
CARRY DCD 0
	END


