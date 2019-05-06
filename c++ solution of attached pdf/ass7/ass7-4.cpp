#include<iostream>
#include<conio.h>
using namespace std;
template<class T,class U,class V>
class Num{
	T a;
	U b;
	V c;
	public:
		Num()
		{
			cout<<"\nEnter numbers: "<<endl;
			cout<<"\nNumber 1 : ";
			cin>>a;
			while(!cin)
			{
				cout<<"\nError enter again\n";
				cin.clear();
				cin.ignore();
				cin>>a;
			}
			cout<<"\nNumber 2 : ";
			cin>>b;
			while(!cin)
			{
				cout<<"\nError enter again\n";
				cin.clear();
				cin.ignore();
				cin>>b;
			}
			cout<<"\nNumber 3 : ";
			cin>>c;
			while(!cin)
			{
				cout<<"\nError enter again\n";
				cin.clear();
				cin.ignore();
				cin>>c;
			}
		}
		void max();		
};
template<class T,class U,class V>
void Num<T,U,V>::max()
{
	cout<< (a>b? a>c?a:c : b>c?b:c);
}
int main()
{
	char ans;
	do{
	Num<int,double,float> n;
	cout<<"\nLargest of the three numbers is : ";
	n.max();
	cout<<"\nDo you want to continue? y or n : ";
	cin>>ans;
	system("cls");
	}while(ans=='y');
	getch();
	return 0;
}
