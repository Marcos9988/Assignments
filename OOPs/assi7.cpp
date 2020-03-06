#include<iostream>
using namespace std;

template<class t, class t2>
class matrix
{
    t **a;
    t2 **b;
public:
    void Display(t **a,t2 **b,int n, int m, int l, int o)
    {
        cout<<"\n\tINTEGER MATRIX:-\t"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<"\n";
            for(int j=0;j<m;j++)
                cout<<"\t"<<a[i][j];
        }
        cout<<"\n\tFLOAT MATRIX:-\t"<<endl;
        for(int i=0;i<l;i++)
        {
            cout<<"\n";
            for(int j=0;j<o;j++)
                cout<<"\t"<<b[i][j];
        }
    }
    void matrixadd(t **a,t2 **b,t2 **c,int n, int m, int l, int o)
    {
        cout<<"\n";
        if(n==l&&m==o)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                    c[i][j]=a[i][j]+b[i][j];
            }
            for(int i=0;i<n;i++)
            {
                cout<<"\n";
                for(int j=0;j<m;j++)
                cout<<"\t"<<c[i][j];
            }
        }
        else cout<<"\n\tADDITION NOT POSSIBLE:-\t";

    }
    void matrixmul(t **a,t2 **b,t2 **c,int n, int m, int l, int o);
    void matrixtran(t **a,t2 **b,t **c,t2 **d,int n, int m, int l, int o);
};
template<class z,class z2>
void matrix<z,z2>::matrixmul(z **a,z2 **b,z2 **c,int n, int m, int l, int o)
    {
        cout<<"\n";
        if(m==l)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<o;j++)
                {
                    c[i][j]=0;
                    for(int k=0;k<m;k++)
                        c[i][j]+=z2(a[i][k]*b[k][j]);
                }
            }
        }
        else cout<<"\n\tMULTIPLICATION IS NOT POSSIBLE\t";

        for(int i=0;i<n;i++)
        {
            cout<<"\n";
            for(int j=0;j<o;j++)
                cout<<"\t"<<c[i][j];
        }
    }
template<class z, class z2>
void matrix<z,z2>::matrixtran(z **a,z2 **b,z **c, z2 **d,int n, int m, int l, int o)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                c[i][j]=a[j][i];
        }
        for(int i=0;i<o;i++)
        {
            for(int j=0;j<l;j++)
                d[i][j]=b[j][i];
        }
        cout<<"\n\tTRANSPOSE OF INTEGER MATRIX IS:\t";
        for(int i=0;i<m;i++)
        {
            cout<<"\n";
            for(int j=0;j<n;j++)
                cout<<"\t"<<c[i][j];
        }
        cout<<"\n\tTRANSPOSE OF FLOAT MATRIX IS:\t";
        for(int i=0;i<o;i++)
        {
            cout<<"\n";
            for(int j=0;j<l;j++)
                cout<<"\t"<<d[i][j];
        }
    }

int main()
{
    matrix<int,float> m;
    int **a;
    float **b;
    float **c;
    int **d;
    int row1,col1,row2,col2;
    int ch;
    do
    {
        cout<<"\n\t-----MATRIX OPERATION MENU------\t";
        cout<<"\n\t1.INSERT 2 MATRIX\t";
        cout<<"\n\t2.DISPLAY\t";
        cout<<"\n\t3.MATRIX ADDITION\t";
        cout<<"\n\t4.MATRIX MULTIPLICATION\t";
        cout<<"\n\t5.TRANSPOSE\t";
        cout<<"\n\t6.EXIT!!!\t";
        cout<<"\n\tENTER YOUR CHOICE\t";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"\n\tINSERT 2 MATRIX OF DIFFEREBT TYPES, 1.INTEGER, 2.FLOAT:\t";
                    cout<<"\n\tEnter The Rows and Columns of Integer Matrix\t";
                    cin>>row1>>col1;
                    a=new int*[row1];
                    for(int i=0;i<row1;i++)
                        a[i]=new int[col1];
                    cout<<"\n\tEnter the Elements of first Matrix:\t";
                    for(int i=0;i<row1;i++)
                    {
                        cout<<"\n\t";
                        for(int j=0;j<col1;j++)
                        {
                            cin>>a[i][j];
                            cout<<"\t";
                        }
                    }
                    cout<<"\n\tEnter The No. of Rows and Columns OF Float Matrix:\t";
                    cin>>row2>>col2;
                    b=new float*[row2];
                    for(int i=0;i<row2;i++)
                        b[i]=new float [col2];
                    cout<<"\n\tEnter the Elements of Second Matrix:\t";
                    for(int i=0;i<row2;i++)
                    {
                        cout<<"\n\t";
                        for(int j=0;j<col2;j++)
                        {
                            cin>>b[i][j];
                            cout<<"\t";
                        }
                    }
                    break;
            case 2: cout<<"\n\tDISPLAYING\t";
                    m.Display(a,b,row1,col1,row2,col2);
                    break;
            case 3: cout<<"\n\tMATRIX ADDITION\t";
                    c=new float*[row1];
                    for(int i=0;i<row1;i++)
                        c[i]=new float[col1];
                    m.matrixadd(a,b,c,row1,col1,row2,col2);
                    break;
            case 4: cout<<"\n\tMATRIX MULTIPLICATION\t";
                    c=new float*[row1];
                    for(int i=0;i<row1;i++)
                        c[i]=new float[col2];
                    m.matrixmul(a,b,c,row1,col1,row2,col2);
                    break;
            case 5: cout<<"\n\tTRANSPOSE OF MATRIX\t";
                    c=new float*[col2];
                    for(int i=0;i<col2;i++)
                        c[i]=new float[row2];
                    d=new int*[col1];
                    for(int i=0;i<col1;i++)
                        d[i]=new int[row1];
                    m.matrixtran(a,b,d,c,row1,col1,row2,col2);
                    break;
            default: cout<<"\n\tTERMINATING!!!!";
                    break;
        }
    }while(ch!=6);
}
