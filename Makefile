CC = gcc
CFLAGS = -std=c99 -Wall -Wextra

all: build/ir_tables

build/ir_tables: src/intermediate_representations.c
	mkdir -p build
	$(CC) $(CFLAGS) src/intermediate_representations.c -o build/ir_tables

run: all
	./build/ir_tables

clean:
	rm -rf build *.exe
