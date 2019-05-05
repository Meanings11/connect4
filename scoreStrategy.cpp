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

ScoreStrategy::ScoreStrategy(char** b){
    this->board = b;
    possibility = new predictPossibility[7];


}

void ScoreStrategy::guessPlus(){
    for(int i = 0; i < 7; i++){

        // char** temp = new char*[6];
        // for (int i=0; i<6; i++){
        //     temp [i] = new char[7];
        // }
        
        // for (int i=0; i<6; i++){
        //     for (int k=0; k<7; k++){
        //         temp[i][k] = board[i][k];
        //     }
        // }

        char temp [6][7];
        for (int i=0; i<6; i++){
            for (int k=0; k<7; k++){
                temp[i][k] = board[i][k];
            }
        }       

        for (int i=0; i<6; i++){
                for (int k=0; k<7; k++){
                    cout << board[i][k];
                }
            }
        cout << endl;

        //cout << temp [4][0] <<endl;

        possibility[i].setCol(i+1);       
        possibility[i].setR(chessPosition(i, temp));
        
        //cout << possibility[i].getR() <<endl;

        possibility[i].setPlus(getScore(possibility[i].getR(), i+1, 1));

        temp[6-possibility[i].getR()][i] = 'O';

        possibility[i].setMinus(guessMinus(temp));
        possibility[i].setTotal();
        
        // for(int i=0; i<6; i++){
        //     delete[] temp[i];
        // }
        
        // delete[] temp;

    }


    pickMove();
    
}

int ScoreStrategy::guessMinus(char t[6][7]){//char** t){
    
    // for (int i=0; i<6; i++){
    //     for (int k=0; k<7; k++){
    //         if (t[i][k] == 'O'){
    //             cout << i <<endl;
    //             cout << k <<endl;
    //         }
    //     }
    // }
    
    int* minus = new int[7];
    for (int i = 0; i < 7; i++){
        int r_X = chessPosition(i,t);
        minus[i] = getScore(r_X, i+1, 0);
    }
    int key = minus[0];
    for (int k = 0; k < 7; k++){
        if (key < minus[k])
            key = minus[k];
    }
    
    return key;
}

void ScoreStrategy::pickMove(){
    
    predictPossibility best;
    for (int i = 0; i < 7; i++){
        cout << possibility[i].getTotal() <<endl;
        if (best.getTotal() < possibility[i].getTotal()){
            best = possibility[i];
        }
    }

    //cout << best.getCol() <<endl;
    cout << best.getR() <<endl;
    board[6-best.getR()][best.getCol()-1] = 'O';

    // for (int i=0; i<6; i++){
    //     for (int k=0; k<7; k++){
    //         cout << board[i][k];
    //     }
    // }
    // cout << endl;

    //cout << board[6-best.getR()][best.getCol()] <<endl;
}

int ScoreStrategy::getScore(int a, int b, int player){
    
    int r = 6 - a;
    int c = b - 1;
    
    int score = 0;

    score = 2 * check2(r, c, player) + 20 * check3(r, c, player) + 1000 * check4(r, c, player);
    

    return score;
}

int ScoreStrategy::check2(int r, int c, int player){
    int connect2Count = 0;
    
    char mark;
    if(player == 0)
        mark = 'X';
    else
        mark = 'O';
    
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
    
    if (c < col-1 && r < row-1 && board[r-1][c-1] == mark)
        connect2Count++;
    
    return connect2Count;
}

int ScoreStrategy::check3(int r, int c, int player){
    
    int connect3Count = 0;
    
    char mark;
    if(player == 0)
        mark = 'X';
    else
        mark = 'O';
    
    
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

    return connect3Count;
}

int ScoreStrategy::check4(int r, int c, int player){
    
    int connect4Count = 0;
    
    char mark;
    if(player == 0)
        mark = 'X';
    else
        mark = 'O';
    
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
    
    if (c > 0 && c < col - 2 && r > 1 && r < row - 1 && board[r - 1][c + 1] == mark && board[r - 2][c + 2] == mark && board[r+1][c-1])
        connect4Count++;
    
    if (c > 1 && c < col - 1 && r > 0 && r < row - 2 && board[r - 1][c + 1] == mark && board[r + 2][c - 2] == mark && board[r+1][c-1])
        connect4Count++;
    
    if (c > 0 && c < col - 2 && r > 0 && r < row - 2 && board[r + 1][c + 1] == mark && board[r + 2][c + 2] == mark && board[r-1][c-1])
        connect4Count++;
    
    if (c > 1 && c < col - 1 && r > 1 && r < row - 1 && board[r + 1][c + 1] == mark && board[r - 2][c - 2] == mark && board[r-1][c-1])
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

bool ScoreStrategy::checkBound(){
    return true;
}

bool ScoreStrategy::checkPath(){
    return true;
}

int ScoreStrategy::chessPosition(int c, char t[6][7]){//char** t){


    for (int i = 5; i >= 0 ; i--){
        
        if (t[i][c] != 'X' && t[i][c] != 'O'){

            return 6-i;
        }
        // continue;
    }
    return 10;
}

ScoreStrategy::~ScoreStrategy(){
    delete [] board;
}
