yacc -d -v  abstree.y
lex abstree.l
gcc lex.yy.c y.tab.c -w
./a.out $1
