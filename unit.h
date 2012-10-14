#include<iostream>
#include<vector>
#include<list>

using namespace std;

class units
{
public:
	units();
	bool deleteNum(int num);
	bool textEnableNum1();
	bool findNum(int num);    //  返回该空格是否可以填这个数
	int findToPush();       // 当空格只剩一个可填数时
	void clearEnableNum();
private:
	int enableNum;
	bool  k[10];
};

class waitUnit
{
public:
	waitUnit(int row, int col, int num);
	int getRow();
	int getCol();
	int getNum();
private:
	int row;
	int col;
	int num;
};
