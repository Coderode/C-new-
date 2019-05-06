#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
class student{
	int roll;
	char name[25];
	float marks;
	void getdata(){
		cout<<"\nEnter roll no.: ";
		cin>>roll;
		fflush(stdin);
		cout<<"\nEnter name : ";
		cin.getline(name,25);
		fflush(stdin);
		cout<<"\nEnter marks : ";
		cin>>marks;
	}
	void putdata()
	{
		cout<<"\n\t"<<roll<<"\t"<<name<<"\t"<<marks;
	}
	public:
		void addrecord()
		{
			fstream f;
			student s;
			f.open("prog7.dat",ios::app|ios::binary);
			s.getdata();
			f.write((char*)&s,sizeof(s));
			f.close();
		}
		void display()
		{
			fstream f;
			student s;
			f.open("prog7.dat",ios::in|ios::binary);
			cout<<"\n\tRoll\tName\tMarks\n";
			while(f.read((char*)&s,sizeof(s))!=NULL)
				s.putdata();
			f.close();
		}
};
int main()
{
	student s;
	//for clearing the file
	ofstream f;
	f.open("prog7.dat",ios::trunc|ios::binary);
	f.close();
	
	//start prog
	char ch='n';
	do{
		s.addrecord();
		cout<<"\nDo you want to add another data(y/n):";
		ch=getche();
	}while(ch=='y'||ch=='Y');
	cout<<"\ndata written successfully...";
	
	cout<<"\nreading from file\n";
	s.display();
	getch();
	return 0;
}
