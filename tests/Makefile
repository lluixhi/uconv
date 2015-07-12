CFLAGS = -fPIE

all: test_squeue test_sstack test_string test_file_to_string test_fnv1a

test_fnv1a: test_fnv1a.o
	${CC} ${CFLAGS} -o test_fnv1a test_fnv1a.o -L../lib -lstuff

test_squeue: test_squeue.o
	${CC} ${CFLAGS} -o test_squeue test_squeue.o -L../lib -lstuff

test_sstack: test_sstack.o
	${CC} ${CFLAGS} -o test_sstack test_sstack.o -L../lib -lstuff

test_string: test_string.o
	${CC} ${CFLAGS} -o test_string test_string.o -L../lib -lstuff

test_file_to_string: test_file_to_string.o
	${CC} ${CFLAGS} -o test_file_to_string test_file_to_string.o -L../lib -lstuff


clean:
	${MAKE} cleanobj
	-rm -f test_file_to_string test_string test_sstack test_squeue test_fnv1a

cleanobj:
	-rm -f test_file_to_string.o test_string.o test_sstack.o test_squeue.o test_fnv1a.o
