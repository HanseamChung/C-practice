#include <iostream>
#include <stdio.h>
using namespace std;
//call by value
//call by-reference

void swap(int x, int y)
{
    int tmp= x;
    x = y;
    y = tmp;
}

void swap2(int &x, int &y)
{
    int tmp= x;
    x = y;
    y = tmp;
}


int main()
{
    int a,b;
    scanf("%d%d", &a, &b);

    swap(a,b); // call by-value
    printf("a = %d, b = %d\n",a,b);

    swap2(a,b); // call by-reference;
    printf("a = %d, b = %d\n",a,b);

}
