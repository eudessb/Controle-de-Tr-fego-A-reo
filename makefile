CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude -pedantic
SRC = src/main.c src/heaptree.c
OBJ = $(SRC:.c=.o)
EXEC = bin/main

all: $(EXEC)

$(EXEC): $(OBJ)
	@mkdir -p bin
	$(CC) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: run clean
run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(OBJ) $(EXEC)
