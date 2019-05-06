#include<iostream>
#include<conio.h>
#include<string.h>
#include<cstring>
#include<iomanip>
#include<regex>
using namespace std;
class student{
	protected:
	string name;
	char rollno[5];
	public:
		void get()
		{
			bool match;
			do{
			cout<<"Enter student name:";
			fflush(stdin);
			getline(cin,name);
			fflush(stdin);
			regex r1("[a-zA-Z ]+");
			match=regex_match(name,r1);
			if(match==false)
				cout<<"\nError! enter again(characters only!) \n";
			}while(match==false);
			do{
			cout<<"Enter rollno.:";
			cin>>rollno;
			fflush(stdin);
			regex r2("[0-9]+");
			 match=regex_match(rollno,r2);
			if(!match or strlen(rollno)>4)
				cout<<"\nError!\n";
			
			}while(!match or strlen(rollno)>4);
					
		}
		void display()
		{
			cout<<setw(25)<<name<<"|"<<setw(7)<<rollno<<"\t|";
		}
	
};
class mark:public student
{
	protected:
	int mark1,mark2;
	public:
		void get_marks()
		{
			cout<<"\nEnter the marks:"<<endl;
			cout<<"\nMarks in English :";
			cin>>mark1;
			while(!cin or mark1<0 or mark1>100)
			{
			cout<<"wrong input! enter again\n";
			cin.clear();
			cin.ignore();
			cin>>mark1;
			}
			cout<<"\nMarks in Maths: ";
			cin>>mark2;
			while(!cin or mark2<0 or mark2>100)
			{
			cout<<"wrong input! enter again\n";
			cin.clear();
			cin.ignore();
			cin>>mark2;
			}
			
		}	
		void display_marks()
		{
			cout<<mark1<<"\t\t|"<<mark2<<"\t|";
		}
};
class result:public mark{
	private:
		int total;
	public:
		int cal_result()
		{
			total=mark1+mark2;
			return total;
		}
		void display_result()
		{
			if(mark1<33 or mark2<33)
			{
				cout<<"Failed\t|";	
			}
			else
			{
				cout<<"Passed\t|";
			}	
		}
};
int main()
{
	int n;
	cout<<"How many students:"<<endl;
	cin>>n;
	result S[n];
	cout<<"Enter students details:"<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<"\nStudentid:"<<i+1<<endl;
		S[i].get();
		S[i].get_marks();
	}
	cout<<"Displaying Result:"<<endl;
	cout<<"--------------------------------------------------------------------------------------------------"<<endl;
	cout<<"|S.no.|\t\tName\t\t|RollNo.\t|English\t|Maths\t|Total marks\t|Result\t|"<<endl;
	cout<<"--------------------------------------------------------------------------------------------------"<<endl;
//	cout<<"\t\t\t\t\t\t|----------Marks--------|"<<endl;
	for(int i=0; i<n; i++)
	{	
		cout<<"|"<<i+1<<"    |";
		S[i].display();
		S[i].display_marks();
		cout<<S[i].cal_result()<<"\t\t|";
		S[i].display_result();
		cout<<"\n";
	}
	cout<<"-------------------------------------------------------------------------------------------------"<<endl;
	getch();
	return 0;
}
