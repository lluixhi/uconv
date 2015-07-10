all: test_squeue test_sstack test_string test_file_to_string

test_squeue:
	${CC} ${CFLAGS} -c test_squeue.c
	${CC} ${CFLAGS} -o test_squeue test_squeue.o -L../lib -lstuff

test_sstack:
	${CC} ${CFLAGS} -c test_sstack.c
	${CC} ${CFLAGS} -o test_sstack test_sstack.o -L../lib -lstuff

test_string:
	${CC} ${CFLAGS} -c test_string.c
	${CC} ${CFLAGS} -o test_string test_string.o -L../lib -lstuff

test_file_to_string:
	${CC} ${CFLAGS} -c test_file_to_string.c
	${CC} ${CFLAGS} -o test_file_to_string test_file_to_string.o -L../lib -lstuff


clean:
	${MAKE} cleanobj
	-rm -f test_file_to_string test_string test_sstack test_squeue

cleanobj:
	-rm -f test_file_to_string.o test_string.o test_sstack.o test_squeue.o
