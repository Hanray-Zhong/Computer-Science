DATAS SEGMENT
      CHAR   DW ?; 定义char 为db 类型 但是不赋值 
DATAS ENDS

STACKS SEGMENT
     DB 256 DUP(?);申请 256 个字节空间
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    ;代码初始化
    MOV AH ,01H; 输入一个字符 并且回显到屏幕上 输入的字符串保存在 AL 中
    INT 21H
    MOV [CHAR] , AL 
    MOV DL , [CHAR] ; 显示一个字符 该字符在 DL 中
    MOV AH , 02H;
    INT 21H
    MOV AH , 07H ; 
    INT 21H
    MOV DL,AL;
    MOV  AH , 02H;
    INT 21H;
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START