#include <iostream>
#include <string>
#include "ConnectFour.h"
#include "scoreStrategy.hpp"

#include "test.h"
// #include "ManhattanDistance.h"
using namespace std;

void ConnectFour::initialize()
{
    board = new char* [row];
    for(int i =0; i < row; i++){
        board[i] = new char [col];
    }
	for (int i = 0; i < row; i++)
	{
       
		for (int k = 0; k < col; k++)
		{
           
			board[i][k] = ' ';
		}
	}
}

void ConnectFour::display()
{

	cout << " 1 2 3 4 5 6 7" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col; k++)
		{

			cout << "|" << board[i][k];
		}
		cout << "|" << endl;
	}
	cout << "===============" << endl;

	//playGame();
}
void ConnectFour::playGame()
{
	int player1Choice;
	int m;
	int n;
	int check;
	display();
	do
	{
        cout << "Choose a column(1-" << col << "): " << endl;
		cin >> player1Choice;
		while (player1Choice < 1 || player1Choice > col)
		{
			cout << "Invalid input" << endl;
			cout << "Choose a column(1-" << col << "): " << endl;
			cin >> player1Choice;
		}
		counter++;
		for (m = row - 1; m >= 0; m--)
		{
			if (board[m][player1Choice - 1] != ' ')
			{
				continue;
			}
			else
			{
				break;
			}
		}

		//if col filled, skip this iteration
		if (m >= 0)
		{
			board[m][player1Choice - 1] = 'X';
			check = checkWinner();
			if (check == 1)
			{
				display();
				cout << "You win !" << endl;
				exit(0);
			}
			else
			{
				display();
			}
		}
		else
		{
			cout << "This column has been filled. Please select another column" << endl;
			continue;
		}

        cout << "Rival's turn" << endl;
        
		//call heuristic here
		ScoreStrategy s(board);
		s.guessPlus();

		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!?"<<endl;


		display();
        // int computerChoice = 1;
        // cout<< "Computer's choice: " << computerChoice << endl;
		// counter++;
		// for (n = row - 1; n >= 0; n--)
		// {
		// 	if (board[n][computerChoice - 1] != ' ')
		// 	{
		// 		continue;
		// 	}
		// 	else
		// 	{
		// 		break;
		// 	}
		// }

		// if (n >= 0)
		// {
		// 	board[n][computerChoice - 1] = 'O';
		// 	// cout << "row: " << n << endl;
		// 	check = checkWinner();
		// 	if (check == 1)
		// 	{
		// 		display();
		// 		cout << "Player 2 wins !" << endl;
		// 		exit(0);
		// 	}
		// 	else
		// 	{
		// 		display();
		// 	}
		// }
		// else
		// {
		// 	cout << "This column has been filled. Please select another column" << endl;
		// 	cout << endl;
		// 	continue;
		// }

	} while (counter <= row * col);
	cout << "Tie !" << endl;
	exit(0);
}

int ConnectFour::checkWinner()
{
	for (int k = 0; k < row; k++)
	{
		for (int n = 0; n < col; n++)
		{

			if (n < col - 3 && board[k][n] != ' ' && board[k][n] == board[k][n + 1] && board[k][n] == board[k][n + 2] && board[k][n] == board[k][n + 3])
			{
				return 1;
			}
			else if (k < row - 3 && board[k][n] != ' ' && board[k][n] == board[k + 1][n] && board[k][n] == board[k + 2][n] && board[k][n] == board[k + 3][n])
			{
				return 1;
			}
			else if (n < col - 3 && k < row - 3 && board[k][n] != ' ' && board[k][n] == board[k + 1][n + 1] && board[k][n] == board[k + 2][n + 2] && board[k][n] == board[k + 3][n + 3])
			{
				return 1;
			}
			else if (n < col - 3 && k < row - 3 && board[k][n] != ' ' && board[k][n] == board[k + 1][n - 1] && board[k][n] == board[k + 2][n - 2] && board[k][n] == board[k + 3][n - 3])
			{
				return 1;
			}
		}
	}
	return 0;
}

//this method is used to creating a customized game table
void ConnectFour::createTest()
{
	test testBoard;
	board = testBoard.create();
	display();
	ScoreStrategy t(board);
	//check(row[i], col[i], player)
	int score = t.check4(3,3,1) + t.check2(3,3,1) + t.check3(3,3,1);
	cout << score << endl;
}