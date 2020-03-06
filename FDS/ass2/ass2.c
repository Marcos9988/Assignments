#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int input(char *p)
{
    int i=0;
    char ch;
    do
    {
        ch= getchar();
        *p= ch;
        p++;
        i++;
    }while(ch!='\n');
    p--;
    i--;
    *p='\0';
    return i;
}

void len(int l)
{
    printf("\n\tThe length of string is%d\t",l);
}
void display(char *p)
{
    while(*p!='\0')
    {
        printf("%c",*p++);
    }
}

char *rev1(char *a)
{
    int i,j,l;
    l= strlen(a);
    char temp, *m,*n,*c;
    c=a;
    m=c;
    n=c;
    for(i=0;i<l-1;i++)
        n++;
    for(i=0;i<l/2;i++)
    {
        temp=*n;
        *n=*m;
        *m=temp;
        m++;
        n--;
    }
    return c;
}

char *concatenate(char *d, char *k, int m, int n)
{
    char *a, *b,*c;
    a=d;
    c=a;
    while(*a!='\0')
    {
        a++;
    }
    b=k;
    while(*b!='\0')
    {
        *a=*b;
        a++;
        b++;
    }
    *a='\0';
   return c;

}
void palindrome(char *k)
{
    char *n;
    n= strrev(k);
    if(*n==*k)
        printf("\n\tPalindrome\t");
    else
        printf("\n\tNot a palindrome\t");
}

void comparestr(char *m, char *n)
{
    int a,b;
    a= strlen(m);
    b= strlen(n);
    if(a!=b)
        printf("\n\tStrings are not equal\t");
    else
    {
        if(*m==*n)
            printf("\n\tStrings are equal\t");
        else
            printf("\n\tStrings are not equal\t");
    }
}
void substring(char *p, char *q)
{

}


int main()
{
    char *p,*q,*a,*b,*c;
    int l,n,m;


    printf("\n\tEnter the string:\t");
    p=(char*)malloc(200*sizeof(char));
    l=input(p);
    len(l);
    p=(char*)realloc(p,l*sizeof(char));
    display(p);
    //palindrome(p);
    //a=rev1(p);
    //printf("\n\tThe Reversed string is:-\t");
    //display(a);
    printf("\n\tEnter the second string:\t");
    q=(char*)malloc(200*sizeof(char));
    n= input(q);
    len(n);
    q=(char*)realloc(q,n*sizeof(char));
    display(q);
    //palindrome(q);
    //printf("\n\tThe reversed string is:-\t");
    //b= rev1(q);
    //display(b);
    comparestr(p,q);
    c=(char*)malloc((l+n)*sizeof(char));
    printf("\n\tThe concatenated string is:-\t");
    c= concatenate(p,q,l,n);
    display(c);


    return 0;
}
