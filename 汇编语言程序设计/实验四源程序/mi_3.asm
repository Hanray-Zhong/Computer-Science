.386
PRINT MACRO A
    MOV DL,A
    MOV AH,2
    INT 21H
ENDM

STACK SEGMENT USE16 STACK
    DB 200 DUP(0)
STACK ENDS

CODE SEGMENT USE16
ASSUME SS:STACK,CS:CODE
START:
LOOP1: 
    MOV AH, 1
    INT 21H
    CMP AL,'q'
    JE QUIT
    SUB AL,30H
    OUT 70H,AL
    IN AL,71H
    MOV AH,AL
    AND AL,0FH
    SHR AH,4
    ADD AX,3030H
    MOV BX,AX
    PRINT 0AH
    PRINT 0DH
    PRINT BH
    PRINT BL
    PRINT 0AH
    PRINT 0DH
    JMP LOOP1
QUIT: 
    MOV AH,4CH
    INT 21H
CODE ENDS
END START