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
        int r_O;
        int col = 7;
        int row = 6;
    public:
        ScoreStrategy(char**);
        ~ScoreStrategy();
        void guessPlus();
        int guessMinus(char**);
        int getScore(int, int, int);
        bool check2(int, int , int);
        bool check3(int, int, int);
        bool check4(int, int, int);
        bool checkBound();
        bool checkPath();
        int chessPosition(int, char**);
        void pickMove ();
    
};

#endif /* scoreStrategy_hpp */
