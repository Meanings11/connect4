#ifndef MD_H
#define MD_H
#include <string>

class ManhattanDistance{
	private:
		int bestStep;
		int row;
		int col;

	public:
		ManhattanDistance(int, int);
		~ManhattanDistance();

		int getMDistance(int, int);
		int getCost(char**, int, int, int);

		int pick(char**);
		bool checkPath(char**, int, int, int, int);

		int defense(char**, int, int, int);

		int getRow();
		int getCol();
};

#endif
