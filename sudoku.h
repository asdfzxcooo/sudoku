#include"unit.h"
#include<iostream>
#include<vector>
#include<list>

class sudoku
{
public:
	sudoku();
	bool setNum(int row, int col, int num);
    bool disEnable(int row, int col, int num);
	void textCount();
	void testRowCount(int num, int row);
	void testColCount(int num, int col);
	void testAreaCount(int num, int area);
	void print();
	void setAdd();
	bool trySetAdd();
	bool isProgramOver();
	bool trial( int id );
private:
	int final[9][9];
	int rowCount[10][9];
	int colCount[10][9];
	int areaCount[10][9];
	units u[9][9];
	list<waitUnit> add;
};