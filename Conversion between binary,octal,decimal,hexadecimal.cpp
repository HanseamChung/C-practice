#include <iostream>
#include <cmath>
using namespace std;

int conv_bodh(char a)
{
// Because it gets input by ASC11 code, the number need to be changed

    int result;
    if (a>=48 && a<=57)
        result= a-48;

        //0~9 changed 0~9
    else if (a>=65 && a<=70)
        result= a-55;
        // A~F changed 10~15
    else if (a>=97 && a<=102)
        result= a-87;
        //a~f changed 10~15
    else
        cout<<"Put the right number"<<endl;
        // if people input other things it shows error message
result;
}

void conv_cal (int base,int A,int B,int C,int D)
{
    int result;

    if (base == 2||base==4||base==8||base==10||base==16)
    {
        A=conv_bodh(A);
        B=conv_bodh(B);
        C=conv_bodh(C);
        D=conv_bodh(D);
        //it receive processed number by conv_bodh()
        result= A*pow(base,3) + B*pow(base,2) + C*pow(base,1) + D*pow(base,0);
        cout<<result<<endl;
        //the result is sum of the the numbers * (dight-1) squared at base
    }

    else
        cout<<"Put the right base"<<endl;
        //if the input base is not 1,4,8,10,16, it shows error message
}

int main()
{

    char z,a,b,c,d;
    int base,A,B,C,D;
    cout<<"Put the base"<<endl;
    cin >> base;
    cout <<"Put the number"<<endl;
    cin.get(z); cin.get(a); cin.get(b); cin.get(c); cin.get(d);
    //there is blank in front of the input, so through 'g' exclude the blank
    //and receive number(character) in regular order

    conv_cal( base,a,b,c,d);
}
