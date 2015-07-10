all: cli

cli: conversion.o setup.o libs
	$(MAKE) -C cli all

test: libs
	${MAKE} -C tests all

conversion.o:
	${CC} ${CFLAGS} -c conversion.c

setup.o:
	${CC} ${CFLAGS} -c setup.c

libs:
	${MAKE} -C lib all

clean:
	${MAKE} -C lib clean
	${MAKE} -C tests clean
	${MAKE} -C cli clean
	-rm -f conversion.o setup.o

cleanobj:
	${MAKE} -C lib cleanobj
	${MAKE} -C tests cleanobj
	${MAKE} -C cli cleanobj
	-rm -f conversion.o setup.o
