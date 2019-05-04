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
		int getCost(std::string**, int, int, int);

		int pick(std::string**);
		bool checkPath(std::string**, int, int, int);

		int getRow();
		int getCol();

};

#endif