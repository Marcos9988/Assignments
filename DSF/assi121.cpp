#include<bits/stdc++.h>
#include<iomanip>
#include<fstream>
#define size 10
#define ha(x) x%size
using namespace std;
struct stud
{
    int roll, status, link;
    float mark;
    char name[50];
};

class hash1
{
    string table;
    fstream f;
    stud s;
public:
    void read(int rec)
    {
        f.open(table, ios::binary | ios::in);
        f.seekg(rec * sizeof(stud), ios::beg);
        f.read((char*)&s, sizeof(stud));
        f.close();
    }
    void write(int rec)
    {
        f.open(table, ios::binary | ios::out | ios::in);
        f.seekg(rec * sizeof(stud), ios::beg);
        f.write((char*)&s, sizeof(stud));
        f.close();
    }
    hash1(string a)
    {
        table = a;
        s.status = 1;
        s.link = -1;
        f.open(table, ios::binary | ios::out);
        f.close();
        for(int i = 0; i < size; i++)
            write(i);
    }
    void Display(int rec)
    {
        int i = rec;
        f.open(table, ios::binary | ios::in);
        f.seekg(rec * sizeof(stud), ios::beg);
        f.read((char*)&s, sizeof(stud));
        if(s.status == 0)
        {
            cout<< "\n\t" << i << ")  " << s.name <<"  "<<setprecision(2) << s.mark;
            cout<<"  "<<s.link;
        }
        else
            cout<< "\n\t" << i << ") -------Empty------";
        f.close();        
    }
    void displayall()
    {
        cout<<"\n\t-------DATA FILE-------";
        for(int i = 0; i < size; i++)
            Display(i);
    }
    void insert(stud rec)
    {
        int n, i, j, k, start;
        rec.status = 0; rec.link = -1;
        start = ha(rec.roll); // hashed location
        for(i = 0; i < size; i++)
        {
            j = (start + i)%size;
            read(j);
            if((s.status == 0) && (ha(s.roll) == start))
                break;
        }
        if(i < 10)
        {
            while (s.link != -1)
            {
                j = s.link;
                read(j);
            }
            for(i = 0; i < size; i++)
            {
                k = (start + i)%size;
                read(k);
                if(s.status == 1)
                {
                    s = rec;
                    write(k), read(j);
                    s.link = k;
                    write(j);
                    return;
                }
            }
            cout<<"\n\tTable is full";
        }
        else
        {
            for(i = 0; i < size; i++)
            {
                k = (start + i)%size;
                read(k);
                if(s.status == 1)
                {
                    s = rec;
                    write(k);
                    return;
                }
            }
            cout<<"\nTable is full";
        }
    }
    void Delete(int rollno)
    {
        stud s1;
        int rec, i, j, start, k;
        start = ha(rollno);
        for(i = 0; i < size; i++)
        {
            j = (start + i)%size;
            read(j);
            if((s.status == 0) && (ha(s.roll) == start))
                break;
        }
        if(i < 10)
        {
            if(s.roll == rollno)
            {
                s.status = 1;
                write(j);
            }
            else
            {
                while (s.roll != rollno && s.link != -1)
                {
                    k = j;
                    j = s.link;
                    read(j);
                }
                if(s.roll == rollno)
                {
                    s.status = 1;
                    write(j);
                    int next = s.link;
                    read(k);
                    s.link = next;
                    write(k);
                }
                else    cout<<"\n\tElement not found";
            }  
        }
        else
            cout<<"\n\tRecord not found";
    }
    int search(int rollno)
    {
        int start, i, j;
        start = ha(rollno);
        for(i = 0; i < size; i++)
        {
            j = (start + i)%size;;
            read(j);
            if((s.status == 0) && (ha(s.roll) == start))
                break;
        }
        if(i < 10)
        {
            while (s.roll != rollno && s.link != -1)
            {
                j = s.link;
                read(j);
            }
            if(s.roll == rollno)
                return j;
            else return -1;
        }
        else return -1;
    }
};
int main()
{
    hash1 obj("TAT.txt");
    int roll, ch, rec;
    stud s;
    do
    {
        cout<<"\n\t1.Insert";
        cout<<"\n\t2.Display all";
        cout<<"\n\t3.Delete";
        cout<<"\n\t4.Search";
        cout<<"\n\t5.Quit";
        cout<<"\n\tEnter your choice:\t";
        cin>>ch;
        switch (ch)
        {
        case 1: cout<<"\n\tEnter the Record (Roll no, Name, Marks):\t";
                cin>>s.roll>>s.name>>s.mark;
                obj.insert(s);
            break;

        case 2: obj.displayall();
            break;
        
        case 3: cout<<"\n\tEnter the Roll no to be Deleted:\t";
                cin>>roll;
                obj.Delete(roll);
            break;

        case 4: cout <<"\n\tEnter Roll No to searched:\t";
                cin >> roll;
                rec = obj.search(roll);
                if(rec >= 0)
                {
                    cout << "\n\tRecord No. : " << rec;
                    obj.Display(rec);
                }
                else 
                    cout <<"\n\tRecord not found";
            break;
        default:    cout<<"\n\tTerminating!!!!!";
            break;
        }

    } while (ch != 5);
}
