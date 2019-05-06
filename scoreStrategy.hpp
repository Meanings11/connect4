//
//  scoreStrategy.hpp
//  connect4
//
//  Created by richen98 on 5/4/19.
//  Copyright © 2019 richen98. All rights reserved.
//

#ifndef scoreStrategy_hpp
#define scoreStrategy_hpp

#include <stdio.h>
#include "predictPossibility.hpp"
class ScoreStrategy {
    
    private:
        predictPossibility* possibility;
        char** board;

        int col = 7;
        int row = 6;
    
    public:
        ScoreStrategy(char**);
        ~ScoreStrategy();
        
        int guessPlus();
        int guessMinus(char[6][7]);
        int getScore(int, int, int);
        int check2(int, int , int);
        int check3(int, int, int);
        int check4(int, int, int);
        
        int chessPosition(int, char[6][7]);
        int pickMove ();
    
};

#endif /* scoreStrategy_hpp */
