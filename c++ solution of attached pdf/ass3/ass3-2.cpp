#include<iostream>
#include<conio.h>
using namespace std;

class Num{
	int n;
	public:
		Num()
		{
			cout<<"\nEnter a number:";
			cin>>n;
		}
		bool operator--(void)
		{
			int i;
			for(i=2; i<=n/2; i++)
			{
				if(n%i==0)
					break;
			}
			if(i==(n/2+1))
			return true;
			else
			return false;
		}
};
int main()
{
	char ans;
	do{
	Num a;
	if(--a==true)
	cout<<"\nprime"<<endl;
	else
	cout<<"\nNot prime"<<endl;
	cout<<"\ndo you want to continue? (y or n):";
	cin>>ans;
	}while(ans=='y');
	return 0;	
}


//if put operator--(int) then use as a--   used as postfix i.e. after the object

