#include<bits/stdc++.h>
using namespace std;

struct node
{
	char name[20];
	long int mobile;
	int flag;
	int chain;
};

class hashtable
{
	node h[10];
public:
    hashtable();
    void insert(int n, long int key, char name[20]);
    void insertReplace(int n, long int key, char name[20]);
    void display();
};
hashtable::hashtable()
{
	for(int i = 0; i < 10; i++)
	{
		h[i].flag = 0;
		h[i].chain = -1;
		h[i].mobile = 0;
		strcpy(h[i].name, " ");
	}
}

void hashtable::insert(int n,long int key, char name[20])
{
	int loc, i,j;
	loc = key % n;
	i = 0;
	j = loc;
	
	if(h[loc].flag != 1)
	{
		h[loc].flag = 1;
		h[loc].mobile = key;
		strcpy(h[loc].name,name);
	}
	
	else if(h[loc].flag == 1)
	{
		while(h[j].flag == 1 && i<n)
		{
			j = (j+1)%n;
			i++;
		}
		if(i == n)
		{
			cout<<"\nTable is full."<<endl;
			return;
		}
		
		h[loc].chain = j;
		loc = j;
		h[loc].flag = 1;
		h[loc].mobile = key;
		strcpy(h[loc].name,name);
	}
	cout<<"\nData inserted successfully"<<endl;
}

void hashtable::insertReplace(int n,long int key, char name[20])
{
	int loc, oldloc, i, j, flag = 0;
	node temp;
	loc = key % n;
	i = 0;
	j = loc;
	
	if(h[loc].flag != 1)
	{
		h[loc].flag = 1;
		h[loc].mobile = key;
		strcpy(h[loc].name,name);
	}
	
	else if(h[loc].flag == 1)
	{
		if(h[loc].mobile % n != loc)
		{
			strcpy(temp.name,h[loc].name);
			temp.mobile = h[loc].mobile;
			temp.flag = 1;
			temp.chain = h[loc].chain;
			
			strcpy(h[loc].name,name);
			h[loc]. mobile = key;
			h[loc].chain = -1;
			
			strcpy(name,temp.name);
			key = temp.mobile;
			oldloc = loc;
			flag = 1;
			
		}
		
		while(h[j].flag == 1 && i<n)
		{
			j = (j+1)%n;
			i++;
		}
		if(i == n)
		{
			cout<<"\nTable is full."<<endl;
			return;
		}
		
		if(!flag)
			h[loc].chain = j;
		loc = j;
		h[loc].flag = 1;
		h[loc].mobile = key;
		strcpy(h[loc].name,name);
		
		for(int i=0; i<10; i++)
			if(h[i].chain == oldloc)
			{
				h[i].chain = loc;
				break;
			}
	}
	cout<<"\nData inserted successfully"<<endl;
}

void hashtable::display()
{
	for(int i=0;i<10;i++)
	{
		cout<<h[i].name<<"\t"<<h[i].mobile<<"\t"<<h[i].flag<<"\t"<<h[i].chain<<endl;
	}
}
void noreplacement()
{
	hashtable h;
	char name[20];
	long int mobile;
	int choice;
	
	do
	{
		cout<<"\n*****NO REPLACEMENT MENU*****\n1)Add record\n2)Display hashtable\n3)Exit"<<endl;
		cin>>choice;
		
		switch(choice)
		{
		case 1:
			cout<<"\nEnter the name :";
			cin>>name;
			cout<<"\nEnter the phone number :";
			cin>>mobile;
			h.insert(10,mobile,name);
			break;
		case 2:
			h.display();
			break;
		case 3:
			return;
		}
	}while(1);
}

void replacement()
{
	hashtable h;
	char name[20];
	long int mobile;
	int choice;
	do
	{
		cout<<"\n*****REPLACEMENT MENU*****\n1)Add record\n2)Display hashtable\n3)Exit"<<endl;
		cin>>choice;
		
		switch(choice)
		{
		case 1:
			cout<<"\nEnter the name :";
			cin>>name;
			cout<<"\nEnter the phone number :";
			cin>>mobile;
			h.insertReplace(10,mobile,name);
			break;
		case 2:
			h.display();
			break;
		case 3:
			return;
		}
	}while(1);
}
int main()
{
	int choice;
	do
	{
		cout<<"\n*****ENTER YOUR CHOICE*****\n1)Don't use replacement\n2)Use replacement\n3)Exit"<<endl;
		cin>>choice;
		
		switch(choice)
		{
		case 1:
			noreplacement();
			break;
		case 2:
			replacement();
			break;
		case 3:
			exit(0);
		}
	}while(1);
}