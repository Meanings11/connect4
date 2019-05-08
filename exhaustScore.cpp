#include "exhaustScore.h"
#include <iostream>
using namespace std;
//a[0]
//a[i][j]=0
//a[i][j]=1

ExhaustScore::ExhaustScore(char** b){
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            board[i][j] = b[i][j];
        }
    }
    for (int i = 0; i < 7; i++)
        score[i] = 0;
}

ExhaustScore::~ExhaustScore(){}


void ExhaustScore::DFS(int curr_P,int ancestor){
    int flag = 0;
    for(int i=0;i<7;i++){
        for(int j=5;j>=0;j--){
            if(board[j][i]== ' '){
                if(curr_P%2==0){
                    board[j][i]='O';
                }else{
                    board[j][i]='X';
                }
            }
            else {
                continue;
            }
            if(checkWinner(6,7)==1&&curr_P%2==0){
                score[ancestor]+=1;
                board[j][i] = ' ';
                flag = 1;
                break;//if judge()1，score[ancestor]+1, start another new search
            }
            else if(checkWinner(6, 7)==1&&curr_P%2==1){
                score[ancestor]-=1;
                board[j][i] = ' ';
                flag = 1;
                break;
            }
            else if(checkWinner(6, 7)==-1){
                DFS(curr_P + 1, ancestor);      //recursively call DFS(curr_P+1) if game is not over
                board[j][i] = ' ';
                break;
            }
            else {
                board[j][i] = ' ';
            }
        }
        if (flag)
            break;
    }
}

int ExhaustScore::AIchoice(){ //send score[]
    run();
    int high = -100000;
    int choice = 0;
    for(int i=0; i<7; i++){
        if (score[i] >= high) {
            choice = i;
            high = score[i];
        }
    }
    return choice+1; //return AI choice of column
}

void ExhaustScore::run(){
    int i, j;
    for(i=0;i<7;i++){
        for (j = 5; j >= 0; j--) {
            if (board[j][i] == ' ')
            {
                board[j][i] = 'O';
                break;
            }
        }
        if (j == -1)
            break;
        DFS(1,i);
        board[j][i] = ' ';
    }
}

int ExhaustScore::checkWinner(int row,int col)
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
    for (int k = 0; k < row; k++)
    {
        for (int n = 0; n < col; n++)
        {
            if (board[k][n] == ' ')
                return -1;
        }
    }
    return 0;
}
