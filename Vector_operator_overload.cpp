#include <iostream>

using namespace std;

//separate declare of member method and definition of it

class Vector2{
public:
    Vector2();
    Vector2(float x, float y);

    float GetX() const;
    float GetY() const;

    static Vector2 Sum(Vector2 a, Vector2 b)
    {
        return Vector2(a.x+b.x,a.y+b.y);
    }

    Vector2 Add(Vector2 rhs)
    {
        return Vector2(x + rhs.x,y + rhs.y);
    }

    Vector2 operator+(const Vector2 rhs) const;
    Vector2 operator-(const Vector2 rhs) const;
    Vector2 operator*(const float rhs) const;
    Vector2 operator/(const float rhs) const;
    float operator*(const Vector2 rhs) const;



private:
    float x;
    float y;


    };

Vector2 Sum2(Vector2 a, Vector2 b)
    {
        return Vector2(a.GetX()+b.GetX(),a.GetY()+b.GetY());
    }

Vector2 operator*(const float a, const Vector2 b)
    {
        return Vector2(a*b.GetX(),a.GetY()+b.GetY());
    }
// member operator is calculate something to itself
// non-member operator has no concept of itself
int main()
{
    Vector2 a(2,3);
    Vector2 b(-1,4);
    /*
    Vector2 c1 = Vector2::Sum(a,b);
    Vector2 c2 = a.Add(b);
    Vector2 c3 = a+b; // if give operator+
    */
    Vector2 c1 = a-b;
    Vector2 c2 = a*1.6; // 1,6*a is impossible because 1.6 is not subject
    Vector2 c3 = a/2;
    float c4 = a * b;

    cout<< a.GetX()<<","<<a.GetY()<<endl;
    cout<< b.GetX()<<","<<b.GetY()<<endl;
    cout<< c1.GetX()<<","<<c1.GetY()<<endl;
    cout<< c2.GetX()<<","<<c2.GetY()<<endl;
    cout<< c3.GetX()<<","<<c3.GetY()<<endl;
    cout<< c4<<endl;

}

Vector2::Vector2() : x(0),y(0){}
Vector2::Vector2(float x, float y) : x(x), y(y){}

float Vector2::GetX() const { return x;}
float Vector2::GetY() const {return y; }

Vector2 Vector2::operator+(const Vector2 rhs) const{
    return Vector2(x + rhs.x,y+rhs.y);
}
Vector2 Vector2::operator-(const Vector2 rhs) const{
    return Vector2(x - rhs.x,y-rhs.y);
}
Vector2 Vector2::operator*(const float rhs) const{
    return Vector2(x * rhs,y *rhs);
}
Vector2 Vector2::operator/(const float rhs) const{
    return Vector2(x / rhs, y / rhs);
}
float Vector2::operator*(const Vector2 rhs) const{
    return x * rhs.x+y *rhs.y;
}


