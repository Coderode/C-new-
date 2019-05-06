#include<iostream>
#include<conio.h>
using namespace std;
template<class T>
class Num{
	T a,b,c;
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
		T max();		
};
template<class T>
T Num<T>::max()
{
	return a>b? a>c?a:c : b>c?b:c;
}
int main()
{
	char ans;
	do{
	Num<int> n;
	cout<<"\nLargest of the three numbers is : "<<n.max()<<endl;
	cout<<"\nDo you want to continue? y or n : ";
	cin>>ans;
	system("cls");
	}while(ans=='y');
	getch();
	return 0;
}
