all:
	${CC} ${CFLAGS} -c main.c
	${CC} ${CFLAGS} -fPIE main.o ../setup.o ../conversion.o  -L../lib -lstuff -o cliconv

clean:
	${MAKE} cleanobj
	-rm -f cliconv

cleanobj:
	-rm -f main.o
