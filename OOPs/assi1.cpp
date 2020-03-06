#include<iostream>
using namespace std;

class Weather
    {
        int ht, lt, as, ar;
        static int aht, alt, aas, aar;
        public:
        Weather()
        {
            ht=36;
            lt=24;
            as=20;
            ar=54;
        }
        void getdata()
        {
            cout<<"\n\tEnter the High Temperature of the day\t";
            cin>>ht;
            cout<<"\n\tEnter the Low Temperature of the day\t";
            cin>>lt;
            cout<<"\n\tEnter the Amount of Snow\t";
            cin>>as;
            cout<<"\n\tEnter the Amount of rain\t";
            cin>>ar;
            aht+=ht;
            alt+=lt;
            aas+=as;
            aar+=ar;             
        }
        
        void display(int i)
        {
            cout<<"\t"<<i<<"\t"<<ht<<"\t"<<lt<<"\t"<<as<<"\t"<<ar<<endl;
        }
        
        void average(int j)
        {
            cout<<"\n\tAverage High Temp\t"<<(aht/j);
            cout<<"\n\tAverage Low Temp\t"<<(alt/j);
            cout<<"\n\tAverage Amount of snow\t"<<(aas/j);
            cout<<"\n\tAverage Amount of snoe\t"<<(aar/j);
        } 
        
    };
int Weather::aht;
int Weather::alt;
int Weather::aas;
int Weather::aar;


int main()
    {
        Weather w[31];
        int ch,i,j=0,dayno,n;
        do
        {
            cout<<"\n\n\t--------WEATHER REPORT MENU---------\n";
            cout<<"\n\t1. ACCEPT\t";
            cout<<"\n\t2. DISPLAY ALL\t";
            cout<<"\n\t3. DISPLAY SPECIFIC\t";
            cout<<"\n\t4. MONTHLY REPORT\t";
            cout<<"\n\t5. EXIT\t";
            cout<<"\n\tEnter your Choice\t";
            cin>>ch;
            switch(ch)
            {
               case 1:  cout<<"\n\tEnter The No. Of Days Whose Data You Want To Enter\t";
                        cin>>n;
                        j+=n;
                        for(i=0;i<n;i++)
                        {
                            cout<<"\n\tEnter the Day No. whose data you want to enter the record\t";
                            cin>>dayno;
                            w[dayno].getdata();
                        }  
                        break;
                        
               case 2:  cout<<"\n\tDisplaying The All Data\n";
                        cout<<"\tDay\t HT\t LT\t SF\t RF"<<endl;
                        for(i=0;i<31;i++)
                        {
                            w[i].display(i);
                        }
                        break;
                        
               case 3:  cout<<"\n\tDisplaying The Specific Data\t";
                        cout<<"\n\tEnter the no. of days you want to display\t";
                        cin>>n;
                        for(i=0;i<n;i++)
                        {
                            cout<<"\n\tEnter The Day no. whose data you want to show\t";
                            cin>>dayno;
                            w[dayno].display(dayno);
                        }
                        break;
                        
               case 4:  cout<<"\n\tGenerating The Monthly Report\t";
                        for(i=0;i<31;i++)
                        {
                            w[i].display(i);
                        }
                        w[0].average(j);
                        break;
                       
               default: cout<<"\n\tInvalid choice. Terminating!!!!!!!!!\t";
                        break;
                        
             }
        }while(ch!=5);  
        return 0; 
    }   
    
