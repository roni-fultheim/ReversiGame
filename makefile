#create executalbe file by linking the object files
a.out: Square.o Board.o Player.o HumanConsolePlayer.o Location.o MoveLogic.o StandardMoveLogic.o GameFlow.o main.o
	g++ Square.o Board.o Player.o HumanConsolePlayer.o Location.o MoveLogic.o StandardMoveLogic.o GameFlow.o main.o

#creating all object files from source code
Square.o: Square.cpp Square.h Color.h
	g++ -c Square.cpp

Board.o: Board.cpp Board.h Square.h Location.h
	g++ -c Board.cpp

Player.o: Player.cpp Player.h Color.h Location.h
	g++ -c Player.cpp

HumanConsolePlayer.o: HumanConsolePlayer.cpp HumanConsolePlayer.h
	g++ -c HumanConsolePlayer.cpp
	
Location.o: Location.cpp Location.h
	g++ -c Location.cpp

MoveLogic.o: MoveLogic.cpp MoveLogic.h Player.h Location.h
	g++ -c MoveLogic.cpp

StandardMoveLogic.o: StandardMoveLogic.cpp StandardMoveLogic.h MoveLogic.h
	g++ -c StandardMoveLogic.cpp
	
GameFlow.o: GameFlow.cpp GameFlow.h Board.h MoveLogic.h Player.h
	g++ -c GameFlow.cpp
	
main.o: main.cpp GameFlow.h HumanConsolePlayer.h StandardMoveLogic.h
	g++ -c main.cpp
