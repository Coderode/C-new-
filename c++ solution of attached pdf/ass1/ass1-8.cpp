#include<iostream>
#include<conio.h>
using namespace std;
class Time{
	int h,m;
	public:
		Time():h(0),m(0){}	
		void input()
		{
			cout<<"Enter time (hour and minute respectively):"<<endl;
			cin>>h>>m;	
		}
		friend void display(Time);
		friend void gettime(Time);
		friend Time sum(Time,Time);
};
void display(Time t)
	{
		cout<<"result(hh:mm)="<<t.h<<":"<<t.m<<endl;
	}
void gettime(Time t)
	{
 		cout<<"time:"<<t.h<<":"<<t.m<<endl;		
	}
Time sum(Time t1,Time t2)
	{
		Time t3;
		t3.h=(t1.h+t2.h)+(t1.m+t2.m)/60;
		t3.m=(t1.m+t2.m)%60;
		return t3;	
	}
int main()
{
	Time t1,t2,t3;
	cout<<"to add two times in hh:mm"<<endl;
	cout<<"Enter time1"<<endl;
	t1.input();
	gettime(t1);
	cout<<"Enter time2"<<endl;
	t2.input();
	gettime(t2);
	t3=sum(t1,t2);
	display(t3);
	getch();
	return 0;
}
