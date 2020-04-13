#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left, *right;
};
class BST
{
    node *root;
public:
    BST()
    {
        root = NULL;
    }
    node *create(node *T, int x)
    {   

        node*s;
        s = serach(T,x);
        if(s == NULL)
        {
            node *p, *q, *r;
            r = new node;
            r->data = x;
            r->left = NULL;
            r->right = NULL;
            if(T == NULL)
                return(r);
            p = T;
            while(p != NULL)
            {
                q = p;
                if(x > p->data)
                    p = p->right;
                else
                    p = p->left;
            }
            if(x > q->data)
                q->right = r;
            else
                q->left = r;
        }
        else
        {
            cout<<"\n\tAlready Present can't Insert";
        }
        return (T);
    }
    void display(node *T)
    {
        if(T != NULL)
        {
            cout<<"\t"<<T->data;
            display(T->left);
            display(T->right);
        }
    }
    node * minimum(node *T)
    {
        node *temp = T;
        while(temp && temp->left != NULL)
            temp = temp->left;
        return temp;
    }
    int maximum(node *T)
    {
        while(T->right != NULL)
            T = T->right;
        return(T->data);
    }
    void mirror(node *T)
    {
        if(T == NULL)
            return ;
        else
        {
            node * temp;
            mirror(T->left);
            mirror(T->right);
            temp = T->left;
            T->left = T->right;
            T->right = temp;
        }
    }
    node *delete1(node *T, int x)
    {
        if(T == NULL)
            return T;
        if(x < T->data)
            T->left = delete1(T->left, x);
        
        else if(x > T->data)
            T->right = delete1(T->right, x);

        else
        {
            if(T->left == NULL)
            {
                node *temp = T->right;
                free(T);
                return temp;           
            }
            else if(T->right == NULL)
            {
                node *temp = T->left;
                free(T);
                return temp;
            }
            node *temp = minimum(T->right);
            T->data = temp ->data;
            T->right = delete1(T->right, temp->data);
        }
        return T;        
    }
    node* serach(node *T, int x)
    {
        while (T != NULL)
        {
            if(x == T->data)
                return T;
            if (x > T->data)
                T = T->right;
            else
                T = T->left;
        }
        return NULL;   
    }
};

int main()
{
    BST b;
    int ch,x,y;
    node *m = NULL;
    node *n = NULL;
    //m = n = NULL;
    do
    {
        cout<<"\n\t1.Insert";
        cout<<"\n\t2.Display";
        cout<<"\n\t3.Minimum";
        cout<<"\n\t4.Maximum";
        cout<<"\n\t5.Mirror";
        cout<<"\n\t6.Delete";
        cout<<"\n\t7.Search";
        cout<<"\n\tEnter your choice\t";
        cin>>ch;
        switch (ch)
        {
        case 1: cout<<"\n\tEnter the data\t";
                cin>>x;
                m = b.create(m,x);
            break;
        case 2: b.display(m);
            break;
        case 3: n = b.minimum(m);
                cout<<"\t"<<n->data;
            break;
        case 4: y = b.maximum(m);
            cout<<"\t"<<y;
            break;
        case 5: b.mirror(m);
                b.display(m);
                break;
        case 6: cout<<"\n\tEnter the data you want to delete\t";
                cin>>x;
                m = b.delete1(m, x);
                break;
        case 7: cout<<"\n\tEnter the element to be searched\t";
                cin>>x;
                n = b.serach(m,x);
                if(n == NULL)
                    cout<<"\n\tNot Found";
                else
                    cout<<"\n\tPresent";
                break;
        default:cout<<"\n\tTerminating";
            break;
        }
    } while (ch!=8);
    
}