#include<iostream>
#include<conio.h>
using namespace std;
class marks{
	int a,b,c;
	public:
		marks(int a,int b,int c)
		{
			this ->a =a;
			this ->b=b;
			this ->c=c;
		}
		int least_mark()
		{
			return a<b? a<c?a:c : b<c ? b:c;
		}
};
int main()
{
	int a,b,c;
	char ans;
	do{
	cout<<"\nEnter the marks of 3 subjects: \n";
	cin>>a;
	while(!cin or a<0)
	{
		cout<<"\nError enter again!\n";
		cin.clear();
		cin.ignore();
		cin>>a;
	}
	cin>>b;
	while(!cin or b<0)
	{
		cout<<"\nError enter again!\n";
		cin.clear();
		cin.ignore();
		cin>>b;
	}
	cin>>c;
	while(!cin or c<0)
	{
		cout<<"\nError enter again!\n";
		cin.clear();
		cin.ignore();
		cin>>c;
	}
	marks m(a,b,c);
	cout<<"\nLeast number obtained among three subjects is: "<<m.least_mark()<<endl;
	cout<<"\nDo you want to continue? y or n:";
	cin>>ans;
	}while(ans=='y');
	getch();
	return 0;
}
