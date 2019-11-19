fib_list: fib_list.o fib_list.h linkedList.o linkedList.h 
	gcc -g -ansi -Wall -pedantic fib_list.o linkedList.o -o fib_list

fib_list.o: fib_list.c fib_list.h
	gcc -c -ansi -Wall -pedantic fib_list.c -o fib_list.o
linkedList.o: linkedList.c linkedList.h
	gcc -c -ansi -Wall -pedantic linkedList.c -o linkedList.o
