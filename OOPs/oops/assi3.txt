#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
class personal
{
    char name[50];
    char add[100];
    int age;
    char dob[10];
    char gender[10];
    long long int mob;
    char email[50];
public:
    personal()
    {
        strcpy(name,"Ashishmishra");
        strcpy(add,"AitPune");
        age=0;
        strcpy(dob,"03 Apr 2000");
        strcpy(gender,"Male");
        mob= 0;
        strcpy(email,"ashishkite88@gmail.com");
    }
    personal(char na[], char ad[], int ag, char don[], char ge[], long long int mo, char em[])
    {
        strcpy(name,na);
        strcpy(add,ad);
        age=ag;
        strcpy(dob,don);
        strcpy(gender,ge); mob= mo;
        strcpy(email,em);
    }

    void display()
    {
        cout<<"\n\tNAME:\t"; puts(name);
        cout<<"\n\tADDRESS:\t"; puts(add);
        cout<<"\n\tAGE:\t"<<age;
        cout<<"\n\tDATE OF BIRTH:\t";puts(dob);
        cout<<"\n\tGENDER:\t";puts(gender);
        cout<<"\n\tMOBILE NO.:\t"<<mob;
        cout<<"\n\tEMAIL ID:\t";puts(email);
    }
};

class professional
{
    char designation[50];
    int emyno;
    char yoj[20];
    float income;
    int exp;
    int norp;
public:
    professional()
    {
        strcpy(designation,"Chief Executive Officer");
        emyno= 0;
        strcpy(yoj,"12 Dec 2018");
        income= 0;
        exp= 0;
        norp= 0;
    }
    professional(char des[], int emy, char yo[], float inc, int ex, int nor)
    {
        strcpy(designation,des);
        emyno=emy;
        strcpy(yoj,yo);
        income= inc;
        exp= ex;
        norp= nor;
    }
    void display()
    {
        cout<<"\n\tDESIGNATION:\t";puts(designation);
        cout<<"\n\tEMPLOYEE NO:\t"<<emyno;
        cout<<"\n\tYEAR OF JOIONING:\t";puts(yoj);
        cout<<"\n\tMONTHLY INCOME:\t"<<income;
        cout<<"\n\tTOTAL YEAR EXPERIENCE:\t"<<exp;
        cout<<"\n\tNO. OF RESEARCH PAPER PUBLISHED:\t"<<norp;
    }
};

class academic
{
    float xmarks;
    float xiimarks;
    float gmarks;
    float pgmarks;
    char schoolname[100];
    char collegename[100];
public:
    academic()
    {
        xmarks= 0;
        xiimarks=0;
        gmarks= 0;
        pgmarks=0;
        strcpy(schoolname,"Kendriya Vidyalaya Bhandup");
        strcpy(collegename,"Army Institute Of Technology");
    }
    academic(float a, float b, float c, float d, char s[], char m[])
    {
        xmarks=a;
        xiimarks=b;
        gmarks=c;
        pgmarks=d;
        strcpy(schoolname,s);
        strcpy(collegename,m);
    }
    void display()
    {
        cout<<"\n\tPERCENTAGE IN Xth CLASS:\t"<<xmarks;
        cout<<"\n\tPERCENTAGE IN XIIth CLASS:\t"<<xiimarks;
        cout<<"\n\tPERCENTAGE IN GRADUATION:\t"<<gmarks;
        cout<<"\n\tPERCENTAGE IN POST GRADUATION:\t"<<pgmarks;
        cout<<"\n\tSCHOOL NAME:\t";puts(schoolname);
        cout<<"\n\tCOLLEGE NAME:\t";puts(collegename);
    }
};

class biodata: public personal, public professional, public academic
{
    int inetrn;
public:
    biodata()
    {
        inetrn= 0;
    }
    biodata(char na[], char ad[], int ag, char don[], char ge[], long long int mo, char em[],char des[], int emy, char yo[], float inc, int ex, int nor,float a, float b, float c, float d, char s[], char m[],int intern):personal(na,ad,ag,don,ge,mo,em),professional(des,emy,yo,inc,ex,nor),academic(a,b,c,d,s,m)
    {
        inetrn=intern;
    }
    void displaydata()
    {
        cout<<"\n\t----BIODATA-----\t";
        personal::display();
        professional::display();
        academic::display();
        cout<<"\n\tNO. OF INTERNSHIPS:\t"<<inetrn;
    }
};
int main()
{
    char name[200], address[200],dob[50],gen[30],emai[100],desig[80], yojin[50],school[200],college[200];
    int agh, emynos,exp,nrp,internship;
    long long int mobno;
    float incom,xmar,xiimar,gmar,pgmar;
    int k;
    float c;
    cout<<"\n\tEnter the Name:\t";
    gets(name);
    cout<<"\n\tEnter the Address:\t";
    gets(address);
    cout<<"\n\tEnter the Age:\t";
    cin>>agh;
    cout<<"\n\tEnter the date of birth:\t";
    fflush(stdin);
    gets(dob);
    cout<<"\n\tEnter the gender:\t";
    gets(gen);
    cout<<"\n\tEnter the mobile no.:\t";
    cin>>mobno;
    cout<<"\n\tEnter the Email id:\t";
    fflush(stdin);
    gets(emai);
    cout<<"\n\tEnter the designation:\t";
    gets(desig);
    cout<<"\n\tEnter your employee no.:\t";
    fflush(stdin);
    cin>>emynos;
    cout<<"\n\tEnter the year of joining:\t";
    fflush(stdin);
    gets(yojin);
    cout<<"\n\tEnter the Monthly income:\t";
    fflush(stdin);
    cin>>incom;
    cout<<"\n\tEnter the NO. of year of experience:\t";
    cin>>exp;
    cout<<"\n\tEnter the No. Of research paper published:\t";
    cin>>nrp;
    cout<<"\n\tEnter the percentage in 10th class:\t";
    cin>>xmar;
    cout<<"\n\tEnter the percentage in 12th class:\t";
    cin>>xiimar;
    cout<<"\n\tEnter the percentage in graduation:\t";
    cin>>gmar;
    cout<<"\n\tEnter the percentage in post graduation:\t";
    cin>>pgmar;
    cout<<"\n\tEnter the School name:\t";
    fflush(stdin);
    gets(school);
    cout<<"\n\tEnter the College name:\t";
    gets(college);
    cout<<"\n\tEnter the no. of internship completed:\t";
    fflush(stdin);
    cin>>internship;
    biodata *b;
    b= new biodata(name,address,agh,dob,gen,mobno,emai,desig,emynos,yojin,incom,exp,nrp,xmar,xiimar,gmar,pgmar,school,college,internship);
    b->displaydata();

}

