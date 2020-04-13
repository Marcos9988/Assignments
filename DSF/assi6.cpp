#include<bits/stdc++.h>
using namespace std;
static int maximum = 1;

typedef struct dob
{
	int date, month, year;
}dob;

struct node;

typedef struct friendNode
{
	node *friendAddress;
	friendNode *next;
}friendNode;

typedef struct node
{
	int id, visited, comments;
	char name[25];
	dob birthday;
	struct node *next;
	friendNode *friends;
}node;

class graph
{
	node *head;
    public:
   	graph()
    {
        head = NULL;
    }
   	int isEmpty()
    {
	    if(head == NULL)
		    return 1;
	    return 0;
    }
    void createNode(char name[25], int date, int month, int year, int comments)
    {
	    node *temp;
	    node *current = new node;
	    current->id = maximum++;
	    strcpy(current->name,name);
	    current->birthday.date = date;
	    current->birthday.month = month;
	    current->birthday.year = year;
	    current->comments = comments;
	    current->friends = NULL;
	    current->next = NULL;
	
	    if(head == NULL)
		    head = current;
	    else
	    {
		    temp = head;
		    while(temp->next !=NULL)
			    temp = temp->next;
		    temp->next = current;
	    }
    }
	void displayNode(char name[25])
    {
	    node *temp = head;
	    friendNode *temp1;
	
	    while(temp != NULL && strcmp(temp->name,name) != 0)
		    temp = temp->next;
		
	    if(temp)
	    {
		    temp1 = temp->friends;
		    cout<<"\n-----"<<temp->name<<"'s Profile-----"<<endl;
		    cout<<"\nBirthday : "<<temp->birthday.date<<"/"<<temp->birthday.month<<"/"<<temp->birthday.year<<endl;
		    cout<<"\nComments : "<<temp->comments<<endl;
		    if(temp1)
		    {
			    int i = 1;
			    cout<<"\nFriends List :"<<endl;
			    while(temp1 != NULL)
			    {
				    cout<<i++<<". "<<temp1->friendAddress->name<<endl;
				    temp1 = temp1->next;
			    }
		    }   
		    cout<<endl;
	    }
	    else
		    cout<<"\nUser does not exist."<<endl;
    }
	void display()
    {
	    node *temp = head;
	    while(temp != NULL)
	    {
		    cout<<temp->id<<". "<<temp->name<<endl;
		    temp = temp->next;
	    }	
    }
    void makeFriend(char name1[25], char name2[25]);
    void dfs(int month);
    void bfs();
};
void graph::makeFriend(char name1[25], char name2[25])
{
	node *temp = head;
	friendNode *temp1;
	node *user1, *user2;
	friendNode *newfriend1 = new friendNode;
	friendNode *newfriend2 = new friendNode;
	
	while(temp != NULL && strcmp(temp->name,name1) != 0)
		temp = temp->next;
	user1 = temp;
	
	while(temp != NULL && strcmp(temp->name,name2) != 0)
		temp = temp->next;
	user2 = temp;
	
	if(user1 == NULL || user2 == NULL)
	{
		cout<<"\nUser does not exist."<<endl;
		return;
	}
	else
	{
		newfriend1->friendAddress = user2;
		newfriend1->next = NULL;
		newfriend2->friendAddress = user1;
		newfriend2->next = NULL;
	}
	if(user1->friends == NULL)
		user1->friends = newfriend1;
	else
	{
		temp1 = user1->friends;
		while(temp1->next != NULL)
			temp1 = temp1->next;
		 temp1->next = newfriend1;
	}
	if(user2->friends == NULL)
		user2->friends = newfriend2;
	else
	{
		temp1 = user2->friends;
		while(temp1->next != NULL)
			temp1 = temp1->next;
		 temp1->next = newfriend2;
	}
	cout<<"\n"<<user1->name<<" is now friends with "<<user2->name<<"."<<endl;
}
void graph:: dfs(int month)
{
	stack<node *>s;
	friendNode *temp1;
	node *temp = head;
	while(temp)
	{
		temp->visited = 0;
		temp = temp->next;
	}
		
	temp = head;
	s.push(temp);
	head->visited = 1;
	while(!s.empty())
	{
		temp = s.top();
		s.pop();
		
		if(temp->birthday.month == month)
			cout<<temp->name<<"\t"<<temp->birthday.date<<"/"<<temp->birthday.month<<"/"<<temp->birthday.year<<endl;
			
		temp1 = temp->friends;
		while(temp1)
		{
			if(!temp1->friendAddress->visited)
			{
				temp1->friendAddress->visited = 1;
				s.push(temp1->friendAddress);
			}
			temp1 = temp1->next;
		}	
	}
}

void graph:: bfs()
{
	queue<node *>q;
	int min, max;
	friendNode *temp1;
	node *temp = head;
	while(temp)
	{
		temp->visited = 0;
		temp = temp->next;
	}
	
	min = head->comments;
	max = head->comments;
	temp = head;
	q.push(temp);
	head->visited = 1;
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		if(temp->comments > max)
			max = temp->comments;
		if(temp->comments < min)
			min = temp->comments;
			
		temp1 = temp->friends;
		while(temp1)
		{
			if(!temp1->friendAddress->visited)
			{
				temp1->friendAddress->visited = 1;
				q.push(temp1->friendAddress);
			}
			temp1 = temp1->next;
		}	
	}
	
	cout<<"\n-----MINIMUM COMMENTS-----"<<endl;
	temp = head;
	while(temp != NULL)
	{
		if(temp->comments == min)
			cout<<temp->name<<"\t"<<temp->comments<<endl;
		temp = temp->next;
	}
	cout<<"--------------------------"<<endl;
	
	cout<<"\n-----MAXIMUM COMMENTS-----"<<endl;
	temp = head;
	while(temp != NULL)
	{
		if(temp->comments == max)
			cout<<temp->name<<"\t"<<temp->comments<<endl;
		temp = temp->next;
	}
	cout<<"--------------------------"<<endl;
}
class facebook
{
	graph g;
public:
 	void createProfile();
 	void displayProfile();
 	void displayAll();
 	void befriend();
 	void birthdays();
 	void comments();
};

void facebook::createProfile()
{
	node profile;
	
	cout<<"\n*****CREATE YOUR PROFILE*****"<<endl;
	cout<<"\nEnter your name :"<<endl;
	cin>>profile.name;
	cout<<"\nEnter your birth date(dd<space>mm<space>yyyy) :"<<endl;
	cin>>profile.birthday.date>>profile.birthday.month>>profile.birthday.year;
	cout<<"\nEnter the number of comments you've made :"<<endl;
	cin>>profile.comments;
	
	g.createNode(profile.name,profile.birthday.date,profile.birthday.month,profile.birthday.year,profile.comments);
	cout<<"\nProfile created successfully! Welcome to facebook."<<endl;
}

void facebook::displayAll()
{
	if(g.isEmpty())
		cout<<"\nNo network yet."<<endl;	
	else
	{
		cout<<"\n-------------FACEBOOK USERS-------------"<<endl;
		g.display();
		cout<<"----------------------------------------"<<endl;
	}
}
void facebook::displayProfile()
{
	char user[25];
	
	cout<<"\nEnter name :"<<endl;
	cin>>user;
	g.displayNode(user);
}
void facebook::befriend()
{
	char user1[25], user2[25];
	
	cout<<"\nEnter your name :"<<endl;
	cin>>user1;
	cout<<"\nEnter the name of your new friend :"<<endl;
	cin>>user2;
	g.makeFriend(user1,user2);
}
void facebook::birthdays()
{
	int month;
	char monthc[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	cout<<"\nEnter the month :"<<endl;
	cin>>month;
	cout<<"\n-----Birthdays in "<<monthc[month-1]<<"-----"<<endl;
	g.dfs(month);
	cout<<"----------------------------"<<endl;
}
void facebook::comments()
{
	g.bfs();
}
int main()
{
	int choice, data;
	facebook f;
	
	do
	{
		cout<<"\n*****FACEBOOK*****\n1)Create new profile\n2)See who's on facebook\n3)Add Friends\n4)View Profile\n5)See who is most /least active(MINIMUM/MAXIMUM COMMENTS)\n6)Birthdays in the month\n7)Logout"<<endl;
		cin>>choice;
		
		switch(choice)
		{
		case 1:
			f.createProfile();
			break;
		case 2:
			f.displayAll();
			break;
		case 3:
			f.befriend();
			break;
		case 4:
			f.displayProfile();
			break;
		case 5:
			f.comments();
			break;
		case 6:
			f.birthdays();
			break;
		case 7:
			exit(0);
		}
	}while(1);
	
	return 0;
}