all:	fileman

fileman:	fileman.o
	cc fileman.o -o fileman -g

fileman.o:	fileman.c
	cc -c fileman.c -o fileman.o -g

clean:
	rm -rf *.o filemane