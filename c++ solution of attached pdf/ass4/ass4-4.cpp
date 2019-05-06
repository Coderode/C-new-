#include<iostream>
#include<conio.h>
using namespace std;
//Inheritance-> to create new class(derived class) from a existing class (base class)
class perimeter:public rectangle;
class rectangle;

class rectangle
{
	protected:  
	     float length;
	public:
		rectangle():length(10){
		}
		float calc1()
		{
			permeter obj;
			return 2*(length*breadth);
		}
};

class perimeter:public rectangle  //derived class
{
	private:
		float breadth;
	public:
		perimeter():breadth(20){
		}
		float calc2()
		{
			return 2*(length+breadth);
		}
		
	friend class rectangle;
};
int main()
{
	char ans;
	do{
	cout<<"Enter data for rectangle to find perimeter.\n";
	perimeter p;
//	p.input2();
	cout<<"\nperimeter="<<p.calc1()<<"meter";
	cout<<"\nDo you want to continue? y or n :";
	cin>>ans;
	}while(ans=='y');
	getch();
	return 0;
}




//for 4 th problem
//		void input2()
//		{
//			cout<<"Enter length:";
//			cin>>length;
//			while(!cin or length<0)
//			{
//				cout<<"\nError enter again!\n";
//				cin.clear();
//				cin.ignore();
//				cin>>length;
//			}
//			cout<<"Enter breadth:";
//			cin>>bread;
//			while(!cin or bread<0)
//			{
//				cout<<"\nError enter again!\n";
//				cin.clear();
//				cin.ignore();
//				cin>>bread;
//			}
//		} 

