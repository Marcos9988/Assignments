#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int input(char *w)
{
    int i=0;
    char ch;
    do
    {
        ch= getchar();
        *w= ch;
        w++;
        i++;
    }while(ch!='\n');
    w--;
    i--;
    *w='\0';
    return i;
}
void copystr(char *p, char *q)
{
    int i = 0;
    while (*(q+i) != '\0')
    {
        *(p+i) = *(q+i);
        i++;
    }
   *(p+i) = '\0';
   printf("%s",p);
}

void len(int l)
{
    printf("\n\tThe length of string is%d\t",l);
}
void display(char *a)
{
    while(*a!='\0')
    {
        printf("%c",*a++);
    }

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

void palindrome(char *p)
{
    int l,i,j,flag=1;
    l= strlen(p);
    for(i=0,j=l-1;i<l/2;j--,i++)
    {
        if(*(p+i)!=*(p+j))
        {
            flag=0;
            break;
        }
    }
    if(flag)
        printf("\n\tPalindrome\t");
    else
        printf("\n\tNot a palindrome\t");
}

void revstr(char *a)
{
    char *c;
    int l,i,j,k;
    l= strlen(a);
    for(i=l-1,j=0;i>=0;--i,++j)
    {
        *(c+j)=*(a+i);
    }
    *(c+j)='\0';
    printf("\n\tThe reversed string is:\t");
    printf("%s",c);
}
void concatstr(char *a, char *b)
{
    char *d, *k, *c;
    d=a;
    c=d;
    while(*d!='\0')
    {
        d++;
    }
    k=b;
    while(*k!='\0')
    {
        *d=*k;
        d++;
        k++;
    }
    *d='\0';
    printf("%s",c);
}

void substring(char *a, char* b)
{

    int ct = 0,l=0;
    char *temp = b;        // define new variable

    while (*temp != '\0')
    {
        temp++;
        l++;

    }

    while (*a != '\0' && *b != '\0')
    {
        if (*b == *a)
        {
            b++;
            ct++;
            a++;

        }
        else
        {
            a++;
        }

    }

    if (ct == l)
    {
        printf("\n\t Substring\t");
    }
    else
    {
        printf("\n\tNot a substring\t");
    }


}
void vowel(char *a,int x)
{
    int i,j,k=0,c,count;
    char s[]={'a','e','i','o','u','A','E','I','O','U','\0'};
    char *b=(char*)malloc(30*sizeof(char));
    for(i=0;i<x-1;i++)
    {
        for(j=0;j<10;j++)
        {
            if(*(a+i)==*(s+j))
            {
                *(b+k)=*(s+j);
                k++;
            }
        }
    }
    printf("%s\n",b);
   // printf("\n\tTotal No. of vowels%d\t",k);
}
int main()
{
    char *a, *b, *c, *d, *e;
    int l,m,ch,k;
    do
    {
        printf("\n\t-----------STRING OPERATION MENU-------------\t");
        printf("\n\t1.Input String\t");
        printf("\n\t2.Length of String\t");
        printf("\n\t3.String Compare\t");
        printf("\n\t4.Palindrome\t");
        printf("\n\t5.String Reverse\t");
        printf("\n\t6.String Concatinate\t");
        printf("\n\t7.SubString\t");
        printf("\n\t8.String Copy\t");
        printf("\n\t9.Vowels\t");
        printf("\n\t0.EXIT!!!!!\t");
        printf("\n\tEnter your choice\t");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("\n\tEnter the first string\t");
                    fflush(stdin);
                    a= (char*)malloc(100*sizeof(char));
                    l=input(a);
                    a= (char*)realloc(a,(l+1)*sizeof(char));
                    display(a);
                    printf("\n\tEnter the second string\t");
                    b= (char*)malloc(100*sizeof(char));
                    m=input(b);
                    b= (char*)realloc(b,(m+1)*sizeof(char));
                    display(b);
                    break;
            case 2: printf("\n\tLength of first string is:-\t%d",l);
                    printf("\n\tLength of second string is:-\t%d",m);
                    break;
            case 3: printf("\n\tComparing the both string\t");
                    comparestr(a,b);
                    break;
            case 4: printf("\n\tChecking whether strings are palindrome\t");
                    palindrome(a);
                    palindrome(b);
                    break;
            case 5: printf("\n\tReversing the strings\t");
                    malloc(l*sizeof(char));
                    revstr(a);
                    malloc(m*sizeof(char));
                    revstr(b);
                    break;
            case 6: printf("\n\tConcatinating the string:\t");
                    malloc((l+m)*sizeof(char));
                    concatstr(a,b);
                    break;
            case 7: printf("\n\tEnter the small string you want to find whether substring or not\t");
                    fflush(stdin);
                    c= (char*)malloc(100*sizeof(char));
                    k= input(c);
                    c= (char*)realloc(c, k*sizeof(char));
                    substring(a,c);
                    substring(b,c);
                    break;
            case 8: printf("\n\tCopying the second string in first\t");
                    malloc(l*sizeof(char));
                    copystr(a,b);
                    break;
            case 9: printf("\n\tPrinting The vowels present in the given string\t");
                    vowel(a,l);
                    printf("\n");
                    vowel(b,m);
                    break;
            default:printf("\n\tNot a valid choice\t");
                    break;
        }
    }while(ch!=0);
}
