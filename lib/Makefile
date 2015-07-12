CFLAGS = -fPIC

all:
	${MAKE} -C data all
	${MAKE} libstuff.so
	${MAKE} libstuff.a

libstuff.so: strings.o file.o
	${CC} ${CFLAGS} -shared strings.o file.o data/squeue.o data/sstack.o data/mkeyhmap.o -o libstuff.so

libstuff.a: strings.o file.o
	${AR} rcs libstuff.a strings.o file.o data/squeue.o data/sstack.o data/mkeyhmap.o

clean:
	${MAKE} cleanobj
	${MAKE} cleanlib

cleanobj:
	${MAKE} -C data clean
	-rm -f file.o strings.o

cleanlib:
	-rm -f libstuff.so
	-rm -f libstuff.a
