#include<iostream>
#include<conio.h>
#include<regex>
#include<cstring>
#include<iomanip>
using namespace std;
class student{
	protected:
	string name;
	char rollno[5];
	public:
		void get_details()
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
		void display_details()
		{
			cout<<setw(25)<<name<<"|"<<setw(7)<<rollno<<"\t|";
		}
	
};
class Examination:virtual public student{   //virtual to remove ambiguity 
	protected:
		int test1,test2;
	public:
		void get_marks()
		{
			cout<<"\nEnter the marks:"<<endl;
			cout<<"\nMarks in test1 :";
			cin>>test1;
			while(!cin or test1<0 or test1>100)
			{
			cout<<"wrong input! enter again\n";
			cin.clear();
			cin.ignore();
			cin>>test1;
			}
			cout<<"\nMarks in test2: ";
			cin>>test2;
			while(!cin or test2<0 or test2>100)
			{
			cout<<"wrong input! enter again\n";
			cin.clear();
			cin.ignore();
			cin>>test2;
			}
		}
		float cal_average()
		{
			return (test1+test2)/2.0;
		}
		void display_average()
		{
			cout<<cal_average()<<"\t\t|";	
		}
};
class Extracurricular:public virtual student{
	protected:
		int painting,music;
	public:
		void get_score()
		{
			cout<<"\nEnter marks for extracurricular : "<<endl;
			cout<<"\nMarks in painting :";
			cin>>painting;
			while(!cin or painting<0 or painting>100)
			{
			cout<<"wrong input! enter again\n";
			cin.clear();
			cin.ignore();
			cin>>painting;
			}
			cout<<"\nMarks in music : ";
			cin>>music;
			while(!cin or music<0 or music>100)
			{
			cout<<"wrong input! enter again\n";
			cin.clear();
			cin.ignore();
			cin>>music;
			}		
		}
		void display_total()
		{
			//extracurricular total marks
			int total=painting+music;
			cout<<total<<"\t\t|";
		}
};
class result:public Examination,public Extracurricular{
	int total;
	public:
		int cal_total()
		{
			total=test1+test2+painting+music;	
			return total;	
		}
		void comment()
		{
			if(test1<35 or test2<35 or painting<25 or music < 25)
			cout<<"Failed\t|";
			else
			cout<<"Passed\t|";	
		}
};
int main()
{
	int n;
	cout<<"How many students:"<<endl;
	cin>>n;
	result **S=new result*[n];
	for(int i=0; i<n; i++)
	{
		S[i]=new result;
	}
	cout<<"Enter students details:"<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<"\nStudentid:"<<i+1<<endl;
		S[i]->get_details();
		S[i]->get_marks();
		S[i]->get_score();
	}
	cout<<"Displaying Result:"<<endl;
	cout<<"-------------------------------------------------------------------------------------------------"<<endl;
	cout<<"|S.no.|\t\tName\t\t|RollNo.\t|Average marks\t|Total of curr.\t|Total\t|Result\t|"<<endl;
	cout<<"-------------------------------------------------------------------------------------------------"<<endl;
//	cout<<"\t\t\t\t\t\t|----------Marks--------|"<<endl;
	for(int i=0; i<n; i++)
	{	
		cout<<"|"<<i+1<<"    |";
		S[i]->display_details();
		S[i]->display_average();
		S[i]->display_total();
		cout<<S[i]->cal_total()<<"\t|";
		S[i]->comment();
		cout<<"\n";
	}
	cout<<"-------------------------------------------------------------------------------------------------"<<endl;
	getch();
	return 0;
	
}


//it is like diamond problem 
//show ambiguity if we do without virtual (error)
//without virtual keyword result has two copies of student members
