#include<iostream>
#include<conio.h>
using namespace std;
template<class T>
class array{
	T *a;
	int size;
	public:
		array(int n)
		{
			size=n;
			a=new T[n];	
		}
		void getvalues();
		void sort();
		void display();
};
template<class T>
void array<T>::getvalues()
{
	cout<<"\nEnter values to insert in arrray : \n";
	for(int i=0; i<size; i++)
	{
	cout<<"\nEnter value "<<i+1<<" : ";
	cin>>a[i];
	while(!cin)
	{
		cout<<"\nError : wrong data type enter again!\n";
		cin.clear();
		cin.ignore();
		cin>>a[i];
	}
	}
}
template<class T>
void array<T>::sort()
{
	T temp;
	//bubble sort
	for(int round=1; round<=size-1; round++)  //no. of rounds=n-1
    {
        for(int i=0; i<=size-1-round; i++)  //storing last value with max
        {
            if(a[i]>a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];  //swaping two values
                a[i+1]=temp;
            }
        }
    }
}
template<class T>
void array<T>::display()
{
	if(size==0)
	{
		cout<<"\narray is empty\n";
	}
	else
	{
	cout<<"\n[ ";
	for(int i=0; i<size; i++)
	{
		cout<<a[i]<<", ";
	}
	cout<<"\b\b]\n";
	}
}

int main()
{
	int n;
	char ans;
	do{
	cout<<"\nEnter the size of the array : ";
	cin>>n;
	array<char> A(n);
	A.getvalues();
	cout<<"\nDisplay before sorting:\n";
	A.display();
	A.sort();
	cout<<"\nDisplay after sorting:\n";
	A.display();
	cout<<"\nDo you want to continue? y or n : ";
	cin>>ans;
	}while(ans=='y');
	getch();
	return 0;
}
