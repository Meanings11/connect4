#ifndef Something
#define Something
#endif

#include <string>
#include "ConnectFour.h"


class ExhaustScore{
private:
	char board[6][7];
	int score[7];

public:
	ExhaustScore() {};
	ExhaustScore(char**);
	~ExhaustScore();

	void DFS(int, int);
	void run();
	int AIchoice();
	int checkWinner(int,int);
};
