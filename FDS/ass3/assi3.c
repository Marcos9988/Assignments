#include<stdio.h>
#include<stdlib.h>
void input(int **a, int m, int n)
{
    printf("\n\tEnter the elements of matrix:\t");
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",(*(a+i)+j));
    }
}

void display(int **a,int m, int n)
{
    printf("\n\tTHE MATRIX IS:\t");
    int i,j;
    for(i=0;i<m;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
        {
            printf("\t%d",*(*(a+i)+j));
        }
    }
}

void sum(int **a, int **b,int **c, int m, int n, int l, int o)
{
    int i,j;
        printf("\n\tMATRIX ADDITION IS POSSIBLE\t");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                   *(*(c+i)+j)= *(*(a+i)+j)+*(*(b+i)+j);
            }
        }
}

void multiply(int **a, int **b, int **c, int m, int n, int l, int o)
{
    int i,j,k;
    for(i=0;i<m;i++)
    {
        for(j=0;j<o;j++)
        {
            *(*(c+i)+j)=0;
            for(k=0;k<n;k++)
              {
                   *(*(c+i)+j)+=(*(*(a+i)+k))*(*(*(b+k)+j));
              }
        }
    }
}

void transpose(int **d, int **e, int m, int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            *(*(e+i)+j)=*(*(d+j)+i);
    }
}

void subtract(int **a, int **b, int **c, int m, int n, int l, int o)
{
    int i,j;
    printf("\n\tMATRIX SUBTRACTION IS POSSIBLE\t");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            *(*(c+i)+j)=*(*(a+i)+j)-*(*(b+i)+j);
        }
    }
}

int saddle(int **a, int m, int n)
{
    int i,j,t,p,min,max,k;
    for(i=0;i<m;i++)
    {
       min= *(*(a+i)+0);
       t=0;
       for(j=1;j<n;j++)
       {
           if(min>*(*(a+i)+j))
           {
                min=*(*(a+i)+j);
                t=j;
           }
       }
       max= *(*(a+0)+t);
       p=0;
       for(j=1;j<m;j++)
       {
           if(max<*(*(a+j)+t))
            max= *(*(a+j)+t);
            p=j;
       }
       if(i==p)
       {
           printf("\n\t Saddle point is at %d,%d and value is:\t%d",i,t,*(*(a+i)+t));
           return (1);
       }
    }
        printf("\n\tNo saddle point");
        return (0);
}
void MagicSquare(int **mat, int m, int n)
{
    int z, cnt=0;
    z= (((m*m)+1)*m)/2;
    int i,j,k, sum=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            sum+= *(*(mat+i)+j);
        }
        if(i==0)
            k=sum;
        if(sum==k&&sum==z)
            cnt++;
        sum=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            sum+= *(*(mat+i)+j);
        }
        if(sum==k&&sum==z)
            cnt++;
        sum=0;
    }
    if(cnt==m+n)
        printf("\n\tA MAGIC SQUARE:\t");
    else
        printf("\n\tNOT A MAGIC SQUARE:\t");
}


int main()
{
    int **a,**b,**c,**d,**e,**f,m,n,l,o,ch,i,j;
    do
    {
        printf("\n\t----------MATRIX OPERATION MENU-----------\t");
        printf("\n\t1.INPUT\t");
        printf("\n\t2.DISPLAY\t");
        printf("\n\t3.ADDITION\t");
        printf("\n\t4.SUBTRACTION\t");
        printf("\n\t5.MULTIPLICATION\t");
        printf("\n\t6.TRANSPOSE\t");
        printf("\n\t7.SADDLE POINT\t");
        printf("\n\t8.MAGIC SQUARE\t");
        printf("\n\t9.EXIT!!!\t");
        printf("\n\tENTER YOUR CHOICE\t");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("\n\tEnter the no. of rows and columns of matrix:\t");
                    scanf("%d%d", &m,&n);
                    a=(int**)malloc(m*sizeof(int*));
                    for(i=0;i<m;i++)
                        *(a+i)=(int*)malloc(n*sizeof(int));
                    input(a,m,n);
                    printf("\n\tEnter the no. of rows and columns of second matrix:\t");
                    scanf("%d%d", &l, &o);
                    b=(int**)malloc(l*sizeof(int*));
                    for(i=0;i<l;i++)
                        *(b+i)=(int*)malloc(o*sizeof(int));
                    input(b,l,o);
                    break;

            case 2: display(a,m,n);
                    display(b,l,o);
                    break;

            case 3: c=(int**)malloc(m*sizeof(int*));
                    for(i=0;i<m;i++)
                        *(c+i)= (int*)malloc(n*sizeof(int));
                    if(m==l&&n==o)
                    {
                        printf("\n\tAddition of given two matrix is equal to:\t");
                        sum(a,b,c,m,n,l,o);
                        display(c,m,n);
                    }
                    else
                        printf("\n\tAddition is not possible for given two matrix:\t");
                    break;

            case 4: c=(int**)malloc(m*sizeof(int*));
                    for(i=0;i<m;i++)
                        *(c+i)= (int*)malloc(n*sizeof(int));
                    if(m==l&&n==o)
                    {
                        printf("\n\tSubtraction of given two matrix is equal to:\t");
                        subtract(a,b,c,m,n,l,o);
                        display(c,m,n);
                    }
                    else
                        printf("\n\tSubtraction is not possible for given two matrix:\t");
                    break;

            case 5: d=(int**)malloc(m*sizeof(int*));
                    for(i=0;i<m;i++)
                        *(d+i)=(int*)malloc(o*sizeof(int));
                    if(n==l)
                    {
                        printf("\n\tMultiplication is possible\t:");
                        multiply(a,b,d,m,n,l,o);
                        display(d,m,o);
                    }
                    else
                        printf("\n\tMultiplication is not possible:\t");
                    break;

            case 6: e=(int**)malloc(n*sizeof(int*));
                    for(i=0;i<n;i++)
                        *(e+i)=(int*)malloc(m*sizeof(int));
                    printf("\n\tTranspose of First Matrix:\t");
                    transpose(a,e,m,n);
                    display(e,n,m);
                    d=(int**)malloc(o*sizeof(int*));
                    for(i=0;i<o;i++)
                        *(d+i)=(int*)malloc(l*sizeof(int));
                    transpose(b,d,l,o);
                    display(d,o,l);
                    break;

            case 7: saddle(a,m,n);
                    saddle(b,l,o);
                    break;

            case 8: if(m==n)
                    {
                        MagicSquare(a,m,n);
                    }
                    if(l==o)
                    {
                        MagicSquare(b,l,o);
                    }
                    else
                    {
                        printf("\n\tEnter A square matrix:\t");
                        printf("\n\tEnter the no. of rows and columns of square matrix:\t");
                        scanf("%d", &m);
                        f=(int**)malloc(m*sizeof(int*));
                        for(i=0;i<m;i++)
                            *(f+i)=(int*)malloc(m*sizeof(int));
                        input(f,m,m);
                        MagicSquare(f,m,m);
                    }
                    break;

            default: printf("\n\tTERMINATING!!!!!\t");
        }
    }while(ch!=9);

}
