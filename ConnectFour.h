#ifndef Something
#define Something
#include <string>
#include "test.h"

class ConnectFour{

private:
	int col = 7;
	int row = 6;
    char** board;
	int counter=0;
	


public:
	void initialize();
	void display();
	void playGame();
	int checkWinner();

	void createTest();

};
#endif
