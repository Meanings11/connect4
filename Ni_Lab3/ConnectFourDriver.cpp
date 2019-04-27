#include <iostream>
#include "ConnectFour.h"
using namespace std;

int main(){
	
	cout<<"Welcome to Connect 4 !"<<endl;
    ConnectFour myConnectFour;
	myConnectFour.initialize();
	myConnectFour.playGame();
	
}