#include <iostream>

class Board {};

class ChessGame {
public:
	ChessGame() {
		if (pBoard) {
			std::cout << "Ending previous game";
			// Do something
		}
		else
			pBoard = new Board;
	}
	~ChessGame() {
        delete pBoard;
        pBoard = nullptr;
	}
private:
	static Board* pBoard;
};

Board* ChessGame::pBoard = nullptr;

int main() {
//	ChessGame game1;
//	ChessGame game2;
    int *xp = new int;
    delete xp;
    delete xp;

}
