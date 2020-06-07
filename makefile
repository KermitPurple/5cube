all: main.o FiveCube.o Coord.o
	g++ bin/*.o -o bin/test.exe -I include -lopenGL32 -lfreeGLUT
	@echo

main.o: src/main.cpp
	g++ src/main.cpp -c -o bin/main.o -I include -lopenGL32 -lfreeGLUT

FiveCube.o: src/FiveCube.cpp
	g++ src/FiveCube.cpp -c -o bin/FiveCube.o -I include -lopenGL32 -lfreeGLUT

Coord.o: src/Coord.cpp
	g++ src/Coord.cpp -c -o bin/Coord.o -I include -lopenGL32 -lfreeGLUT

clean:
	rm bin/*

new:
	mkdir bin

test: all
	bin/test.exe
