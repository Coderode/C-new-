#include<iostream>
#include<conio.h>
using namespace std;
class digit{
	int d;
	public:
		digit():d(0){}
		digit(int i){d=i;}
		//prefix increment
		int operator++()
		{
			++d;
			return d;
		}
		//postfix increment
		int operator++(int)
		{
			//saving previous value
			int c=d;
			//increment this object
			++d;
			//return old value
			return c;
		}
		void print()
		{
			cout<<"\ndigit="<<d<<endl;
		}		
};
int main()
{
	digit c(10);
	cout<<"\nc=";
	c.print();
	cout<<"\n++c="<<++c<<endl;
	cout<<"\nc++="<<c++<<endl;
	
	cout<<"\nc=";
	c.print();
	getch();
	return 0;		
}





//operator overloading without any argument will be used as prefix always like +a,++a,!a
//if one argument then used as postfix a++,a!, or a+b=(a+)b  b is as argument value, a+=b  a=(a+)b
//if two arguments then used as (a)+(b)   a first argument b-second argument;
