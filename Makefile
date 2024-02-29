
output: Meow.o
	g++ Meow.o -o Meow

main.o: Meow.cpp Meow.h
	g++ -c Meow.cpp

target: dependecies
	action

clean:
	rm *.o Meow
