#include<iostream>
#include<conio.h>
using namespace std;
enum even_odd{even,odd};
class Num{
	int n;
	public:
		Num(int i=0)
		{
			n=i;
		}
		even_odd operator!(void)
		{
			if(n%2==0)
			{
//				cout<<n<<" is even!"<<endl;
				return even;
			}
			else
			{
//				cout<<n<<" is odd!"<<endl;
				return odd;
			}
		}
		
};
int main()
{
	int n;
	char ans;
	do{
	cout<<"\nEnter a number:"<<endl;
	cin>>n;
	Num a(n);
	cin.clear();
	cin.ignore(10000,'\n');
	if(!a==even)
	cout<<n<<" is even!"<<endl;
	if(!a==odd)
	cout<<n<<" is odd!"<<endl;
	cout<<"\ndo you want to continue? (y or n):";
	cin>>ans;
	}while(ans=='y');
//	getch();
	return 0;
}

