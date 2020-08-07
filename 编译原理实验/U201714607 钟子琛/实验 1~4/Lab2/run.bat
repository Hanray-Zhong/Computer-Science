chcp 65001
flex lex.l
bison parser.y
gcc -o parser lex.yy.c parser.tab.c ast.c analysis.c
parser test.c