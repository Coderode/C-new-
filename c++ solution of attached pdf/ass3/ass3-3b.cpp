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
	    
		friend complex operator+(complex a,complex b);
		
		void display()
		{
			cout<<real<<"+"<<imag<<"i";
		}
		
		
};
complex operator+(complex a,complex b)
{
	complex res;
	res.real=a.real+b.real;
	res.imag=a.imag+b.imag;
	return res;
}

int main()
{
	float real,imag;
	char ans;
	do
	{
	cout<<"\naddition of two complex numbers:"<<endl;
	cout<<"complex no.1:"<<endl;
	cout<<"Enter real and imaginary part respectively:"<<endl;
	cin>>real>>imag;
	complex c1(real,imag);
	cout<<"\ncomplex 1:";
	c1.display();
	cin.clear();
	
	
	cout<<"\ncomplex no.2:"<<endl;
	cout<<"Enter real and imaginary part respectively:"<<endl;
	cin>>real>>imag;
	complex c2(real,imag);
	cout<<"\ncomplex 2:";
	c2.display();
	cin.clear();
	cin.ignore(1000,'\n');
	
	
	
	complex c3=c1+c2;
	cout<<"\nsum of c1 and c2 is:"<<endl;
	c3.display();
	cin.clear();
	cin.ignore(1000,'\n');
	
	
	cout<<"\nDo you want to continue? (y or n)"<<endl;
	cin>>ans;
	system("cls");
	}while(ans=='y' or ans=='Y');
	
	return 0;
}
