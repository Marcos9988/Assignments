#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class personal
{
    int id;
    char name[30];
    char dob[20];
    char bloodgp[5];
public:
    personal()
    {
        id=0;
        strcpy(name,"ASHISH MISHRA");
        strcpy(dob,"03/04/2000");
        strcpy(bloodgp,"B+");
    }
    personal(int i,char a[30], char b[20], char c[5])
    {
        id=i;
        strcpy(name,a);
        strcpy(dob,b);
        strcpy(bloodgp,c);
    }
    void display()
    {
        cout<<"\n\tID NO.:-\t"; cout<<id;
        cout<<"\n\tNAME:\t";puts(name);
        cout<<"\n\tDATE OF BIRTH:\t";puts(dob);
        cout<<"\n\tBLOOD GROUP:\t";puts(bloodgp);
    }
    void getdata()
    {
        cout<<"\n\tEnter the Name\t";   fflush(stdin);   gets(name);
        cout<<"\n\tEnter the DOB\t";    gets(dob);
        cout<<"\n\tEnter the Blood Group\t";    gets(bloodgp);
    }
    int get(int i)
    {
        if(i==id)
            return 1;
        else return 0;
    }
};

class medical
{
    float ht;
    float wt;
public:
    medical()
    {
        ht=178.5;
        wt=60;
    }
    medical(float d, float e)
    {
        ht=d;
        wt=e;
    }
    void display()
    {
        cout<<"\n\tHEIGHT:\t"<<ht;
        cout<<"\n\tWEIGHT:\t"<<wt;
    }
    void getdata()
    {
        cout<<"\n\tEnter the Height\t"; cin>>ht;
        cout<<"\n\tEnter the Weight\t"; cin>>wt;
    }
};

class insure
{
    long int policy;
    char add[200];
public:
    insure()
    {
        policy=254654854;
        strcpy(add,"AIT PUNE DIGHI");
    }
    insure(long int f, char g[200])
    {
        policy=f;
        strcpy(add,g);
    }
    void display()
    {
        cout<<"\n\tPOLICY NO.:\t"<<policy;
        cout<<"\n\tADDRESS:\t";puts(add);
    }
    void getdata()
    {
        cout<<"\n\tEnter the Policy no.\t"; cin>>policy;
        cout<<"\n\tEnter the Address\t"; fflush(stdin);   gets(add);
    }
};

class drive: public personal, public medical, public insure
{
    long int mob;
    long int drilic;
public:
    drive()
    {
        mob=8898224;
        drilic=0;
    }
    drive(int i,char a[30], char b[20], char c[5], float d, float e, long int f, char g[200], long int h, long int dl):personal(i,a,b,c),medical(d,e),insure(f,g)
    {
        mob=h;
        drilic=dl;
    }
    void displaydata()
    {
        personal::display();
        medical::display();
        insure::display();
        cout<<"\n\tMOBILE NO:\t"<<mob;
        cout<<"\n\tDRIVING LICENCE NO:\t"<<drilic<<endl;
        cout<<"\n\t";
    }
    void getdata()
    {
        int ch;
        do
        {
            cout<<"\n\tEnter your choice\t";
            cout<<"\n\t1.NAME, DOB, BLOODGROUP\t";
            cout<<"\n\t2.HEIGHT, WEIGHT\t";
            cout<<"\n\t3.POLICY NO, ADDRESS\t";
            cout<<"\n\t4.MOBILE NO, DRIVING LICENCE\t";
            cout<<"\n\t5.EXIT!!";
            cin>>ch;
            switch(ch)
            {
                case 1: personal::getdata();
                        break;
                case 2: medical::getdata();
                        break;
                case 3: insure::getdata();
                        break;
                case 4: cout<<"\n\tEnter the Mobile no:\t"; cin>>mob;
                        cout<<"\n\tEnter the Driving license No.:\t";   cin>>drilic;
                        break;
                default: cout<<"\n\tEXIT FROM EDIT DATA\t";
                        break;
            }
        }while(ch!=5);
    }
};

int main()
{
    drive *p[30];
    int ch,t,i=0,id,flag=0,id2,ch1,id1,j,k;
    char name[30], dobt[20], bg[5], address[200];
    float height, weight;
    long int policy, mobile, driv;
    do
    {
        cout<<"\n\t-------PERSONAL RECORD MENU-------\t";
        cout<<"\n\t1.ENTER A NEW RECORD\t";
        cout<<"\n\t2.DISPlAY ALL\t";
        cout<<"\n\t3.DELETE A ENTRY\t";
        cout<<"\n\t4.EDIT A RECORD\t";
        cout<<"\n\t5.SEARCH FOR A RECORD\t";
        cout<<"\n\t6.EXIT!!!\t";
        cout<<"\n\tENTER YOUR CHOICE\t";
        cin>>ch;
        switch(ch)
        {
            case 1: do
                    {
                        cout<<"\n\tEnter the ID No.:\t";    cin>>id;
                        flag=1;
                        if(i!=0)
                        {
                            for(k=0;k<i;k++)
                            {
                                id2=p[k]->get(id);
                                if(id2==1)
                                    flag++;
                            }
                        }
                        if(flag==1)
                        {
                            cout<<"\n\tEnter The Name:\t";  fflush(stdin);  gets(name);
                            cout<<"\n\tEnter The DOB:\t";   gets(dobt);
                            cout<<"\n\tEnter The Blood Group:\t";   gets(bg);
                            cout<<"\n\tEnter The Height:\t";    cin>>height;
                            cout<<"\n\tEnter The Weight:\t";    cin>>weight;
                            cout<<"\n\tEnter The Policy No.:\t";    cin>>policy;
                            cout<<"\n\tEnter The Address:\t"; fflush(stdin);  gets(address);
                            cout<<"\n\tEnter The Mobile No.:\t";    cin>>mobile;
                            cout<<"\n\tEnter The Driving License No.:\t";   cin>>driv;
                            p[i]=new drive(id,name,dobt,bg,height,weight,policy,address,mobile,driv);
                            cout<<"\n\tEnter 1 To Exit or any other key to continue:\t";    i++;
                            cin>>ch1;
                        }
                        else
                        {
                            cout<<"\n\tThe ID is Already There\t";
                            cout<<"\n\tEnter 1 To Exit or any other key to continue:\t";
                            cin>>ch1;
                        }
                    }while(ch1!=1);
                    break;
            case 2: for(j=0;j<i;j++)
                    {
                        p[j]->displaydata();
                    }
                    break;
            case 3: cout<<"\n\tEnter the ID No. Whose Record you Want to delete:\t";
                    cin>>id1;
                    for(j=0;j<i;j++)
                    {
                        id2=p[j]->get(id1);
                        if(id2!=0)
                        {
                            for(k=j;k<i&&(k+1)<i;k++)
                            {
                                p[k]=p[k+1];
                            }
                            delete p[i];
                             i--;
                        }
                    }

                    break;
            case 4: cout<<"\n\tEnter the Id no. whose record you want to edit:\t";
                    cin>>id1;
                    flag=0;
                    for(k=0;k<i;k++)
                    {
                     id2=p[k]->get(id1);
                     if(id2==1)
                        flag++;
                    }

                    if(flag==1)
                    {
                    for(j=0;j<i;j++)
                    {
                        id2=p[j]->get(id1);
                        if(id2!=0)
                            break;
                    }
                    p[j]->getdata();
                    }
                    if(flag==0)
                    {
                        cout<<"\n\tThe Id is not there\t";
                    }
                    break;
            case 5: cout<<"\n\tEnter the ID no. whose Record you want to search\t";
                    cin>>id1;
                    for(j=0;j<i;i++)
                    {
                        id2=p[j]->get(id1);
                        if(id2!=0)
                        p[j]->displaydata();
                    }

                    break;
            default: cout<<"\n\tTERMINATING!!!!\t";

        }
    }while(ch!=6);
}
