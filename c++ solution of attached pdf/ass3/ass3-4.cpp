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
			int flag=0;
			do{
			cout<<"\nEnter feet:";
			cin>>feet;
			if(feet<0)
			{
				flag=1;
				cout<<"\nError please enter again!\n";
			}
			cin.clear();
			cin.ignore(10000,'\n');
			}while(flag==1);
			flag=0;
			do{
			cout<<"Enter inch:";
			cin>>inch;
			if(inch<0)
			{
				flag=1;
				cout<<"\nError please enter again!\n";
			}
			if(inch>=12)
			{
				feet=feet+inch/12;   //12"==1'
				inch=inch%12;
			}
			cin.clear();
			cin.ignore(10000,'\n');
			}while(flag==1);
		}
		bool operator < (Distance d2);
		void operator += (Distance d2);
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

int main()
{
	char ans;
	int option,flag;
	Distance d1,d2;
	do{
		flag=0;
		cout<<"\nFor Distance 1:\n";
		d1.getdata();
		d1.show();
		cout<<"\n\nFor Distance 2:\n";
		d2.getdata();
		d2.show();
		while(flag==0)
		{
			cout<<"\n\n1.show\t2.Is d1 < d2\t3.find d1+=d2\t4.exit\nselect option:";
			cin>>option;
			switch(option)
			{
				case 1:
					cout<<"\nDistance 1=";
					d1.show();
					cout<<"\nDistance 2=";
					d2.show();
					break;
				case 2:
					if(d1<d2)
					{
						cout<<"\n";
						d1.show();
						cout<<" < ";
						d2.show();
					}
					else
					{
						cout<<"\n";
						d1.show();
						cout<<" > ";
						d2.show();
					}
					break;
				case 3:
					cout<<"\nDistance1+=Distance2 is =";
					d1+=d2;
					d1.show();
//					d2.show();
					break;
				case 4:
					flag=1;
					break;	
				default:
					cout<<"wrong option enter again!";
					break;	
			}
			
		}
		cout<<"\nDo you want to continue?(y or n):";
		cin>>ans;
		system("cls");
	}while(ans=='y');
	return 0;
}
