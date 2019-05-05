//it's a test case for testing heuristic function
#include <iostream>
#include "test.h"
using namespace std;



char** test::create()
{
    char testBoard[6][7] = 
    {   
        {' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ','O',' ',' ',' '},
        {' ',' ','O',' ',' ',' ',' '},
        {' ',' ','O','O',' ',' ',' '},
        {' ',' ','O','O',' ',' ',' '}
    };

    char** newBoard = new char*[row];

    for(int i =0; i < row; i++){
        newBoard[i] = new char [col];
    }

    for (int i = 0; i < row; i++)
	{
       
		for (int k = 0; k < col; k++)
		{
           
			newBoard[i][k] = testBoard[i][k];
		}
	}

    return newBoard;
}

char** test::generate()
{

}

