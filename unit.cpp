#include"unit.h"


units::units()
{
	enableNum = 9;
	for(int i=0; i<10; i++)
		k[i] = true;
}

bool units::deleteNum(int num)
{
	if(k[num])
	{
		k[num] = false;
		if(enableNum!=0)
			enableNum--;
		return true;
	}
		return false;
}

int units::findToPush()
{
	for(int i=1; i<10; i++)
	{
		if(k[i])
			return i;
	}
	return 0;
}


bool units::textEnableNum1()
{
	return (enableNum == 1);
}

bool units::findNum(int num)
{
	return k[num];
}

void units::clearEnableNum()
{
	enableNum = 0;
}

waitUnit::waitUnit(int row, int col, int num)
{
	this->row = row;
	this->col = col;
	this->num = num;
}

int waitUnit::getRow()
{
	return row;
}

int waitUnit::getCol()
{
	return col;
}

int waitUnit::getNum()
{
	return num;
}