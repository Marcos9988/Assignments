#include<iostream>
using namespace std;

class shape
{
    double x,y;
public:
    double getdata()
    {
        cout<<"\n\tEnter the Dimensions of the shape:\t";
        cin>>x>>y;
        return (x*y);
    }
    virtual void area()=0;
};

class rectangle: public shape
{
    double m;
public:
    void area()
    {
        m= getdata();
        cout<<"\n\tThe area of rectangle is:\t"<<m;
    }
};

class triangle: public shape
{
    double q;
public:
    void area()
    {
        q= getdata();
        cout<<"\n\tThe area of triangle is:\t"<<(0.5)*q;
    }
};

int main()
{
    double a,b;
    int ch;
    shape *s;
    rectangle r;
    triangle t;

    do
    {
        cout<<"\n\t----------SHAPE AREA MENU----------\t";
        cout<<"\n\t1.RECTANGLE\t";
        cout<<"\n\t2.TRIANGLE\t";
        cout<<"\n\t3.EXIT\t";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"\n\tYou have selected RECTANGLE as shape:\t";
                    s=&r;
                    s->area();
                    break;
            case 2: cout<<"\n\tYou have selected TRIANGLE as shape:\t";
                    s=&t;
                    s->area();
                    break;
            default: cout<<"\n\tTERMINATING!!!!\t";
                    break;
        }
    }while(ch!=3);
}

