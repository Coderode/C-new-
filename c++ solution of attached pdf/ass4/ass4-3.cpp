#include<iostream>
#include<conio.h>
using namespace std;
//Inheritance-> to create new class(derived class) from a existing class (base class)
class Area;
class rectangle
{
	private:   
	     float length,breadth;
	public:
	    rectangle():length(0.0),breadth(0.0)
	    {  	}
	    //for 3rd problem
		void input1()
		{
			cout<<"Enter length:";
			cin>>length;
			while(!cin or length<0)
			{
				cout<<"\nError enter again!\n";
				cin.clear();
				cin.ignore();
				cin>>length;
			}
			cout<<"Enter breadth:";
			cin>>breadth;
			while(!cin or breadth<0)
			{
				cout<<"\nError enter again!\n";
				cin.clear();
				cin.ignore();
				cin>>breadth;
			}
		} 
	    friend class Area; 
	    friend class perimeter;
};
//for 3rd problem
class Area:public rectangle   //derived class  
{
	public:
		float calc()
		{
			return length*breadth;
		}
};
class perimeter:public rectangle  //derived class
{
	public:
		float calc()
		{
			return 2*(length+breadth);
		}
};
int main()
{
	char ans;
	do{
	cout<<"Enter data for first rectangle to find area:\n";
	Area a;
	a.input1();
	cout<<"Area="<<a.calc()<<"square meter\n\n";
	cout<<"Enter data for second rectangle to find perimeter.\n";
	perimeter p;
	p.input1();
	cout<<"\nperimeter="<<p.calc()<<"meter";
	cout<<"\nDo you want to continue? y or n :";
	cin>>ans;
	system("cls");
	}while(ans=='y');
	getch();
	return 0;
}
