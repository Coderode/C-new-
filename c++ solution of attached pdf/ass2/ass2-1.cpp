#include<iostream>
#include<conio.h>
using namespace std;

class complex
{
	private:
		float real;
		float imag;
	public:
		complex():real(0),imag(0){}
		complex(float r):real(r),imag(r)
		{	}
		complex(float r,float g):real(r),imag(g)
		{	}
	    
		friend complex* sum(complex&,complex&);
		
		friend void display(complex);
		
};

complex* sum(complex &c1,complex &c2)
	{
		complex c3;
		c3.real=c1.real+c2.real;
		c3.imag=c1.imag+c2.imag;
		return &c3;
	}
void display(complex c)
	{
		cout<<c.real<<"+"<<c.imag<<"i";
	}
int main()
{
	float real,imag;
	complex c4(4);
	display(c4);
	
	char ans;
	do
	{
	cout<<"\naddition of two complex numbers:"<<endl;
	cout<<"complex no.1:"<<endl;
	cout<<"Enter real and imaginary part respectively:"<<endl;
	cin>>real>>imag;
	complex c1(real,imag);
	display(c1);
	
	
	cout<<"\ncomplex no.2:"<<endl;
	cout<<"Enter real and imaginary part respectively:"<<endl;
	cin>>real>>imag;
	complex c2(real,imag);
	display(c2);
	
	
	
	complex *c3=sum(c1,c2);
	cout<<"\nsum of c1 and c2 is:"<<endl;
	display(*c3);
	
	
	cout<<"\nDo you want to continue? (y or n)"<<endl;
	cin>>ans;
	}while(ans=='y' or ans=='Y');
	getch();
	return 0;
}
