all: proi-2

proi-2: proi-2.o chess.o shell.o
	g++ -std=c++11 -g -o proi-2 proi-2.o chess.o shell.o

proi-2.o: proi-2.cpp
	g++ -std=c++11 -g -c proi-2.cpp

chess.o: chess.cpp
	g++ -std=c++11 -g -c chess.cpp

shell.o: shell.cpp
	g++ -std=c++11 -g -c shell.cpp

clean:
	rm *0 proi-2
