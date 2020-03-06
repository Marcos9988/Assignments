#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
class stack1
{
    node *dat[30];
    int top;
public:
    stack1(){top = -1;}
    int empty()
    {
        if(top == -1)
            return 1;
        return 0;
    }
    void push(node *p)
    {
        dat[++top]  = p;
    }
    node *pop()
    {
        return (dat[top--]);
    }
};
class tree
{
    node *root;
public:
    tree()
    {
        root = NULL;
    }
    node *create()
    {
        node *p;
        int x;
        cout<<"\n\tEnter the X or (-1) for Null:\t";    cin>>x;
        if(x == -1)
            return NULL;
        p = new node(x);
        cout<<"\n\tEnter the Left of X:\t"<<x;
        p -> left = create();
        cout<<"\n\tEnter the Right of X:\t"<<x;
        p -> right = create();
        return p;
    }
    void preorder(node *T)
    {
        stack1 k;
        while(T != NULL)
        {
            cout<<"\t"<<T->data;
            k.push(T);
            T = T->left;
        }
        while(!k.empty())
        {
            T = k.pop();
            T = T->right;
            while (T != NULL)
            {
                cout<<"\t"<<T->data;
                k.push(T);
                T = T->left;
            }
        }
    }
    void inorder(node *T)
    {
        stack1 k;
        while(T != NULL)
        {
            k.push(T);
            T = T->left;
        }
        while(!k.empty())
        {
            T = k.pop();
            cout<<"\t"<<T->data;
            T = T->right;
            while (T != NULL)
            {
                k.push(T);
                T = T->left;
            }
        }
    }
    void postorder(node *T)
    {
        stack1 s,s1;
        while(T != NULL)
        {
            s.push(T);
            s1.push(NULL);
            T = T->left;
        }
        while(!s.empty())
        {
            T = s.pop();
            if(s1.pop() == NULL)
            {
                s.push(T);  s1.push((node*)1);
                T = T->right;
                while(T != NULL)
                {
                    s.push(T); s1.push(NULL);
                    T = T->left;
                }
            }
            else
                cout<<"\t"<<T->data;
        }
    }
    int treedepth(node * T)
    {
        queue<node *> q;
        if(T==NULL)
            return 0;

        q.push(T);
        int height =0;
        while(1)
        {
            int nodecount=q.size();
            if(nodecount==0)
                return (height);
            height ++;

            while(nodecount>0)
            {
                node *node=q.front();
                q.pop();
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
                nodecount--;
            }
        }
    }
    void display_leaf(node *t)
    {
        stack<node*>s;
        int cnt = 0;
        if (t == NULL)
            return ;
        while(t != NULL)
        {
            s.push(t);
            if(t->left==NULL && t->right==NULL)
            {
                cnt++;
                cout<<"\t"<<t->data;
            }
            t =t->left;
        }
        while (!s.empty())
        {
            t = s.top();
            s.pop();
            t = t->right;
            while (t!=NULL)
            {
                s.push(t);
                if(t->left == NULL && t->right == NULL)
                {
                    cnt++;
                    cout<<"\t"<<t->data;
                }
                 t = t->left;
            }    
        }  
    }
};

int main()
{
    tree t;
    int y,ch;
    node *ptr = NULL;
    do
    {
        cout<<"\n\t1.Create\t";
        cout<<"\n\t2.Preorder Display\t";
        cout<<"\n\t3.Postorder Display\t";
        cout<<"\n\t4.Inorder Display\t";
        cout<<"\n\t5.Leaf Node\t";
        cout<<"\n\t6.Depth of Tree\t";
        cout<<"\n\t7.Exit\t";
        cout<<"\n\tEnter Your choice\t";
        cin>>ch;
        switch (ch)
        {
        case 1:  ptr = t.create();
            break;
        case 2: t.preorder(ptr);
            break;
        case 3: t.postorder(ptr);
            break;
        case 4: t.inorder(ptr);
            break;
        case 5: t.display_leaf(ptr);
            break;
        case 6: y = t.treedepth(ptr);
                cout<<"\n\t"<<y;
            break;
        default:cout<<"\n\tTerminating!!!!!\t";
            break;
        }
    }while(ch!=6);
}