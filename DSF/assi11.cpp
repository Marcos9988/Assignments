#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class student
{
    int roll;
    string name, dob;
    float mark1, mark2;
public:
    void getdata()
    {
        cout<<"\n\tEnter The Roll no.:-\t"; cin>>roll;
        cout<<"\n\tEnter The Name:-\t";   cin>>name;
        cout<<"\n\tEnter The Date of birth:-\t";   cin>>dob;
        cout<<"\n\tEnter The Marks1 and Marks2:-\t";   cin>>mark1>>mark2;
    }
    void display()
    {
        cout<<"\n\tRoll No.:-\t"<<roll;
        cout<<"\n\tName:-\t"<<name;
        cout<<"\n\tDOB:-\t"<<dob;
        cout<<"\n\tMarks1:-\t"<<mark1;
        cout<<"\n\tMarks2:-\t"<<mark2;
    }
    int uni()
    {
        return roll;
    }
    void edit()
    {
        cout<<"\n\tRoll No.:-\t"<<roll;
        cout<<"\n\tEnter The Name:-\t";   cin>>name;
        cout<<"\n\tEnter The Date of birth:-\t";   cin>>dob;
        cout<<"\n\tEnter The Marks1 and Marks2:-\t";   cin>>mark1>>mark2;
    }
    friend fstream & operator >>(fstream &in, student &s);
    friend fstream & operator <<(fstream &out, student &s);
    void report()
    {
        cout<<"\n\t"<<roll<<"\t\t"<<name<<"\t\t"<<dob<<"\t\t"<<mark1<<"\t\t"<<mark2;
    }

};
fstream & operator >>(fstream &in, student &s)
{
    in>>s.roll>>s.name>>s.dob>>s.mark1>>s.mark2;
    return in;
}
fstream & operator <<(fstream &out, student &s)
{
    out<<"\n\t"<<s.roll<<"\t\t"<<s.name<<"\t\t"<<s.dob<<"\t\t"<<s.mark1<<"\t\t"<<s.mark2;
    return out;
}

void create()
{
    fstream fp;
    student s;
    char ch;
    fp.open("student.txt",ios::out|ios::trunc);
    do
    {
        s.getdata();
        fp<<s;
        cout<<"\n\tWant to Enter more records:-\t, press Y or y:-\t";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}

void inser()
{
    fstream fp;
    student s;
    char ch;
    fp.open("student.txt",ios::out|ios::app);
    do
    {
        s.getdata();
        fp<<s;
        cout<<"\n\tWant to Enter more records:-\t, press Y or y:-\t";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}

void display_per()
{
    fstream fp;
    student s;
    int n, flag = 0;
    cout<<"\n\tEnter The roll no. of student whose record you want to search:-";    cin>>n;
    fp.open("student.txt",ios::in);
    while(!fp.eof())
    {
        fp>>s;
        if(n == s.uni())
        {
            s.display();
            flag = 1;
        }

    }
    fp.close();
    if(flag == 0)
        cout<<"\n\tRecord Does Not Exist\t";
}

void modify()
{
    fstream fp, fp1;
    student s;
    int n, flag = 0;
    cout<<"\n\tEnter the Roll no. of student whose record you want to modify:\t";   cin>>n;
    fp.open("student.txt",ios::in|ios::out);
    fp1.open("temp.txt",ios::out);
    while(!fp.eof())
    {
        fp>>s;
        if(n != s.uni())
        fp1<<s;
        else
        {
            cout<<"\n\tEnter the New details:-\t";
            s.edit();
            fp1<<s;
            cout<<"\n\tRecord Updated";
            flag = 1;
        }
    }
    fp.close();
    fp1.close();
    remove("student.txt");
    rename("temp.txt","student.txt");
    if(flag == 0)
        cout<<"\n\tRecord Not found";
}

void del()
{
    fstream fp, fp1;
    student s;
    int n, flag = 0;
    cout<<"\n\tEnter the Roll no. of student whose record you want to delete:\t";   cin>>n;
    fp.open("student.txt",ios::in|ios::out);
    fp.seekg(0, ios::beg);
    fp1.open("temp1.txt",ios::out);
    while(!fp.eof())
    {
        fp>>s;
        if(n != s.uni())
        {
            fp1<<s;
        }
        else flag = 1;
    }
    fp.close();
    fp1.close();
    remove("student.txt");
    rename("temp1.txt","student.txt");
    if(flag == 1)
        cout<<"\n\tRecord Deleted";
    else cout<<"\n\tNOT FOUND";

}

void display_all()
{
    fstream fp;
    student s;
    fp.open("student.txt", ios::in);
    if(!fp)
    {
        cout<<"\n\tFILE CANNOT BE OPENED. ERROR!!!!\t";
        return ;
    }
    cout<<"\n\tSTUDENT RECORD\t";
    cout<<"\n\tRoll No.\t\tName\t\tDOB\t\tMarks 1\t\tMarks 2";
    while(!fp.eof())
    {
        fp>>s;
        s.report();
    }
    fp.close();
}

int main()
{
    int ch;
    do
    {
        cout<<"\n\tSTUDENT DATABASE MENU USING FILE\t";
        cout<<"\n\t1.Create a Database\t";
        cout<<"\n\t2.Display the Database\t";
        cout<<"\n\t3.Display a particular\t";
        cout<<"\n\t4.Insert a Record\t";
        cout<<"\n\t5.Modify a Record\t";
        cout<<"\n\t6.Delete a Record\t";
        cout<<"\n\t7.EXIT!!!\t";
        cin>>ch;
        switch(ch)
        {
            case 1: create();
                    break;
            case 2: display_all();
                    break;
            case 3: display_per();
                    break;
            case 4: inser();
                    break;
            case 5: modify();
                    break;
            case 6: del();
                    break;
            default: cout<<"\n\tTerminating!!!!\t";
                    break;
        }
    }while(ch!=7);
}
