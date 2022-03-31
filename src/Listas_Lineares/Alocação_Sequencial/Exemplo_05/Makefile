CC = gcc-11
CFLAGS = -O2

all:	listas

listas: main.o ferramentas.o
	$(CC) $(CFLAGS) -o listas ferramentas.o main.o

main.o: main.c
	$(CC) $(CFLAGS) -c -o main.o main.c

ferramentas.o: ferramentas.c
	$(CC) $(CFLAGS) -o ferramentas.o -c ferramentas.c

clean: 
	rm *.o
	rm listas

