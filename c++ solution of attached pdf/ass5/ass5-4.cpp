//a class is abstract if it has at least one pure virtual function
//a pure virtual funciton or abstract function for which we don't have implementation we only declare it 
//a pure virtual function is declared by assigning 0 in declaration 
//e.g. virtual void show()=0;
//we can't have object of abstract class in main (show error)
//we can have pointers and references of abstract class type
//if we don't override the pure virtual function in derived class then derived class also becomes abstract class and can't create obj for this also
//an abstract class can have constructors.
//interface: does not have implementation of any of its methods it can be considered as collection of method declarations
//an interface can be simulated by making all methods as pure virtual
#include<iostream>
#include<conio.h>
#include<cstring>
#include<regex>
using namespace std;
class student{
	protected:
	string name,id,department,project;
	public:
		void get_details()
		{
			bool match;
			do{
			cout<<"Enter name of student :";
			fflush(stdin);
			getline(cin,name);
			fflush(stdin);
			regex r1("[a-zA-Z ]+");
			match=regex_match(name,r1);
			if(match==false)
				cout<<"\nError! enter again(characters only!) \n";
			}while(match==false);
			do{
			cout<<"Enter ID:";
			fflush(stdin);
			getline(cin,id);
			fflush(stdin);
			regex r2("[a-zA-Z0-9 ]+");
			match=regex_match(id,r2);
			if(match==false)
				cout<<"\nError! enter again(characters  and numbers only!) \n";
			}while(match==false);
			
			cout<<"\nEnter the department name : "<<department;
			fflush(stdin);
			getline(cin,department);
			cout<<"\nEnter the project assigned to student : ";
			fflush(stdin);
			getline(cin,project);
		}
		void display()
		{
			cout<<"\nDepartment : "<<department;
			cout<<"\nName of the student : "<<name<<endl;
			cout<<"\nStudent Id : "<<id<<endl;
			cout<<"\nProject assigned : "<<project<<endl;
		}
		virtual void show_faculty()=0;
		virtual void show_timetable()=0;
		virtual void head_of_department()=0;
		virtual void classes()=0;
		virtual void subjects()=0;
};
class engineering:public student{
	public:
	void show_faculty()
	{
		cout<<"\nFaculty provided:\n";
		cout<<"\n1.Mr. rk singh\t2.Dr. Rahul kumar \t 3.Dr. Sonia"<<endl;
	}
	void show_timetable()
	{
		cout<<"\nTime table:\n";
		cout<<"\nmon: (9-10 mechanics) (10-1 electronics)"<<endl;
		cout<<"\ntue: (9-12 practical1) (1-4 practical2)"<<endl;
		cout<<"\nwed: (9-11 digital) (11-1 STR)"<<endl;
	}
	void head_of_department()
	{
		cout<<"\nHOD: Dr. M.s. dahiya"<<endl;
	}
	void classes()
	{
		cout<<"\nClasses alloted: 102, 104, 110"<<endl;
	}
	void subjects()
	{
		cout<<"\nSubjects available:\n";
		cout<<"1.Mechanics\t2.STR\t3.digital\t4.software engineering\n";
	}
};
class medicine:public student{
	public:
	void show_faculty()
	{
		cout<<"\nFaculty provided:\n";
		cout<<"\n1.Mr. t.y singh\t2.Dr. Roshan kumar \t 3.Dr. Sonia"<<endl;
	}
	void show_timetable()
	{
		cout<<"\nTime table:\n";
		cout<<"\nmon: (9-10 biochemistry) (10-1 practical1)"<<endl;
		cout<<"\ntue: (9-12 practical2) (1-4 pharmacology)"<<endl;
		cout<<"\nwed: (9-11 physiology) (11-1 microbiology)"<<endl;
	}
	void head_of_department()
	{
		cout<<"\nHOD: Dr. R.K. dahiya"<<endl;
	}
	void classes()
	{
		cout<<"\nClasses alloted: 105, 106, 107"<<endl;
	}
	void subjects()
	{
		cout<<"\nSubjects available:\n";
		cout<<"1.Biochemistry\t2.Microbiology\t3.Pharmacology\t4.Anatomy\n";
	}	
};
class science:public student{
	public:
	void show_faculty()
	{
		cout<<"\nFaculty provided:\n";
		cout<<"\n1.Mr.Somesh singh\t2.Dr. Tarun kumar \t 3.Dr. Mamta"<<endl;
	}
	void show_timetable()
	{
		cout<<"\nTime table:\n";
		cout<<"\nmon: (9-10 physics) (10-1 chemistry)"<<endl;
		cout<<"\ntue: (9-12 practical1) (1-4 practical2)"<<endl;
		cout<<"\nwed: (9-11 maths) (11-1 biology)"<<endl;
	}
	void head_of_department()
	{
		cout<<"\nHOD: Dr. H.G. golia"<<endl;
	}
	void classes()
	{
		cout<<"\nClasses alloted: 120, 122, 133"<<endl;
	}
	void subjects()
	{
		cout<<"\nSubjects available:\n";
		cout<<"1.Physics\t2.Biology\t3.Chemistry\t4.Maths\n";
	}	
};
int main()
{
	int option;
	student *ptr[3];
	engineering e;
	medicine m;
	science s;
	ptr[0]=&e;
	ptr[1]=&m;
	ptr[2]=&s;
	int i;
	while(1)
	{
	cout<<"\nGet details for student of department : "<<endl;
	cout<<"1.engineering\t2.medicine\t3.science\t4.exit\nselect option:";
	cin>>option;
		switch(option)
		{
			case 1:
				i=0;
				break;
			case 2:
				i=1;
				break;
			case 3:
				i=2;
				break;
			case 4:
				exit(0);
				break;
			default:
				cout<<"\nwrong option enter again!\n";
		}
			ptr[i]->get_details();
			ptr[i]->display();
			ptr[i]->head_of_department();
			ptr[i]->show_faculty();
			ptr[i]->show_timetable();
			ptr[i]->subjects();
	}
	getch();
	return 0;
}

