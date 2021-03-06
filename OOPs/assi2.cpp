/* create a class complex with data member of real and imaginary part. provide default and parametrized constructor. write a program to perform arthematic operation of two complex no. using operator overloading, addition and substraction using friend function. multiplicatio and division using member function. overload insertion and extraction operator.*/
#include<iostream>

using namespace std;
class complex
{
    int real, imag;
    public:
    friend complex operator +(complex &, complex &);
    friend complex operator -(complex &, complex &);
    friend istream & operator >>(istream &, complex &);
    friend ostream & operator <<(ostream &, complex &);
    complex operator *(complex &a)
    {
        complex c;
        c.real= (real*(a.real))-(imag*(a.imag));
        c.imag= (imag*(a.real))-(real*(a.imag));
        return c;
    }

    complex operator /(complex &b)
    {
        complex d;
        d.real= (real/(b.real));
        d.imag= (imag/(b.imag));
        return d;
    }
    complex()
    {
        real=0;
        imag=0;
    }
    complex(int&n,int&m)
    {
        real=n;
        imag=m;
    }
};

complex operator +(complex &a, complex &b)
{
    complex c;
    c.real= a.real+b.real;
    c.imag= a.imag+b.imag;
    return c;
}

complex operator -(complex &a, complex &b)
{
   complex c;
   c.real= a.real-b.real;
   c.imag= a.imag-b.imag;
   return c;
}

istream & operator >>(istream &d, complex &a)
{
    d>>a.real>>a.imag;
    return d;
}

ostream & operator <<(ostream &m, complex &b)
{
    m<<b.real<<" + "<<b.imag<<"i";
    return m;
}

int main()
{
    complex c2,c3;
    int ch,x,y;
    cout<<"\n\tEnter the First complex no. real and imaginary part\t";
    cin>>x>>y;
    complex c1(x,y);
    cout<<"\n\tEnter the Second complex no.\t";
    cin>>c2;
    do
    {
        cout<<"\n\t----------COMPLEX NUMBER CALCULATOR------------\n\t";
        cout<<"\n\t1.ADDITION\t";
        cout<<"\n\t2.SUBTRACTION\t";
        cout<<"\n\t3.MULTIPLICATION\t";
        cout<<"\n\t4.DIVISION\t";
        cout<<"\n\t5.EXIT!!!!\t";
        cout<<"\n\tEnter your choice:-\t";
        cin>>ch;
        switch(ch)
        {
            case 1:     cout<<"\n\tPerforming Addition operation\t";
                        c3= c1+c2;
                        cout<<"\n\tTHE SUM OF COMPLEX NUMBER IS=\t"<<c3;
                        break;

            case 2:     cout<<"\n\tPerforming Subtraction operation\t";
                        c3= c1-c2;
                        cout<<"\n\tResult=\t"<<c3;
                        break;

            case 3:     cout<<"\n\tPerforming Multiplication operation\t";
                        c3= c1*c2;
                        cout<<"\n\tResult=\t"<<c3;
                        break;

            case 4:     cout<<"\n\tPrforming Division operation\t";
                        c3= c1/c2;
                        cout<<"\n\tResult=\t"<<c3;
                        break;

            default:    cout<<"\n\tTerminating!!!!!\t";
                        break;

        }

    }while(ch!=5);

    return 0;
}
