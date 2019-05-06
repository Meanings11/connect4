//
//  ScoreStrategy.cpp
//  connect4
//
//  Created by richen98 on 5/4/19.
//  Copyright © 2019 richen98. All rights reserved.
//

#include "scoreStrategy.hpp"
#include <iostream>

using namespace std;

//Constructor
ScoreStrategy::ScoreStrategy(char** b){
    this->board = b;
    possibility = new predictPossibility[7];
}

//Return the column which the AI decides to play
int ScoreStrategy::guessPlus(){
    for(int i = 0; i < 7; i++){

        char temp [6][7];
        for (int i=0; i<6; i++){
            for (int k=0; k<7; k++){
                temp[i][k] = board[i][k];
            }
        }       

        
        possibility[i].setCol(i+1);       
        possibility[i].setR(chessPosition(i, temp));        
        possibility[i].setPlus(getScore(possibility[i].getR(), i+1, 1));


        if(6-possibility[i].getR() < 0 ){
             possibility[i].setPlus(0);
             possibility[i].setMinus(5000);
             possibility[i].setTotal();
            continue;
        }
        else{
            temp[6-possibility[i].getR()][i] = 'O';

            possibility[i].setMinus(guessMinus(temp));
            possibility[i].setTotal();
        }

    }


    return pickMove();
    
}

//Return the highest score the opponent's next move could get
int ScoreStrategy::guessMinus(char t[6][7]){
    
    
    int* minus = new int[7];
    for (int i = 0; i < 7; i++){
        int r_X = chessPosition(i,t);

        if(6-r_X < 0)
            minus[i] = 0;
        else    
            minus[i] = getScore(r_X, i+1, 0);
    }
    int key = minus[0];
    for (int k = 0; k < 7; k++){
        if (key < minus[k])
            key = minus[k];
    }
    
    return key;
}

//Return the column the Ai decides to drop the chess
int ScoreStrategy::pickMove(){
    
    predictPossibility best;
    for (int i = 0; i < 7; i++){
        if (best.getTotal() < possibility[i].getTotal()){
            best = possibility[i];
        }
    }

    return best.getCol();

}

//Get the total score a chess could get regaring of connect2, connect3 and connect4
int ScoreStrategy::getScore(int a, int b, int player){
    
    int r = 6 - a;
    int c = b - 1;
    
    int score = 0;

    if(r < 0)
        score = 0;
    else
        score = 2 * check2(r, c, player) + 20 * check3(r, c, player) + 1000 * check4(r, c, player);

    return score;
}

//Check the possibility of connecting two chesses
int ScoreStrategy::check2(int r, int c, int player){
    int connect2Count = 0;
    
    char mark;
    if(player == 0)
        mark = 'X';
    else
        mark = 'O';
    
    //There are 8 situations in which a chess can connect with another chess
    if (c < col-1 && board[r][c+1] == mark)
        connect2Count++;
    
    if (c > 0 && board[r][c-1] == mark)
        connect2Count++;
    
    if (r < row-1 && board[r+1][c] == mark)
        connect2Count++;
    
    if (r > 0 && board[r-1][c] == mark)
        connect2Count++;
    
    if (c < col-1 && r > 0 && board[r-1][c+1] == mark)
        connect2Count++;
    
    if (c > 0 && r < row-1 && board[r+1][c-1] == mark)
        connect2Count++;
    
    if (c < col-1 && r < row-1 && board[r+1][c+1] == mark)
        connect2Count++;
    
    if (c >0 && r >0 && board[r-1][c-1] == mark)
        connect2Count++;
    
    return connect2Count;
}

//Check the possibility of connecting three chesses
int ScoreStrategy::check3(int r, int c, int player){
    
    int connect3Count = 0;
    
    char mark;
    if(player == 0)
        mark = 'X';
    else
        mark = 'O';
    
    //There is twelve situations in which a chess could connect with two other chesses and form a connect three. 
    if (c < col-2 && board[r][c+1] == mark && board[r][c+2] == mark)
        connect3Count++;
    
    if (c > 1 && board[r][c-1] == mark && board[r][c-2] == mark)
        connect3Count++;
    
    if (r < row-2 && board[r+1][c] == mark && board[r+2][c] == mark)
        connect3Count++;
    
    if (r > 1 && board[r-1][c] == mark && board[r-2][c] == mark)
        connect3Count++;
    
    if (c < col-2 && r > 1 && board[r-1][c+1] == mark && board[r-2][c+2] == mark)
        connect3Count++;
    
    if (c > 1 && r < row-2 && board[r+1][c-1] == mark && board[r+2][c-2] == mark)
        connect3Count++;
    
    if (c < col-2 && r < row-2&& board[r+1][c+1] == mark && board[r+2][c+2] == mark)
        connect3Count++;
    
    if (c > 1 && r > 1  && board[r-1][c-1] == mark && board[r-2][c-2] == mark)
        connect3Count++;
    
    if (c > 0 && c < col-1 && r > 0 && r < row -1 &&  board[r+1][c-1] == mark && board[r-1][c+1] == mark)
        connect3Count++;
    
    if (r > 0 && r < row -1 && board[r-1][c] == mark && board[r+1][c] == mark)
        connect3Count++;

    if ((c > 0 && c < col-1 && r > 0 && r < row -1 && (board[r+1][c+1] == mark && board[r-1][c-1] == mark)))
        connect3Count++;

    if (c > 0 && c < col-1 && board[r][c-1] == mark && board[r][c+1] == mark)
        connect3Count++;


    if (c < col-3 && c > 0 && board[r][c+1] == mark && board[r][c+2] == mark && (board[r][c+3] != 'X' && board[r][c+3] != 'O') && (board[r][c-1] != 'O' && board[r][c-1] != 'X') ){
        connect3Count += 2;
    }

    //else if (c < col-1 && c > 2 &&  board[r][c-1] == mark && board[r][c-2] == mark && (board[r][c+1] != 'X' && board[r][c+1] != 'O') && (board[r][c-3] != 'X' && board[r][c-3] != 'O'))

    return connect3Count;
}

//Check the possibility of connecting three cheese
int ScoreStrategy::check4(int r, int c, int player){
    
    int connect4Count = 0;
    
    char mark;
    if(player == 0)
        mark = 'X';
    else
        mark = 'O';
    
    //There is sisteen situations in which a chess could connect with three other chesses and form a connect four. 
    if (c < col - 3 && board[r][c + 1] == mark && board[r][c + 2] == mark && board[r][c + 3] == mark)
    {
        connect4Count++;
    }
    if (r < row - 3  && board[r + 1][c] == mark && board[r + 2][c] == mark && board[r + 3][c] == mark)
    {
        connect4Count++;
    }
    if (c < col - 3 && r < row - 3 && board[r + 1][c + 1] == mark && board[r + 2][c + 2] == mark && board[r + 3][c + 3] == mark)
    {
        connect4Count++;
    }
    if (c > 2 && r < row - 3 && board[r + 1][c - 1] == mark && board[r + 2][c - 2] == mark && board[r + 3][c - 3] == mark)
    {
        connect4Count++;
    }
    if (c < col - 3 && r > 2 && board[r - 1][c + 1] == mark && board[r - 2][c + 2] == mark && board[r - 3][c + 3] == mark)
        connect4Count++;
    
    if (c > 0 && c < col - 2 && r > 1 && r < row - 1 && board[r - 1][c + 1] == mark && board[r - 2][c + 2] == mark && board[r+1][c-1] == mark)
        connect4Count++;
    
    if (c > 1 && c < col - 1 && r > 0 && r < row - 2 && board[r - 1][c + 1] == mark && board[r + 2][c - 2] == mark && board[r+1][c-1] == mark)
        connect4Count++;
    
    if (c > 0 && c < col - 2 && r > 0 && r < row - 2 && board[r + 1][c + 1] == mark && board[r + 2][c + 2] == mark && board[r-1][c-1] == mark)
        connect4Count++;
    
    if (c > 1 && c < col - 1 && r > 1 && r < row - 1 && board[r + 1][c + 1] == mark && board[r - 2][c - 2] == mark && board[r-1][c-1] == mark)
        connect4Count++;
    
    if (c > 0 && c < col -2 && board[r][c-1] == mark && board[r][c+1] == mark && board[r][c+2] == mark)
        connect4Count++;

    if (c > 1 && c < col-1 && board[r][c-1] == mark && board[r][c-2] == mark && board[r][c+1] == mark)
        connect4Count++;
    
    if (c > 2 && c < col && board[r][c-1] == mark && board[r][c-2] == mark && board[r][c-3] == mark)
        connect4Count++;
    
    if (r > 2 && r < row && board[r-1][c] == mark && board[r-2][c] == mark && board[r-3][c] == mark)
        connect4Count++;
    
    if (r > 1 && r < row - 1 && board[r+1][c] == mark && board[r-1][c] == mark && board[r-2][c] == mark)
        connect4Count++;

    if (r > 0 && r < row -2 && board[r+1][c] == mark && board[r+2][c] == mark && board[r-1][c] == mark)
        connect4Count++;

    if (r > 2 && r < row && c > 2 && c < col && board[r-1][c-1] == mark && board[r-2][c-2] == mark && board[r-3][c-3] == mark)
        connect4Count++;

    return connect4Count;
}

//Find the row number of the next avaiilable position at a certain column 
int ScoreStrategy::chessPosition(int c, char t[6][7]){


    for (int i = 5; i >= 0 ; i--){
        
        if (t[i][c] != 'X' && t[i][c] != 'O'){

            return 6-i;
        }
    }
    return 10;
}

//Destructor
ScoreStrategy::~ScoreStrategy(){

}
