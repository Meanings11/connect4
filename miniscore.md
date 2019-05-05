class miniscore{
    private:
        array[] object(col,+,-)
        char** board

    public:    
        getScore()      //连子得分 connect2,3,4, call checkPath(),checkBound()
            checkTwo()
            checkThree()
            checkFour()
            checkBound()    //1<col<7 1<row<6
            checkPath()     //check if at least 4 space in the direction

        guessPlus()     //Ai get plus score, call getScore()
        guessMinus()    //Ai get mius score from players, call getScore()

}

