#include <iostream>
#include <string>
#include "ConnectFour.h"
using namespace std;



void ConnectFour::initialize(){
	for(int i=0; i<row; i++){
		for(int k=0; k<column; k++){
			board[i][k] = ' ';
		}
	}
}


void ConnectFour::display(){

	
	
	cout<<" 1 2 3 4 5 6 7"<<endl;
	for(int i=0; i<row; i++){
		for(int k=0; k<column; k++){
			cout<<"|"<<board[i][k];
		}
		cout<<"|"<<endl;
	}
	cout<<"==============="<<endl;

	//playGame();
}
void ConnectFour::playGame(){
	int player1Choice;
	int player2Choice;
	int m;
	int n;
	int check;
	display();
	do{
		cout<<"Player 1, choose a column(1-7): ";
	    cin>>player1Choice;
	    while(player1Choice<1 || player1Choice>7){
	    	cout<<"Invalid input"<<endl;
	    	cout<<"Player 1, choose a column(1-7): ";
	        cin>>player1Choice;
	    }
	    counter++;
	    for( m=row-1; m>=0; m--){
			if(board[m][player1Choice-1]!=' '){
				cout << "m="<< m << endl;
				continue;
			}else{
				break;
			}
			  
	    }
	    board[m][player1Choice-1]='X';
	    check = checkWinner();
	    if (check==1){
		    display();
		    cout<<"Player 1 wins !"<<endl;
		   exit(0);
	    }else{
	    	display();
	    }
	   
	    cout<<"Player 2, choose a column(1-7): ";
	    cin>>player2Choice;
	    while(player2Choice<1 || player2Choice>7){
	    	cout<<"Invalid input"<<endl;
	    	cout<<"Player 2, choose a column(1-7): ";
	        cin>>player2Choice;
	    }
	    counter++;
	    for(n=row-1; n>=0; n--){
		   if(board[n][player2Choice-1]!=' '){
			   cout << "n="<< n << endl;
			   continue;
		   }else{
		   	  break;			   
		   }
	    }
	    board[n][player2Choice-1]='O';
	    check = checkWinner();
	    if (check==1){
	    	display();
		     cout<<"Player 2 wins !"<<endl;
		     exit(0);
	    }else{
	    	display();
	     }
	    
    }while(counter<=row*column);
    cout<<"Tie !"<<endl;
    exit(0);


}

int ConnectFour::checkWinner(){
	for(int k=0; k<row; k++){
		for(int n=0; n<column; n++){
			
			if(n<column-3 && board[k][n]!=' ' && board[k][n]==board[k][n+1] && board[k][n]==board[k][n+2] && board[k][n]==board[k][n+3]){
				return 1;
			}else if (k<row-3 && board[k][n]!=' ' && board[k][n]==board[k+1][n] && board[k][n]==board[k+2][n] && board[k][n]==board[k+3][n]){
				return 1;
			}else if (n<column-3 && k<row-3 && board[k][n]!=' ' && board[k][n]==board[k+1][n+1] && board[k][n]==board[k+2][n+2] && board[k][n]==board[k+3][n+3]){
				return 1;
			}else if (n<column-3 && k<row-3 && board[k][n]!=' ' && board[k][n]==board[k+1][n-1] && board[k][n]==board[k+2][n-2] && board[k][n]==board[k+3][n-3]){
				return 1;
			}
		}
	}
	return 0;
}