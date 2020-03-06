#include<iostream>
#include<string.h>

using namespace std;
struct node
{
    int prio;
    char name[30];
    struct node *link;
};
class hospital
{
    struct node *front;
    public:
    hospital()
    {
        front = NULL;
    }
    void Enqueue()
    {
        node *temp;
        temp = new node;
        cout<<"\n\tEnter the Name:-\t";
        cin>>temp->name;
        cout<<"\n\tEnter The Priority:-\t";
        cin>>temp->prio;
        if(front == NULL||temp->prio < front->prio)
        {
            temp->link = front;
            front = temp;
        }
        else
        {
            node *q = front;
            while (q->link != NULL && q->link->prio <= temp->prio)
                q = q->link;
            temp->link = q->link;
            q->link = temp;    
        }
    }
    void dequeue()
    {
        node *temp;
        if(front == NULL)
            cout<<"\n\tQueue Underflows\t";
        else
        {
            temp = front;
            cout<<"\n\tDeleted item is:\t"<<temp->name<<endl;
            front = front->link;
            delete temp;
        }
    }
    void display()
    {
        node *ptr;
        ptr  = front;
        if(front == NULL)
            cout<<"\n\tQueue is empty";
        else
        {
            cout<<"\n\tQueue is:-";
            while(ptr!=NULL)
            {
                cout<<"\n\t"<<ptr->prio<<"\t\t"<<ptr->name;
                ptr = ptr->link;
            }
        }
    }
    void perticular()
    {
        node *ptr = front;
        int p;
        cout<<"\n\tEnter the Priority of Patient:-\t";
        cin>>p;
        while(ptr != NULL)
        {
            if(ptr->prio == p)
            {
                cout<<"\n\t"<<ptr->prio<<"\t\t"<<ptr->name;
                ptr = ptr ->link;
            }
            else 
                ptr = ptr->link;
        }
    }

};

int main()
{
    hospital h;
    int ch;
    do
    {
        cout<<"\n\t1.Insert\t";
        cout<<"\n\t2.Display All\t";
        cout<<"\n\t3.Delete\t";
        cout<<"\n\t4.Display Perticular\t";
        cout<<"\n\t5.Exit\t";
        cout<<"\n\tEnter your choice:\t";
        cin>>ch;
        switch (ch)
        {
        case 1: h.Enqueue();
            break;
        case 2: h.display();
            break;
        case 3: h.dequeue();
            break;
        case 4: h.perticular();
            break;
        case 5: cout<<"\n\tTerminating the program\t";
            break;
        default:cout<<"\n\tWrong choice\t";
            break;
        }
    } while (ch != 5);
    
}
