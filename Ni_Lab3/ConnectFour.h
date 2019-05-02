#ifndef Something
#define Something
#include <string>

class ConnectFour{

private:
	int column = 7;
	int row = 6;
	char board[6][7];
	int counter=0;
	


public:
	void initialize();
	void display();
	void playGame();
	int checkWinner();
	

};
#endif