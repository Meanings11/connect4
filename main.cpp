//
//  main.cpp
//  connect4
//
//  Created by richen98 on 5/3/19.
//  Copyright © 2019 richen98. All rights reserved.
//

#include <iostream>
#include "ConnectFour.h"
#include "predictPossibility.hpp"
using namespace std;


int main(){
    
    cout<<"Welcome to Connect 4 !"<<endl;
    ConnectFour myConnectFour;
    myConnectFour.initialize();
    myConnectFour.playGame();
    
}
