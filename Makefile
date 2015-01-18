all: cli

cli: libstuff.so
	${CC} ${CFLAGS} -c conversion.c
	${CC} ${CFLAGS} -c setup.c
	$(MAKE) -C cli all

test: libstuff.so
	$(MAKE) -C tests all

libstuff.so:
	${MAKE} -C lib all

clean:
	$(MAKE) -C lib clean
	$(MAKE) -C tests clean
	$(MAKE) -C cli clean
	-rm -f conversion.o setup.o

cleanobj:
	${MAKE} -C lib cleanobj
	${MAKE} -C tests cleanobj
	${MAKE} -C cli cleanobj
	-rm -f conversion.o setup.o
