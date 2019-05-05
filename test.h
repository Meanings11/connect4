#ifndef HEADER_FILE
#define HEADER_FILE

class test{
    private: 
        int playerKey;
        int aiKey;
        int col = 7;
        int row = 6;
        // char testBoard[6][7];

    public:
        char** create();
        char** generate();
};
#endif