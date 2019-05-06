#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
template<class T,class U>
class power{
	T x;
	U y;
	public:
		power()
		{
			float p;  //for not accepting float data type
			cout<<"\n\nCalculation of x^y:\n";
			cout<<"\nEnter x (integer or float):";
			cin>>x;
			
			if(cin.fail())
			 throw 10;
			 
			cout<<"\nEnter y (integer):";
			cin>>p;  //taking value in float
			
			if(cin.fail() or ceil(p)>floor(p))   // or !cin  == cin.fail() true and false
			 throw 'a';
			 
			y=p;  //only if ceil(p)==floor(p)  that is an integer value
			cin.clear();
			cin.ignore();	
		}
		float calculate()
		{
			float ans=1;
			if(y==0)
				return ans;
			if(y>0)
			{
				for(int i=1; i<=y; i++)
				{
					ans=ans*x;
				}
				return ans;
			}
			else
			{
				for(int i=1; i<=(-y); i++)
				{
					ans=ans*(1/x);
				}
				return ans;
			}
		}
		
};
int main()
{
	
	char ans;
	do{
	try{
		power<float,int> p;
	cout<<"\nx^y="<<p.calculate()<<endl;
	}
	catch(int){
		cout<<"\nwrong data type x can be integer or float only\n";
	}
	catch(char){
		cout<<"\nwrong data type y must be integer only!\n";
	}
	catch(...){
		cout<<"\nDefault exception";
	}
	cin.clear();
	cin.ignore();
	cout<<"\nDo you want to continue? y or n:";
	cin>>ans;
	system("cls");
	}while(ans=='y');
	getch();
	return 0;
}
