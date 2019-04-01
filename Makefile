all: chess_pieces_configurations

chess_pieces_configurations: chess_pieces_configurations.o chess.o shell.o
	g++ -std=c++11 -g -o chess_pieces_configurations chess_pieces_configurations.o chess.o shell.o
	rm *.o

chess_pieces_configurations.o: chess_pieces_configurations.cpp
	g++ -std=c++11 -g -c chess_pieces_configurations.cpp

chess.o: chess.cpp
	g++ -std=c++11 -g -c chess.cpp

shell.o: shell.cpp
	g++ -std=c++11 -g -c shell.cpp

clean:
	rm *0 chess_pieces_configurations *.o
