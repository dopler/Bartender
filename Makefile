all: drink

drink: main.o bartender.o
	g++ main.o bartender.o -o drink

main.o: main.cpp
	g++ -c main.cpp

bartender.o: bartender.cpp
	g++ -c bartender.cpp

clean:
	rm -rf *o drink