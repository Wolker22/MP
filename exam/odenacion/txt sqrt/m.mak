all: prueba.exe saludo

prueba.exe: main.o lib.a
	gcc -g -Wall -o prueba.exe main.o lib.a
	
lib.a: funciones.o
	ar -rsv lib.a funciones.o

funciones.o: funciones.c funciones.h
	gcc -g -c funciones.c

main.o: main.c funciones.h
	gcc -g -c main.c

saludo: 
	@echo tu papa
	@rm *.o
	@rm *.a

