#include <iostream>
#include <cassert>
using namespace std;

const int NO_OF_ROWS = 7 ;
const int NO_OF_COLS = 8 ;
const int HEALTHY_CAGE = -2 ;
const int WALL = -1 ;

void show (int map [NO_OF_ROWS][NO_OF_COLS])
{
    //pre-condition
    assert(true);
    //post-condition
    //check the component of map and
    //if the component is HEALTHY_CAGE, print "."
    //if the component is WALL, print "*"
    //and if read one row, change the line
    for(int row=0;row<NO_OF_ROWS;row++)
    {
        for(int col=0;col<NO_OF_COLS;col++)
            {
            if(map[row][col]==HEALTHY_CAGE)
                cout<<".";
            else if(map[row][col]==WALL)
                cout<<"*";
            else
                cout<<map[row][col];
            }
        cout<<"\n";
    }
}

int mark (int map [NO_OF_ROWS][NO_OF_COLS],
          int row, int col, int value)
{
    //pre-condition
    assert(value>=0);
    //post-condition
    /*if row is between 0 and NO_OF_ROWS & col is between 0 and NO_OF_COLS
      (else, mark return 0)
            and if map[row][col]'s component is HEALTHY_CAGE
                map[row][col]'s component changed to value and mark return 1;
            if the second condition(map[row][col] == HEALTHY_CAGE) is not meet,
                    mark return 0
    */
    if (row>=0 && row < NO_OF_ROWS && col >= 0 && col <NO_OF_COLS)
    {
        if (map[row][col] == HEALTHY_CAGE)
        {
            map[row][col] = value;
            return 1;
        }
        return 0;
    }
    return 0;
}

int contaminate_neighbours (int map[NO_OF_ROWS][NO_OF_COLS],
                            int day, int row, int col)
{
    assert(day >=0 && row>=0 && row < NO_OF_ROWS && col >= 0 && col <NO_OF_COLS);
    int con_num = 0;
    for(int n_row= row-1;n_row<row+2;n_row++)
        for(int n_col= col-1;n_col<col+2;n_col++)
        {
            if(n_row==row&&n_col==col)
            {

            }
            else{
            con_num=con_num+mark(map,n_row,n_col,day+1);

            }
        }
    return con_num;
}

bool spread (int map [NO_OF_ROWS][NO_OF_COLS],int no_of_days)
{
    //pre-condition
    assert(no_of_days>0);
    //post-condition
    /*
    count the number of contaminated cages each day by no_of_marked cage
    it check the value of matrix and if the value is day-1, it contaminate the neighboring cages
    if there is no contaminated cages in one day, 'spread' returns false
    after day loop, it shows the map and returns true.

    */
    int no_of_marked_cage;
    for (int d = 0 ; d<no_of_days;d++)
    {   no_of_marked_cage =0;
        for(int row =0 ; row<NO_OF_ROWS;row++)
            {
            for(int col =0; col < NO_OF_COLS;col++)
                {
                    if(map[row][col]== d)
                        {
                            no_of_marked_cage =no_of_marked_cage+contaminate_neighbours(map,d,row,col);

                        }
                }
            }
        if(no_of_marked_cage==0)
            return false;
    }
    show(map);
    return true;
}

int main()
{
    int map[NO_OF_ROWS][NO_OF_COLS] = {{-2,-2,-2, 0,-2,-2,-1,-2}
                                      ,{-1,-1,-1,-2,-1,-2,-1,-2}
                                      ,{-2,-2,-2,-2,-2,-2,-1,-2}
                                      ,{-1,-1,-1,-2,-2,-2,-1,-2}
                                      ,{-2,-2,-1,-2,-2,-2,-2,-2}
                                      ,{-2,-2,-1,-1,-1,-2, 0,-2}
                                      ,{-2,-2,-2,-2,-1,-2,-2,-2}};
    spread(map,5);
    return 0;
}
