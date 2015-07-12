CFLAGS = -fPIE

all: cli

cli: conversion.o setup.o libs
	$(MAKE) -C cli all

test: libs
	${MAKE} -C tests all

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
