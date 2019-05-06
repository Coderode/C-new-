#include<iostream>
#include<conio.h>
#include<regex>
#include<cstring>
#include<string.h>
using namespace std;
class user{
	protected:
	string name;
	int age;
	public:
		user(string n,int g)
		{
			name=n;
			age=g;
		}
};
class student:public user
{
	private:
	string course;
	char rollno[5];
	int marks;
	public:
		student(string n,int g):user(n,g)
		{
			cout<<"\nEnter details of :"<<n<<endl;
			bool match;
			do{
				cout<<"Enter rollno.(max 4 digit):";
				cin>>rollno;
				fflush(stdin);
				regex r2("[0-9]+");
				 match=regex_match(rollno,r2);
				if(!match or strlen(rollno)>4)
					cout<<"\nError!enter again\n";
	
			}while(!match or strlen(rollno)>4);
			cout<<"\nEnter course name: ";
			getline(cin,course);
			fflush(stdin);
	
			cout<<"enter total marks:";
			cin>>marks;
			while(!cin or marks<0 or marks>100)
			{
			cout<<"\nError marks should be between 0 and 100\n";
			cin.clear();
			cin.ignore();
			cin>>marks;
			}
			
		}
		void display()
		{
			cout<<"\nStudent name: "<<name;
			cout<<"\nAge : "<<age;
			cout<<"\nCourse name: "<<course;
			cout<<"\nRollno.: "<<rollno;
			cout<<"\nTotal marks: "<<marks;
		}
		
	
};
class teacher:public user
{
	private:
	string *subject_assigned;
	int contact_hour,subjects;
	public:	
		teacher(string n,int g):user(n,g)
		{
			cout<<"\nEnter Suject assigned to :"<<n;
			cout<<"\nHow many subjects ?: ";
			cin>>subjects;
			subject_assigned=new string[subjects];
			for(int i=0; i<subjects; i++)
			{
				cout<<"\nSubject"<<i+1<<": ";
				fflush(stdin);
				getline(cin,subject_assigned[i]);
			}
			cout<<"\nEnter Contact hour (per week) :";
			cin>>contact_hour;
			while(!cin or contact_hour<0)
			{
			cout<<"\nError enter again!";
			cin.clear();
			cin.ignore();
			cin>>contact_hour;
			}
		}
		void display()
		{
			cout<<"\nTeacher name: "<<name;
			cout<<"\nAge : "<<age;
			cout<<"\nSubjects assigned :"<<endl;
			for(int i=0; i<subjects; i++)
			{
				cout<<subject_assigned[i]<<"\t";
			}
			cout<<"\nContact hour (per week) :"<<contact_hour;
		}
};
int main()
{
	cout<<"\nEnter student details :\n";
	string name;
	
	int age;
	
	bool match;
	
	do{
	cout<<"Enter name:";
	fflush(stdin);
	getline(cin,name);
	fflush(stdin);
	regex r1("[a-zA-Z ]+");
	match=regex_match(name,r1);
	if(match==false)
		cout<<"\nError! enter again(characters only!) \n";
	}while(match==false);
	
	cout<<"\nEnter age: ";
	cin>>age;
	
	while(!cin or age<0)
	{
		cout<<"\nError enter again!\n";
		cin.clear();
		cin.ignore();
		cin>>age;
	}
	
	student S(name,age);
	S.display();
	
	cout<<"\n\nEnter teacher details :\n";
	do{
	cout<<"Enter name:";
	fflush(stdin);
	getline(cin,name);
	fflush(stdin);
	regex r1("[a-zA-Z ]+");
	match=regex_match(name,r1);
	if(match==false)
		cout<<"\nError! enter again(characters only!) \n";
	}while(match==false);
	
	cout<<"\nEnter age: ";
	cin>>age;
	while(!cin or age<0)
	{
		cout<<"\nError enter again!\n";
		cin.clear();
		cin.ignore();
		cin>>age;
	}
	
	teacher T(name,age);
	T.display();
	getch();
	return 0;
}
