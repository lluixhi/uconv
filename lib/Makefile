all:
	$(MAKE) -C data all
	$(MAKE) shared

stuff:
	${CC} ${CFLAGS} -fPIC -c strings.c
	${CC} ${CFLAGS} -fPIC -c file.c

shared: stuff
	${CC} ${CFLAGS} -shared strings.o file.o data/squeue.o data/sstack.o -o libstuff.so

static: stuff
	${AR} rcs libstuff.a strings.o file.o data/squeue.o data/sstack.o

clean:
	$(MAKE) cleanobj
	$(MAKE) cleanso

cleanobj:
	$(MAKE) -C data clean
	-rm -f file.o strings.o

cleanso:
	-rm -f libstuff.so
