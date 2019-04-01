.386 
DATA    SEGMENT     USE16
BNAME   DB  'ZhongZiChen', 0;老板姓名（必须是自己名字的拼音） 
BPASS   DB  '123456' ;密码 
N       EQU 5
S1      DB  'SHOP', 0   ;网店名称，用0结束 
GA1     DB  'PEN', 7 DUP('0') 
        ;   折扣    进货价   销售价  进货总数 已售数量    推荐度
        DW  10,     35,     56,     700,    0,        ?
GA2     DB 'BOOK', 6 DUP('0') ; 商品名称
        ;   折扣    进货价   销售价  进货总数 已售数量    推荐度
        DW  9,      12,     30,     2500,   0,         ?
GA3     DB 'CLOTH', 5 DUP('0') ; 商品名称
        ;   折扣    进货价   销售价  进货总数 已售数量    推荐度
        DW  8,      40,     60,     300,    0,        ?
GA4     DB 'WATER', 5 DUP('0') ; 商品名称
        ;   折扣    进货价   销售价  进货总数 已售数量    推荐度
        DW  10,     1,      2,      3000,   0,        ?
GA5     DB 'Bag', 7 DUP('0') ; 商品名称
        ;   折扣    进货价   销售价  进货总数 已售数量    推荐度
        DW  9,      20,     35,     20000,   0,        ?

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
NAMEINPUT       DB 'Please Input The Name:$'
PASSWORDINPUT   DB 'Please Input The Password:$'
GOODSINPUT      DB 'Please Input The Goods Name:$'
LOGININFAIL     DB 'Login Failed!$'
SUCCESS         DB 'Login In Successful$'
COMPLETE        DB 'Search Complete! Not Found.$'
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
    MOV     CH,0
CHECKNAME:  ;检查名字是否输入正确
    ADD     DI,1 
    ADD     SI,1 
    ADD     CH,1 
    CMP     CH,9H 
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
    LEA     Dx,OFFSET IN_PWD 
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
    MOV     CH,0
CHECKPASS:  ;检查密码输入是否输入
    ADD     DI,1 
    ADD     SI,1 
    ADD     CH,1 
    CMP     CH,7H 
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
LOOKUP:     ;搜索货物
    MOV     DX,OFFSET GOODSINPUT 
    MOV     AH,9H 
    INT     21H 
    MOV     DL,0AH 
    MOV     AH,2H 
    INT     21H
    MOV     DX,OFFSET IN_GOODSNAME
    MOV     AH,10
    INT     21H
    MOV     DL,0AH
    MOV     AH,2H
    INT     21H 

    ;开始计时
    MOV  AX, 0	;表示开始计时
	CALL TIMER
LOOPA:
    ;输入回车重新输入用户名
    MOV     SI,OFFSET IN_GOODSNAME
    CMP     BYTE PTR[SI+2],0DH
    JE      LOGIN

    MOV     CL,N
    MOV     DX,OFFSET GA1
    SUB     DX,22

;计算所有商品的推荐度
CHANGEGOODS: 
    ADD     DX,22 
    ;转入计算推荐度
    JMP     CALCULATE
CALCULATEBACK:
    DEC     CL
    JNZ     CHANGEGOODS
;计算所有商品推荐度结束

    MOV     CL,N
    MOV     DX,OFFSET GA1
    SUB     DX,22

;与当前货物名字不匹配，匹配下一个货物的名字
;SI 当前检查货物名字
;DI 输入的名字
NEXT: 
    MOV     DI,OFFSET IN_GOODSNAME
    ADD     DI,2
    ADD     DX,22 
    MOV     SI,DX
    SUB     SI,1
    SUB     DI,1
    MOV     CH,0
CHECKGOODS: 
    ADD     DI,1 
    ADD     SI,1 
    ADD     CH,1 
    CMP     CH,11 
    JE      FIND 
    MOV     BL,BYTE PTR[SI] 
    CMP     BL,BYTE PTR[DI] 
    JE      CHECKGOODS
    MOV     BL,'0'
    CMP     BL,BYTE PTR[SI]
    MOV     BL,0DH
    CMP     BL,BYTE PTR[DI]
    JE      FIND
    DEC     CL
    JNZ     NEXT
;没有找到货物，重新输入货物的名字
NOTFIND: 
    LEA     DX,OFFSET COMPLETE 
    MOV     AH,9H 
    INT     21H 
    MOV     DL,0AH 
    MOV     AH,2H 
    INT     21H 
    JMP     LOOKUP 
;登陆失败
FAILED: 
    LEA     DX,OFFSET LOGININFAIL
    MOV     AH,9H 
    INT     21H 
    MOV     DL, 0AH
    MOV     AH, 2H 
    INT     21H 
    JMP     LOGIN 
;开始计算推荐度
CALCULATE:
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
    IMUL    AX,8
    IMUL    AX,2
    IMUL    AX,2
    IMUL    AX,2
    IMUL    AX,2
    IDIV    BX;AX=进货价(AX)*128/实际销售价格(BX)
    MOV     TEMP,AX;TEMP=AX=进货价(AX)*128/实际销售价格(BX)

    MOV     AX,WORD PTR[SI+18] ;AX=已售数量
    IMUL    AX,8
    IMUL    AX,2
    IMUL    AX,2
    IMUL    AX,2
    IMUL    AX,2
    CWD
    MOV     BX,WORD PTR[SI+16] ;BX=进货数量
    IDIV    BX;AX=已售数量*128/进货数量

    MOV     BX,TEMP
    ADD     AX,BX;推荐度：AX=AX+TEMP
    MOV     WORD PTR[SI+20],AX
    MOV     DX,SI
    JMP     CALCULATEBACK

;找到了对应的商品，将输出商品的推荐度
FIND: 
    MOV     SI,DX
    ;如果卖完了，输出推荐度，回到功能三（1）
    MOV     AX,WORD PTR[SI+18]
    MOV     BX,WORD PTR[SI+16]
    CMP     AX,BX
    JE      LOOPEND

    ;没有卖完，已售+1，继续循环
    ADD     WORD PTR[SI+18],1
    JMP     LOOPA

;结束循环
LOOPEND:
    ;结束计时
    MOV  AX, 1	
    CALL TIMER	;终止计时并显示计时结果(ms)

    MOV     AX,WORD PTR[SI+20]
    CMP     AX,100 
    JGE     LEVELA 
    CMP     AX,50 
    JGE     LEVELB 
    CMP     AX,10 
    JGE     LEVELC 
    JMP     LEVELF
LEVELA: 
    MOV DL,41H 
    MOV AH,2H 
    INT 21H 
    MOV DL, 0AH
    MOV AH, 2H 
    INT 21H 
    JMP LOOKUP 
LEVELB: 
    MOV DL,42H 
    MOV AH,2H 
    INT 21H 
    MOV DL, 0AH
    MOV AH, 2H 
    INT 21H 
    JMP LOOKUP 
LEVELC: 
    MOV DL,43H 
    MOV AH,2H 
    INT 21H 
    MOV DL, 0AH
    MOV AH, 2H 
    INT 21H 
    JMP LOOKUP 
LEVELF: 
    MOV DL,46H 
    MOV AH,2H 
    INT 21H 
    MOV DL, 0AH
    MOV AH, 2H 
    INT 21H 
    JMP LOOKUP
PRINT: 
    MOV AX,OFFSET IN_GOODSNAME 
    MOV AH,9H 
    INT 21H 
    JMP LOOKUP
EXIT: 
    MOV AH,4CH 
    INT 21H

TIMER	PROC
	PUSH  DX
	PUSH  CX
	PUSH  BX
	MOV   BX, AX
	MOV   AH, 2CH
	INT   21H	     ;CH=hour(0-23),CL=minute(0-59),DH=second(0-59),DL=centisecond(0-100)
	MOV   AL, DH
	MOV   AH, 0
	IMUL  AX,AX,1000
	MOV   DH, 0
	IMUL  DX,DX,10
	ADD   AX, DX
	CMP   BX, 0
	JNZ   _T1
	MOV   CS:_TS, AX
_T0:	POP   BX
	POP   CX
	POP   DX
	RET
_T1:	SUB   AX, CS:_TS
	JNC   _T2
	ADD   AX, 60000
_T2:	MOV   CX, 0
	MOV   BX, 10
_T3:	MOV   DX, 0
	DIV   BX
	PUSH  DX
	INC   CX
	CMP   AX, 0
	JNZ   _T3
	MOV   BX, 0
_T4:	POP   AX
	ADD   AL, '0'
	MOV   CS:_TMSG[BX], AL
	INC   BX
	LOOP  _T4
	PUSH  DS
	MOV   CS:_TMSG[BX+0], 0AH
	MOV   CS:_TMSG[BX+1], 0DH
	MOV   CS:_TMSG[BX+2], '$'
	LEA   DX, _TS+2
	PUSH  CS
	POP   DS
	MOV   AH, 9
	INT   21H
	POP   DS
	JMP   _T0
_TS	DW    ?
 	DB    'Time elapsed in ms is '
_TMSG	DB    12 DUP(0)
TIMER   ENDP

CODE ENDS 
    END START