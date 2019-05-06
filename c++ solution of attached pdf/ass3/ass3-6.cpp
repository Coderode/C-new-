#include<iostream>
#include<conio.h>
using namespace std;

class Distance{
	int feet;
	int inch;
	public:
		Distance():feet(0),inch(0){
		}
		Distance(int f,int i)
		{
			feet=f;
			inch=i;
		}
		void show()
		{
			cout<<"Distance:"<<feet<<"' "<<inch<<"''";  //'-feet  ''-inch
		}
		void getdata()
		{
			cout<<"\nEnter feet:";
			cin>>feet;
			while(!cin or feet<0)        //integer type validation
			{
				cout<<"\nError please enter again!\n";
				cin.clear();
				cin.ignore();
				cin>>feet;
			}

			cout<<"Enter inch:";
			cin>>inch;
			while(!cin or inch<0)
			{
				cout<<"\nError please enter again!\n";
				cin.clear();
				cin.ignore();
				cin>>inch;
			}
			if(inch>=12)
			{
				feet=feet+inch/12;   //12"==1'
				inch=inch%12;
			}
		}
		bool operator < (Distance d2);
		void operator += (Distance d2);
	    operator double();
	    operator = (double);
};
bool Distance::operator < (Distance d2)
{
	if(feet<d2.feet)
		return true;
	else if(feet==d2.feet)
	{
		if(inch<d2.inch)
			return true;
		else
			return false;
	}
	else
		return false;	
} 
void Distance::operator += (Distance d2)
{
	feet=feet+d2.feet+(inch+d2.inch)/12;
	inch=(inch+d2.inch)%12;
}
Distance::operator double()
{	
	return (0.3048*feet+0.0254*inch);     //1 foot = 0.3048 metre;   1 inch =0.0254 metre;		
}
Distance::operator = (double metre)
{
	feet=(int)metre/0.3048;
	inch=(int)(metre/0.0254)%12;
}
int main()
{
	char ans;
	double metre;
	do{
	Distance d,d2;
	cout<<"\nEnter distance in feet and inch:";
	d.getdata();
	d.show();
	metre=d;     //conversion   or metre=d.operator double()   or metre=(double) d;
	cout<<"\nIts metre equivalent is: "<<metre<<" metre"<<endl;
	d2=metre;
	cout<<"\nmetre to distance conversion: "<<endl;
	d2.show();
	cout<<"\nDo you want to continue? (y or n):";
	cin>>ans;
	system("cls");
	}while(ans=='y');
	return 0;
}


//The conversion function should satisfy the following condition:
//It must be a class member.
//It must not specify the return value even though it returns the value.
//It must not have any argument.
//
// operator typename( )
//  {
//       ….
//       ….
//       ….
//  }

