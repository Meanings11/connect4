#ifndef MD_H
#define MD_H

class ManhattanDistance{
	private:
		int bestStep;

	public:
		ManhattanDistance();
		~ManhattanDistance();
		int getMDistance(int, int);
		void pick(std::String[][]);
		bool checkPath(std::String[][], int, int, int);
		int getCost(std::String[][], int, int, int);
};

#endif