#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
    int rno,mark;
    char name[200];
}stu;
FILE *temp,*fp;
void insert()
{
    stu s;
    fseek(fp,0,2);
    printf("\n\tENTER THE ROLL NO.:\t"); scanf("%d",&s.rno);
    printf("\n\tENTER THE NAME:\t");  fflush(stdin);  scanf("%[^\n]%*c",s.name);
    printf("\n\tENTER THE MARKS:\t");   scanf("%d",&s.mark);
    fprintf(fp,"\n\t%d\t\t%s\t\t%d",s.rno,s.name,s.mark);
    fclose(fp);
    fp=fopen("hello.txt","r+");
}
void search()
{
    stu s;
    int roll;
    printf("\n\tENTER THE ROLL NO. WHOSE RECORD YOU WANT TO SEARCH:\t");    scanf("%d",&roll);
    rewind(fp);
    while(!feof(fp))
    {
        fscanf(fp,"%d %s %d",&s.rno,s.name,s.mark);
        if(roll==s.rno)
        {
            printf("\n\tRECORD FOUND!!!\t");
            printf("\n\tRoll no.%d\t",s.rno);
            printf("\n\tName:%s\t",s.name);
            printf("\n\tMarks:%d\t",s.mark);
            return;
        }
    }
    printf("\n\tRECORD NOT FOUND!!!!!!!\t");
}
void Delete()
{
    stu s;
    int rec,i;
    printf("\n\tENTER THE RECORD NO. WHOSE RECORD YOU WANT TO DELETE:\t");
    scanf("%d",&rec);
    temp=fopen("temp.txt","w+");
    rewind(fp);
    for(i=1;i<rec&&!feof(fp);i++)
    {
        fscanf(fp,"%d %s %d",&s.rno,s.name,&s.mark);
        fprintf(temp,"%d%s%d",s.rno,s.name,s.mark);
    }
    if(feof(fp))
    printf("\n\tRECORD NOT FOUND\t");
    else
    {
        fscanf(fp,"%d%s%d",&s.rno,s.name,&s.mark);
        while(!feof(fp))
        {
            fscanf(fp,"%d%s%d",&s.rno,s.name,&s.mark);
            fprintf(temp,"%d %s %d",s.rno,s.name,s.mark);
        }
        fclose(fp);
        fclose(temp);
        fp=fopen("hello.txt","w+");
        temp=fopen("temp.txt","r+");
        while(!feof(temp))
        {
            fscanf(temp,"%d %s %d",&s.rno,s.name,&s.mark);
            fprintf(fp,"\n\t%d\t\t%s\t\t%d",s.rno,s.name,s.mark);
        }
    }
    fclose(temp);
}
void display()
{
    stu s;
    rewind(fp);
    while(!feof(fp))
    {
        fscanf(fp,"%d %s %d",&s.rno,s.name,&s.mark);
        printf("\n\tRoll no.%d\t",s.rno);
        printf("\n\tName:%s\t",s.name);
        printf("\n\tMarks:%d\t",s.mark);
    }
}
void edit()
{
    stu s;
    int rec,i;
    printf("\n\tENTER THE RECORD NO. WHOSE RECORD YOU WANT TO MODIFY:\t");
    scanf("%d",&rec);
    temp=fopen("temp.txt","w+");
    rewind(fp);
    for(i=1;i<rec&&!feof(fp);i++)
    {
        fscanf(fp,"%d %s %d",&s.rno,s.name,&s.mark);
        fprintf(temp,"%d%s%d",&s.rno,s.name,s.mark);
    }
    if(feof(fp))
    printf("\n\tRECORD NOT FOUND\t");
    else
    {
        fscanf(fp,"%d%s%d",&s.rno,s.name,&s.mark);
        printf("\n\tENTER THE ROLL NO.:\t");    scanf("%d",&s.rno);
        printf("\n\tENTER THE NAME:\t");    scanf("%[^\n]%*c",s.name);
        printf("\n\tENTER THE MARKS:\t");   scanf("%d",&s.mark);
        fprintf(temp,"%d %s %d",s.rno,s.name,s.mark);
        while(!feof(fp))
        {
            fscanf(fp,"%d %s %d",&s.rno,s.name,&s.mark);
            fprintf(temp,"%d %s %d",s.rno,s.name,s.mark);
        }
        fclose(fp);
        fclose(temp);
        fp=fopen("hello.txt","w+");
        temp=fopen("temp.txt","r+");
        while(!feof(temp))
        {
            fscanf(temp,"%d %s %d",&s.rno,s.name,&s.mark);
            fprintf(fp,"\n\t%d\t\t%s\t\t%d",s.rno,s.name,s.mark);
        }
    }
    fclose(fp);
}

int main()
{
    int ch,rollno;
    stu s;
    fp=fopen("hello.txt","w+");
    fclose(fp);
    do
    {
        printf("\n\t----FILE HANDLING-----\t");
        printf("\n\t1.INSERT A RECORD\t");
        printf("\n\t2.DELETE A RECORD\t");
        printf("\n\t3.MODIFY A RECORD\t");
        printf("\n\t4.SEARCH FOR PERTICULAR RECORD\t");
        printf("\n\t5.DISPLAY ALL RECORD\t");
        printf("\n\t6.EXIT!!!!!");
        printf("\n\tENTER YOUR CHOICE\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert();
                    break;
            case 2: Delete();
                    break;
            case 3: edit();
                    break;
            case 4: search();
                    break;
            case 5: display();
                    break;
            default: printf("\n\tTERMINATING!!!!\t");
                    break;
        }
    }while(ch!=6);
    fclose(fp);
}
