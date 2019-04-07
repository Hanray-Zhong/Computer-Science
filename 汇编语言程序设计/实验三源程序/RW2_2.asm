.386 
DATA    SEGMENT     USE16
BNAME   DB  'ZhongZiChen', 0;老板姓名（必须是自己名字的拼音） 
BPASS   DB  '123456' ;密码 
N       EQU 5
S1      DB  'SHOP', 0   ;网店名称，用0结束 
GA1     DB  'PEN', 7 DUP('0') 
        ;   折扣    进货价   销售价  进货总数 已售数量    推荐度    推荐度排名
        DW  10,     35,     56,     700,    0,         ?,       ?
GA2     DB 'BOOK', 6 DUP('0') ; 商品名称
        ;   折扣    进货价   销售价  进货总数 已售数量    推荐度
        DW  9,      12,     30,     2500,   0,         ?,       ?
GA3     DB 'CLOTH', 5 DUP('0') ; 商品名称
        ;   折扣    进货价   销售价  进货总数 已售数量    推荐度
        DW  8,      40,     60,     300,    0,         ?,       ?
GA4     DB 'WATER', 5 DUP('0') ; 商品名称
        ;   折扣    进货价   销售价  进货总数 已售数量    推荐度
        DW  10,     1,      2,      3000,   0,         ?,       ?
GA5     DB 'BAG', 7 DUP('0') ; 商品名称
        ;   折扣    进货价   销售价  进货总数 已售数量    推荐度
        DW  9,      20,     35,     20000,   0,        ?,       ?

AUTH DB 0 
TEMP DW 0

IN_NAME DB 12
DB 0
DB 12 DUP(0) 
IN_PWD DB 7 
DB 0 
DB 7 DUP(0) 
IN_GOODSNAME DB 11
DB '0' 
DB 11 DUP(0) 
;储存推荐度
FINAL_RANK DW 20 DUP(0)

NAMEINPUT       DB 'Please Input The Name:$'
PASSWORDINPUT   DB 'Please Input The Password:$'
GOODSINPUT      DB 'Please Input The Goods Name:$'
LOGININFAIL     DB 'Login Failed!$'
SUCCESS         DB 'Login In Successful$'
DATA ENDS

CODE SEGMENT USE16 
ASSUME CS:CODE,DS:DATA 
START: 
    MOV     AX,DATA 
    MOV     DS,AX 
;管理等登陆输入
LOGIN: 
    MOV     AUTH,0 
    LEA     DX,OFFSET NAMEINPUT
    MOV     AH,9H 
    INT     21H 
    MOV     DL, 0AH
    MOV     AH, 2H 
    INT     21H 
    LEA     DX,OFFSET IN_NAME 
    MOV     AH,10 
    INT     21H 
    MOV     DL, 0AH
    MOV     AH, 2H 
    INT     21H 
    LEA     BX,OFFSET IN_NAME 
    CMP     BYTE PTR[BX+2],'Q' ;输入Q退出
    JE      EXIT
    MOV     DI,OFFSET IN_NAME
    ADD     DI,2
    MOV     SI,OFFSET BNAME
    SUB     SI,1
    SUB     DI,1
    MOV     CX,0
CHECKNAME:  ;检查名字是否输入正确
    ADD     DI,1 
    ADD     SI,1 
    ADD     CX,1 
    CMP     CX,9H 
    JE      PASSWORD 
    MOV     BL,BYTE PTR[SI] 
    CMP     BL,BYTE PTR[DI] 
    JE      CHECKNAME 
    JNE     FAILED 
;输入密码
PASSWORD: 
    LEA     DX,OFFSET PASSWORDINPUT
    MOV     AH,9H 
    INT     21H 
    MOV     DL,0AH
    MOV     AH,2H 
    INT     21H 
    LEA     DX,OFFSET IN_PWD 
    MOV     AH,0AH 
    INT     21H 
    LEA     BX,OFFSET IN_PWD 
    MOV     DI,OFFSET IN_PWD 
    ADD     DI,2 
    MOV     SI,OFFSET BPASS
    MOV     DI,OFFSET IN_PWD
    ADD     DI,2
    MOV     SI,OFFSET BPASS
    SUB     SI,1
    SUB     DI,1
    MOV     CX,0
CHECKPASS:  ;检查密码输入是否输入
    ADD     DI,1 
    ADD     SI,1 
    ADD     CX,1 
    CMP     CX,7H 
    JE      SUCCESSFUL 
    MOV     BL,BYTE PTR[SI] 
    CMP     BL,BYTE PTR[DI] 
    JE      CHECKPASS 
    JNE     FAILED 
;成功登陆
SUCCESSFUL: 
    MOV     AUTH,1 
    MOV     DX,OFFSET SUCCESS 
    MOV     AH,9H 
    INT     21H 
    MOV     DL,0AH 
    MOV     AH,2H 
    INT     21H 






;登陆失败
FAILED: 
    LEA     DX,OFFSET LOGININFAIL
    MOV     AH,9H 
    INT     21H 
    MOV     DL, 0AH
    MOV     AH, 2H 
    INT     21H 
    JMP     LOGIN 
PRINT: 
    MOV AX,OFFSET IN_GOODSNAME 
    MOV AH,9H 
    INT 21H 
    JMP LOOKUP
EXIT: 
    MOV AH,4CH 
    INT 21H

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
    RET
;计算所有商品推荐度结束
_CALCULATE:
    MOV     SI,DX 
    CMP     AUTH,1 
    JNE     PRINT 

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
    ;恢复
    POP     AX
    POP     BX
    POP     CX
    POP     DX
    POP     SI
CALCULATE ENDP

;功能4：推荐度排名
RANK PROC
    ;保护
    PUSH    AX;
    PUSH    BX;
    PUSH    CX;CL循环标识
    PUSH    DX;
    PUSH    SI;暂存地址
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
    MOV     BYTE PTR[SI],BYTE PTR[DI]
    DEC     CL
    JNZ     _INIT
    ;初始化结束，进行插入排序






    ;恢复
    POP     AX
    POP     BX
    POP     CX
    POP     DX
    POP     SI
    POP     DI
RANK ENDP

CODE ENDS 
    END START