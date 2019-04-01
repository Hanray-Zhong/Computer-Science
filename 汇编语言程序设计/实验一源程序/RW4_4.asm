.386
;直接寻址
XUEHAO 	SEGMENT USE16
	DB 3 DUP(0)
BUF	DB  6,0,7
XUEHAO 	ENDS

CODE 	SEGMENT USE16
	ASSUME 	DS:XUEHAO
START:	MOV 	AX, XUEHAO
        MOV 	DS, AX
        MOV	AL, BUF + 0
        MOV 	DS:[0H], AL
        MOV 	AL, BUF + 1
        MOV 	DS:[1H], AL
        MOV	AL, BUF + 2
        MOV	DS:[2H], AL
        MOV 	AH, 4CH
        INT 	21H
CODE 	ENDS
        END 	START