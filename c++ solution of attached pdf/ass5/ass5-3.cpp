#include<iostream>
#include<conio.h>
#include<cstring>
using namespace std;
class shape{
	protected:
		float data1,data2,data3;
		string name;
	public:
		void set_value()
		{
			if(name=="circle")
			{ 
				//data1=radius
				cout<<"\nEnter the radius (cm) : ";
				cin>>data1;
				
			}
			else if(name=="rectangle")
			{
				//data1=height data2=width
				cout<<"\nEnter the height and width respectively (cm) : ";
				cin>>data1;
				while(!cin or data1<0)
				{
				cout<<"\nError enter again!\n";
				cin.clear();
				cin.ignore();
				cin>>data1;
				}
				cin>>data2;
				while(!cin or data2<0)
				{
				cout<<"\nError enter again!\n";
				cin.clear();
				cin.ignore();
				cin>>data2;
				}
			}
			else
			{
				//data1=base1 data2=base2 data3=height
				cout<<"\nEnter the base1 ,base 2 and height respectively (cm) : ";
				cin>>data1;
				while(!cin or data1<0)
				{
				cout<<"\nError enter again!\n";
				cin.clear();
				cin.ignore();
				cin>>data1;
				}
				cin>>data2;
				while(!cin or data2<0)
				{
				cout<<"\nError enter again!\n";
				cin.clear();
				cin.ignore();
				cin>>data2;
				}
				cin>>data3;
				while(!cin or data3<0)
				{
				cout<<"\nError enter again!\n";
				cin.clear();
				cin.ignore();
				cin>>data3;
				}
			}
		}
		virtual float area()=0;  //pure virtual function
	    void display()
		{
			cout<<"\nBase Shape : "<<name<<endl;
		}
	
};
class circle:public shape{
	public:
		circle()
		{
			name="circle";	
		}
		float area()
		{
			cout<<"\nThe area of the circle is  : ";
			return 3.14*data1*data1;
		}
		void display()
		{
			cout<<"\nShape : circle"<<endl;
		}
};
class rectangle:public shape{
	public:
		rectangle()
		{
			name="rectangle";	
		}
		float area()
		{
			cout<<"\nThe area of the rectangle is :";
			return data1*data2;
		}
		void display()
		{
			cout<<"\nShape : Rectangle"<<endl;
		}
};
class trapezoid:public shape{
	public:
		trapezoid()
		{
			name="trapezoid";	
		}
		float area()
		{
			cout<<"\nThe area of trapezoid is : ";
			return ((data1+data2)/2)*data3;
		}
		void display()
		{
			cout<<"\nShape : Trapezoid "<<endl;
		}
};

int main()
{
	int option;
	shape *ptr=NULL;
	while(1)
	{
		cout<<"\n1.area of circle\t2.area of rectangle\t3.area of trapezoid\t4.exit\nselect option:";
		cin>>option;
		switch(option)
		{
			case 1:
				//for cirlce
				ptr=new circle;
				ptr->display();    //compile time polymorphism ct
				ptr->set_value();   //run time
				cout<<ptr->area()<<" cm^2"<<endl;  //run time
				break;
			case 2:
				//for rectangle
				ptr=new rectangle;
				ptr->display();
				ptr->set_value();
				cout<<ptr->area()<<" cm^2"<<endl;
				break;
			case 3:
				//for trapezoid
				ptr=new trapezoid;
				ptr->display();
				ptr->set_value();
				cout<<ptr->area()<<" cm^2"<<endl;
				break;
			case 4:
				exit(0);
				break;
			default:
				cout<<"\nwrong option try again!";
				break;
		}
	}
	getch();
	return 0;
}
