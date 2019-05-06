//
//  predictPossibility.cpp
//  connect4
//
//  Created by richen98 on 5/4/19.
//  Copyright © 2019 richen98. All rights reserved.
//

#include "predictPossibility.hpp"

//Constructor
predictPossibility::predictPossibility(){
    this->r_O = 0;
    
    this->col = 0;
    this->plus = 0;
    this->minus = 0;
    this->total = -1100;
}

//Set the column
void predictPossibility::setCol(int c){
    this->col = c;
}

//Set the score the player's move could get
void predictPossibility::setPlus(int p){
    this->plus = p;
}

//Set the score the opponent's next move could get
void predictPossibility::setMinus(int m){
    this->minus = m;
}

//Set the total socre of a player's current move
void predictPossibility::setTotal(){
    this->total = this->plus - this->minus;
    if (this->col == 4)
        this->total += 4;
    if (this->col == 3 || this->col == 5)
        this->total += 3;
}

//Set the number of row at which a player could drop a chess at the column
void predictPossibility::setR(int r){
    this->r_O = r;
}

//Get the number of row at which a player could drop a chess at the column
int predictPossibility::getR(){
    return this->r_O;
}

//Get the column
int predictPossibility::getCol(){
    return this->col;
}

//Get the score the player's move could get
int predictPossibility::getPlus(){
    return this->plus;
}

//Get the score the opponent's next move could get
int predictPossibility::getMinus(){
    return this->minus;
}

//Set the total socre of a player's current move
int predictPossibility::getTotal(){
    return this->total;
}

//Overloading operator assignment
predictPossibility& predictPossibility::operator = (const predictPossibility& p){
    this->col = p.col;
    this->plus = p.plus;
    this->minus = p.minus;
    this->total = p.total;
    this->r_O = p.r_O;
    return *this;
}
