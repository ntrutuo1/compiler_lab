CC = gcc
CFLAGS = -Wall -g

# ====== CONFIG CMOCKA ======
CMOCKA_ROOT = D:/cmocka
CMOCKA_INCLUDE = -I$(CMOCKA_ROOT)/include
CMOCKA_LIB = -L$(CMOCKA_ROOT)/lib -lcmocka

# ====== SOURCE FILES ======
SCANNER_OBJS = scanner.o reader.o charcode.o token.o error.o
TEST_OBJS = unit_test_scanner.o reader.o charcode.o token.o error.o scanner.o

# ====== DEFAULT ======
all: scanner unit_test_scanner

# ====== BUILD SCANNER ======
scanner: $(SCANNER_OBJS)
	$(CC) $(SCANNER_OBJS) -o scanner

scanner.o: scanner.c
	$(CC) $(CFLAGS) -c scanner.c

# ====== BUILD UNIT TEST ======
unit_test_scanner: $(TEST_OBJS)
	$(CC) $(TEST_OBJS) $(CMOCKA_LIB) -o unit_test_scanner

unit_test_scanner.o: unit_test_scanner.c
	$(CC) $(CFLAGS) $(CMOCKA_INCLUDE) -c unit_test_scanner.c

# ====== COMMON OBJECTS ======
reader.o: reader.c
	$(CC) $(CFLAGS) -c reader.c

charcode.o: charcode.c
	$(CC) $(CFLAGS) -c charcode.c

token.o: token.c
	$(CC) $(CFLAGS) -c token.c

error.o: error.c
	$(CC) $(CFLAGS) -c error.c

# ====== CLEAN ======
clean:
	rm -f *.o scanner unit_test_scanner
