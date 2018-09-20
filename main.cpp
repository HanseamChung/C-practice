#include <iostream>
#include <cmath>

using namespace std;


void inclusion (double e, double v)
{
    double a=0, x, i =0 ;
    //declare a, x, i
    if (v == 0)
        x= 0;
    // if v is 0, x(result output) is 0
    else if (v==1)
        x= 1;
    // if v is 0, x(result output) is 0
    else if (v<0)
        cout <<"type bigger that 0"<<endl;
    // if v is smaller than 0, print above error message
    else
        {
        double b = max(1.0,v);
        // after compare 1 and v, it input the bigger output in b
        x = (a+b)/2;
        // x is (a+b)/2

        cout <<" i = "<<i<<", a" << i <<" = "<<a<<", b"<<i<<" = "<<b<<", x"<<i<<" = "<<x<<endl;
        // print i=0's case
        while(abs(x*x-v) > e)
            {
            i++;
            // count the i

            if (x*x<v)
                {
                a=x;
                b=b;
                }

            else
                {
                a=a;
                b=x;
                }

            x= (a+b)/2;
            cout <<" i = "<<i<<", a" << i <<" = "<<a<<", b"<<i<<" = "<<b<<", x"<<i<<" = "<<x<<endl;
            // print i repeatedly by using cout in the while syntax

            }
        }
        cout <<"Inclusion square root of "<<v<<" is "<<x<<" for epsilon "<<e<< endl;
}

void newton_raphson (double e, double v)
{
    double x, i=0;
    //declare x, i=0
    if (v == 0)
        x= 0;
    // if v is 0, x(result output) is 0
    else if (v==1)
        x= 1;
    // if v is 1, x(result output) is 1
    else
    {
        x= max(1.0,v);
        cout <<" i = "<<i<<", x" << i <<" = "<<x<<endl;

        // print when i = 0's output
        while(abs(x*x-v) > e)
        {
            i++;
            x = x - (x*x-v)/(2*x);
            x= x;
            cout <<" i = "<<i<<", x" << i <<" = "<<x<<endl;
            // print i repeatedly by using cout in the while syntax

        }
    }
    cout <<"Newton_raphson square root of "<<v<<" is "<<x<<" for epsilon "<<e<< endl;
}




void test_inclusion()
{
    cout<<endl<<"@@@@@@@@ test the inclusion @@@@@@"<< endl;
    double e = 0.1 ;
    while (e >=0.00001)
    {
        inclusion(e,0.0);
        inclusion(e,1.0);
        inclusion(e,0.6);
        inclusion(e,36.0);
        inclusion(e,333333.3333);

        e = e/10;
    }
    cout << endl << "@@@@@@@@@ test inclusion done @@@@@"<< endl;
}

void test_newton_raphson()
{
    cout<<endl<<"@@@@@@@@ test the newton_raphson @@@@@@"<< endl;
    double e = 0.1 ;
    while (e >=0.00001)
    {
        newton_raphson(e,0.0);
        newton_raphson(e,1.0);
        newton_raphson(e,0.6);
        newton_raphson(e,36.0);
        newton_raphson(e,333333.3333);

        e = e/10;
    }
    cout << endl << "@@@@@@@@@ test newton_raphson done @@@@@"<< endl;
}

int main()
{

    double e,v;
    cout << "Enter the epsilon(range of Error) ";
    cin >> e;
    cout << "Enter the Value ";
    cin >> v;
    newton_raphson(e,v);
    cout << "\t" <<endl;
    inclusion(e,v);

   // test_inclusion();
   // test_newton_raphson();
    //return 0;

}
//in the case of e = 0.1 and v = 10 , Newton repeat 4 times but inclusion repeat 7 times
// this shows that Newton is better than inclusion
/*
This is test result.
@@@@@@@@ test the inclusion @@@@@@
Inclusion square root of 0 is 0 for epsilon 0.1
Inclusion square root of 1 is 1 for epsilon 0.1
Inclusion square root of 0.6 is 0.75 for epsilon 0.1
Inclusion square root of 36 is 5.99414 for epsilon 0.1
Inclusion square root of 333333 is 577.35 for epsilon 0.1
Inclusion square root of 0 is 0 for epsilon 0.01
Inclusion square root of 1 is 1 for epsilon 0.01
Inclusion square root of 0.6 is 0.773438 for epsilon 0.01
Inclusion square root of 36 is 6.00073 for epsilon 0.01
Inclusion square root of 333333 is 577.35 for epsilon 0.01
Inclusion square root of 0 is 0 for epsilon 0.001
Inclusion square root of 1 is 1 for epsilon 0.001
Inclusion square root of 0.6 is 0.774414 for epsilon 0.001
Inclusion square root of 36 is 6.00005 for epsilon 0.001
Inclusion square root of 333333 is 577.35 for epsilon 0.001
Inclusion square root of 0 is 0 for epsilon 0.0001
Inclusion square root of 1 is 1 for epsilon 0.0001
Inclusion square root of 0.6 is 0.774658 for epsilon 0.0001
Inclusion square root of 36 is 5.99999 for epsilon 0.0001
Inclusion square root of 333333 is 577.35 for epsilon 0.0001
Inclusion square root of 0 is 0 for epsilon 1e-005
Inclusion square root of 1 is 1 for epsilon 1e-005
Inclusion square root of 0.6 is 0.774597 for epsilon 1e-005
Inclusion square root of 36 is 6 for epsilon 1e-005
Inclusion square root of 333333 is 577.35 for epsilon 1e-005

@@@@@@@@ test the newton_raphson @@@@@@
Newton_raphson square root of 0 is 0 for epsilon 0.1
Newton_raphson square root of 1 is 1 for epsilon 0.1
Newton_raphson square root of 0.6 is 0.8 for epsilon 0.1
Newton_raphson square root of 36 is 6.00025 for epsilon 0.1
Newton_raphson square root of 333333 is 577.35 for epsilon 0.1
Newton_raphson square root of 0 is 0 for epsilon 0.01
Newton_raphson square root of 1 is 1 for epsilon 0.01
Newton_raphson square root of 0.6 is 0.775 for epsilon 0.01
Newton_raphson square root of 36 is 6.00025 for epsilon 0.01
Newton_raphson square root of 333333 is 577.35 for epsilon 0.01
Newton_raphson square root of 0 is 0 for epsilon 0.001
Newton_raphson square root of 1 is 1 for epsilon 0.001
Newton_raphson square root of 0.6 is 0.775 for epsilon 0.001
Newton_raphson square root of 36 is 6 for epsilon 0.001
Newton_raphson square root of 333333 is 577.35 for epsilon 0.001
Newton_raphson square root of 0 is 0 for epsilon 0.0001
Newton_raphson square root of 1 is 1 for epsilon 0.0001
Newton_raphson square root of 0.6 is 0.774597 for epsilon 0.0001
Newton_raphson square root of 36 is 6 for epsilon 0.0001
Newton_raphson square root of 333333 is 577.35 for epsilon 0.0001
Newton_raphson square root of 0 is 0 for epsilon 1e-005
Newton_raphson square root of 1 is 1 for epsilon 1e-005
Newton_raphson square root of 0.6 is 0.774597 for epsilon 1e-005
Newton_raphson square root of 36 is 6 for epsilon 1e-005
Newton_raphson square root of 333333 is 577.35 for epsilon 1e-005
*/
