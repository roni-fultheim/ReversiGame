#create executalbe file by linking the object files
a.out: Board.o Player.o HumanPlayer.o Location.o MoveLogic.o StandardMoveLogic.o ViewByConsole.o GameManager.o main.o
	g++ Board.o Player.o HumanPlayer.o Location.o MoveLogic.o StandardMoveLogic.o ViewByConsole.o GameManager.o main.o

#creating all object files from source code

Board.o: Board.cpp Board.h Location.h
	g++ -c Board.cpp

Player.o: Player.cpp Player.h Location.h
	g++ -c Player.cpp

HumanPlayer.o: HumanPlayer.cpp HumanPlayer.h Player.h
	g++ -c HumanPlayer.cpp
	
Location.o: Location.cpp Location.h
	g++ -c Location.cpp

MoveLogic.o: MoveLogic.cpp MoveLogic.h Player.h Location.h
	g++ -c MoveLogic.cpp

StandardMoveLogic.o: StandardMoveLogic.cpp StandardMoveLogic.h MoveLogic.h
	g++ -c StandardMoveLogic.cpp
	
ViewByConsole.o: ViewByConsole.cpp ViewByConsole.h ViewGame.h
	g++ -c ViewByConsole.cpp
	
GameManager.o: GameManager.cpp GameManager.h Board.h MoveLogic.h Player.h
	g++ -c GameManager.cpp
	
main.o: main.cpp GameManager.h HumanPlayer.h StandardMoveLogic.h
	g++ -c main.cpp