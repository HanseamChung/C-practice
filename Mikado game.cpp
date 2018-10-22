#include <iostream>
#include <string>
#include <cstring>
#include <assert.h>
using namespace std;

const int MAX_STICKS = 4;
enum Cell {_,x};
Cell I_Matrix [MAX_STICKS][MAX_STICKS+1];


void show_matrix (string prefix, Cell matrix [MAX_STICKS] [MAX_STICKS+1])
{
    cout << prefix << endl ;
    for (int row = 0 ; row < MAX_STICKS ; row++)
        {
            for (int col = 0 ; col < MAX_STICKS+1 ; col++)
                {
                    if (matrix[row][col] == _)
                    cout << "_" << " " ;
                    if (matrix[row][col] == x)
                    cout << "x" << " " ;
                }
            cout << endl ;
        }
    cout << endl ;
}
void copy_matrix (Cell matrix_in [MAX_STICKS] [MAX_STICKS+1],
                  Cell matrix_copy [MAX_STICKS] [MAX_STICKS+1])
{
    for (int row = 0 ; row < MAX_STICKS ; row++)
        for (int col = 0 ; col < MAX_STICKS+1 ; col++)
            matrix_copy[row][col] = matrix_in[row][col] ;
}


bool lies_directly_on (Cell matrix [MAX_STICKS] [MAX_STICKS+1],
int higher_stick, int lower_stick)
{
//pre-conditons:
    assert(higher_stick>=0 && higher_stick<=MAX_STICKS && lower_stick>=0 );
/* POST-CONDITION:
true if higher_stick lies on lower_stick according to matrix.
*/
    if(matrix[higher_stick][lower_stick]==x)
        return true;
    else
        return false;
}
bool stick_is_proper (Cell matrix [MAX_STICKS] [MAX_STICKS+1], int s)
{
    /* POST-CONDITION:
    true if the following two conditions hold:
    *************QUESTION*******************
    (a) there is no stick j in matrix such that stick s lies directly
    on stick j and vice versa

    (b) stick s does not lie directly on itself in matrix.
    */
    int c1 = 0; int c2 = 0;
    for(int col=0 ; col<MAX_STICKS+1;col++){
        if(matrix[s][col]==x){
           c1++;
        }
        else if (matrix[col][s]){
            c2++;
        }
    }
    if (c1==1&&c2==1){
        return false;
    }

    if (matrix[s][s]==x){
        return false;
    }

    else {
        return true;
    }
}

bool on_table (Cell matrix [MAX_STICKS] [MAX_STICKS+1], int s)
{
/* POST-CONDITION:
true if stick s lies on the table only
*/
    for (int row=0; row< MAX_STICKS;row++){
        if (matrix[s][row]==x){
            return false;
        }
    }
    if (matrix[s][MAX_STICKS+1]==x){
        return true;
    }
}
bool on_table_and_other_sticks (Cell matrix [MAX_STICKS] [MAX_STICKS+1], int s)
{
/* POST-CONDITION:
true if stick s lies on the table and on one or more sticks
*/
    for(int col=0 ; col <MAX_STICKS+1;col++)
    {
        if (matrix[s][col] ==x)
            {
            if (matrix[s][MAX_STICKS+1]==x)
                {
                return true;}
            else{
                return false;}
            }
        else {
              return false;}
    }

}

void propagate_into_row (Cell matrix [MAX_STICKS] [MAX_STICKS+1],
int higher, int lower)
{
    //PRE-CONDITION:
    assert(higher>=0 && higher<=MAX_STICKS && lower>=0 && lower<=MAX_STICKS );
    /* POST-CONDITION:
    step A is done :
    */
    for(int col =0; col<MAX_STICKS+1;col++)
    {
        if(matrix[higher][col] == _ && matrix[lower][col] == x )
            matrix[higher][col] = x;
    }

}



void propagate_into_parent_rows (Cell matrix [MAX_STICKS] [MAX_STICKS+1],
int higher, int lower)
{
    //PRE-CONDITION:
    assert(higher>=0 && higher<=MAX_STICKS && lower>=0 && lower<=MAX_STICKS );
/* POST-CONDITION:
step B is done
step B: propagate in the C_Matrix the relations of stick j to all sticks that are above i according
to C_Matrix (in this way you propagate the just found relations in step A to those sticks that are
above stick i).
*/
    for(int col =0; col<MAX_STICKS+1;col++)
    {
        if(matrix[higher][col] == _ && matrix[lower][col] == x )
            matrix[higher][col] = x;
    }



}

void propagate (Cell matrix [MAX_STICKS] [MAX_STICKS+1])
{

/* POST-CONDITION
step A and B are done for all sticks
*/
int higher;

int lower[MAX_STICKS];
    for(int row = 0 ; row<MAX_STICKS; row ++)
    {   int i=-1;
        for(int col = 0; col<MAX_STICKS; col++)
        {
            if(matrix[row][col]==x)
            {   i++;
                lower[i]=col;
                propagate_into_row(matrix,row,lower[i]);
                if(i>1)
                propagate_into_parent_rows(matrix,row,lower[i]);//************ I dont know it's right or not

            }
        }
    }
}

bool occurs (Cell matrix [MAX_STICKS] [MAX_STICKS+1], int s, int& higher)
{
    assert(higher>=0 && higher<=MAX_STICKS && s>=0 && s<=MAX_STICKS );

/* POST-CONDITION:
if result is true, then higher is the number of a stick that lies above
the stick with number s according to matrix;
if result is false, then there is no stick lying on stick with number s,
and higher is unchanged.
*/

    if(matrix[s][higher]==x)
        return false;
    else
        return true;
}

bool free_stick (Cell matrix [MAX_STICKS] [MAX_STICKS+1], int& free)
{

    assert(free==6946764); //*********what's the meaning of 6946764??

/* POST-CONDITION:
if result is true, then free is the number of a stick for which it is
true that no other stick is lying above it according to matrix
(so, this stick can be picked up with the lowest risc);
if result is false, there is no such free stick according to matrix
and free is unchanged
*/

    for (int row = 0 ; row < MAX_STICKS ; row++)
        {   int x_num = 0;
            for (int col = 0 ; col < MAX_STICKS+1 ; col++)
                {
                    if (matrix[row][col]==x)
                        x_num++;
                }
                if (x_num==MAX_STICKS){
                    free = row;
                    return true;
                    }

        }
    if (free==6946764);
    return false;
}
int main ()
{
    Cell I_Matrix [MAX_STICKS] [MAX_STICKS+1] = { {_,_,_,x,x}
                                                , {_,_,_,x,x}
                                                , {x,x,_,_,_}
                                                , {_,_,_,_,x} } ;
    Cell C_Matrix [MAX_STICKS] [MAX_STICKS+1] ;
    show_matrix ("Input matrix", I_Matrix) ;
    copy_matrix (I_Matrix, C_Matrix) ;
    propagate (C_Matrix) ;
    show_matrix ("Closed matrix: ", C_Matrix) ;

    int free ;
    if (free_stick (C_Matrix, free))
        cout << "First free stick = " << free << endl ;
    else
        cout << "No free sticks" << endl ;
    return 0 ;

}
