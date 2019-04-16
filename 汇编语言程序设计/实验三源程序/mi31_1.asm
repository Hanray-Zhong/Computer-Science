NAME    mi31_1
EXTRN   CALCULATE:NEAR,ALL_INFORMATION:NEAR,RANK:NEAR
PUBLIC  GA1,OPTION_4,OPTION_5,OPTION_6_1,OPTION_6_2,FINAL_RANK

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
DATA    SEGMENT USE16 PARA PUBLIC 'DATA'
BNAME    DB     'LI BO',5 DUP(0)   ;老板姓名
BPASS    DB     '123456',4 DUP(0)   ;密码
SNAME    DB     0DH, 0AH,'       SHOUP_NAME$',0    ;网店名称
N        EQU    5  ;n 代表 有N种商品
in_name  DB     10
         DB     ?
         DB     10 DUP(0)
in_pwd   DB     10
         DB     ?
         DB     10 DUP(0)
in_choise DB    2
         DB     ?
         DB     2 DUP(0)                 
in_good  DB     10
         DB     ?
         DB     10 DUP(0)
GA1     DB      'PEN',7 DUP(0)
        DW      10,35,56,700,300,?,?
        DB      'BOOK',6 DUP(0)
        DW      9,12,30,2500,1000,?,?
        DB      N-3 DUP('Temp-Value',8,0,15,0,20,0,30,0,2,0,?,?,?,?)
        DB      'BAG',7 DUP(0)
        DW      6,16,80,1000,20,?  ;m 代表 有1000-20件商品
BUF1    DB      0DH, 0AH,'please input the boss name:$',0
BUF2    DB      0DH, 0AH,'please input the password:$',0
BUF3    DB      0DH, 0AH,'name or password is wrong,go back to main menu!$',0
BUF4    DB      0DH, 0AH,'please input the information again!',0DH,0AH,'$'
BUF5    DB      0DH, 0AH,'please input the goods name:$'
BUF6    DB      0DH, 0AH,'do not find the goods!please input the goods name again!',0DH,0AH,'$'
IMF1    DB      0DH, 0AH,'1=Query product, 2=Modify product, 3=Calculate recommendation,$'
IMF2    DB      0DH, 0AH,'4=Calculate recommendation rank , 5=Output all commodity, 6=Program exits .$'
IMF3    DB      0DH, 0AH,'1=Query product information , 6=Program exits .$'
IMF4    DB      0DH, 0AH,'option input wrong, please try again!$'
BUF2_1  DB      0DH, 0AH,'Discount >>$'
BUF2_2  DB      0DH, 0AH,'InPrice >>$'
BUF2_3  DB      0DH, 0AH,'OutPrice >>$'
BUF2_4  DB      0DH, 0AH,'InCount >>$'
BUF2_5  DB      0DH, 0AH,'OutCount >>$'
OPTION_4        DB 'Calulate Successful!$'
OPTION_5        DB 'Sort Successful!$'
OPTION_6_1      DB 'Name: $'
OPTION_6_2      DB 'Discount--InPrice--OutPrice--InCount--OutCount--TJD--RACK$'
CRLF    DB      0DH, 0AH, '$'
AUTH    DB      0
TEMP    DW      0
X       DW      0
P       DW      0
FINAL_RANK DW 5 DUP(0)
;储存推荐度
DATA    ENDS

CODE    SEGMENT USE16
ASSUME  CS: CODE,DS: DATA,SS:STACK

START:
FUNCTION1_1:
        MOV     AX, DATA    ;输出网店名称
        MOV     DS, AX
        LEA     DX, SNAME
        MOV     AH, 9
        INT     21H

FUNCTION1_2:
        LEA     DX, BUF1    ;提示输入姓名
        MOV     AH, 9
        INT     21H
        LEA     DX, in_name ;将姓名存入存储区
        MOV     AH, 10
        INT     21H

        LEA     DX, BUF2    ;提示输入密码
        MOV     AH, 9
        INT     21H
        LEA     DX, in_pwd  ;将密码存入存储区
        MOV     AH, 10
        INT     21H

FUNCTION1_3:
        MOV     SI, OFFSET  in_name+2
        MOV     AL, [SI]
        MOV     CL, 0DH
        SUB     CL, AL
        JZ      AUTH0

        MOV     CL, 71H
        SUB     CL, AL
        JZ      FINALL
        JNZ     FUNCTION2_1

AUTH0:
        MOV     AUTH, 0
        JZ      FUNCTION3_1

FUNCTION2_1:
        MOV     CL, 0AH
        MOV     DI, OFFSET BNAME
        MOV     SI, OFFSET in_name+2
    LOPA1: ;比较姓名循环
        MOV     AL, BNAME[DI]  
        MOV     DL, in_name+2[DI] 
        INC     DI
        MOV     AH, AL
        SUB     AH, 0
        JZ      NAMERIGHT
        SUB     AL, DL
        JNZ     FUNCTION2_3
        DEC     CL
        JNZ     LOPA1

NAMERIGHT:
        MOV     AH, DL
        SUB     AH, 0DH
        JZ      FUNCTION2_2
        JNZ     FUNCTION2_3

FUNCTION2_2:
        MOV     CL, 0AH
        MOV     DI, OFFSET BNAME
        MOV     SI, OFFSET in_pwd+2
    LOPA2: ;比较密码循环
        MOV     AL, BPASS[DI]
        MOV     DL, in_pwd+2[DI]
        INC     DI
        MOV     AH, AL
        SUB     AH, 0
        JZ      PASSRIGHT
        SUB     AL, DL
        JNZ     FUNCTION2_3
        DEC     CL
        JNZ     LOPA2

FUNCTION2_4:
        JZ     AUTH1

PASSRIGHT:
        MOV     AH, DL
        SUB     AH, 0DH
        JZ      FUNCTION2_4
        JNZ     FUNCTION2_3

FUNCTION2_3:
        LEA     DX, BUF3    ;提示输入信息错误
        MOV     AH, 9
        INT     21H
        LEA     DX, BUF4    ;提示重新输入信息
        MOV     AH, 9
        INT     21H
        JMP      FUNCTION1_1

AUTH1:
        MOV     AUTH, 1
        JNZ     FUNCTION3_1

FUNCTION3_1:
        MOV     AL, 1
        CMP     AL, AUTH
        JNZ      CHOOSE0
        LEA     DX, IMF1    ;菜单
        MOV     AH, 9
        INT     21H
        LEA     DX, IMF2    ;菜单
        MOV     AH, 9
        INT     21H
        JMP     CONTINUE
    CHOOSE0:
        LEA     DX, IMF3    ;菜单
        MOV     AH, 9
        INT     21H
    CONTINUE:
        LEA     DX, CRLF
        MOV     AH, 9
        INT     21H
        LEA     DX, in_choise
        MOV     AH, 10
        INT     21H
        MOV     SI, OFFSET in_choise
        MOV     AL, 2[SI]
        MOV     AH, 1
        CMP     AH, AUTH
        JNZ     INP0

        MOV     AH, 32H
        CMP     AL, AH
        JZ      OPTION2
        INC     AH
        CMP     AL, AH
        JZ      OPTION3
        INC     AH
        CMP     AL, AH
        JZ      OPTION4
        INC     AH
        CMP     AL, AH
        JZ      OPTION5
    INP0:
        MOV     AH, 31H
        CMP     AL, AH
        JZ      OPTION1
        MOV     AH, 36H
        CMP     AL, AH
        JZ      FINALL
        JNZ     OPTION6

    OPTION1:
        CALL    Query
        JMP     FUNCTION3_1
    OPTION2:
        CALL    Modify
        JMP     FUNCTION3_1
    OPTION3:
        CALL    CALCULATE
        JMP     FUNCTION3_1
    OPTION4:
        CALL    RANK
        JMP     FUNCTION3_1
    OPTION5:
        CALL    ALL_INFORMATION
        JMP     FUNCTION3_1
    OPTION6:
        LEA     DX, IMF4   ;错误提示
        MOV     AH, 9
        INT     21H
        JMP     FUNCTION3_1

FINALL:
        MOV     AH, 4CH
        INT     21H

;----------------子程序------------------
;功能1：查询商品信息
Query PROC
    ;保护
        PUSH    AX
        PUSH    BX
        PUSH    CX
        PUSH    DX
        PUSH    SI
    _IN1:
        LEA     DX, BUF5    ;提示输入商品信息
        MOV     AH, 9
        INT     21H
        LEA     DX, in_good ;将商品名存入存储区
        MOV     AH, 10
        INT     21H

        MOV     SI, OFFSET  in_good+2
        MOV     AL, [SI]
        MOV     CL, 0DH
        SUB     CL, AL
        JZ      _OUT1

        MOV     SI, N
        MOV     BX, 0
    _LOPA1: ;查找商品循环
        MOV     CL, 0AH
        MOV     DI, 0
    _LOPA1_1:
        MOV     AL, GA1[BX][DI]
        MOV     DL, in_good+2[DI]
        INC     DI
        MOV     DH, AL
        SUB     DH, 0
        JZ      _GOODRIGHT1
        CMP     AL, DL
        JNZ     _LPOA1_2
        DEC     CL
        JNZ     _LOPA1_1
        JZ      _PRINT1
    _LPOA1_2:
        ADD     BX, 18H ;数据结构变则变
        DEC     SI
        JNZ     _LOPA1
    _LPOA1_3:
        LEA     DX, BUF6    ;提示重新输入商品信息
        MOV     AH, 9
        INT     21H
        JMP     _IN1

    _GOODRIGHT1:
        MOV     DH, DL
        SUB     DH, 0DH
        JZ      _PRINT1
        JNZ     _LPOA1_2

    _PRINT1:
        LEA     DX, CRLF
        MOV     AH, 9
        INT     21H
        MOV     DI, OFFSET GA1
        ADD     DI, BX
        MOV     AX, [DI+10];折扣
        MOV     P , AX
        CALL    OUTPUT
        SPACE
        MOV     AX, [DI+12];进货价
        MOV     P,AX
        CALL    OUTPUT
        SPACE
        MOV     AX, [DI+14];销售价
        MOV     P,AX
        CALL    OUTPUT
        SPACE
        MOV     AX, [DI+16];进货总数
        MOV     P,AX
        CALL    OUTPUT
        SPACE
        MOV     AX, [DI+18];已售总数
        MOV     P,AX
        CALL    OUTPUT
        SPACE
        MOV     AX, [DI+20];推荐度
        MOV     P,AX
        CALL    OUTPUT
    _OUT1:
        ;恢复
        POP     SI
        POP     DX
        POP     CX
        POP     BX
        POP     AX
        RET
Query ENDP
;----------------子程序------------------
;功能2：修改商品信息
Modify   PROC
        ;保护
        PUSH    AX
        PUSH    BX
        PUSH    CX
        PUSH    DX
        PUSH    SI
    _IN2:
        LEA     DX, BUF5    ;提示输入商品信息
        MOV     AH, 9
        INT     21H
        LEA     DX, in_good ;将商品名存入存储区
        MOV     AH, 10
        INT     21H

        MOV     SI, OFFSET  in_good+2
        MOV     AL, [SI]
        MOV     CL, 0DH
        SUB     CL, AL
        JZ      _OUT2

        MOV     SI, N
        MOV     BX, 0
    _LOPA2: ;查找商品循环
        MOV     CL, 0AH
        MOV     DI, 0
    _LOPA2_1:
        MOV     AL, GA1[BX][DI]
        MOV     DL, in_good+2[DI]
        INC     DI
        MOV     DH, AL
        SUB     DH, 0
        JZ      _GOODRIGHT2
        CMP     AL, DL
        JNZ     _LPOA2_2
        DEC     CL
        JNZ     _LOPA2_1
        JZ      _PRINT2
    _LPOA2_2:
        ADD     BX, 18H ;数据结构变则变
        DEC     SI
        JNZ     _LOPA2
    _LPOA2_3:
        LEA     DX, BUF6    ;提示重新输入商品信息
        MOV     AH, 9
        INT     21H
        JMP     _IN2

    _GOODRIGHT2:
        MOV     DH, DL
        SUB     DH, 0DH
        JZ      _PRINT2
        JNZ     _LPOA1_2

    _PRINT2:
        LEA     DX, CRLF
        MOV     AH, 9
        INT     21H
        MOV     DI, OFFSET GA1
        ADD     DI, BX
        ADD     DI, 10
        MOV     SI, OFFSET BUF2_1
        CALL    XIUGAI
        ADD     DI, 2
        MOV     SI, OFFSET BUF2_2
        CALL    XIUGAI
        ADD     DI, 2
        MOV     SI, OFFSET BUF2_3
        CALL    XIUGAI
        ADD     DI, 2
        MOV     SI, OFFSET BUF2_4
        CALL    XIUGAI
        ADD     DI, 2
        MOV     SI, OFFSET BUF2_5
        CALL    XIUGAI
    _OUT2:
        ;恢复
        POP     SI
        POP     DX
        POP     CX
        POP     BX
        POP     AX
        RET
Modify ENDP
        
XIUGAI  PROC
        PUSH    AX
        PUSH    BX
        PUSH    CX
        PUSH    DX
        MOV     CX, SI ;字符串偏移地址
        PUSH    SI
        MOV     BX, DI ;修改数据地址
        PUSH    DI
        MOV     SI, CX
        MOV     DI, BX
    I0:
        LEA     DX, [SI]
        MOV     AH, 9
        INT     21H
        MOV     AH, 1
        INT     21H
        CMP     AL, 0DH
        JZ      _OUTX1
        CMP     AL, '0'
        JB      I0
        CMP     AL, '9'
        JA      I0
        SUB     AL, 30H
        MOV     AH, 0
        MOV     X,  AX
    I1:
        MOV     AH, 1
        INT     21H
        CMP     AL, 0DH
        JZ      _OUTX2
        CMP     AL, '0'
        JB      I0
        CMP     AL, '9'
        JA      I0
        SUB     AL, 30H
        MOV     CH, AL
        MOV     BX, 10
        MOV     AX, X
        MUL     BX
        ADD     AL, CH
        MOV     X , AX
        JMP     I1
    _OUTX1:
        LEA     DX, CRLF
        MOV     AH, 9
        INT     21H
        JMP     _OUTX
    _OUTX2:
        MOV     AX, X
        MOV     WORD PTR[DI],AX
    _OUTX:
        ;恢复
        POP     DI
        POP     SI
        POP     DX
        POP     CX
        POP     BX
        POP     AX
        RET
XIUGAI  ENDP

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

; RANK PROC
;     ;保护
;     PUSH    AX;
;     PUSH    BX;
;     PUSH    CX;
;     PUSH    DX;
;     PUSH    SI;
;     ;每次开始调用该功能，初始化排名表
;     MOV     DI,OFFSET GA1
;     MOV     SI,OFFSET FINAL_RANK
;     SUB     DI,24
;     SUB     SI,2
;     MOV     CL,N
;     _INIT:
;     ADD     DI,24
;     ADD     SI,2
;     MOV     DX,[DI+20]
;     MOV     [SI],DX
;     DEC     CL
;     JNZ     _INIT
;     ;初始化结束，进行排序
;     PUSH    SI
;     PUSH    DI
;     PUSH    AX
;     PUSH    BX
;     PUSH    CX
;     PUSH    DX

;     LEA     SI,FINAL_RANK
;     XOR     DX,DX
;     MOV     BL,N
;     MOV     CX,N
;     LEA     SI,FINAL_RANK
;     MOV     DI,SI
;     ADD     DI,2
;     MOV     CL,N-1
;     MOV     CH,N-1
;     _COMPARE:   
;     MOV     BX,[DI]
;     CMP     BX,[DI-2]
;     JA      _CONTINUE
;     MOV     DX,[DI-2]
;     PUSH    DX
;     MOV     [DI-2],BX
;     POP     DX
;     MOV     [DI],DX
;     _CONTINUE:    
;     ADD     DI,2
;     DEC     CH
;     CMP     CH,0
;     JNE     _COMPARE
;     MOV     DI,SI
;     ADD     DI,2
;     DEC     CL
;     MOV     CH,CL
;     CMP     CL,1
;     JNE     _COMPARE
;     POP     DX
;     POP     CX
;     POP     BX
;     POP     AX
;     POP     DI
;     POP     SI
;     ;排序结束
;     ; WRITE   OPTION_5
;     ; NEWLINE
;     ;开始由排名对应到商品
;     MOV     SI,OFFSET FINAL_RANK
;     MOV     CX,N
;     _LOOP1:
;     MOV     BX,N
;     MOV     DI,OFFSET GA1
;     MOV     AX,[SI]
;     _BACK:
;     CMP     BX,0
;     JE      _LOOP1_1
;     CMP     [DI+20],AX
;     JNE     _NEXT
;     MOV     [DI+22],CX
;     JMP     _NEXT
;     _LOOP1_1:
;     ADD     SI,2
;     LOOP    _LOOP1
;     ;恢复
;     POP     SI
;     POP     DX
;     POP     CX
;     POP     BX
;     POP     AX
;     RET
;     _NEXT:
;     DEC     BX
;     ADD     DI,24
;     JMP     _BACK
; RANK ENDP

CODE    ENDS
        END     START