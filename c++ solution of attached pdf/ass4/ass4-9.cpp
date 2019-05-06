#include<iostream>
#include<conio.h>
#include<string.h>
#include<cstring>
#include<regex>
using namespace std;
class staff{
	protected:
	string name;
	string code;
	public:
		void get()
		{
			bool match;
			do{
			cout<<"Enter staff name:";
			fflush(stdin);
			getline(cin,name);
			fflush(stdin);
			regex r1("[a-zA-Z ]+");
			match=regex_match(name,r1);
			if(match==false)
				cout<<"\nError! enter again(characters only!) \n";
			}while(match==false);
	
			cout<<"\nEnter Id :";
			fflush(stdin);
			getline(cin,code);
		}
		void display()
		{
			cout<<"\nStaff name: "<<name;
			cout<<"\nStaff Id: "<<code;
		}
		
};
class faculty: public staff{
	private:
		string Department;
		string SubjectTaken;
		string ResearchArea;
	public:
		void get_faculty()
		{
			cout<<"\nHe is a faculty member";
			cout<<"\nEnter the department name : ";
			fflush(stdin);
			getline(cin,Department);
			cout<<"\nEnter the subject taken : ";
			fflush(stdin);
			getline(cin,SubjectTaken);
			cout<<"\nEnter the Area of Research : ";
			fflush(stdin);
			getline(cin,ResearchArea);
		}
		void display_faculty()
		{
			cout<<"\nDepartment : "<<Department;
			cout<<"\nSubject taken : "<<SubjectTaken;
			cout<<"\nResearch area : "<<ResearchArea;
		}
};
class typist:public staff{
	protected:
	string office;
	int speed;
	public:
		void get_typist()
		{
			cout<<"\nHe is a typist";
			cout<<"\nEnter the office name : ";
			getline(cin,office);
			fflush(stdin);
			cout<<"\nEnter the speed of typing (wpm): ";
			cin>>speed;	
			while(!cin or speed<0)
			{
				cout<<"\nError enter again!\n";
				cin.clear();
				cin.ignore();
				cin>>speed;
			}
		}
		void display_typist()
		{
			cout<<"\nOffice name : "<<office;
			cout<<"\ntyping speed (wpm) : "<<speed;
		}
	
};
class officer:public staff{
	private:
		int rank;
		char grade[3];
	public:
		void get_officer()
		{
			fflush(stdin);
			cout<<"\nHe is a officer";
			cout<<"\nEnter the rank of the officer : ";
			cin>>rank;
			while(!cin or rank<0 or rank>10)
			{
				cout<<"\nError enter again!\n";
				cin.clear();
				cin.ignore();
				cin>>rank;
			}
			fflush(stdin);
			cout<<"\nEnter the grade : ";
			cin.getline(grade,3);
		}
		void display_officer()
		{
			cout<<"\nRank of the officer is : "<<rank;
			cout<<"\nGrade of the officer is : "<<grade;
		}
};
class permanent:public typist{
	private:
		int salary;
	public:
		void get_permanent()
		{
			cout<<"\nEnter the salary(Rs) : ";
			cin>>salary;
			while(!cin or salary<0)
			{
				cout<<"\nError enter again!\n";
				cin.clear();
				cin.ignore();
				cin>>salary;
			}
		}
		void display_permanent()
		{
			cout<<"\nThe salary of the typist is (Rs) : "<<salary;
		}
};
class casual:public typist{
	private:
		int dailywages;
	public:
		void get_casual()
		{
			cout<<"\nEnter the daily wages (Rs) : ";
			cin>>dailywages;
			while(!cin or dailywages<0)
			{
				cout<<"\nError enter again!\n";
				cin.clear();
				cin.ignore();
				cin>>dailywages;
			}
		}
		void display_casual()
		{
			cout<<"\nThe daily wages of the typist is (Rs) : "<<dailywages;
		}
};
int main()
{
	faculty f;
	permanent p;
	officer o;
	casual c;
	cout<<"\nfor faulty member :\n";
	f.get();
	f.get_faculty();
	f.display();
	f.display_faculty();
	cout<<"\n\nfor permanent typist :\n";
	p.get();
	p.get_typist();
	p.get_permanent();
	p.display();
	p.display_typist();
	p.display_permanent();
	cout<<"\n\nfor casual typist :\n";
	c.get();
	c.get_typist();
	c.get_casual();
	c.display();
	c.display_typist();
	c.display_casual();
	cout<<"\n\nfor officer :\n";
	o.get();
	o.get_officer();
	o.display();
	o.display_officer();
	getch();
	return 0;
}
