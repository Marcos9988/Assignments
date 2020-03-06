#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct student
{
	int rno, marks;
	char name[50];
}student;

void create(student *s, int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		printf("\n\tEnter the roll no.:-\t");
		scanf("%d", &(s+i)->rno);
		for(j=0;j<i;j++)
		{
			if((s+i)->rno==(s+j)->rno)
			{
				printf("\n\tRoll no. already exist. Enter the new Roll no.\t");
				scanf("%d",&(s+i)->rno);
				j=-1;
			}
		}
		printf("\n\tEnter the Name:-\t");
		scanf("%d",&k);
		scanf("%[^\n]%*c",(s+i)->name);
		printf("\n\tEnter the Marks:-\t");
		scanf("%d",&(s+i)->marks);
	}
}

void display(student *s,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\n\tRoll No.:-%d\t",(s+i)->rno);
		printf("\n\tName:-%s\t",(s+i)->name);
		printf("\n\tmarks:-%d\t",(s+i)->marks);
	}
}

void displayper(student *s, int n, int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		if(m==(s+i)->rno)
		{
			printf("\n\tRoll no:-%d\n\tName:-%s\n\tmarks:-%d\t", (s+i)->rno, (s+i)->name, (s+i)->marks);
			break;
		}
	}
	if(i==n)
	printf("\n\tNOT found\t");
}

int edit(student *s,int n, int m)
{
	int i,j,z;
	for(i=0;i<n;i++)
	{
		if(m==(s+i)->rno)
		{
			printf("\n\tEnter the name of student:\t");
			scanf("%d", &z);
			scanf("%[^\n]%*c",(s+i)->name);
			printf("\n\tEnter the marks:\t");
			scanf("%d",&(s+i)->marks);
			return 0;

		}

	}printf("\n\tNo Record found\t");
}

void insert(student *p, int n)
{
	int i,pos,roll,mak;
	char nam[200];
	//cnt++;
	printf("\n\tEnter the position where you want to insert:\t");
	scanf("%d",&pos);
        for(i=n-1;i>=pos;i--)
        {
            *(p+i)=*(p+i-1);
        }
        printf("\n\tEnter the Roll no.:\t");
        scanf("%d",&roll);
        for(i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(roll==(p+i)->rno)
                {
                    printf("\n\tRoll no. already exit.Enter New roll no.\t");
                    scanf("%d",&roll);
                }
            }
        }
        (p+pos-1)->rno=roll;
        printf("\n\tEnter the name of student:\t");
        fflush(stdin);
        scanf("%[^\n]%*c",nam);
        strcpy((p+pos-1)->name,nam);
        printf("\n\tEnter the marks:\t");
        scanf("%d",&mak);
        (p+pos-1)->marks=mak;
       // fflush(stdin);
        //display(p,n);

}

int delete(student *s, int n, int val)
{
	int i,j,r=0;
	for(i=0;i<n;i++)
	{
		if(val==(s+i)->rno)
		{
			printf("\n\tRoll no:-%d\n\tName:-%s\n\tmarks:-%d\t", (s+i)->rno, (s+i)->name, (s+i)->marks);
			printf("\n\tIf you really want to delete the press 1 or else 2:\t");
			scanf("%d",&j);
			if(j==1)
			{
			    r=1;
				for(j=i;j<n-1;j++)
				{
					(s+j)->rno=(s+j+1)->rno;
					strcpy((s+j)->name,(s+j+1)->name);
					(s+j)->marks=(s+j+1)->marks;
				}
			}
			break;
		}
	}
	return r;
}

int main()
{
	student *p;
	int n,m,k,j,o=0,i,y;
	int ch;
	do
	{
		printf("\n\t---------RECORD MENU---------\t");
		printf("\n\t1.CREATE DATABASE\t");
		printf("\n\t2.DISPLAY ALL\t");
		printf("\n\t3.DISPLAY PARTICULAR RECORD\t");
		printf("\n\t4.EDIT A SPECIFIC RECORD\t");
		printf("\n\t5.INSERT AT SPECIFIC LOCATION\t");
		printf("\n\t6.DELETE A RECORD\t");
		printf("\n\t7.EXIT!!!!!\t");
		printf("\n\tEnter Your choice:\t");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("\n\tFor How much student you want to enter the data:-\t");
					scanf("%d",&n);
					p=(student*)malloc(n*sizeof(student));
					create(p,n);
					break;

			case 2:	printf("\n\tDisplaying All the Record\t");
					display(p,n);
					break;

			case 3:	printf("\n\tHow many records you want to display:-\t");
					scanf("%d",&k);
					for(j=0;j<k;j++)
					{
						printf("\n\tEnter the Roll no. whose record you want to display:-\t");
						scanf("%d",&m);
						displayper(p,n,m);
					}
					break;

			case 4: printf("\n\tEnter the Roll no. whose record you want to edit:\t");
					scanf("%d",&m);
					edit(p,n,m);
					break;

			case 5: o=o+1;
                    n=n+o;
                    printf("\n\tEnter the details you Want to insert\t:");
                    p=(student*)realloc(p,(n)*sizeof(student));
                    insert(p,n);
                    break;

			case 6: printf("\n\tEnter the Roll no. whose record you Want to delete:\t");
					scanf("%d",&m);
					for(i=0;i<n;i++)
					{
						if(m==(p+i)->rno)
						break;
					}
					if(i==n)
						printf("\n\tRoll no. NOT FOUND!!. Cannot delete\t");
					else
					{
						p=(student*)realloc(p,(n)*sizeof(student));
						if(delete(p,n,m)==1)
						n--;
					}
					break;

			default: printf("\n\tTerminating!!!\t");

		}
	}while(ch!=7);
}
