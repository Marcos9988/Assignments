#include<iostream>
#include<string.h>
using namespace std;


struct node
{
	char d;
	struct node *next;
};


class stack1
{
	node *top;
	public:
	stack1()
	{
		top=NULL;
	}

	int emp()
	{
	if(top==NULL)
		return 1;
	else
		return 0;
	}

	void push(char d1)
	{
		node *p = new node;
		p->d = d1;
		p->next = top;
		top = p;
	}

	char pop()
	{
		if(emp()==1)
		{
			cout<<"\n\tUnderflow\t";
			return -1;
		}
		else
		{
			node *p = top;
			top=top->next;
			char x=p->d;
			delete p;
			return x;
		}
	}

	void dis()
	{
		node *p = top;
		while(p != NULL)
		{
			cout<<p->d<<"\n";
			p = p->next;
		}
	}
};


float Operation(char Op,float A,float B)
{
int I = 0;
float P = 1;
if(Op == '*')
	P = A * B;
else if(Op == '/')
	P = A / B;
else if(Op == '+')
	P = A + B;
else if(Op == '-')
	P = A - B;
else while( I++ < B)
	P = P * A;
return P;
}


float Postfix_Evaluation(char String[20])
{
	int I=0;
	float Operand1,Operand2,Result;
	stack1 s;
	while(String[I]!='\0')
	{
		if(String[I] >= '0' && String[I] <= '9')
			s.push(String[I] - 48);
		else
		{
			Operand2 = s.pop();
			Operand1 = s.pop();
			Result = Operation((char)String[I],Operand1,Operand2);
			s.push(Result);
		}
		I++;
	}
	return s.pop();
}


float Prefix_Evaluation(char String[20])
{
	int I=strlen(String);
	float Operand1,Operand2,Result;
	stack1 s;
	I--;
	while(I>=0)
	{
		if(String[I]>='0' &&String[I]<='9')
			s.push(String[I]-48);
		else
		{
			Operand1=s.pop();
			Operand2=s.pop();
			Result=Operation((char)String[I],Operand1,Operand2);
			s.push(Result);
		}
		I--;
	}
	return s.pop();
}


int  Priority(char Op)
{
	if(Op == '^')
		return 2;
	if(Op == '+' || Op == '-')
		return 0;
	else
		return 1;
}




void infix_to_postfix(char String[])
{
    char PostExpression[25],opr;
    int I=0,J=0,count;
    stack1 s;

    for(I=0;I<strlen(String);I++ )
    {
		if(isalnum(String[I]))
			PostExpression[J++]=String[I];
		else
		{
			if(String[I]==')')
			{
				opr=s.pop();
				while(opr!='(')
				{
					PostExpression[J++]=opr;
					opr=s.pop();
				}
			}

			else
			{
				if(String[I]=='(')
					s.push(String[I]);
				else
				{
					while(!s.emp())
					{
						opr=s.pop();
						if(opr!='('&& Priority(opr)>Priority(String[I]))
						{
				  			PostExpression[J++]=opr;
						}
						else if(opr!='('&& Priority(opr)==Priority(String[I]))
                		{
                    		s.push(opr);
                    		break;
                		}
						else
						{
						  s.push(opr);
						  break;
						}
					}
			    	s.push(String[I]);
				}
			} //else
	    }
	}  //for

	while(!s.emp())
  	{
		PostExpression[J++]=s.pop();
  	}
	PostExpression[J]='\0';
	cout<<"\nPost: "<<PostExpression;
}


void InfixToPrefix(char String[20])
{
 	char PreExpression[20],opr;
 	int I=0,J=0;
 	I=strlen(String);
 	I--;
 	stack1 s;
	for(I=strlen(String);I>=0;I-- )
    	{
			if(isalnum(String[I]))
				PreExpression[J++]=String[I];
			else
			{
				if(String[I]=='(')
				{
					opr=s.pop();
					while(opr!=')')
					{
						PreExpression[J++]=opr;
						opr=s.pop();
					}

				}	

				else
				{
					if(String[I]==')')
						s.push(String[I]);
					else
					{
						while(!s.emp())
						{
							opr=s.pop();
							if(opr!=')'&& Priority(opr)>=Priority(String[I]))
							{
				  				PreExpression[J++]=opr;
							}
							else
							{
				  				s.push(opr);
				  				break;
							}
						}//while
			    		s.push(String[I]);
					}
				} //else
	      	}	
		}  //for

	while(!s.emp())
   	PreExpression[J++]=s.pop();
 	PreExpression[J]='\0';
	cout<<" prefix is ";//<<PreExpression;
	for(I=J-1;I>=0;I--)
 	cout<<PreExpression[I];
}


int main()
{
	stack1 s;
	int d1,i,ch1;
	char ch;
	char Infix_expression[100];
    char expression[100];
	/*Infix_expression[100]=NULL;
    expression[100]=NULL;*/
	do
	{
		cout<<"\n1:Infix to postfix";
		cout<<"\n2:Infix to Prefix";
		cout<<"\n3:Postfix Evaluation";
		cout<<"\n4:Prefix Evaluation";
		cout<<"\n5:Exit";
		cout<<"\nEnter your choice \t";
		cin>>ch1;
		switch(ch1)
		{
			case 1:	cout<<"\n\n Enter the Infix Expression : ";
					cin>>Infix_expression;
					infix_to_postfix(Infix_expression);
					break;
			case 2:	cout<<"\n\n Enter the Infix Expression : ";
		 			cin>>Infix_expression;
		 			InfixToPrefix(Infix_expression);
		 			break;
			case 3:	cout<<"\n\n Enter the Postfix Expression : ";
		 			cin>>expression;
		 			cout<<Postfix_Evaluation(expression);
					break;
			case 4:	cout<<"\n\n Enter the Prefix Expression : ";
					cin>>expression;
		 			cout<<Prefix_Evaluation(expression);
					break;
			default:	cout<<"\n\tTerminating\n";
					break;
		}
	}while(ch1!=5);
}