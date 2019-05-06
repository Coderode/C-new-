#include<iostream>
#include<conio.h>
using namespace std;
class base1{
	private:
		int a;
	protected:
		int b;
	public:
		int c;
		base1()
		{
			a=10;
			b=20;
			c=30;	
		}
//		friend class derived;
};
class base2{
	private:
		int d;
	protected:
		int e;
	public:
		int f;
		base2()
		{
			d=40;
			e=50;
			f=60;
		}
		friend class base1;
};
class derived:public base1,public base2{
	int g;
	public:
		derived():g(70){
		}
		void display()
		{
//			cout<<"a="<<a<<endl;
			cout<<"b="<<b<<endl;
			cout<<"c="<<c<<endl;
//			cout<<"d="<<d<<endl;
			cout<<"e="<<e<<endl;
			cout<<"f="<<f<<endl;
			cout<<"g="<<g<<endl;
		}
};
int main()
{
	derived d;
	d.display();
	getch();
	return 0;	
}
