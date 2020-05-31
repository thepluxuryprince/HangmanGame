main: bin/main

run: bin/main
	./bin/main

test: bin/test

build/main.o: src/main.c build
	gcc -Wall -Werror -c src/main.c -o build/main.o

build/hangman.o: src/hangman.c
	gcc -Wall -Werror -c src/hangman.c -o build/hangman.o

build/test.o: test/test.c build
	gcc -I thirdparty -I src -c test/test.c -o build/test.o
	
bin/main: build/main.o build/hangman.o bin
	gcc -Wall -Werror build/main.o build/hangman.o -o bin/main
	
bin/test: build/test.o build/hangman.o bin
	gcc -Wall -Werror build/test.o build/hangman.o -o bin/test

.PHONY : clean

bin:
	mkdir bin

build:
	mkdir build

clean:
	rm -rf build
	rm -rf bin
