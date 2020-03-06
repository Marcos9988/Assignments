#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

class book
{
    char *title, *pub, *author;
    float price;
    int stock;
public:
    static int stran, ustran;
    book(char a[], char b[], char c[], float d, int e)
    {
        title = new char(strlen(a)+1);
        strcpy(title,a);
        author = new char(strlen(b)+1);
        strcpy(author,b);
        pub = new char(strlen(c)+1);
        strcpy(pub,c);
        price = d;
        stock = e;
    }
    void display()
    {
        cout<<"\n\tTitle Name:\t"<<title;
        cout<<"\n\tAuthor Name:\t"<<author;
        cout<<"\n\tPublisher Name:\t"<<pub;
        cout<<"\n\tPrice:\t"<<price;
        cout<<"\n\tStock:\t"<<stock;
    }
    int find(char buy[], char auth[])
    {
        if(strcmp(buy,title)==0 && strcmp(auth,author)==0)
        return 1;
        else    return 0;
    }
    void buy()
    {
        int cnt;
        cout<<"\n\tEnter the No. of books you want to buy:\t";
        cin>>cnt;
        if(cnt <= stock)
        {
            stock -= cnt;
            cout<<"\n\tBought Successfully\t";
            cout<<"\n\tAmount:\t"<<price*cnt;
            stran++;
        }
        else 
        {
            cout<<"\n\tRequired No. of Copies Not in stock\t";
            ustran++;
        }
    }
    void modify()
    {
        int ch, pri, sto;
        char a[100], b[100], c[100];
        cout<<"\n\tEnter the detail you want to Update\t";
        cout<<"\n\t1.Title\t";
        cout<<"\n\t2.Author Name\t";
        cout<<"\n\t3.Publisher Name\t";
        cout<<"\n\t4.Price\t";
        cout<<"\n\t5.Stock\t";
        cin>>ch;
        switch(ch)
        {
            case 1: delete[] title;
                    cout<<"\n\tEnter the New Title:\t";
                    cin>>a;
                    title = new char(strlen(a)+1);
                    strcpy(title,a);
                    break;
            case 2: delete[] author;
                    cout<<"\n\tEnter the New Author Name:\t";
                    cin>>b;
                    author = new char(strlen(b)+1);
                    strcpy(author,b);
                    break;
            case 3: delete[] pub;
                    cout<<"\n\tEnter the New Publisher Name:\t";
                    cin>>c;
                    pub = new char(strlen(c)+1);
                    strcpy(pub,c);
                    break;
            case 4: cout<<"\n\tEnter the New Price:\t";
                    cin>>pri;
                    price = pri;
                    break;
            case 5: cout<<"\n\tEnter the New Stock:\t";
                    cin>>sto;
                    stock = sto;
                    break;
        }
    }

};
int book::stran;
int book::ustran;

int main()
{
    int n, i = 0, ch, t, s;
    char a[100], b[100], c[100], tbuy[30], aubuy[30], h;
    float p;
    book *m[30];
    do
    {
        cout<<"\n\t-------Book Shop-------\t";
        cout<<"\n\t1.Enter A New Book\t";
        cout<<"\n\t2.Buy A Book\t";
        cout<<"\n\t3.Search for A Book\t";
        cout<<"\n\t4.Update Book Record\t";
        cout<<"\n\t5.Successful And Unsuccessful transactions\t";
        cout<<"\n\t6.Exit!!!!\t";
        cout<<"\n\tEnter Your Choice\t";
        cin>>ch;
        switch (ch)
        {
        case 1: do
                {
                    cout<<"\n\tTitle Of Book:\t";   cin>>a;
                    cout<<"\n\tAuthor Name:\t";     cin>>b;
                    cout<<"\n\tPublisher Name:\t";  cin>>c;
                    cout<<"\n\tCost of Each Book:\t";   cin>>p;
                    cout<<"\n\tStock Of book:\t";   cin>>s;
                    m[i] = new book(a,b,c,p,s); 
                    i++;
                    cout<<"\n\tWant to Enter More Record(y/n):\t";  cin>>h;
                } while (h == 'y'|| h == 'Y');
                break;
        case 2: cout<<"\n\tEnter the Title of Book you want to buy:\t"; cin>>tbuy;
                cout<<"\n\tEnter the Name of Author:\t";    cin>>aubuy;
                for(t = 0; t < i; t++)
                {
                    if(m[t]->find(tbuy, aubuy))
                    {
                        cout<<"\n\tBook Found\t";
                        m[t]->buy();
                        break;
                    }
                }
                if(t == i)
                cout<<"\n\tThis Book is not in stock\t";
                break;
        case 3: cout<<"\n\tEnter the Title of Book Whose Detail you want to show:\t"; cin>>tbuy;
                cout<<"\n\tEnter the Name of Author:\t";    cin>>aubuy;
                for(t = 0; t < i; t++)
                {
                    if(m[t]->find(tbuy, aubuy))
                    {
                        cout<<"\n\tBook Found\t";
                        m[t]->display();
                        break;
                    }
                }
                if(t == i)
                cout<<"\n\tThis Book is not in stock\t";
                break;
        case 4: cout<<"\n\tEnter the Title of Book you want edit:\t"; cin>>tbuy;
                cout<<"\n\tEnter the Name of Author:\t";    cin>>aubuy;
                for(t = 0; t < i; t++)
                {
                    if(m[t]->find(tbuy, aubuy))
                    {
                        cout<<"\n\tBook Found\t";
                        m[t]->modify();
                        break;
                    }
                }
                if(t == i)
                cout<<"\n\tThis Book is not in stock\t";
                break;        
        case 5: cout<<"\n\tNo. of successful Transaction:\t"<<book::stran;
                cout<<"\n\tNo. of Unsuccessful Transaction:\t"<<book::ustran;
                break;
        default:    cout<<"\n\tTerminating!!!";
            break;
        }
    }while(ch!=6);
}