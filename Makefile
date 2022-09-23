CC=gcc
CFLAGS=-c -Wall -Werror -Wextra

SOURCES=sort.c
SOURCES2=sort_no_leak.c
SOURCES3=matrix.c
SOURCES4=matrix_extended.c
SOURCES5=matrix_sort.c
SOURCES6=matrix_arithmetic.c

OBJECTS=$(SOURCES:.c=.o)
OBJECTS2=$(SOURCES2:.c=.o)
OBJECTS3=$(SOURCES3:.c=.o)
OBJECTS4=$(SOURCES4:.c=.o)
OBJECTS5=$(SOURCES5:.c=.o)
OBJECTS6=$(SOURCES6:.c=.o)

EXECUTABLE=./build/SORT
EXECUTABLE2=./build/SORT_NO_LEAK
EXECUTABLE3=./build/MATRIX
EXECUTABLE4=./build/MATRIX_EXTENDED
EXECUTABLE5=./build/MATRIX_SORT
EXECUTABLE6=./build/MATRIX_ARITHMETIC

all: sort sort_no_leak matrix matrix_extended matrix_sort matrix_arithmetic

rebuild: clear all

clean:
	rm -rf *.o $(EXECUTABLE) $(EXECUTABLE2) $(EXECUTABLE3) $(EXECUTABLE4) $(EXECUTABLE5) $(EXECUTABLE6)

sort:
	$(CC) $(CFLAGS) $(SOURCES)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)

sort_no_leak:
	$(CC) $(CFLAGS) $(SOURCES2)
	$(CC) $(LDFLAGS) $(OBJECTS2) -o $(EXECUTABLE2)

matrix:
	$(CC) $(CFLAGS) $(SOURCES3)
	$(CC) $(LDFLAGS) $(OBJECTS3) -o $(EXECUTABLE3)
	
matrix_extended:
	$(CC) $(CFLAGS) $(SOURCES4)
	$(CC) $(LDFLAGS) $(OBJECTS4) -o $(EXECUTABLE4)

matrix_sort:
	$(CC) $(CFLAGS) $(SOURCES5)
	$(CC) $(LDFLAGS) $(OBJECTS5) -o $(EXECUTABLE5)

matrix_arithmetic:
	$(CC) $(CFLAGS) $(SOURCES6)
	$(CC) $(LDFLAGS) $(OBJECTS6) -o $(EXECUTABLE6)
	
	
