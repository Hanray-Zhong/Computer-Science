.386 
DATA    SEGMENT     USE16
BNAME   DB  'ZhongZiChen', 0;老板姓名（必须是自己名字的拼音） 
BPASS   DB  '123456' ;密码 
N       EQU 3
S1      DB  'SHOP', 0   ;网店名称，用0结束 
GA1     DB  'PEN', 7 DUP('0') 
        ;   折扣    进货价   销售价  进货总数 已售数量    推荐度
        DW  10,     35,     56,     70,     25,        ?
GA2     DB 'BOOK', 6 DUP('0') ; 商品名称
        ;   折扣    进货价   销售价  进货总数 已售数量    推荐度
        DW  9,      12,     30,     25,     5,         ?
GA3     DB 'CLOTH', 5 DUP('0') ; 商品名称
        ;   折扣    进货价   销售价  进货总数 已售数量    推荐度
        DW  8,      40,     60,     30,     15,        ?

AUTH DB 0 

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
FAIL            DB 'Failed!$'
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
    ;输入回车重新输入用户名
    MOV     SI,OFFSET IN_GOODSNAME
    CMP     BYTE PTR[SI+2],0DH
    JE      LOGIN

    MOV     DI,OFFSET IN_GOODSNAME
    ADD     DI,2
    MOV     CL,3
    MOV     DX,OFFSET GA1
    SUB     DX,22
;与当前货物名字不匹配，匹配下一个货物的名字
NEXT: 
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
    LEA     DX,OFFSET FAIL 
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
FIND: 
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
    MOV     CX,128
    IMUL    AX,CX
    IDIV    BX;AX=进货价(AX)*128/实际销售价格(BX)
    MOV     CX,AX;CX=AX=进货价(AX)*128/实际销售价格(BX)

    MOV     AX,WORD PTR[SI+18] ;AX=已售数量
    MOV     BX,128
    IMUL    AX,BX
    CWD
    MOV     BX,WORD PTR[SI+16] ;BX=进货数量
    IDIV    BX;AX=已售数量*128/进货数量

    ADD     AX,CX;AX=AX+CX

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
    MOV DX,OFFSET IN_GOODSNAME 
    MOV AH,9H 
    INT 21H 
    JMP LOOKUP
EXIT: 
    MOV AH,4CH 
    INT 21H 
    CODE ENDS 
    END START