//
//  predictPossibility.hpp
//  connect4
//
//  Created by richen98 on 5/4/19.
//  Copyright © 2019 richen98. All rights reserved.
//

#ifndef predictPossibility_hpp
#define predictPossibility_hpp

#include <stdio.h>
class predictPossibility {
    private:
        int col;
        int plus;
        int minus;
        int total;
    public:
        predictPossibility();
        void setCol (int);
        void setPlus (int);
        void setMinus (int);
        int getCol ();
        int getPlus ();
        int getMinus ();
        int getTotal();
        predictPossibility& operator = (const predictPossibility&);
    
    
};

#endif /* predictPossibility_hpp */
