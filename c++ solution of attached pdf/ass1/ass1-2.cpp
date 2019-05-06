//calculate total seconds of any time
#include<iostream>
#include<conio.h>
using namespace std;
class clock
{
	public:
	int h,m,s;
	
	void gettime();
	long hms_to_secs(int,int,int);	
};
using namespace std;
long clock::hms_to_secs(int h,int m,int s)
{
	long sec;
	sec=s+(m*60)+(h*60*60);
	return sec;
}
void clock::gettime()
{
	int flag=0;

	cout<<"Enter time (format hh:mm:ss):"<<endl;
	cin>>h;
	if(cin.get()!=':' or h>24 or h<0){
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
			if(s<0 or s>60){
			cin.clear();
			cin.ignore(10000, '\n'); 
			flag=1;
			cout<<"\nerror in format\n";
		}
		}
	}
	if(flag==1)
	{
		h=m=s=0;
	}
	cout<<"Time::"<<h<<":"<<m<<":"<<s<<endl;
}


int main()
{
	char ans;
	do
	{
	clock t1;
	t1.gettime();
	cout<<"Equivalent seconds="<<t1.hms_to_secs(t1.h,t1.m,t1.s)<<endl;
	cout<<"\nDo you want to continue?( y or n):";
	fflush(stdin);
	cin>>ans;
	}while(ans=='y' or ans=='Y');
	getch();

	return 0;
}
