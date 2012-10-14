#include"sudoku.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>

sudoku trial(sudoku o);
int main()
{
	sudoku o;
	int original[9][9] = 
	{{0,0,2,0,6,0,4,0,0},
	 {0,0,0,0,0,3,0,0,5},
	 {0,1,0,0,7,0,3,0,0},
	 {0,0,0,0,3,0,0,8,0},
	 {7,8,3,0,5,0,0,9,2},
  	 {0,0,9,2,0,8,0,0,0},
	 {0,0,0,0,0,6,0,5,0},
	 {6,0,0,0,8,0,0,0,0},
	 {0,5,0,1,0,0,2,0,0}};
    freopen("sudoku.in","r",stdin);
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            scanf("%d",& original[i][j]);
        }
	for(int i=0; i<9; i++)
		for(int j=0; j<9; j++)
		{
			if(original[i][j])
			{
				
				if(!o.setNum(i, j, original[i][j]))
				{
					cout<<"Wrong Exercise!!"<<endl;
                    return 0;
				}
				
			}
		};
	o.setAdd();
	
	/*while(!o.isProgramOver())
	{
		sudoku tr1 = o;
        sudoku tr2 = o;
		bool t1 = tr1.trial(1);
		bool t2 = tr2.trial(2);
		if(t1&&!t2)
			o = tr1;
		else if(t2&&!t1)
				o = tr2;
		else 
			o = tr1;
	}*/
	o = trial(o);
	o.print();

}

sudoku trial(sudoku o)
{
	if(o.isProgramOver())
	{
		//	return o;
		o.print();
        exit(0);        //  假如使用return的话, 会使程序把剩余递归使用掉的...
	}
	sudoku tr1 = o;
	sudoku tr2 = o;
	bool t1 = tr1.trial(1);
	bool t2 = tr2.trial(2);
	if(t1&&!t2)
		return trial(tr1);
	else if(t2&&!t1)
		return trial(tr2);
	else if(!t1&&!t2)
		return o;
	else if(trial(tr1).isProgramOver())
		return trial(tr1);
	else if(trial(tr2).isProgramOver())
		return trial(tr2);
	else 
		return o;
}
