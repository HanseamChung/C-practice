#include <iostream>
#include <fstream>
#include <cassert>
#include <string.h>
//s1025079 Hansaem Chung & s1025078 Hanseop Yoo
using namespace std;

enum Cell {Dead=0, Live};                         // a cell is either Dead or Live (we use the fact that dead = 0 and live = 1)

const char DEAD             = '.' ;               // the presentation of a dead cell (both on file and screen)
const char LIVE             = '*' ;               // the presentation of a live cell (both on file and screen)
const int NO_OF_ROWS        = 40 ;                // the number of rows (height) of the universe (both on file and screen)
const int NO_OF_COLUMNS     = 60 ;                // the number of columns (width) of the universe (both on file and screen)
const int ROWS              = NO_OF_ROWS    + 2 ; // the number of rows in a universe array, including the 'frame' of dead cells
const int COLUMNS           = NO_OF_COLUMNS + 2 ; // the number of columns in a universe array, including the 'frame' of dead cells

const int MAX_FILENAME_LENGTH = 80 ;              // the maximum number of characters for a file name (including termination character)

#include <string>
//  Part 1: one-dimensional arrays
int find_index(char filename [MAX_FILENAME_LENGTH])
{
    int index = 0;
    for(index =0; index < MAX_FILENAME_LENGTH; index++)
    {
        if(filename[index] == '\0')
            return index;
    }
}

bool enter_filename (char filename [MAX_FILENAME_LENGTH])
{
    assert (find_index(filename) <= MAX_FILENAME_LENGTH);
    if(find_index(filename)+1 <= MAX_FILENAME_LENGTH )
        return true;
    else
        return false;
}


//  Part 2: setting the scene
bool read_universe_file (ifstream& inputfile, Cell universe [ROWS][COLUMNS])
{
    assert(inputfile.is_open());
    // pre-conditions

    for (int i = 0 ; i < NO_OF_COLUMNS;i++)
    {
        for(int j = 0 ; j < NO_OF_ROWS;j++)
            {
                char c = inputfile.get();
                cout<<c;
                if (c == DEAD)
                {
                    universe[i][j] = Dead;
                }
                else if (c == LIVE)
                {

                    universe[i][j] = Live;
                }
                else
                {
                    //cout<< "end";
                    //return false;
                }


            }
        return true;
        return universe;
    }

}

void show_universe (Cell universe [ROWS][COLUMNS])
{

    // pre-conditions
    assert(true)
    //post-conditions, implementation
    //it shows universe one by one.
    for (int i = 0; i < NO_OF_COLUMNS; i++){
        for (int j = 0 ; j < NO_OF_ROWS ; j ++){
        cout << universe[i][j]<<" " ;
        }
        cout<< "\n";
        }
}

//  Part 3: the next generation
void next_generation (Cell now [ROWS][COLUMNS], Cell next [ROWS][COLUMNS])
{
    // pre-conditions
    assert(true)
    //post-conditions, implementation
    // when now is live, it compare sum in 3 case
    // sum <2 , sum =2or3 , sum > 3 and according to this decide next
    // when now is dead, it compare whether sum is 3 or not
    // and decide next
    int sum=0;
        for (int i = 1; i < COLUMNS; i++){
        for (int j = 1 ; j < ROWS ; j ++){
        if (now[i][j]==Live)
        {
                for (int a = -1; a < 2; a++){
                for (int b = -1 ; b < 2 ; b ++){
                 sum= sum+now[i-a][i-b];
                 cout<<now[i][j];
                }
                sum= sum- now[i][j];

                }
            if(sum < 2)
            {
                next[i][j]=Dead;
            }
            else if (sum==2 ||sum==3){
                next[i][j]=Live;
            }
            else{
                next[i][j]=Dead;
            }


        }
        if (now[i][j]==Dead)
        {
                for (int a = -1; a < 2; a++){
                for (int b = -1 ; b < 2 ; b ++){
                 sum= sum+now[i-a][i-b];
                 cout<<now[i][j];
                }
                sum= sum- now[i][j];

                }
            if(sum == 3)
            {
                next[i][j]=Live;
            }

            else{
                next[i][j]=Dead;
            }
        }
        }
}
}

int main ()
{

Cell universe[ROWS][COLUMNS];
Cell universe2[ROWS][COLUMNS];
ifstream filename("aa.txt");
if (!read_universe_file(filename,universe)){
    cout << "Program aborted." << endl ;
    return  -1;
        }
next_generation(universe,universe2);


//show_universe(universe);
/*
cout << "enter filename";
char filename[FILENAME_MAX];
cin.getline(filename,FILENAME_MAX);
*/
//enter_filename(filename);
}
