#include<iostream>
#include<conio.h>
using namespace std;
class Civil_Time;
class Railway_Time;

class Railway_Time{
	int h,m,s;
	public:
		void input()
		{
			int flag=1;
			cout<<"\nRailway_Time\n";
			while(flag==1)
			{
			flag=0;
			cout<<"Enter time (format 24:60:60):"<<endl;
			cin>>h;
			if(cin.get()!=':' or !cin or h>24 or h<0){
				cout<<"Error in format\n";
				cin.clear();
				cin.ignore(); 
				flag=1;
			}
			else
			{
				cin>>m;
				if(cin.get()!=':' or !cin or m<0 or m>60){
					flag=1;
					cin.clear();
					cin.ignore(); 
					cout<<"\nerror in format\n";
				}
				else{
					cin>>s;
					if(!cin or s<0 or s>60){
					cin.clear();
					cin.ignore(); 
					flag=1;
					cout<<"\nerror in format\n";
				}
				}
			}
			if(h==24 and m>0 and s>0)
			{
				h=h%24;
			}

			}
		}
		void display()
		{
			cout<<"\nRailway_Time::"<<h<<":"<<m<<":"<<s<<endl;
		}
		friend class Civil_Time;
		void operator = (Civil_Time c);
		
};
class Civil_Time{
	int h,m,s;
	string zone;
	public:
		void input()
		{
			int flag=1;
			cout<<"\nCivil_Time:\n";
			while(flag==1)
			{
			flag=0;
			cout<<"Enter time (format 12:60:60 AM/PM):"<<endl;
			cin>>h;
			if(cin.get()!=':' or h>12 or h<0){
				cout<<"Error in format\n";
				cin.clear();
				cin.ignore(10000, '\n'); 
				flag=1;
			}
			else
			{
				cin>>m;
				if(cin.get()!=':' or m<0 or m>60){
					flag=1;
					cin.clear();
					cin.ignore(10000, '\n'); 
					cout<<"\nerror in format\n";
				}
				else{
					cin>>s;
					if(cin.get()!=' ' or s<0 or s>60){
					cin.clear();
					cin.ignore(10000, '\n'); 
					flag=1;
					cout<<"\nerror in format\n";
			    	}
			    	else
			    	{
			    		cin>>zone;
			    		if(zone!="AM" and zone!="PM")
			    		{
			    			flag=1;
			    			cout<<"\nerror in format\n";
						}
					}
				}
			}
		
			}
		}
		void display()
		{
			cout<<"\nCivil_Time::"<<h<<":"<<m<<":"<<s<<" "<<zone<<endl;
		}
		
		//class to class data conversion using operator overloading
		void operator = (Railway_Time r)
		{
			if(r.h==12 or r.h==0 or r.h==24)
			{
				h=12; m=r.m; s=r.s;
			}
			else
			{
				h=r.h%12;  m=r.m;  s=r.s;
			}
			if(r.h>=0 and r.h<12)
			{
				zone="AM";
			}
			else if(r.h==12 and r.m==0 and r.s==0)
			zone="PM";
			else if(r.h=24 and r.m==0 and r.s==0)
			zone="AM";
			else
			{
				zone="PM";
			}
			
		}
		friend class Railway_Time;		
};
//railway time to civil time
void Railway_Time::operator = (Civil_Time c)
{		
	if(c.zone=="AM")
		h=c.h%12;
	else
		h=12+c.h%12;
	m=c.m;
	s=c.s;		
}
int main()
{
	Civil_Time c,c2;
	Railway_Time r,r2;
	char ans;
	do{
	r.input();
	r.display();
	c=r;
	cout<<"\nCivil_time is:\n";
	c.display();
	cout<<"\n-----------------------------------------------------\n";
	c2.input();
	c2.display();
	r2=c2;
	cout<<"\nRailway time is:\n";
	r2.display();

	cout<<"\nDo you want to continue? (y or n):";
	cin>>ans;

	system("cls");
	}while(ans=='y');
	getch();
	return 0;
}

