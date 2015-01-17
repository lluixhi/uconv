all: cli

cli: libstuff.a
	${CC} ${CFLAGS} -c conversion.c
	$(MAKE) -C cli all

test: libstuff.a
	$(MAKE) -C tests all

libstuff.a:
	${MAKE} -C lib all

clean:
	$(MAKE) -C lib clean
	$(MAKE) -C tests clean
	$(MAKE) -C cli clean
	-rm -f conversion.o

cleanobj:
	${MAKE} -C lib cleanobj
	${MAKE} -C tests cleanobj
	${MAKE} -C cli cleanobj
	-rm -f conversion.o
