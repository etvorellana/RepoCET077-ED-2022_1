CC = gcc
CFLAGS = -Wall

all:	exe

exe: main.o ferramentas.o
	$(CC) $(CFLAGS) -o exe ferramentas.o main.o

main.o: main.c
	$(CC) $(CFLAGS) -c -o main.o main.c

ferramentas.o: ferramentas.c
	$(CC) $(CFLAGS) -o ferramentas.o -c ferramentas.c

clean: 
	rm *.o
	rm exe

