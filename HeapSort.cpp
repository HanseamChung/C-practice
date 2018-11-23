//1025079 Hansaem Chung
//4817575 Jimmy Hu



#include <iostream>
#include <vector>
#include <cassert>
#include <string>
using namespace std;

int HeapSort1[10] = {2, 14, 30, 29, 42, 30, 11, -5, 0, 51};
 int HeapSort2[7] = {15, 40, 42, -15, 30, 35, 5};
vector<int> heap = {2, 14, 30, 29, 42, 30, 11, -5, 0, 51};

ostream& operator<< (ostream& out, vector<int> heap[10])
{// pre-condition:
    assert (true) ;
/*  post-condition:
    out has emitted all members of track, including the last separating newline.
*/
    out << heap   << endl ;
    return out ;
}



//void swap1(vector<int> heap, int i, int j)
void swap1(int heap[], int i, int j)
{
    // pre-condition:
    assert ( i >= 0 && j >= 0 ) ; // ... and i < size of songs
                     // ... and j < size of songs
    // Post-condition: songs[i] = old songs[j] and songs[j] = old songs[i]
    const int HELP =  heap[i];
    heap [i] = heap [j] ;
    heap [j] = HELP;
}




//void push_up(vector<int> &v)
void push_up(int v[],int n, int i)
{
    for(int j=0; j<i;j++)
    {
    int left = 2*j + 1;
    int right = 2*j +2;
    if (left<n &&v[left]> v[j])
        swap1(v,j,left);
    if (right<n && v[right] > v[j])
        swap1(v,j,right);
    }
}

void buildHeap(int v[], int n)
{
    for (int i = 0; i <n; i++)
        push_up(v,n,i);

}
void showHeap(int v[],int n)
{
    for ( int i = 0 ; i <n; i++)
        cout << v[i]<<"  ";
    cout<<"\n";
}

int compare (int v[], int a, int b)
{
    if (v[a]>v[b])
        return a;
    else
        return b;
}

void push_down(int v[], int n)
{

    for(int j=0; j<n;j++)
    {
    int left = 2*j + 1;
    int right = 2*j +2;
    int large = compare(v,left,right);
    if (right>=n&&left>=n)
    { }
    else if (right>=n&&left<n)
    {
        if (v[left]> v[j])
            swap1(v,j,left);
    }
    else if (right<n && left<n)
        if (v[j]<v[large])
            swap1(v,j,large);

    }

}


void pick_heap(int v[], int n)
{

    for (int i = n-1; i >0; i--)
        {

        swap1(v,0,i);
        push_down(v,i);
        showHeap(v,n);
        }
}



/* Part 1 a):
the input consists of the three arguments of the function: year, day and month.
The order consists of the constants being calculated. the arguments do not change once given and the function itself contains 14 constants itself
So the order of runtime complexity = O(1), because every constant is 1 step.
b):
in this case, the input needed to run the function are int x and int& divisor. And the x is used square root of x amount of times
So the order of runtime complexity = O(sqrt(x)), the divisor is not involved in the notation, because it gets iterated sqrt(x) amount of times.

Part 2
a)
Phase 1 Building a heap

{15, 40, 42, -15, 30, 35, 5}

        15
    40      42
-15    30 35    5

        40
    15       42
-15    30 35    5

        42
    15      40
-15    30 35    5

        42
    30      40
-15    15 35    5

Phase 2 Sorting the array

{42 , 30 , 40 , -15 , 15 , 35 , 5 }
{40 , 15 , 35 , -15 , 5 , 30 , 42 }
{35 , 15 , 30 , -15 , 5 , 40 , 42 }
{30 , 5 , 15 , -15 , 35 , 40 , 42 }
{15 , -15 , 5 , 30 , 35 , 40 , 42 }
{5 , -15 , 15 , 30 , 35 , 40 , 42 }
{-15 , 5 , 15 , 30 , 35 , 40 , 42 }
b)

order of runtime complexity push_up: o(n)
order of runtime complexity build_heap: o(n^2)
order of runtime complexity push_down: o(n)
order of runtime complexity pick_heap: o(n^2)




*/






int main()
{
    int n = sizeof(HeapSort1)/sizeof(HeapSort1[0]);
    buildHeap(HeapSort1,n);
    showHeap(HeapSort1,n);
    pick_heap(HeapSort1,n);



}
