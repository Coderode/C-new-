#include<iostream>
#include<conio.h>
using namespace std;
class division{
	int a,b;
	public:
		void getdata()
		{
			cout<<"\nEnter number 1: ";
			cin>>a;
			if(!cin){
				throw 1;   //throw by integer
			}
			cout<<"\nEnter number 2 :";
			cin>>b;
			if(!cin){
				throw 1;    //throw by integer
			}
		}
		float divide()
		{
			if(b==0)
			{
				throw 'a';   //throw by character
			}
			return a/1.0/b;
		}
};
int main()
{
	char ans;
	division d;
	do{
		
	try{
	cout<<"\nEnter numbers for division : \n";
	d.getdata();
	cout<<"number1/number2= "<<d.divide()<<endl;
	}
	catch(int x){
		cout<<"\nException caught not a integer!"<<endl;
	}
	catch(char y)
	{
		cout<<"\nDivision by zero occurs!\n";
	}
	catch(...)
	{
		cout<<"\nDefault Exception is caught!\n";
	}
	
	
	cin.clear();
	cin.ignore();
	
	cout<<"\nDo you want to continue? y or n: ";
	cin>>ans;
	}while(ans=='y');
	getch();
	return 0;
}
