CC := gcc
INCLUDE_FLAGS := -I./headers
C_FLAGS := -Wall -Wextra -pedantic -lm $(INCLUDE_FLAGS)

.PHONY: all clean

all: mario name hello integers credit

mario: mario.o cs50.o
	$(CC) $^ -o $@
	rm -rf *.o

hello: hello.o
	$(CC) $^ -o $@
	rm -rf *.o


name: name.o cs50.o
	$(CC) $^ -o $@
	rm -rf *.o

integers: integers.o cs50.o
	$(CC) $^ -o $@
	rm -rf *.o

credit: credit.o credit_helper.o cs50.o
	$(CC) $^ -o $@
	rm -rf *.o

test: test.o credit_helper.o cs50.o
	$(CC) $^ -o $@
	rm -rf *.o


# Object files
%.o: %.c
	$(CC) $(C_FLAGS) -c $^ -o $@

clean:
	rm -rf *.o
	rm -rf hello
	rm -rf mario
	rm -rf integers
	rm -rf name
	rm -rf credit
	rm -rf test
