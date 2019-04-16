NAME    mi31_2
EXTRN   GA1:BYTE,OPTION_4:BYTE,OPTION_5:BYTE,OPTION_6_1:BYTE,OPTION_6_2:BYTE,FINAL_RANK:WORD
PUBLIC  CALCULATE,RANK,ALL_INFORMATION
.386
SPACE   MACRO
        MOV     DL,20H 
        MOV     AH,2H 
        INT     21H
        MOV     DL,20H 
        MOV     AH,2H 
        INT     21H
        MOV     DL,20H 
        MOV     AH,2H 
        INT     21H
        MOV     DL,2DH 
        MOV     AH,2H 
        INT     21H
        MOV     DL,2DH 
        MOV     AH,2H 
        INT     21H
        MOV     DL,20H 
        MOV     AH,2H 
        INT     21H
        MOV     DL,20H 
        MOV     AH,2H 
        INT     21H
        ENDM
NEWLINE MACRO
        MOV     DL,0AH
        MOV     AH,2H
        INT     21H
        ENDM
WRITE   MACRO   A
        LEA     DX,OFFSET A
        MOV     AH,9H
        INT     21H
        ENDM

STACK	SEGMENT STACK use16 PARA STACK 'STACK'
	DB	200 DUP(0)
STACK	ENDS
DATA    SEGMENT USE16
N        EQU    5  ;n 代表 有N种商品
TEMP    DW      0
T       DB      0
P       DW      0
DATA    ENDS

CODE    SEGMENT USE16 PARA PUBLIC 'CODE'
ASSUME  CS:CODE,DS:DATA,SS:STACK
;----------------子程序------------------
;功能3：计算推荐度
CALCULATE PROC
    ;保护
    PUSH    AX
    PUSH    BX
    PUSH    CX
    PUSH    DX
    PUSH    SI
    
    MOV     CL,N
    MOV     DX,OFFSET GA1
    SUB     DX,24
    ;计算所有商品的推荐度
    _CHANGEGOODS: 
    ADD     DX,24
    ;转入计算推荐度
    JMP     _CALCULATE
    _CALCULATEBACK:
    DEC     CL
    JNZ     _CHANGEGOODS
    JMP     _RETURN_CALCULATE
    ;计算所有商品推荐度结束
    _CALCULATE:
    MOV     SI,DX 

    MOV     AX,WORD PTR[SI+10] ;折扣
    MOV     BX,WORD PTR[SI+14] ;销售价
    IMUL    AX,BX;AX=销售价*折扣
    CWD
    MOV     BX,10
    IDIV    BX;AX=实际销售价格=AX/10(BX)

    MOV     BX,AX;BX=AX=实际销售价格
    MOV     AX,WORD PTR[SI+12];AX=进货价
    SAL     AX,7
    IDIV    BX;AX=进货价(AX)*128/实际销售价格(BX)
    MOV     TEMP,AX;TEMP=AX=进货价(AX)*128/实际销售价格(BX)

    MOV     AX,WORD PTR[SI+18] ;AX=已售数量
    SAL     AX,7
    CWD
    MOV     BX,WORD PTR[SI+16] ;BX=进货数量
    IDIV    BX;AX=已售数量*128/进货数量

    MOV     BX,TEMP
    ADD     AX,BX;推荐度：AX=AX+TEMP
    MOV     WORD PTR[SI+20],AX
    MOV     DX,SI
    JMP     _CALCULATEBACK
    _RETURN_CALCULATE:
    WRITE   OPTION_4
    NEWLINE
    ;恢复
    POP     SI
    POP     DX
    POP     CX
    POP     BX
    POP     AX
    RET
CALCULATE ENDP
;----------------子程序------------------
;功能4：推荐度排名
RANK PROC
    ;保护
    PUSH    AX;
    PUSH    BX;
    PUSH    CX;
    PUSH    DX;
    PUSH    SI;
    PUSH    DI;
    ;每次开始调用该功能，初始化排名表
    MOV     DI,OFFSET GA1
    MOV     SI,OFFSET FINAL_RANK
    SUB     DI,24
    SUB     SI,2
    MOV     CL,N
    _INIT:
    ADD     DI,24
    ADD     SI,2
    MOV     DX,[DI+20]
    MOV     [SI],DX
    DEC     CL
    JNZ     _INIT
    ;初始化结束，进行排序
    PUSH    SI
    PUSH    DI
    PUSH    AX
    PUSH    BX
    PUSH    CX
    PUSH    DX

    LEA     SI,FINAL_RANK
    XOR     DX,DX
    MOV     BL,N
    MOV     CX,N
    LEA     SI,FINAL_RANK
    MOV     DI,SI
    ADD     DI,2
    MOV     CL,N-1
    MOV     CH,N-1
    _COMPARE:   
    MOV     BX,[DI]
    CMP     BX,[DI-2]
    JA      _CONTINUE
    MOV     DX,[DI-2]
    PUSH    DX
    MOV     [DI-2],BX
    POP     DX
    MOV     [DI],DX
    _CONTINUE:    
    ADD     DI,2
    DEC     CH
    CMP     CH,0
    JNE     _COMPARE
    MOV     DI,SI
    ADD     DI,2
    DEC     CL
    MOV     CH,CL
    CMP     CL,1
    JNE     _COMPARE
    POP     DX
    POP     CX
    POP     BX
    POP     AX
    POP     DI
    POP     SI
    ;排序结束
    ; WRITE   OPTION_5
    ; NEWLINE
    ;开始由排名对应到商品
    MOV     SI,OFFSET FINAL_RANK
    MOV     CX,N
    _LOOP1:
    MOV     BX,N
    MOV     DI,OFFSET GA1
    MOV     AX,[SI]
    _BACK:
    CMP     BX,0
    JE      _LOOP1_1
    CMP     [DI+20],AX
    JNE     _NEXT
    MOV     [DI+22],CX
    JMP     _NEXT
    _LOOP1_1:
    ADD     SI,2
    LOOP    _LOOP1
    ;恢复
    POP     DI
    POP     SI
    POP     DX
    POP     CX
    POP     BX
    POP     AX
    RET
    _NEXT:
    DEC     BX
    ADD     DI,24
    JMP     _BACK
RANK ENDP
;----------------子程序------------------
;功能5：输出所有信息
ALL_INFORMATION PROC
    PUSH    DI
    PUSH    CX

    MOV     CX,N
    MOV     DI,OFFSET GA1
    _LOOP2:
    CALL    SINGLE_INF
    ADD     DI,24
    LOOP    _LOOP2

    POP     CX
    POP     DI
    RET
ALL_INFORMATION ENDP

SINGLE_INF  PROC
    PUSH    DX
    PUSH    AX
    PUSH    BX

    PUSH    DI
    WRITE   OPTION_6_1
    _OUTPUT_NAME:
    CMP     BYTE PTR[DI],0
    JE      _CON
    MOV     DL,BYTE PTR[DI]
    MOV     AH,2H
    INT     21H
    ADD     DI,1
    JMP     _OUTPUT_NAME
    _CON:
    POP     DI
    NEWLINE
    WRITE   OPTION_6_2
    NEWLINE
    MOV     AX,[DI+10];折扣
    MOV     P,AX
    CALL    OUTPUT
    SPACE
    MOV     AX,[DI+12];进货价
    MOV     P,AX
    CALL    OUTPUT
    SPACE
    MOV     AX,[DI+14];销售价
    MOV     P,AX
    CALL    OUTPUT
    SPACE
    MOV     AX,[DI+16];进货总数
    MOV     P,AX
    CALL    OUTPUT
    SPACE
    MOV     AX,[DI+18];已售总数
    MOV     P,AX
    CALL    OUTPUT
    SPACE
    MOV     AX,[DI+20];推荐度
    MOV     P,AX
    CALL    OUTPUT
    SPACE
    MOV     AX,[DI+22];推荐度排名
    MOV     P,AX
    CALL    OUTPUT
    SPACE
    NEWLINE

    POP     BX
    POP     AX
    POP     DX
    RET
SINGLE_INF  ENDP


OUTPUT  PROC
    PUSH    AX
    PUSH    BX
    PUSH    CX
    PUSH    DX

    XOR CX, CX 
    MOV AX, P
    MOV BX, 10
    L2: XOR DX, DX
    DIV BX
    PUSH    DX
    INC CX
    CMP AX, 0
    JNE L2

    L3: POP DX
    ADD DX, 30H
    MOV AH, 2
    INT 21H
    LOOP    L3

    POP DX
    POP CX
    POP BX
    POP AX
    RET
OUTPUT  ENDP

CODE    ENDS
        END