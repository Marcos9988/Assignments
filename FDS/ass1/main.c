#include <stdio.h>
#include <stdlib.h>
int input(int set[])   //function to input sets
{
    int i=0,l,j;
    printf("\n\tEnter the length of set:- ");
    scanf("%d", &l);
    printf("\n\tEnter the elements of set:- \n");
    while(i<l)
    {
        scanf("%d", &set[i]);
        for(j=0; j<i; j++)
        if(set[i]==set[j])
        {
            break;
        }
        if(i==j)
            i++;
    }
    return l;
}

int Union(int set1[20],int set2[20], int l1,int l2, int set3[20])  // function to perform union
{
    int i,j,len=0, temp;
    for(i=0; i<l1; i++)   // coping set1 element to set3.
    {
        set3[i]=set1[i];
    }
    len=l1;
    for(i=0; i<l2; i++)  // set2
    {
        temp=0;
        for(j=0;j<l1;j++)   //set1
        {
            if(set1[j]==set2[i])
            {
                temp=1;
                break;
            }
        }
        if(temp==0)
        {
            set3[len]=set2[i];
            len++;
        }
    }
    return len;
}

int Intersect(int set1[20], int set2[20], int l1, int l2, int set3[20])  //function to perform intersection
{
    int i,j, len=0;

    for(i=0;i<l1;i++)   //set 1
    {
        for(j=0;j<l2;j++)   //set2
        {
            if(set1[i]==set2[j])
            {
                set3[len]=set1[i];
                len++;
                break;
            }
        }
    }
    return len;
}

int Difference(int set1[20], int set2[20], int l1, int l2, int set3[20])  // function to perform difference between two sets
{
    int i,j, len=0,temp;
    for(i=0;i<l1;i++)
    { temp=0;
        for(j=0;j<l2;j++)
        {
            if(set1[i]==set2[j])
            {
                temp=1;
                break;
            }
        }
        if(temp==0)
        {
            set3[len]=set1[i];
            len++;
        }
    }
    return len;
}

int Symmetric(int set1[20], int set2[20],int set3[20], int l1, int l2 ) // to perform symmetric difference
{
    int l3, se1[20], se2[20], un1, un2;
    un1= Difference(set1, set2, l1, l2, se1);
    un2= Difference(set2, set1, l2, l1, se2);
    l3=  Union(se1, se2, un1, un2, set3);
    return l3;
}

void Display(int set[], int l)   // to display the set
{
    int i;
    for(i=0; i<l; i++)
    {
        printf("%d \t", set[i]);
    }
}

int main()
{
    int set1[20], set2[20], set3[20], set4[20], set5[20],set6[20],set7[20], l1, l2, l3, l4, l5, l6, l7, ch, ch1;

    do
    {

        printf("\n\n\n\n\t\t------MENU-------\n\n");
        printf("\n\t1.\tINPUT\n");
        printf("\n\t2.\tDISPLAY\n");
        printf("\n\t3.\tUNION\n");
        printf("\n\t4.\tINTERSECTION\n");
        printf("\n\t5.\tDIFFERENCE\n");
        printf("\n\t6.\tSYMMETRIC DIFFERENCE\n");
        printf("\n\t7.\tEXIT\n");
        printf("\n\tPlease Enter your choice\t:-");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("\n\tNoW We Will Take Input Of Sets:-");
                    l1= input(set1);
                    l2= input(set2);
                    break;

            case 2: printf("\n\t SET1:-\t");
                    Display(set1,l1);
                    printf("\n\t SET2:-\t");
                    Display(set2,l2);
                    break;

            case 3: printf("\n\tNow We Will Perform Union Operation:-");
                    l3= Union(set1,set2,l1,l2,set3);
                    printf("\n\tThe set After Union:-\t");
                    Display(set3,l3);
                    break;

            case 4: printf("\n\t Now we Will perform Intersection of 2 sets:=");
                    l4= Intersect(set1,set2,l1,l2,set4);
                    printf("\n\tThe Set After Intersection:-\t");
                    Display(set4,l4);
                    break;

            case 5: printf("\n\tNow We Will Perform Difference Operation:-");
                    printf("\n\t1. SET1-SET2\t");
                    l5= Difference(set1,set2,l1,l2,set5);
                    Display(set5,l5);
                    printf("\n\t2. SET2-SET1\t");
                    l6= Difference(set2,set1,l2,l1,set6);
                    Display(set6,l6);
                    break;

            case 6: printf("\n\tNow we will perform Symmetric Difference:-\t");
            		printf("\n\tSymmetric Difference between Set1 and Set2 is:-");
                    l7= Symmetric(set1,set2,set7,l1,l2);
                    Display(set7,l7);
                    break;
            default:printf("\n\tTERMINATING!!!!!\t");

        }
    } while(ch!=7);
    return 0;
}
