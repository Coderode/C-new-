#include<iostream>
#include<conio.h>
using namespace std;
template<class T,class U>
class Num{
	T x;
	U y;
	public:
	Num()
	{
		cout<<"\n\nCalculation of x^y:\n";
		cout<<"\nEnter x : ";
		cin>>x;
			
		if(!cin)
		 throw 10;
			 
		cout<<"\nEnter y : ";
		cin>>y;
			
		if(cin.fail())
		 throw 10;
			 
		cin.clear();
		cin.ignore();
	}
	void divide()
	{
		if(y==0)
		{
			throw 'a';   //throw by character
		}
		cout<<"\nx/y= "<<x/y;
	}
};
int main()
{
	char ans;
	int option;
	do{
	try{
		while(1)
		{	
			cout<<"\n1.integer/integer\t2.float/integer\t3.integer/float\t4.float/float\t5.exit\nselect option:";
			cin>>option;
			if(option==1)
			{
				Num<int,int> p;
				p.divide();	
			}
			else if(option==2)
			{
				Num<float,int> p;
				p.divide();		
			}
			else if(option==3)
			{
				Num<int,float> p;
				p.divide();	
			}
			else if(option==4)
			{
				Num<float,float> p;
				p.divide();	
			}
			else if(option==5)
			{
				break;
			}
			else
				cout<<"\nwrong selection enter again!\n";
			getch();
			system("cls");
		}	
	}
	catch(int){
		cout<<"\nyou entered wrong data type\n";
	}
	catch(char y)
	{
		cout<<"\nDivision by zero occurs!\n";
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
