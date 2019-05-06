#include<iostream>
#include<conio.h>
using namespace std;
class complex
{
	private:
		int real;
		int imag;
	public:
		complex():real(0),imag(0){}
	    void getdata()
	    {
	    	cout<<"Enter real and imaginary number respectively:"<<endl;
	    	cin>>real>>imag;
		}
		void sum(complex c1,complex c2)
		{
			real=c1.real+c2.real;
			imag=c1.imag+c2.imag;
		}
		void show()
		{
			cout<<real<<"+"<<imag<<"i";
		}
};
int main()
{
	complex c1,c2,c3;
	char ans;
	do
	{
	cout<<"addition of two complex numbers:"<<endl;
	cout<<"complex no.1:"<<endl;
	c1.getdata();
	cout<<"complex no.2:"<<endl;
	c2.getdata();
	c3.sum(c1,c2);
	cout<<"sum of c1 and c2 is:"<<endl;
	c3.show();
	cout<<"\nDo you want to continue? (y or n)"<<endl;
	cin>>ans;
	}while(ans=='y' or ans=='Y');
	getch();
	return 0;
}
