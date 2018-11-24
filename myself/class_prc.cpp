/*
//class = save& process data = variable + function
//class(type) = frame which has some variable & function to do some process(data type)
//Object : object made by that frame(space in memory and variable)

#include <iostream>

using namespace std;

//private, Public, protected
//in structure, it's default is public / in class, it's default is private

class TV
{
private:
    bool powerOn;
    int channel;
    int volume;


public:
    void on()
    {
        powerOn= true;
        cout<< "turn on the TV" <<endl;
    }

    void off()
    {
        powerOn= false;
        cout<<"turn of the TV"<<endl;
    }

    void setChannel(int cnl)
    {
        if(cnl >= 1 && cnl <= 999)
        {
            channel = cnl;
            cout<<"change channel to "<<cnl<<endl;
        }
    }


    void setVolume(int vol)
    {
        if(vol >=0 && vol <= 100)
            volume = vol;
        cout<<"change volume to "<<vol<<endl;
    }
};



int main()
{
    TV lg;
    lg.on() ;
    lg.setChannel(1) ;
    lg.setVolume(50);




}
*/
//this pointer == Myclass *ptr
//this is invisible pointer
#include <iostream>

using namespace std;

class Myclass
{
public:
    void PrintThis()
    {
        cout<<"my address is" << this <<endl;

    }
};

int main()
{
    Myclass a,b;

    cout << " a's address is " <<&a << endl;
    cout << " b's address is " <<&b << endl;

    a.PrintThis();
    b.PrintThis();
}

