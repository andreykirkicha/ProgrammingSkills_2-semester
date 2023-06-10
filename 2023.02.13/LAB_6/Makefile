calculate : calculate.o main.o stack.o prog_log.o
	gcc calculate.o main.o stack.o -o calculate

main.o : main.c
	gcc -c main.c -o main.o

calculate.o : calculate.c
	gcc -c calculate.c -o calculate.o

stack.o : stack.c
	gcc -c stack.c -o stack.o

prog_log.o : prog_log.h
	gcc -c prog_log.c -o prog_log.o
