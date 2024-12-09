all: prueba.exe saludo

prueba.exe: main.o lib.a
	gcc -Wall -o prueba.exe main.o funciones.o

funciones.o: funciones.c funciones.h
	gcc -g -c funciones.c

lib.a: funciones.o
	ar -rsv lib.a funciones.o

main.o: main.c funciones.h
	gcc -g -c main.c

saludo: 
	@echo se está ejecutando el programa make
	@echo Borrando ficheros.o ...
	@rm *.o