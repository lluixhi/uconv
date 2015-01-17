all:
	${CC} ${CFLAGS} -c test_squeue.c
	${CC} ${CFLAGS} -o test_squeue test_squeue.o -L../lib -lstuff
	${CC} ${CFLAGS} -c test_sstack.c
	${CC} ${CFLAGS} -o test_sstack test_sstack.o -L../lib -lstuff
	${CC} ${CFLAGS} -c test_string.c
	${CC} ${CFLAGS} -o test_string test_string.o -L../lib -lstuff

clean:
	$(MAKE) cleanobj
	$(MAKE) cleanexe

cleanobj:
	-rm -f test_string.o test_sstack.o test_squeue.o

cleanexe:
	-rm -f test_string test_sstack test_squeue
