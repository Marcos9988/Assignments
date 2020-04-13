#include<iostream>
#include<string.h>
using namespace std;

struct node
{
    char data;
    int flag;
    struct node *left;
    struct node * right;
};
struct node1
{
	node *dat;
	node1 *next;
};
class stack1
{
	node1 *top;
	public:
	stack1()
	{
		top=NULL;
	}
	void push(node *pt);
	void  pop();
	//void dis();
	int emp();
	void inorder(node * T)
    {
        if(T!=NULL)
        {
            inorder(T->left);
            cout<<T->data;
            inorder(T->right);
        }
    }
    node * post_to_expression(char *a)
    {
        int i=0,j;
        node *t1,*t2;
        while(a[i]!='\0')
          {
              if(isalnum(a[i]))
              {
                  node *temp = new node;
                  temp->left=NULL;
                  temp->right=NULL;
                  temp->data =a[i++];
                  push(temp);
              }
              else
              {
                  t1= top->dat;pop();
                  t2= top->dat;pop();
                  node *temp = new node;
                  temp -> data = a[i++];
                  temp->left = t2;
                  temp->right = t1;
                  push(temp);
              }
          }
          node *pt = top->dat;
          pop();
          return pt;
    }
    node *pre_to_expreission(char *a)
    {
        int l = strlen(a) - 1;
        node *t1, *t2;
        for(int i=l;i>=0;i--)
        {
            if(isalnum(a[i]))
            {
                node *temp = new node;
                temp -> data = a[i];
                temp->left=temp->right=NULL;
                push(temp);
            }
            else
            {
                t1 = top ->dat; pop();
                t2 = top->dat;pop();
                node *temp = new node;
                temp ->data = a[i];
                temp ->left = t1;
                temp ->right = t2;
                push(temp);
            }
        }
        node *pt = top->dat;
        pop();
        return pt;
    }
    node * peek()
     {
    // check for empty stack
    if (!emp())
        return top->dat;
    else
        exit(1);
    }

    void inOrder(struct node *root)
    {
        node *current = root;

        while (current != NULL || emp() == 0) 
        {
            while (current != NULL)
            {
                push(current);
                current = current->left;
            }

            current = peek();
            pop();
            cout << current->data << " ";
            current = current->right;
        }   
    }

void preOrder(struct node * root)
{
    if(root==NULL)
    {
        cout<<"\n ..thr tree is empty\n";
        return;
    }
    while(root!=NULL)
    {
        push(root);
         cout<<root->data<<" ";
         root=root->left;

    }
    while(emp()==0)
    {

        root=top->dat;
        pop();
        //cout<<root->data<<" ";
        root=root->right;
        while(root!=NULL)
        {
            push(root);
             cout<<root->data<<" ";
            root=root->left;
        }

    }

}

void postOrder(node *ptr)
{
    while(ptr!= NULL){
        ptr->flag = 0;
        push(ptr);
        ptr = ptr->left;
    }
    while(emp()==0){
        ptr = peek();
        pop();
        if(ptr->flag==0){
            ptr->flag = 1;
            push(ptr);
            ptr = ptr->right;
            while(ptr!=NULL){
                ptr->flag = 0;
                push(ptr);
                ptr = ptr->left;
            }
        }
        else
            cout<<ptr->data<<" ";
    }

}


};
void stack1 :: pop()
{
        node1 *p = top;
		top = top->next;
		delete p;
}
void stack1 :: push(node *d1)
{
        node1 *temp = new node1;
        temp->next = NULL;
        temp->dat = d1;
        if(top != NULL)
            temp->next = top;
        top = temp;
}
int stack1 :: emp()
{
	if(top==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
    stack1 s;
    char post[50],pre[50];
    int ch;
    node *y, *z;
    do
    {
        cout<<"\n\t1. Postfix to Expression\t";
        cout<<"\n\t2. Prefix to Expression\t";
        cout<<"\n\t3. Inorder Display\t";
        cout<<"\n\t4. PreOrder Display\t";
        cout<<"\n\t5. PostOrder Display\t";
        cout<<"\n\t6. Exit\t";
        cout<<"\n\tENter your Choice\t";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"\n\tEnter the postfix\t";
                    cin>>post;
                    y = s.post_to_expression(post);
                    s.inorder(y);
                    break;
            case 2: cout<<"\n\tEnter the prefix\t";
                    cin>>pre;
                    z = s.pre_to_expreission(pre);
                    s.inorder(z);
                    break;
            case 3: s.inOrder(z);
                    break;
            case 4: s.preOrder(z);
                    break;
            case 5: s.postOrder(z);
                    break;
        }
    } while (ch != 6);    
}
