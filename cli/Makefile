CFLAGS = -fPIE
LDFLAGS = -pie

all: cliconv

cliconv: main.o
	${CC} ${CFLAGS} ${LDFLAGS} main.o ../setup.o ../conversion.o  -L../lib -lstuff -o cliconv

clean:
	${MAKE} cleanobj
	-rm -f cliconv

cleanobj:
	-rm -f main.o
