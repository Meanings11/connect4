#ifndef Something
#define Something
#include <string>

class ConnectFour{
	private:
		int col;
		int row;
    	char** board;
		int counter;

	public:
		ConnectFour();
		~ConnectFour();

		void display();
		void playGame();
		int checkWinner();
};
#endif
