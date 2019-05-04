#ifndef Something
#define Something
#include <string>

class ConnectFour{

private:
	int col = 8;
	int row = 8;
    char** board;
	int counter=0;
	


public:
	void initialize();
	void display();
	void playGame();
	int checkWinner();
	

};
#endif
