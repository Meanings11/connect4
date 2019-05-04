#include "ManhattanDistance.h"
#include <iostream>
#include <vector>

using namespace std;

ManhattanDistance::ManhattanDistance(int r, int c){
	bestStep = 0;
	row = r;
	col = c;
}

ManhattanDistance::~ManhattanDistance(){}

int ManhattanDistance::getMDistance(int D, int direction){
	//top
	int dx = 0;
	int dy = 0;
	if(direction == 0){
		dx = 0;
		dy = 3;
	//top right
	}else if(direction == 1){
		dx = 3;
		dy = 3;
	//right
	}else if(direction == 2){
		dx = 3;
		dy = 0;
	//bottom right
	}else if(direction == 3){
		dx = 3;
		dy = 3;
	//bottom left
	}else if(direction == 4){
		dx = 3;
		dy = 3;
	//left
	}else if(direction == 5){
		dx = 3;
		dy = 0;
	//top left
	}else if(direction == 6){
		dx = 3;
		dy = 3;
	}

	return D * (dx + dy);
}

int ManhattanDistance::pick(char** board){
	int D = 0;
	int** tempA = new int*[200];
	for(int i = 0; i < 200; i++){
		tempA[i] = new int[4];
	}
	int rCount = 0;
	int ifFRound = 0;

	//find every AI's chess as a start point
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(board[i][j] == 'X'){
				ifFRound = 1;
				//when find 1 chess, find all possible path to connect 4 pieces
				//then calculate and store all manhattan distances, original
				//(x,y) and direction into a temp array tempA
				for(int k = 0; k < 7; k++){
					if(checkPath(board, i, j, k) == true){
						D = getCost(board, i, j, k);
						tempA[rCount][0] = i;
						tempA[rCount][1] = j;
						tempA[rCount][2] = k;
						tempA[rCount][3] = getMDistance(D, k);
						rCount++;					
					}
				}
			}
		}
	}

	//check if it is the 1st round, if it is, suggest the default step
	if(ifFRound == 0){
		bestStep = 3;
	}else{
		//compare all manhattan values stored, find the best one
		for(int i = 0; i < rCount; i++){
			if(tempA[i][3] < tempA[rCount][3]){
				rCount = i;
			}
		}

		//calculate the best step
		int x = 0;
		int y = 0;
		//top
		if(tempA[rCount][2] == 0){
			bestStep = tempA[rCount][0];
		//top right
		}else if(tempA[rCount][2] == 1){
			x = tempA[rCount][0];
			y = tempA[rCount][1];
			if(board[x+1][y-1] != 'X'){
				bestStep = x + 1;
			}else{
				if(board[x+2][y-2] != 'X'){
					bestStep = x + 2;
				}else{
					bestStep = x + 3;
				}
			}
		//right
		}else if(tempA[rCount][2] == 2){
			x = tempA[rCount][0];
			y = tempA[rCount][1];
			if(board[x+1][y] != 'X'){
				bestStep = x + 1;
			}else{
				if(board[x+2][y] != 'X'){
					bestStep = x + 2;
				}else{
					bestStep = x + 3;
				}
			}
		//buttom right
		}else if(tempA[rCount][2] == 3){
			x = tempA[rCount][0];
			y = tempA[rCount][1];
			if(board[x+1][y+1] != 'X'){
				bestStep = x + 1;
			}else{
				if(board[x+2][y+2] != 'X'){
					bestStep = x + 2;
				}else{
					bestStep = x + 3;
				}
			}
		//bottom left
		}else if(tempA[rCount][2] == 4){
			x = tempA[rCount][0];
			y = tempA[rCount][1];
			if(board[x-1][y+1] != 'X'){
				bestStep = x - 1;
			}else{
				if(board[x-2][y+2] != 'X'){
					bestStep = x - 2;
				}else{
					bestStep = x - 3;
				}
			}
		//left
		}else if(tempA[rCount][2] == 5){
			x = tempA[rCount][0];
			y = tempA[rCount][1];
			if(board[x-1][y] != 'X'){
				bestStep = x - 1;
			}else{
				if(board[x-2][y] != 'X'){
					bestStep = x - 2;
				}else{
					bestStep = x - 3;
				}
			}
		//top left
		}else if(tempA[rCount][2] == 6){
			x = tempA[rCount][0];
			y = tempA[rCount][1];
			if(board[x-1][y-1] != 'X'){
				bestStep = x - 1;
			}else{
				if(board[x-2][y-2] != 'X'){
					bestStep = x - 2;
				}else{
					bestStep = x - 3;
				}
			}
		}
	}

	return bestStep;
}

//check if inputing direction has enough room for 4 pieces and has enemy's chess
bool ManhattanDistance::checkPath(char** board, int x, int y, int direction){
	//top
	if(direction == 0){
		//check if this path has enough room for 4 pieces
		if(y < 3){
			return false;
		}

		//check if this path has enemy's chess
		for(int i = 1; i < 4; i++){
			if(board[x][y-i] == 'O'){
				return false;
			}
		}
	//top right
	}else if(direction == 1){
		//check if this path has enough room for 4 pieces
		if(x > 4 || y < 3){
			return false;
		}

		//check if this path has enemy's chess
		for(int i = 1; i < 4; i++){
			if(board[x+i][y-i] == 'O'){
				return false;
			}
		}
	//right
	}else if(direction == 2){
		//check if this path has enough room for 4 pieces
		if(x > 4){
			return false;
		}

		//check if this path has enemy's chess
		for(int i = 1; i < 4; i++){
			if(board[x+i][y] == 'O'){
				return false;
			}
		}
	//bottom right
	}else if(direction == 3){
		//check if this path has enough room for 4 pieces
		if(x > 4 || y > 4){
			return false;
		}

		//check if this path has enemy's chess
		for(int i = 1; i < 4; i++){
			if(board[x+i][y+i] == 'O'){
				return false;
			}
		}
	//bottom left
	}else if(direction == 4){
		//check if this path has enough room for 4 pieces
		if(x < 3 || y > 4){
			return false;
		}

		//check if this path has enemy's chess
		for(int i = 1; i < 4; i++){
			if(board[x-i][y+i] == 'O'){
				return false;
			}
		}
	//left
	}else if(direction == 5){
		//check if this path has enough room for 4 pieces
		if(x < 3){
			return false;
		}

		//check if this path has enemy's chess
		for(int i = 1; i < 4; i++){
			if(board[x-i][y] == 'O'){
				return false;
			}
		}
	//top left
	}else if(direction == 6){
		//check if this path has enough room for 4 pieces
		if(x < 3 || y < 3){
			return false;
		}

		//check if this path has enemy's chess
		for(int i = 1; i < 4; i++){
			if(board[x-i][y-i] == 'O'){
				return false;
			}
		}
	}

	return true;
}

//get the number of steps cost to connect 4 pieces in inputing direction
int ManhattanDistance::getCost(char** board, int x, int y, int direction){
	int D = 0;
	int temp = 0; 
	//top
	if(direction == 0){
		D = 3;
	//top right
	}else if(direction == 1){
		//check cost from (x,y) to (x+1,y-1)
		for(int i = y - 1; i < 8; i++){
			if(board[x+1][i] == 'X' || board[x+1][i] == 'O'){
				temp = 8 - i;
				break;
			}
		}
		if(temp == 0){
			D = D + (8 - (y - 1));
		}else{
			D = D + temp;
		}
		temp = 0;

		//check cost from (x,y) to (x+2,y-2)
		for(int i = y - 2; i < 8; i++){
			if(board[x+2][i] == 'X' || board[x+2][i] == 'O'){
				temp = 8 - i;
				break;
			}
		}
		if(temp == 0){
			D = D + (8 - (y - 2));
		}else{
			D = D + temp;
		}
		temp = 0;

		//check cost from (x,y) to (x+3,y-3)
		for(int i = y - 3; i < 8; i++){
			if(board[x+3][i] == 'X' || board[x+3][i] == 'O'){
				temp = 8 - i;
				break;
			}
		}
		if(temp == 0){
			D = D + (8 - (y - 3));
		}else{
			D = D + temp;
		}
		temp = 0;
	//right
	}else if(direction == 2){
		//check cost from (x,y) to (x+1,y)
		for(int i = y; i < 8; i++){
			if(board[x+1][i] == 'X' || board[x+1][i] == 'O'){
				temp = 8 - i;
				break;
			}
		}
		if(temp == 0){
			D = D + (8 - y);
		}else{
			D = D + temp;
		}
		temp = 0;

		//check cost from (x,y) to (x+2,y)
		for(int i = y; i < 8; i++){
			if(board[x+2][i] == 'X' || board[x+2][i] == 'O'){
				temp = 8 - i;
				break;
			}
		}
		if(temp == 0){
			D = D + (8 - y);
		}else{
			D = D + temp;
		}
		temp = 0;

		//check cost from (x,y) to (x+3,y)
		for(int i = y; i < 8; i++){
			if(board[x+3][i] == 'X' || board[x+3][i] == 'O'){
				temp = 8 - i;
				break;
			}
		}
		if(temp == 0){
			D = D + (8 - y);
		}else{
			D = D + temp;
		}
		temp = 0;
		//bottom right
	}else if(direction == 3){
		//check cost from (x,y) to (x+1,y+1)
		for(int i = y + 1; i < 8; i++){
			if(board[x+1][i] == 'X' || board[x+1][i] == 'O'){
				temp = 8 - i;
				break;
			}
		}
		if(temp == 0){
			D = D + (8 - (y + 1));
		}else{
			D = D + temp;
		}
		temp = 0;

		//check cost from (x,y) to (x+2,y+2)
		for(int i = y + 2; i < 8; i++){
			if(board[x+2][i] == 'X' || board[x+2][i] == 'O'){
				temp = 8 - i;
				break;
			}
		}
		if(temp == 0){
			D = D + (8 - (y + 2));
		}else{
			D = D + temp;
		}
		temp = 0;

		//check cost from (x,y) to (x+3,y+3)
		for(int i = y + 3; i < 8; i++){
			if(board[x+3][i] == 'X' || board[x+3][i] == 'O'){
				temp = 8 - i;
				break;
			}
		}
		if(temp == 0){
			D = D + (8 - (y + 3));
		}else{
			D = D + temp;
		}
		temp = 0;
	//bottom left
	}else if(direction == 4){
		//check cost from (x,y) to (x-1,y+1)
		for(int i = y + 1; i < 8; i++){
			if(board[x-1][i] == 'X' || board[x-1][i] == 'O'){
				temp = 8 - i;
				break;
			}
		}
		if(temp == 0){
			D = D + (8 - (y + 1));
		}else{
			D = D + temp;
		}
		temp = 0;

		//check cost from (x,y) to (x-2,y+2)
		for(int i = y + 2; i < 8; i++){
			if(board[x-2][i] == 'X' || board[x-2][i] == 'O'){
				temp = 8 - i;
				break;
			}
		}
		if(temp == 0){
			D = D + (8 - (y + 2));
		}else{
			D = D + temp;
		}
		temp = 0;

		//check cost from (x,y) to (x-3,y+3)
		for(int i = y + 3; i < 8; i++){
			if(board[x-3][i] == 'X' || board[x-3][i] == 'O'){
				temp = 8 - i;
				break;
			}
		}
		if(temp == 0){
			D = D + (8 - (y + 3));
		}else{
			D = D + temp;
		}
		temp = 0;
	//left
	}else if(direction == 5){
		//check cost from (x,y) to (x-1,y)
		for(int i = y; i < 8; i++){
			if(board[x-1][i] == 'X' || board[x-1][i] == 'O'){
				temp = 8 - i;
				break;
			}
		}
		if(temp == 0){
			D = D + (8 - y);
		}else{
			D = D + temp;
		}
		temp = 0;

		//check cost from (x,y) to (x-2,y)
		for(int i = y; i < 8; i++){
			if(board[x-2][i] == 'X' || board[x-2][i] == 'O'){
				temp = 8 - i;
				break;
			}
		}
		if(temp == 0){
			D = D + (8 - y);
		}else{
			D = D + temp;
		}
		temp = 0;

		//check cost from (x,y) to (x-3,y)
		for(int i = y; i < 8; i++){
			if(board[x-3][i] == 'X' || board[x-3][i] == 'O'){
				temp = 8 - i;
				break;
			}
		}
		if(temp == 0){
			D = D + (8 - y);
		}else{
			D = D + temp;
		}
		temp = 0;
	//top left
	}else if(direction == 6){
		//check cost from (x,y) to (x-1,y-1)
		for(int i = y - 1; i < 8; i++){
			if(board[x-1][i] == 'X' || board[x-1][i] == 'O'){
				temp = 8 - i;
				break;
			}
		}
		if(temp == 0){
			D = D + (8 - (y - 1));
		}else{
			D = D + temp;
		}
		temp = 0;

		//check cost from (x,y) to (x-2,y-2)
		for(int i = y - 2; i < 8; i++){
			if(board[x-2][i] == 'X' || board[x-2][i] == 'O'){
				temp = 8 - i;
				break;
			}
		}
		if(temp == 0){
			D = D + (8 - (y - 2));
		}else{
			D = D + temp;
		}
		temp = 0;

		//check cost from (x,y) to (x-3,y-3)
		for(int i = y - 3; i < 8; i++){
			if(board[x-3][i] == 'X' || board[x-3][i] == 'O'){
				temp = 8 - i;
				break;
			}
		}
		if(temp == 0){
			D = D + (8 - (y - 3));
		}else{
			D = D + temp;
		}
		temp = 0;
	}

	return D;
}

int ManhattanDistance::getRow(){
	return row;
}

int ManhattanDistance::getCol(){
	return col;
}
