#include <iostream>
#include <stdio.h>
using namespace std;
/*
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

    swap2(a,b); // call by-reference
    printf("a = %d, b = %d\n",a,b);

}
*/



//prototype declare first and define later

void walk(int );
void rotate(int );
void drawSquare();

int main()
{
    drawSquare();
}

void walk(int distance)
{
 printf("walked %dcm\n",distance);
}

void rotate(int angle)
{
    printf("rotated %d degree", angle);
}

void drawSquare()
{
    for(int i = 1 ; i <=4 ; i++)
    {
        walk(10);
        rotate(90);
    }
}

