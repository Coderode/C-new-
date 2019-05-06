#include<iostream>
#include<conio.h>
using namespace std;
class A;
class B;
class C;
class D;
class A{
	int a;
	public:
		A()
		{
			a=10;
		}
		void getA()
		{
			cout<<"a="<<a<<endl;
		}
		friend class B;
		friend class C;
		friend class D;
		
};
class B{
	int b;
	public:
		B()
		{
			b=20;
		
		}
		void getB()
		{	cout<<"b="<<b<<endl;
		}
		friend class D;
	
};
class C{
	int c;
	public:
		C()
		{
			c=30;
			
		}
		void getC()
		{
			cout<<"c="<<c<<endl;
		}
		friend class D;
	
};
class D{
	int d;
	public:
		D()
		{
			d=40;		
		}
		void getD()
		{
			A a;
			B b;
			C c;
			cout<<"a="<<a.a<<endl;
			cout<<"b="<<b.b<<endl;
			cout<<"c="<<c.c<<endl;
			cout<<"d="<<d<<endl;
		}
		
};
int main()
{
	D d;
	d.getD();
	getch();
	return 0;
	
	
}
