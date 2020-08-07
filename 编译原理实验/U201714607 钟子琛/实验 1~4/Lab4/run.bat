flex lex.l
bison -d -v parser.y
gcc -o parser lex.yy.c parser.tab.c ast.c analysis.c ObjectCode.c
parser test.c
