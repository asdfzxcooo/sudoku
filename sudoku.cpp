#include"sudoku.h"



sudoku::sudoku()
{
	for(int i=0; i<9; i++)
		{
			for(int j=0; j<9; j++)
			{
				final[i][j] = 0;
			
			rowCount[i+1][j] = 9;
			colCount[i+1][j] = 9;
			areaCount[i+1][j] = 9;
			}
	}

}

bool sudoku::setNum(int row, int col, int num)
{
	int q = final[row][col];
	;
	if(final[row][col]!=0 && final[row][col]==num)
		return true;
	else if(final[row][col] != 0)
		return false;
	else if(rowCount[num][row]==0 || colCount[num][col]==0 || areaCount[num][row/3 *3+col/3] == 0)
		return false;
	else 
		final[row][col] = num;
	
	rowCount[num][row] = 0;     // 对该数的行列区的计数置为0
	colCount[num][col] = 0;
	areaCount[num][row/3 *3+col/3] = 0;
	u[row][col].clearEnableNum();
	for(int i=0; i<9; i++)     
	{

		disEnable(row, col, i+1);   // 删除该单元上所有可填的数
	}
	for(int i=0; i<9; i++)
	{
		disEnable(row, i, num);
		disEnable(i, col, num);
		disEnable(row/3 *3+i/3 , col/3 *3+i%3, num);
	}
    //this->print();
	//cout<<endl;
	return true;

}

bool sudoku::disEnable(int row, int col, int num) // 删除一个unit内可填的某个数的操作
{
	if(u[row][col].deleteNum(num))
	{
		if(rowCount[num][row]!=0)         // 一个可填数少掉时对行列区的Count操作
		{
			rowCount[num][row]--; 
			testRowCount(num, row);
		}
		if(colCount[num][col]!=0)
		{
			colCount[num][col]--;
			testColCount(num, col);
		}
		if(areaCount[num][row/3 *3+col/3]!=0)
		{
			areaCount[num][row/3 *3+col/3]--;
			testAreaCount(num, row/3 *3+col/3);
		}
		if(u[row][col].textEnableNum1())
			add.push_back( waitUnit(row, col, u[row][col].findToPush() ) );
		return true;
	}
	else
		return false;
	
}

void sudoku::testRowCount(int num, int row)
{
	if(rowCount[num][row] == 1)
	{
		for(int i=0; i<9; i++)
			if( u[row][i].findNum(num) )
			{
				add.push_back( waitUnit(row, i, num) );
				return;
			}
	}
	if(rowCount[num][row] == 2)
	{
		int col[2]= {0,0};
		for(int i=0; i<9&&!col[1]; i++)
		{
			if(u[row][i].findNum(num))
			{
				if(col[0])
					col[1] = i;
				else
					col[0] = i;
			}
			
		}
		if(col[0]/3 == col[1]/3)
		{
			int i = 0;
			while(areaCount[num][row/3 *3+col[0]/3]!=2 && i<9)
			{
				int r = row/3 *3 + i/3;
				int c = col[0]/3 *3 + i%3;
				if(u[r][c].findNum(num)&& r!=row )
					disEnable(r,c,num);
				i++;
			}
		}
	}
}

void sudoku::testColCount(int num, int col)
{
	if(colCount[num][col] == 1)
	{
		for(int i=0; i<9; i++)
			if( u[i][col].findNum(num) )
			{
				add.push_back( waitUnit(i, col, num) );
				return;
			}
	}
	if(colCount[num][col] == 2)
	{
		int row[2]= {0,0};
		for(int i=0; i<9&&!row[1]; i++)
		{
			if(u[i][col].findNum(num))
			{
				if(row[0])
					row[1] = i;
				else
					row[0] = i;
			}
			
		}
		if(row[0]/3 == row[1]/3)
		{
			int i = 0;
			while(areaCount[num][row[0]/3 *3+col/3]!=2 && i<9)
			{
				int r = row[0]/3 *3 + i/3;
				int c = col/3 *3 + i%3;
				if(u[r][c].findNum(num)&& c!=col )
					disEnable(r,c,num);
				i++;
			}
		}
	}
}

void sudoku::testAreaCount(int num, int area)
{
	if(areaCount[num][area] == 1)
	{
		int r = area/3 *3;
		int c = area%3 *3;
		for(int i=0; i<9; i++)
		{
			if(u[r+i/3][c+i%3].findNum(num))
			{
				add.push_back( waitUnit(r+i/3, c+i%3, num) );
				return;
			}
		}
	}
}

void sudoku::setAdd()
{
	list<waitUnit>::iterator first = add.begin();
	while(first!=add.end())
		{
			this->setNum(first->getRow(),first->getCol(), first->getNum());
			first++;
	}
}

bool sudoku::trySetAdd()
{
	list<waitUnit>::iterator first = add.begin();
	while(first!=add.end())
		{
			if( !this->setNum(first->getRow(),first->getCol(), first->getNum()) )
				return false;;
			first++;
	}
	return true;
}

void sudoku::print()
{
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
			cout<<final[i][j]<<' ';
		cout<<endl;
	}
}

bool sudoku::isProgramOver()
{
	for(int i=0; i<9; i++)
		for(int j=0; j<9; j++)
		{
			if(!final[i][j])
				return false;
		};
	return true;
}

bool sudoku::trial( int ID )      //  尝试
{
	int id = ID;
	int remainder = 2;
	for(int num=1; num<10; num++)
		for(int row=0; row<9; row++)
		{
			if(rowCount[num][row] == remainder)
			{
				for(int col=0; col<9; col++)
				{
					if(u[row][col].findNum(num))
						if(--id)
						{
							add.push_back( waitUnit(row, col, num) );
							if(this->trySetAdd())
								return true;
							else
								return false;
						}
				}
			}
		};
	id = ID;
	for(int num=1; num<10; num++)
		for(int col=0; col<9; col++)
		{
			if(colCount[num][col] == remainder)
			{
				for(int row=0; row<9; row++)
				{
					if(u[row][col].findNum(num))
						if(--id)
						{
							add.push_back( waitUnit(row, col, num) );
							if(this->trySetAdd())
								return true;
							else
								return false;
						}
				}
			}
		};
	for(int num=1; num<10; num++)
		for(int area=0; area<9; area++)
		{
			if(areaCount[num][area] == remainder)
			{
				for(int i=0; i<9; i++)
				{
					int row = area/3 *3+i/3;
					int col = area%3 *3+i%3;
					if(u[row][col].findNum(num))
						if(--id)
						{
							add.push_back( waitUnit(row, col, num) );
							if(this->trySetAdd())
								return true;
							else
								return false;
						}
				}
			}
		}
		return false;
}
