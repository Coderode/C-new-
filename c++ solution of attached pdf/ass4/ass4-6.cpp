#include<iostream>
#include<conio.h>
using namespace std;
class count{
	protected:
	int c;
	public:
		count()
		{
			c=0;
		}
		count(int i)
		{
			c=i;
		}
		//copy constructor
		count(const count &obj)
		{
			c=obj.c;
		}
		int getdata()
		{
			return c;
		}
		//prefix increment
		int operator++()
		{
			c=c+1;
			return c;
		}
		//postfix increment
		int operator++(int)
		{
			//saving previous value
			int d=c;
			//increment this object
			c=c+1;
			//return old value
			return d;
		}
};
class counter:public count{
	public:
		counter(int i):count(i)
		{}
		counter():count(){
		}
		//copy constructor
		counter(const counter &obj)
		{
			c=obj.c;
		}
		//prefix
		int operator -- ()
		{
			c=c-1;
			return c;
		}		
		//postfix
		int operator -- (int)
		{
			int d=c;
			c=c-1;
			return d;
		}
};
int main()
{
	counter c(10);
	cout<<"C="<<c.getdata()<<endl;
	cout<<"++C="<<++c<<endl;
	cout<<"C++="<<c++<<endl;
	cout<<"C="<<c.getdata()<<endl;
	cout<<"--C="<<--c<<endl;
	cout<<"C--="<<c--<<endl;
	cout<<"C="<<c.getdata()<<endl;
	getch();
	return 0;
		
}
