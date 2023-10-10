last : handle.o main.o stack.o
	gcc main.o handle.o stack.o -o last -lreadline 

main.o : main.c head.h
	gcc -c main.c -o main.o

handle.o : handle.c head.h
	gcc -c handle.c -o handle.o -lreadline

stack.o : stack.c head.h
	gcc -c stack.c -o stack.o

clean:
	rm -rf *.o last
