#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
class Time{
	int h,m;
	public:
		Time():h(0),m(0){}
		void display()
		{
			cout<<"result="<<h<<":"<<m<<endl;
		}
		void input()
		{
			int flag=0;
			cout<<"Enter time (format hh:mm):"<<endl;
			cin>>h;
			if( cin.get()!=':' or h>24 or h<0)
			{
				cout<<"\nerror in format\n";
				flag=1;
			}
			else
			{
				cin>>m;
				if(m>60 or m<0)
				{
				cout<<"\nError in format\n";
				flag=1;
				}
			}	
			if(flag==1)
			{
				h=m=0;
			}
			gettime(h,m);
		}
		void gettime(int h,int m)
		{
			cout<<"time:"<<h<<":"<<m<<endl;		
		}
		void sum(Time t1,Time t2)
		{
			h=(t1.h+t2.h)+(t1.m+t2.m)/60;
			m=(t1.m+t2.m)%60;	
		}
};
int main()
{
	Time t1,t2,t3;
	char ans;
	do{
	cout<<"to add two times in hh:mm"<<endl;
	cout<<"Enter time1"<<endl;
	t1.input();
	fflush(stdin);
	cout<<"Enter time2"<<endl;
	t2.input();
	t3.sum(t1,t2);
	t3.display();
	cout<<"\ndo you want to continue? y or n:";
	cin>>ans;
	}while(ans=='y' or ans=='Y');
	getch();
	return 0;
	
}
