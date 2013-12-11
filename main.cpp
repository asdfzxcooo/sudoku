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
                                }
                                
                        }
                };

        o.setAdd();

        o.print();


}
