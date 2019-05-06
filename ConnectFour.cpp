#include <iostream>
#include <string>
#include "ConnectFour.h"
#include "scoreStrategy.hpp"

// #include "test.h"
#include "ManhattanDistance.h"
using namespace std;

//Initialize an empty game board
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
	cout << endl;
	cout << "===============" << endl;
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

}

//Play the game
void ConnectFour::playGame()
{
	int player1Choice;
	int aiChoice;
	int computerChoice;
	int m;
	int n;
	int check;
	
	aiChoice = chooseHeuristic();
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
			cout << endl;
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
		cout << endl;
        cout << "Rival's turn" << endl;
        
		//call heuristic here
		switch(aiChoice){
			case 1:
				{
				ScoreStrategy s(board);
				computerChoice =  s.guessPlus();
				break;
				}

			case 2:
				{
				ManhattanDistance mh(row, col);
				computerChoice =  mh.pick(board);
				break;
				}

		}
		
		
		//display();
        cout<< "Computer's choice: " << computerChoice << endl << endl;


		counter++;
		for (n = row - 1; n >= 0; n--)
		{
			if (board[n][computerChoice - 1] != ' ')
			{
				continue;
			}
			else
			{
				break;
			}
		}

		if (n >= 0)
		{
			board[n][computerChoice - 1] = 'O';
			check = checkWinner();
			if (check == 1)
			{
				display();
				cout << "Player 2 wins !" << endl;
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
			cout << endl;
			continue;
		}

	} while (counter <= row * col);
	cout << "Tie !" << endl;
	exit(0);
}

//Check if someone successfully connect 4 chesses
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
			else if (n > 2 && k < row - 3 && board[k][n] != ' ' && board[k][n] == board[k + 1][n - 1] && board[k][n] == board[k + 2][n - 2] && board[k][n] == board[k + 3][n - 3])
			{
				return 1;
			}
			else if (n < col && k < row && n > 2 && k > 2 && board[k][n] != ' ' && board[k][n] == board[k - 1][n - 1] && board[k][n] == board[k - 2][n - 2] && board[k][n] == board[k - 3][n - 3])
			{
				return 1;
			}
			else if (n < col - 3 && k > 2 && board[k][n] != ' ' && board[k][n] == board[k - 1][n + 1] && board[k][n] == board[k - 2][n + 2] && board[k][n] == board[k - 3][n + 3])
			{
				return 1;
			}
		}
	}
	return 0;
}

//this func is for choosing heuristic
int ConnectFour::chooseHeuristic()
{
	int choice = 0;

		do
		{
			cout << "Choose one of following heuristics" << endl;
			cout << "  1. Score Strategy (Hard)" << endl;
			cout << "  2. Manhattan Distance (Easy)" << endl;
			cout << "  3. Unknown" << endl;
			cout << endl;
			cin >> choice;

			if(choice < 1 || choice > 3)
			{
				cout<< "Invalid input! Choose again" << endl;
				cout<< endl;
			}
		}while(choice < 1 || choice > 3);
		
	
	return choice;	
}

//this method is used to creating a customized game table
// void ConnectFour::createTest()
// {
// 	test testBoard;
// 	board = testBoard.create();
// 	display();
	//ScoreStrategy t(board);
	//check(row[i], col[i], player)
	// int score = t.check4(3,3,1);
	// cout << score << endl;
// }
