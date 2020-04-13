#include<iostream>
#include<bits/stdc++.h>
#include<iomanip>
#include<fstream>
#define SIZE 10
#define h(x) x%SIZE
using namespace std;
struct student
{
    int rollno;
    char name[20];
    float marks;
    int status;
    int link;
};
class lin_probe
{
    char table[30];
    fstream tab;
    student rec;
public:
    lin_probe(){}
    lin_probe(char *a);
    void displayall();
    void insert(student rec1);
    void Delete( int rollno);
    int search(int rolno);
    void display(int recno)
    {
        int i = recno;
        tab.open(table, ios::binary | ios::in);
        tab.seekg(recno * sizeof(student), ios::beg);
        tab.read((char*)&rec, sizeof(student));
        if(rec.status == 0)
        {
            cout << "\n" << i << ") " << rec.rollno << " " << rec.name << " " << setprecision(2) << rec.marks;
            cout << " " << rec.link;
        }
        else
        {
            cout << "\n" << i << ") ***** Empty ***** ";
        }
        tab.close();      
    }
    void read(int recno)
    {
        tab.open(table, ios::binary | ios::in);
        tab.seekg(recno * sizeof(student), ios::beg);
        tab.read((char*)&rec, sizeof(student));
        tab.close();
    }
    void write(int recno)
    {
        tab.open(table, ios::binary | ios::out | ios::in);
        tab.seekg(recno * sizeof(student), ios::beg);
        tab.write((char*)&rec, sizeof(student));
        tab.close();
    }
};

lin_probe::lin_probe(char *a)
{
    int i;
    strcpy(table, a);
    rec.status = 1;
    rec.link = -1;
    tab.open(table, ios::binary | ios::out);
    tab.close();
    for(int i = 0; i < SIZE; i++)
        write(i);
}

void lin_probe::displayall()
{
    int i = 1, n;
    cout << "\n****** Data File ******";
    for(i = 0; i < SIZE; i++)
        display(i);
}

void lin_probe::insert(student rec1)
{
    int n, i, j, k, start;
    rec1.status = 0;
    rec1.link = -1;
    start = h(rec1.rollno); // hashed location
    //locate begining of chain
    for(i = 0; i < SIZE; i++)
    {
        j = (start + i)%SIZE;
        read(j);
        if((rec.status == 0) && (h(rec.rollno) == start))
            break;
    }
    if(i < 10)
    {
        //chain found, goto the end of chain
        while(rec.link != -1)
        {
            j = rec.link;
            read(j);
        }
        //find empty location
        for(i = 0; i < SIZE; i++)
        {
            k = (start + i)%SIZE;
            read(k);
            if(rec.status == 1)
            {
                rec = rec1;
                write(k);
                read(j);
                rec.link = k;
                write(j);
                return;
            }
        }
        cout << "\nTable is full";
    }
    else
    {
        for(i = 0; i < SIZE; i++)
        {
            k = (start + i)%SIZE;
            read(k);
            if(rec.status == 1)
            {
                rec = rec1;
                write(k);
                return;
            }
        }
        cout << "\nTable is full";
    }
}

void lin_probe::Delete(int rollno)
{
    student rec1;
    int recno;
    int i, j, start, k;
    start = h(rollno);//hashed loction for given rolno
    //locate beginning of the chain
    for(i = 0; i < SIZE; i++)
    {
        j = (start + i)%SIZE;
        read(j);
        if((rec.status == 0) && (h(rec.rollno) == start))//synonym found
            break;
    }
    if(i < 10)
    {
        if(rec.rollno == rollno) //found at the beginning of the chain
        {
            rec.status = 1;
            write(j);
        }
        else
        {
            // locate the predecessor
            while(rec.rollno != rollno && rec.link != -1)
            {
                k = j;
                j = rec.link;
                read(j);
            }
            if(rec.rollno == rollno)
            {
                rec.status = 1;
                write(j);
                int nextlink = rec.link;
                read(k);
                rec.link = nextlink;
                write(k);
            }
            else
                cout << "\nElement not found";
        }    
    }
    else 
        cout << "\nRecord not found";
}

int lin_probe::search(int rollno)
{
    int start, i, j;
    start = h(rollno);
    for(i = 0; i < SIZE; i++)
    {
        j = (start + i) % SIZE;
        read(j);
        if((rec.status == 0) && (h(rec.rollno) == start))//synonym found
            break;
    }
    if(i < 10)//chain exists
    {
        while(rec.rollno != rollno && rec.link != -1)
        {
            j = rec.link;
            read(j);
        }
        if(rec.rollno == rollno)
            return j;

        else 
            return -1;
    }
    else 
        return -1;
}

int main()
{
    lin_probe object("table.txt");
    int rollno, op, recno;
    student rec1;
    do
    {
        cout << "\n\n1. Print \n2. Insert\n3. Delete";
        cout << "\n4. Search \n5. Quit";
        cout << "\nEnter Your Choice : ";
        cin >> op;
        switch(op)
        {
            case 1: object.displayall();
                    break;
            case 2: cout << "\nEnter a record to be inserted(rollno, name, marks) : ";
                    cin >> rec1.rollno >> rec1.name >> rec1.marks;
                    object.insert(rec1);
                    break;
            case 3: cout << "\nEnter the roll no : ";
                    cin >> rollno;
                    object.Delete(rollno);
                    break;
            case 4: cout << "\nEnter roll : ";
                    cin >> rollno;
                    recno = object.search(rollno);
                    if(recno >= 0)
                    {
                        cout << "\n Record No. : " << recno;
                        object.display(recno);
                    }
                    else 
                        cout << "\nRecord not found";
                    break;                 
        }
    }while(op != 5);

    int stopper;
    cin >> stopper;
    return 0;
}
