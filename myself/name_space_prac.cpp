#include <iostream>


/*
using namespace std;
int n;
void set();

namespace doodle
{
    int n;
    void set();

}
namespace google
{
    int n;
    void set();


}

int main()
{
    ::set();
    doodle::set();
    google::set();

    cout << ::n<<endl;
    cout << doodle::n<<endl;
    cout << google::n<<endl;
}


void set()
{
    n = 10;

}
namespace doodle
{

    void set()
    {
        n= 20;
    }
}
// don't need to declare namespace google
void google::set()
{
    n=30;
}
*/
//overlapping namespace

/*
using namespace std;
int n;
void set()
{
    n= 10;
}

namespace doodle
{
    int n;
    void set();


    namespace google
    {
        //if there is no declared some variable, it serch above variable

        void set();
        int n;
    }
}


int main()
{
    ::set();
    doodle::set();
    doodle::google::set();


    cout<< n<<endl;
    cout<< doodle::n<<endl;
    cout<< doodle::google::n<<endl;



}

void doodle::set()
{
    n=20;
}


void doodle::google::set()
{
    n=30;
}
*/

//utility of using namespace
int n;
void set()
{
    n= 10;
}

namespace doodle
{
    int n;
    void set();


    namespace google
    {
        //if there is no declared some variable, it serch above variable

        void set();
        int n;
    }
}


int main()
{
    using namespace std;
    using namespace doodle;
    ::set();
    doodle::set();
    google::set();

    cout<< n<<endl;
    cout<< doodle::n<<endl;
    cout<< doodle::google::n<<endl;
}

void doodle::set()
{
    n=20;
}


void doodle::google::set()
{
    n=30;
}
