CFLAGS = -c -Wall
CC = gcc
LIBS =  -lm 

# ====== CONFIG CMOCKA ======
CMOCKA_ROOT = D:/cmocka
CMOCKA_INCLUDE = -I$(CMOCKA_ROOT)/include
CMOCKA_LIB = -L$(CMOCKA_ROOT)/lib -lcmocka

all: parser

parser: main.o parser.o scanner.o reader.o charcode.o token.o error.o
	${CC} main.o parser.o scanner.o reader.o charcode.o token.o error.o -o parser

main.o: main.c
	${CC} ${CFLAGS} main.c

scanner.o: scanner.c
	${CC} ${CFLAGS} scanner.c

parser.o: parser.c
	${CC} ${CFLAGS} parser.c

# ====== UNIT TEST (CMocka) ======
TEST_OBJS = unit_test.o reader.o charcode.o token.o error.o scanner.o run_scan.o

unit_test: $(TEST_OBJS)
	$(CC) $(TEST_OBJS) $(CMOCKA_LIB) -o unit_test

unit_test.o: unit_test.c
	$(CC) $(CFLAGS) $(CMOCKA_INCLUDE) -c unit_test.c

reader.o: reader.c
	${CC} ${CFLAGS} reader.c

charcode.o: charcode.c
	${CC} ${CFLAGS} charcode.c

token.o: token.c
	${CC} ${CFLAGS} token.c

error.o: error.c
	${CC} ${CFLAGS} error.c

run_scan.o: run_scan.c
	${CC} ${CFLAGS} run_scan.c

clean:
	rm -f *.o *~

clean-all: clean
	rm -f parser unit_test

