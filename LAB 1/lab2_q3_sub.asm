    AREA RESET, DATA, READONLY
    EXPORT __Vectors
    
__Vectors
    DCD    0X10000100
    DCD Reset_Handler
    ALIGN
    AREA MY_CODE, CODE, READONLY
    ENTRY
    EXPORT Reset_Handler
Reset_Handler
    LDR R9,=SUB+4
    ldr r11,=CARRY
    LDR R0,=n1+4
    LDR R1,=n2+4
    MOV R2,#2
    ;ldr r10,=0x20000000
    ;msr xpsr,r10
    ldr r10,=0x20000000
    msr xpsr,r10

BACK
    
    LDR R3,[R0],#-4
    LDR R4,[R1],#-4
    ;SUBS R5,R3,R4
    ;sbc R7,#0
    sbcs r5,r3,r4
    ;subs r5,r7
    STR R5,[R9],#-4
    SUB R2,#1
    TEQ R2,#0
    BNE BACK
    ;sbc R7,#0
    ;ldr r6,[r9,#4]
    ;mov r12,#0
    ;sbc r12,r6,#0
    ;str r12,[r9,#4]
    
    
STOP B STOP
    
n2 DCD 0x11223344,0x12345678
n1 DCD 0X67676788,0XABCDEF11
    AREA MY_DATA, DATA, READWRITE


SUB DCD 0,0
CARRY DCD 0
    END
