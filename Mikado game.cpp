#include <iostream>
#include <cassert>
using namespace std;

const int MAX_STICKS = 4 ;
enum Cell {_,x} ;
Cell I_Matrix [MAX_STICKS] [MAX_STICKS+1] ;

void show_matrix (string prefix, Cell matrix [MAX_STICKS][MAX_STICKS+1])
{
    cout << prefix << endl;
    for (int row=0; row<MAX_STICKS ; row++)
    {
        for (int col =0; col <MAX_STICKS+1; col++)
        {
            if (matrix[row][col] == _)
                cout <<"_"<<" " ;
            if (matrix[row][col] == x)
                cout <<"x"<<" " ;
        }
        cout << endl;
    }
    cout << endl;
}

void copy_matrix (Cell matrix_in [MAX_STICKS][MAX_STICKS+1],
                  Cell matrix_copy[MAX_STICKS][MAX_STICKS+1])
{
    for (int row=0; row<MAX_STICKS ; row++)
        for (int col =0; col <MAX_STICKS+1; col++)
            matrix_copy[row][col] = matrix_in[row][col] ;
}

bool lies_directly_on (Cell Matrix [MAX_STICKS] [MAX_STICKS+1],
                       int higher_stick, int lower_stick)
{
    //Pre-condition
    assert(higher_stick>=0&&lower_stick>=0);
    /*Post-condition
        true if higher_stick lies on lower_stick according to matrix
    */
    return Matrix[higher_stick][lower_stick]==x;
}

bool stick_is_proper (Cell Matrix [MAX_STICKS] [MAX_STICKS+1], int s)
{
    //Pre-condition
    assert(s>=0);
    /* Post_Condition:
        true if the following two conditions hold:
            (a) there is no stick j in matrix such that stick s lies directly
            on stick j and vice versa
            (b) stick s does not lie directly on itself in matrix
        */
   for (int j=0; j<MAX_STICKS ; j++)
   {
       if (lies_directly_on(Matrix,s,j))
        return false;
       else if (lies_directly_on(Matrix,j,s))
        return false;
       else
        return true;
   }
}

bool on_table (Cell Matrix [MAX_STICKS] [MAX_STICKS+1], int s)
{
    //pre-condition
    assert(s>=0);
    //Post-condition
        //true if stick s lies on the table only
    for(int col = 0 ; col < MAX_STICKS ; col++)
        {
        if(Matrix[s][col]==x)
            return false;
        }
    return Matrix[s][MAX_STICKS]==x;
}

bool on_table_and_other_sticks (Cell Matrix [MAX_STICKS] [MAX_STICKS+1], int s)
{
    int x_num=0;
    for(int col = 0 ; col <MAX_STICKS ; col++)
    {
        if(lies_directly_on(Matrix,s,col))
            x_num++;
    }
    if(x_num>0&&lies_directly_on(Matrix,s,MAX_STICKS))
        return true;
    else
        return false;
}

void propagate_into_row (Cell matrix[MAX_STICKS][MAX_STICKS+1],
                          int higher, int lower)
{
    //pre-condition
    assert(higher>=0&&lower>=0);
    //post- condition
    /* if row lower's component is x,
        it is propagated to row higher's component
    */
    for (int col =0; col<MAX_STICKS+1;col++)
    {
        if(matrix[lower][col]==x)
            matrix[higher][col]=x;
    }
}
void propaate_into_parent_rows (Cell matrix [MAX_STICKS][MAX_STICKS+1],
                                int higher, int lower)
{


    //pre-condition
    assert(higher>=0&&lower>=0);
    //post-condition
    //check the other sticks above parameter 'higher'
    //if the 'lower' stick's component is x,
    //then the above sticks' component changed to x

{
    for(int row = 0; row<MAX_STICKS;row++)
    {
        if(lies_directly_on(matrix,row,higher))
            for (int col =0; col<MAX_STICKS+1;col++)
            {
                if(matrix[lower][col]==x)
                    matrix[row][col]=x;
            }
    }
}
}
void propagate (Cell matrix [MAX_STICKS][MAX_STICKS+1])
{
    assert(true);
    for(int row =0;row<MAX_STICKS;row++)
        for(int col = 0; col <MAX_STICKS;col++)
            if(lies_directly_on(matrix,row,col))
            {
                propagate_into_row(matrix,row,col);
                propaate_into_parent_rows(matrix,row,col);
            }
}

bool occurs (Cell matrix[MAX_STICKS][MAX_STICKS+1],int s, int& higher)
{
    /*post-condition:
    if result is true, then higher is the number of a stick that lies above
        the stick with number s according to matrix
    if result is false, then there is no stick lying on stick with number s,
    and higher is unchanged
    */
    for(int col=0;col<MAX_STICKS;col++)
    {
        if (lies_directly_on(matrix,col,s))
            {
                higher = col;
                return true;
            }
    }
    return false;

}

bool free_stick (Cell matrix[MAX_STICKS][MAX_STICKS+1], int& free)
{
    /*post-condition:
        if result is true, then free is the number of a stick for which it is
            true that no other stick is lying above it according to matrix
            (so, this stick can be picked up with the lowest risc);
        if result is false, there is no such free stick according to matrix
        and free is unchanged
        */

}




int main()
{

    Cell I_Matrix [MAX_STICKS][MAX_STICKS+1] = { {_,_,_,x,x}
                                              ,{_,_,_,x,x}
                                              ,{x,x,_,_,_}
                                              ,{_,_,_,_,x}};




    Cell C_matrix [MAX_STICKS][MAX_STICKS+1] ;
    show_matrix("Input matrix", I_Matrix);
    copy_matrix(I_Matrix,C_matrix);



    propagate (C_matrix);
    show_matrix("Closed matrix", C_matrix);
    /*
    int free ;
    if (free_stric (C_Matrix, free))
        cout << "First free stick = " << free << endl;
    else
        cout << "No free sticks" << endl;
    return 0;
    */
}
