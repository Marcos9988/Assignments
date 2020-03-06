#include<iostream>
using namespace std;
class tv
{
    int model, size, price;
    public:
    void modl(int a)
    {
        model=a;
    }
    void screen(int b)
    {
        size=b;
    }
    void amount(int c)
    {
        price=c;
    }
    void Display()
    {
        cout<<"\n\tDETAILS OF TELEVISION IS:\t";
        cout<<"\n\tMODEL no.:\t"<<model<<endl;
        cout<<"\n\tSCREEN SIZE:\t"<<size<<endl;
        cout<<"\n\tPRICE:\t"<<price<<endl;
    }
};
int main()
{
    tv t;
    int i=0, mod,siz,pri,a=0,b=0,c=0,flag;
    while(a==0||b==0||c==0)
    {
        if(a==0)
        {
            flag=0;
            while(flag==0)
            {
                try
                {
                    cout<<"\n\tENTER THE MODEL NO.:\t";
                    cin>>mod;
                    if(mod>=1000&&mod<=9999)
                    {
                        t.modl(mod);
                        i=1;
                        flag=1;
                    }
                    else 
                        throw mod;
                }
                catch(int x)
                {
                    cout<<"\n\tENTERED DATA IS INVALID\t";
                }
                 a=1;
            }
           
        }
        if(b==0)
        {
            flag=0;
            while(flag==0)
            {
                try
                {
                    cout<<"\n\tENTER THE SIZE OF TELEVISION SCREEN:\t";
                    cin>>siz;
                    if(siz>12&&siz<17)
                    {
                        t.screen(siz);
                        flag=1;
                    }
                    else 
                        throw siz;
                }
                catch(int y)
                {
                    cout<<"\n\tENTERED DATA IS INVALID:\t";
                }
                b=1;
            }
        }
        if(c==0)
        {
            flag=0;
            while(flag==0)
            {
                try
                {
                    cout<<"\n\tENTER THE PRICE OF TELEVISION:\t";
                    cin>>pri;
                    if(pri>=0&&pri<=5000)
                    {
                        t.amount(pri);
                        flag=1;
                    }
                    else
                        throw pri;
                }
                catch(int z)
                {
                    cout<<"\n\tENTERED DATA IS INVALID:\t"; 
                }
                c=1;
            }
        }
        if(a==1&&b==1&&c==1)
            break;    
    }
    t.Display();
    
    
}
