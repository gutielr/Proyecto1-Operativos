OBJSP = procesos.o ordenamiento.o
OBJSH =
CC = gcc
DEBUG = -g
CFLAGS = $(DEBUG) -Wall -c
LFLAGS = $(DEBUG) -Wall
.SUFFIXES: .o .c  # store important suffixes in the .SUFFIXES macro

all: ordenArchivo-p

ordenArchivo-p: $(OBJSP) hoja
	$(CC) $(LFLAGS) -lm $(OBJSP) -o $@	

hoja: ordenamiento.o
	$(CC) $(LFLAGS) ordenamiento.o hoja.c -o $@

.c.o:
	gcc $(CFLAGS) $<
	
clean:
	rm -f *.o
