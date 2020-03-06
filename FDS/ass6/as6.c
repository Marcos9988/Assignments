#include<stdio.h>
#include<stdlib.h>
typedef struct data
{
	char name[15];	
	long long int mob;
	int id;
	float fee;
}data;
int find(int r)
{
	FILE *fp;
	int flag=0;
	data d;
	fp=fopen("main.txt","r");
	do
	{					
		fscanf(fp,"%d\t%s\t%lld\t%f\n",&d.id,d.name,&d.mob,&d.fee);
		if(d.id==r)
		flag=1;			
	}while(!feof(fp));
	return flag;
}
int inputs(data *d)
{
		int j,i,r,f;		
		j:
		printf("\nEnter Roll no ");		
		scanf("%d",&r);
		f=find(r);
		if(f==1)
		{
			printf("\nRoll no Already Exits\n");
			goto j;			
		}
		d->id=r;
		printf("Enter Name ");
		scanf("%s",d->name);
		printf("Enter Mobile Number ");
		scanf("%lld",&d->mob);
		printf("Enter Fee ");
		scanf("%f",&d->fee);
}
int show(data *d)
{
		printf("\n\nRoll no : %d",d->id);
		printf("\nName : %s",d->name);
		printf("\nMobile Number : %lld",d->mob);
		printf("\nFee : %f",d->fee);
return 0;
}
int edit(data *d)
{
		printf("Enter Name ");
		scanf("%s",d->name);
		printf("Enter Mobile Number ");
		scanf("%lld",&d->mob);
		printf("Enter Fee ");
		scanf("%f",&d->fee);
return 0;
}

int main()
{
	data *d;
	FILE *fp,*temp;
	int n,o,flag=0,fi=1,i,r=0,j;
	fp=fopen("main.txt","w");
	fclose(fp);
	{d=(data*)malloc(1*sizeof(data));}
	do{
		printf("\n\nSelect from following choice \n1.Insert Data\n2.Insert a Record \n3.Display Database\n4.Display Selected\n5.Edit a Database\n6.Delete a Record\n7.Exit");
		scanf(" %d",&o);
	switch(o)
	{
		case 1:{fp=fopen("main.txt","a");
				inputs(d);
				fprintf(fp,"%d\t%s\t%lld\t%f\n",d->id,d->name,d->mob,d->fee);
				fclose(fp);
				fi=1;										
				}break;
		case 2:{fp=fopen("main.txt","r");
				temp=fopen("temp.txt","w");
				printf("Enter the Roll no. to Enter Data After element");
				scanf("%d",&r);
				flag=0;	
				do
				{					
					fscanf(fp,"%d\t%s\t%lld\t%f\n",&d->id,d->name,&d->mob,&d->fee);
					if(d->id==r)
					{	
						flag=1;
						fprintf(temp,"%d\t%s\t%lld\t%f\n",d->id,d->name,d->mob,d->fee);
						inputs(d);									
					}
					fprintf(temp,"%d\t%s\t%lld\t%f\n",d->id,d->name,d->mob,d->fee);
				}while(!feof(fp));
				if(flag==0)
				{printf("\nData not Found");}
				fclose(fp);
				fclose(temp);
				fp=fopen("main.txt","w");
				temp=fopen("temp.txt","r");
				do{
					fscanf(temp,"%d\t%s\t%lld\t%f\n",&d->id,d->name,&d->mob,&d->fee);
					fprintf(fp,"%d\t%s\t%lld\t%f\n",d->id,d->name,d->mob,d->fee);
				}while(!feof(temp));
				fclose(temp);
				fclose(fp);
				}break;
		case 3:{fp=fopen("main.txt","r");
				if(fi==0)
				{
					printf("NO Data");
					break;
				}				
				do
				{					
					fscanf(fp,"%d\t%s\t%lld\t%f\n",&d->id,d->name,&d->mob,&d->fee);
					show(d);
				}while(!feof(fp));
				fclose(fp);			
				}break;
		case 4:{fp=fopen("main.txt","r");
				printf("Enter the Roll no. to Display Data");
				scanf("%d",&r);
				flag=0;	
				do
				{					
					fscanf(fp,"%d\t%s\t%lld\t%f\n",&d->id,d->name,&d->mob,&d->fee);
					if(d->id==r)
					{
						show(d);
						flag=1;						
						break;
					}
				}while(!feof(fp));
				if(flag==0)
				{printf("\nData not Found");}
				fclose(fp);
				}break;
		case 5:{fp=fopen("main.txt","r");
				temp=fopen("temp.txt","w");
				printf("Enter the Roll no. to Edit Data");
				scanf("%d",&r);
				flag=0;	
				do
				{					
					fscanf(fp,"%d\t%s\t%lld\t%f\n",&d->id,d->name,&d->mob,&d->fee);
					if(d->id==r)
					{	
						flag=1;
						edit(d);
					}
					fprintf(temp,"%d\t%s\t%lld\t%f\n",d->id,d->name,d->mob,d->fee);
				}while(!feof(fp));
				if(flag==0)
				{printf("\nData not Found");}
				fclose(fp);
				fclose(temp);
				fp=fopen("main.txt","w");
				temp=fopen("temp.txt","r");
				do{
					fscanf(temp,"%d\t%s\t%lld\t%f\n",&d->id,d->name,&d->mob,&d->fee);
					fprintf(fp,"%d\t%s\t%lld\t%f\n",d->id,d->name,d->mob,d->fee);
				}while(!feof(temp));
				fclose(temp);
				fclose(fp);
				}break;
		case 6:{fp=fopen("main.txt","r");
				temp=fopen("temp.txt","w");
				printf("Enter the Roll no. to Delete Data");
				scanf("%d",&r);
				flag=0;	
				do
				{	j:		
					fscanf(fp,"%d\t%s\t%lld\t%f\n",&d->id,d->name,&d->mob,&d->fee);					
					if(d->id==r)
					{	
						flag=1;
						goto j;
					}
					fprintf(temp,"%d\t%s\t%lld\t%f\n",d->id,d->name,d->mob,d->fee);
				}while(!feof(fp));
				if(flag==0)
				{printf("\nData not Found");}
				fclose(fp);
				fclose(temp);
				fp=fopen("main.txt","w");
				temp=fopen("temp.txt","r");
				do{
					fscanf(temp,"%d\t%s\t%lld\t%f\n",&d->id,d->name,&d->mob,&d->fee);
					fprintf(fp,"%d\t%s\t%lld\t%f\n",d->id,d->name,d->mob,d->fee);
				}while(!feof(temp));
				fclose(fp);
				fclose(temp);
				break;	
		case 7:{}break;
		default:{printf("Wrong Choice");
				}break;
	}}
	}while(o!=7);
return 0;
}
