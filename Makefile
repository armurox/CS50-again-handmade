CC := gcc
INCLUDE_FLAGS := -I./headers
C_FLAGS := -Wall -Wextra -pedantic $(INCLUDE_FLAGS)

.PHONY: all clean

all: mario name hello integers credit

mario: mario.o cs50.o
	$(CC) $^ -o $@

hello: hello.o
	$(CC) $^ -o $@


name: name.o cs50.o
	$(CC) $^ -o $@

integers: integers.o cs50.o
	$(CC) $^ -o $@

credit: credit.o credit_helper.o cs50.o
	$(CC) $^ -o $@

test: test.o credit_helper.o cs50.o
	$(CC) $^ -o $@


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
