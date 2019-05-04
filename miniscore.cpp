

miniscore::miniscore(char** b){
    board = b;
}

int miniscore::getScore(int a, int b, int player){

    int r = 6 - a;
    int c = b - 1;


    int score = 0;
    
    score = 2 * check2(r, c, player) + 20 * check3(r, c, player) + 1000 * check4(r, c, player);

    return score; 
}

int miniscore::check2(int a, int b, int player){

    int connect2Count = 0;

    char mark;
    if(player == 0)
        mark = 'X';
    else
        mark = 'O';
    

    if (c < col-1 && board[r][c+1] == mark)
        connect2Count++;
    
    else if (c > 0 && board[r][c-1] == mark)
        connect2Count++;

    else if (r < row-1 && board[r+1][c] == mark)
        connect2Count++;
    
    else if (r > 0 && board[r-1][c] == mark)
        connect2Count++;
    
    else if (c < col-1 && r > 0 && board[r-1][c+1] == mark)
        connect2Count++;

    else if (c > 0 && r < row-1 && board[r+1][c-1] == mark)
        connect2Count++;

    else if (c > 0 && r > 0 && board[r+1][c+1] == mark)
        connect2count++;
    
    else if (c < col-1 && r < row-1 && board[r-1][c-1] == mark)
        connect2count++;

    return connect2Count;
}

int miniscore::check3(int c, int r, int player){

    int connect3Count = 0;

    char mark;
    if(player == 0)
        mark = 'X';
    else
        mark = 'O';


    if (c < col-2 && board[r][c+1] == mark && board[r][c+2] == mark)
        connect3Count++;
    
    else if (c > 1 && board[r][c-1] == mark && board[r][c-2] == mark)
        connect3Count++;

    else if (r < row-2 && board[r+1][c] == mark && board[r+2][c] == mark)
        connect3Count++;
    
    else if (r > 1 && board[r-1][c] == mark && board[r-2][c] == mark)
        connect3Count++;
    
    else if (c < col-2 && r > 1 && board[r-1][c+1] == mark && board[r-2][c+2] == mark)
        connect3Count++;

    else if (c > 1 && r < row-2 && board[r+1][c-1] == mark && board[r+2][c-2] == mark)
        connect3Count++;

    else if (c > 1 && r > 1 && board[r+1][c+1] == mark && board[r+2][c+2] == mark)
        connect3count++;
    
    else if (c < col-2 && r < row-2 && board[r-1][c-1] == mark && board[r-2][c-2] == mark)
        connect3count++;

    else if (c > 0 && c < col-1 && r > 0 && r < row -1 && (board[r+1][c+1] == mark && board[r-1][c-1] == mark) || (board[r+1][c+1] == mark && board[r-1][c-1] == mark) )
        connect3count++;


    return connect3Count;
}


int miniscore::check4(int c, int r, int player){

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
			else if (r < row - 3  && board[r + 1][c] == mark && board[r + 2][c] == mark && board[r + 3][c] == mark)
			{
				connect4Count++;
			}
			else if (c < col - 3 && r < row - 3 && board[r + 1][c + 1] == mark && board[r + 2][c + 2] == mark && board[r + 3][c + 3] == mark)
			{
				connect4Count++;
			}
			else if (c > 2 && r < row - 3 && board[r + 1][c - 1] == mark && board[r + 2][c - 2] == mark && board[r + 3][c - 3] == mark)
			{
				connect4Count++;
			}
            else if (c < col - 3 && r > 2 && board[r - 1][c + 1] == mark && board[r - 2][c + 2] == mark && board[r - 3][c + 3] == mark)
                connect4Count++;
            
            else if (c > 0 && c < col - 2 && r > 1 && r < row - 1 && board[r - 1][c + 1] == mark && board[r - 2][c + 2] == mark && board[r+1][c-1])
                connect4Count++;

            else if (c > 1 && c < col - 1 && r > 0 && r < row - 2 && board[r - 1][c + 1] == mark && board[r + 2][c - 2] == mark && board[r+1][c-1])
                connect4Count++;

            else if (c > 0 && c < col - 2 && r > 0 && r < row - 2 && board[r + 1][c + 1] == mark && board[r + 2][c + 2] == mark && board[r-1][c-1])
                connect4Count++;

            else if (c > 1 && c < col - 1 && r > 1 && r < row - 1 && board[r + 1][c + 1] == mark && board[r - 2][c - 2] == mark && board[r-1][c-1])
                connect4Count++;

        return connect4Count;

}



}
