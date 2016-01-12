#Name:		Sajant Anand
#Date:		October 16, 2015
#Purpose:	KPCB Engineering Fellows Challenge Problem

#Description:	Makefile to allow for easy compilation. To compile, type 'make'. To clean project and remove executibles and object files, type 'make clean'.
CC = g++
CFLAGS = -Wall -pedantic
main:	main.o hashtable.o
	$(CC) -o main main.o hashtable.o
main.o:	main.cpp hashtable.o
	$(CC) $(CFLAGS) -c main.cpp
hashtable.o:	hashtable.cpp
	$(CC) $(CFLAGS) -c hashtable.cpp

clean:
	\rm -f *.o main

run:
	cat stop.txt | main
