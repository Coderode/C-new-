#include<iostream>
#include<conio.h>
using namespace std;
class polygon{
	protected:
	float width,height;
	public:
	    void set_value()
		{
			cout<<"\nEnter width (cm): ";
			cin>>width;
			while(!cin or width<0)
			{
				cout<<"\nError enter again!\n";
				cin.clear();
				cin.ignore();
				cin>>width;
			}
			cout<<"\nEnter height (cm): ";
			cin>>height;
			while(!cin or height<0)
			{
				cout<<"\nError enter again!\n";
				cin.clear();
				cin.ignore();
				cin>>height;
			}
		}
		virtual float calculate_area()=0; //pure virtual functions  for which we don't have implementation we only declare it 
};
class rectangle:public polygon{
	public:
		float calculate_area()
		{
			cout<<"\nThe area of the rectangle is  : ";
			return height*width;
		}
};
class triangle:public polygon{
	public:
		float calculate_area()
		{
			cout<<"\nThe area of the triangle is  : ";
			return (height*width)/2.0;
		}
};
int main()
{
	polygon *ptr;
	char ans;
	rectangle r;
	triangle t;
	do{
		cout<<"\nFor area of rectangle:\n";
		ptr = &r;
		ptr->set_value();
		cout<<ptr->calculate_area()<<" cm^2"<<endl;
		cout<<"\nFor area of triangle:\n";
		ptr = &t;
		ptr->set_value();
		cout<<ptr->calculate_area()<<" cm^2"<<endl;
		
	cout<<"\nDo you want to continue? y or n :";
	cin>>ans;		
	}while(ans=='y');
	getch();
	return 0;
}
