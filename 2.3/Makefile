all: 2.3

2.3: main.o add.so sub.so mult.so div.so max.so min.so
	gcc -rdynamic -o program main.c -ldl
	./program
	
main.o: main.c
	gcc -c main.c

add.so: add.c
	gcc -fPIC add.c -c
	gcc -shared add.o -o libadd.so

sub.so: sub.c
	gcc -fPIC sub.c -c
	gcc -shared sub.o -o libsub.so

mult.so: mult.c
	gcc -fPIC mult.c -c
	gcc -shared mult.o -o libmult.so

div.so: div.c
	gcc -fPIC div.c -c
	gcc -shared div.o -o libdiv.so

max.so: max.c
	gcc -fPIC max.c -c
	gcc -shared max.o -o libmax.so

min.so: min.c
	gcc -fPIC min.c -c
	gcc -shared min.o -o libmin.so

clean:
	rm -rf *.o 2.3
