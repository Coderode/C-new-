
//array of objects dynamically
#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
class person{
	char name[100];
	char id[50];
	public:
		person()
		{
			cout<<"\nEnter the name : ";
			fflush(stdin);
			cin.getline(name,100);
			fflush(stdin);
			cout<<"\nEnter id : ";
			cin.getline(id,50);
			fflush(stdin);
		}
		void show()
		{
			cout<<"\nname:"<<name;
			cout<<"\nid:"<<id;
		}
		~person()
		{
			delete name;
			delete id;
		}
};
int main()
{
//	person *p[5];
//	for(int i=0; i<5; i++)
//	{
//		p[i]=new person;
//		p[i]->show();
//	}

//	person *p;
//	p=new person[4];
//	for(int i=0; i<4; i++)
//	{
//		p[i].show();
//	}
	
	//for dynamic size of array
	int n=4;
	person **p=new person*[n];
	for(int i=0; i<n; i++)
		{
			p[i]=new person;
			p[i]->show();
		}

	getch();
	return 0;
	
}
