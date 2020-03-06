#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void stringsort(char a[][1000], int size)
{
    int i,j;
    char temp[1000];
    for(i=0;i<size-1;i++)
    {   int flag = 0;
        for(j=i+1;j<size;j++)
        {
            if(strcmpi(a[i],a[j])<0)
            {
                strcpy(temp,a[i]);
                strcpy(a[i],a[j]);
                strcpy(a[j],temp);
                flag = 1;
            }
        }
        if(!flag)   break;
        printf("\n\tSTRINGS AFTER PASS %d",i+1);
        for(int k=0;k<size;k++)
        {
        printf("\n\t");
            printf("%s\t",a[k]);
        }
    }
}

int Binarysearch(char a[][1000], char s[], int size) //Without Recursion
{
    int l,r;
    l = 0;  r = size - 1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(strcmp(s,a[mid])==0)
            return mid;
        else if(strcmp(s,a[mid])>0)
            l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
int binary(char a[][1000], char s[], int l, int r)
{
    if(r>=l)
    {
        int mid = (l+r)/2;
        if(strcmp(s,a[mid])==0) return mid;

        if(strcmp(s,a[mid])>0)  return binary(a,s,mid+1,r);

        return binary(a,s,l,mid-1);
    }
    return -1;
}
void insertion(char a[][1000], int size)
{
    int i,j;
    char temp[1000];
    for(i=0;i<size;i++)
    {
        strcpy(temp,a[i]);
        j=i-1;
        while(j>=0 && strcmpi(a[j],temp)>0)
        {
            strcpy(a[j+1],a[j]);
            j = j-1;
        }
        strcpy(a[j+1],temp);
    }
    printf("\n\tInsertion Sorted String is:\t");
    for(i=0;i<size;i++)
    {
        printf("\n\t");
        printf("%s\t",a[i]);
    }

}

void selection(char a[][100], int size)
{
    int i,j,k;
    char temp[100];
    for(i = 0; i < size - 1; i++)
    {
        k = i;
        strcpy(temp, a[i]);
        for(j = i+1; j < size; j++)
        {
            if(strcmpi(temp, a[j])>0)
            {
                strcpy(a[j+1], a[j]);
                k = j;
            }
        }
    
    if(k!=i)
    {
        char temp2[100];
        strcpy(temp2, a[i]);
        strcpy(a[i], a[k]);
        strcpy(a[k], temp2);
    }
    }
}
int main()
{
    char s[1000][1000],a[1000];
    int n,ch;
    printf("\n\tEnter the size of String\t");
    scanf("%d",&n);
    printf("\n\tEnter the String\t");
    for(int i=0;i<n;i++)
    {
            scanf("\n\t%s",s[i]);
    }
    do
    {
        printf("\n\t1.Bubble Sort\t");
        printf("\n\t2.Insertion sort\t");
        printf("\n\t3.Binary Search\t");
        printf("\n\t4.EXIT\t");
        printf("\n\tEnter your choice:\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:     stringsort(s,n);
                        printf("\n\tSorted String is:-");
                        for(int i=0;i<n;i++)
                        {
                            printf("\n\t");
                            printf("%s\t",s[i]);
                        }
                        break;
            case 3:
                        printf("\n\tEnter The second string\t");
                        scanf("%s",a);
                        printf("\n\tITERATIVE\t");
                        int z = Binarysearch(s,a,n);
                        if(z == -1)
                        printf("\n\tNot Present\t");
                        else printf("\n\tPresent %d", z);
                        printf("\n\tRECURSIVE\t");
                        int k = binary(s,a,0,n-1);
                        if(k == -1)
                        printf("\n\tNot Present\t");
                        else printf("\n\tPresent %d", k);
                        break;
            case 2:     insertion(s,n);
                        break;
        }
    }while(ch!=4);


}
