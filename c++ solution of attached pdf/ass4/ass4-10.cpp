#include<iostream>
#include<conio.h>
#include<regex>
#include<cstring>
using namespace std;
class university{
	protected:
	string uni_name;
	string proj_dep;
	string proj_person;
	public:
		university()
		{
			bool match;
			do{
			cout<<"Enter university name:";
			fflush(stdin);
			getline(cin,uni_name);
			fflush(stdin);
			regex r1("[a-zA-Z ]+");
			match=regex_match(uni_name,r1);
			if(match==false)
				cout<<"\nError! enter again(characters only!) \n";
			}while(match==false);
			match=true;
			do{
			cout<<"Enter name of department to which project is assigned :";
			fflush(stdin);
			getline(cin,proj_dep);
			fflush(stdin);
			regex r1("[a-zA-Z ]+");
			match=regex_match(proj_dep,r1);
			if(match==false)
				cout<<"\nError! enter again(characters only!) \n";
			}while(match==false);
			match=true;
			do{
			cout<<"Enter name of person to whom project is assigned :";
			fflush(stdin);
			getline(cin,proj_person);
			fflush(stdin);
			regex r1("[a-zA-Z ]+");
			match=regex_match(proj_person,r1);
			if(match==false)
				cout<<"\nError! enter again(characters only!) \n";
			}while(match==false);
		}
		void display()
		{
			cout<<"\nName of the university:\n";
			cout<<uni_name;
			cout<<"\nName of department to which project is assigned:\n";
			cout<<proj_dep;
			cout<<"\nName of person to whom the project is assigned:\n";
			cout<<proj_person;
		}
	
};
class company{
	protected:
		string comp_name;
		int no_of_engineers;
		float amt_invested;
	public:
		company()
		{
			bool match;
			do{
			cout<<"Enter compay name:";
			fflush(stdin);
			getline(cin,comp_name);
			fflush(stdin);
			regex r1("[a-zA-Z ]+");
			match=regex_match(comp_name,r1);
			if(match==false)
				cout<<"\nError! enter again(characters only!) \n";
			}while(match==false);
			cout<<"\nEnter the number of engineers assigned : ";
			cin>>no_of_engineers;
			while(!cin or no_of_engineers<0)
			{
				cout<<"\nError enter again!\n";
				cin.clear();
				cin.ignore();
				cin>>no_of_engineers;
			}
			cout<<"\nEnter amount invested by the company to do the project : ";
			cin>>amt_invested;
			while(!cin or amt_invested<0)
			{
				cout<<"\nError enter again!\n";
				cin.clear();
				cin.ignore();
				cin>>amt_invested;
			}
		}
		void display()
		{
			cout<<"\nName of the company: \n";
			cout<<comp_name;
			cout<<"\nNumber of Engineers assigned to project : "<<no_of_engineers;
//			cout<<"\nAmount invested to do the project : "<<amt_invested;
		}
};
//it is example of multiple inheritance
//project is derived from university and company
class project:public university,public company{
	string type;
	int duration;
	float amount_granted;
	public:
		project()
		{
			cout<<"\nEnter the type of project: ";
			fflush(stdin);
			getline(cin,type);
			fflush(stdin);
			cout<<"\nEnter duration of the project(days) : ";
			cin>>duration;
			while(!cin or duration<0)
			{
				cout<<"\nError enter again!\n";
				cin.clear();
				cin.ignore();
				cin>>duration;
			}
			cout<<"\nEnter the amount granted to complete the project : ";
			cin>>amount_granted;
			while(!cin or amount_granted<0)
			{
				cout<<"\nError enter again!\n";
				cin.clear();
				cin.ignore();
				cin>>amount_granted;
			}
		}
		void display()
		{
			cout<<"\nType of project is : "<<type;
			cout<<"\nDuration of the project is(days) : "<<duration;
			cout<<"\nAmount granted to complete the project : "<<amount_granted;
			cout<<"\nthis project is taken by a university and a company jointly the details are as follows:\n";
		}
	
};
int main()
{
	project p;
	university &u=p;
	company &c=p;
	p.display();
	u.display();
	c.display();
	getch();
	return 0;
	
}
