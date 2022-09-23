CC=gcc
CFLAGS=-c -Wall -Werror -Wextra
SOURCES=state_sort.c
SOURCES2=state_search.c
SOURCES3=clear_state.c
OBJECTS=$(SOURCES:.c=.o)
OBJECTS2=$(SOURCES2:.c=.o)
OBJECTS3=$(SOURCES3:.c=.o)
EXECUTABLE=../build/Quest_1
EXECUTABLE2=../build/Quest_2
EXECUTABLE3=../build/Quest_3

all: state_sort state_search clear_state

rebuild: clear all

clean:
	rm -rf *.o $(EXECUTABLE) $(EXECUTABLE2)

state_sort:
	$(CC) $(CFLAGS) $(SOURCES)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)

state_search:
	$(CC) $(CFLAGS) $(SOURCES2)
	$(CC) $(LDFLAGS) $(OBJECTS2) -o $(EXECUTABLE2)

clear_state:
	$(CC) $(CFLAGS) $(SOURCES3)
	$(CC) $(LDFLAGS) $(OBJECTS3) -o $(EXECUTABLE3)