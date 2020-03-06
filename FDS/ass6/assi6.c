#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct student
{
	int rno, marks;
	char name[50];
}student;

void create(student *s, int n, FILE *fp)
{
	int i,j,k;
	fp= fopen("RECORD.txt","w+");
	fprintf(fp,"\n\tROLL NO.\tNAME\t\tMARKS\n");
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
		fprintf(fp,"\n\t%d\t\t%s\t\t%d",(s+i)->rno,(s+i)->name,(s+i)->marks);
	}
	fclose(fp);
}

void display(student *s,int n,FILE *fp)
{
	int i;
	fp=fopen("RECORD.txt","r+");
	for(i=0;i<n;i++)
	{
	    fscanf(fp,"%d %s %s",&s[i].rno,s[i].name,&s[i].marks);
		printf("\n\tRoll No.:-%d\t",s[i].rno);
		printf("\n\tName:-%s\t",s[i].name);
		printf("\n\tmarks:-%d\t",s[i].marks);
	}
	fclose(fp);
}

void displayper(student *s, int n, int m,FILE *fp)
{
	int i,j;
	fp=fopen("RECORD.txt","r");
	for(i=0;i<n;i++)
	{
	    fscanf(fp,"%d",&(s+i)->rno);
		if(m==(s+i)->rno)
		{
		    fscanf(fp,"%d %s %d",&(s+i)->rno,(s+i)->name,&(s+i)->marks);
			printf("\n\tRoll no:-%d\n\tName:-%s\n\tmarks:-%d\t", (s+i)->rno, (s+i)->name, (s+i)->marks);
			break;
		}
	}
	if(i==n)
	printf("\n\tNOT found\t");
	fclose(fp);
}

int edit(student *s,int n, int m, FILE *fp)
{
	int i,j,z;
	fp=fopen("RECORD.txt","w+");
	for(i=0;i<n;i++)
	{
	    while(!feof(fp))
	    {fscanf(fp,"%d %s %d",&(s+i)->rno,(s+i)->name,&(s+i)->marks);}
		if(m==(s+i)->rno)
		{
			printf("\n\tEnter the name of student:\t");
			scanf("%d", &z);
			scanf("%[^\n]%*c",(s+i)->name);
			printf("\n\tEnter the marks:\t");
			scanf("%d",&(s+i)->marks);
		}
	}
	for(i=0;i<n;i++)
    {
        fprintf(fp,"\n\t%d\t\t%s\t\t%d",(s+i)->rno,(s+i)->name,(s+i)->marks);
    }
	fclose(fp);
}

void insert(student *p, int n, FILE *fp)
{
	int i,pos,roll,mak;
	char nam[200];
	fp=fopen("RECORD.txt","a+");
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
        fprintf(fp,"\n\t%d\t\t%s\t\t%d",roll,nam,mak);
        fclose(fp);

}

int delete(student *s, int n, int val,FILE *fp)
{
	int i,j,r=0;
	fp=fopen("RECORD.txt","r+");
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
					s[j]=s[j-1];
				}
			}n=n-1;
			break;
		}
	}fclose(fp);
	fp=fopen("RECORD.txt","a+");
	for(i=0;i<n;i++)
    {
        fprintf(fp,"\n\t%d\t\t%s\t\t%d",(s+i)->rno,(s+i)->name,(s+i)->marks);
    }
	return r;
	fclose(fp);
}

int main()
{
	student *s;
	int n,m,k,j,o=0,i,y;
	int ch;
	FILE *fp=fopen("RECORD.txt","w+");
	if(fp==NULL)
	{
	    printf("\n\tCannot create file!!\t");
	}
	fclose(fp);

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
					s=(student*)malloc(n*sizeof(student));
					create(s,n,fp);
					break;

			case 2:	printf("\n\tDisplaying All the Record\t");
                    display(s,n,fp);
					break;

			case 3:	printf("\n\tHow many records you want to display:-\t");
					scanf("%d",&k);
                    printf("\n\tEnter the Roll no. whose record you want to display:-\t");
                    scanf("%d",&m);
                    displayper(s,n,m,fp);
					break;

			case 4: printf("\n\tEnter the Roll no. whose record you want to edit:\t");
					scanf("%d",&m);
					fp=fopen("RECORD.txt","r+");
					edit(s,n,m,fp);
					fclose(fp);
					break;

			case 5: o=o+1;
                    n=n+o;
                    printf("\n\tEnter the details you Want to insert\t:");
                    s=(student*)realloc(s,(n)*sizeof(student));
                    fp=fopen("RECORD.txt","a+");
                    insert(s,n,fp);
                    fclose(fp);
                    break;

			case 6: printf("\n\tEnter the Roll no. whose record you Want to delete:\t");
					scanf("%d",&m);
					//fp=fopen("RECORD.txt","a+");
					for(i=0;i<n;i++)
					{
						if(m==(s+i)->rno)
						break;
					}
					if(i==n)
						printf("\n\tRoll no. NOT FOUND!!. Cannot delete\t");
					else
					{
						s=(student*)realloc(s,(n)*sizeof(student));
						if(delete(s,n,m,fp)==1)
						n--;
					}
					//fclose(fp);
					break;

			default: printf("\n\tTerminating!!!\t");

		}
	}while(ch!=7);
}

