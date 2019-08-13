all:	fileman

fileman:	fileman.o LList.o
	cc fileman.o LList.o -o fileman -g -lncurses

fileman.o:	fileman.c
	cc -c fileman.c -o fileman.o -g

LList.o:	LList.c
	cc -c LList.c -o LList.o -g

clean:
	rm -rf *.o filemane