.386
;变址寻址
XUEHAO 	SEGMENT USE16
		DB 3 DUP(0)
BUF1	DB 6, 0, 7
XUEHAO 	ENDS

CODE 	SEGMENT USE16
		ASSUME CS:CODE, DS:XUEHAO
START:	MOV 	AX, XUEHAO
		MOV 	DS, AX
		MOV 	SI, 0
		MOV 	CX, 3
LOOPA:	MOV 	AL, BUF1[SI]
		MOV 	[SI], AL
		INC 	SI
		DEC		CX
		JNZ		LOOPA
		MOV 	AH, 4CH
		INT 	21H
CODE 	ENDS
		END 	START