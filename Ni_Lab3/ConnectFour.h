#ifndef Something
#define Something
#include <string>

class ConnectFour{

private:
	char board[9][7];
	int counter=0;


public:
	void initialize();
	void display();
	void playGame();
	int checkWinner();
	

};
#endif