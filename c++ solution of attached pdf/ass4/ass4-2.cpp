#include<iostream>
#include<conio.h>
#include<regex>
#include<iomanip>
#include<string.h>
using namespace std;
class exam;
class student{
	private:
	char name[25];
	char rollno[4];
	string course;
	public:
		void input_student();
		void display_student();
//		friend class exam;
};
void student::input_student()
{
	bool match;
	int flag=0;
	do{
	cout<<"Enter name:";
	fflush(stdin);
	cin.getline(name,25);
	fflush(stdin);
	regex r1("[a-zA-Z ]+");
	match=regex_match(name,r1);
	if(match==false)
		cout<<"\nError! enter again(characters only!) \n";
	}while(match==false);
	

	do{
	cout<<"Enter rollno.(4 digit only):";
	cin>>rollno;
	fflush(stdin);
	regex r2("[0-9]+");
	 match=regex_match(rollno,r2);
	if(!match or strlen(rollno)>4)
		cout<<"\nError!\n";
	
	}while(!match or strlen(rollno)>4);
	
	do{
		flag=0;
		cout<<"Enter course name(MCA or Physics or Zoology or CS):";
		cin>>course;
		fflush(stdin);
		regex r3("[a-zA-Z]+ ");
		match=regex_match(course,r3);
//		if(!match )
//		{
//         cout<<"\nError!\n";
//         flag=1;
//     	}
     	if(course!="MCA" and course!="Physics" and course!="Zoology" and course!="CS")
     	{
     		cout<<"\nEnter valid course name!\n";
     		flag=1;
		}
	}while(flag==1);
}
void student::display_student()
{
	cout<<setw(20)<<name<<"\t|"<<setw(7)<<rollno<<"|"<<setw(7)<<course<<"|";
}
class exam:private student{
	int mark[3];
	public:
		void input_marks()
		{
			input_student();
			cout<<"enter marks of sub1:";
			cin>>mark[0];
			
			while(!cin or mark[0]<0 or mark[0]>100)
			{
			cout<<"\nError marks should be between 0 and 100\n";
			cin.clear();
			cin.ignore();
			cin>>mark[0];
			}
			cout<<"enter marks of sub2:";
			cin>>mark[1];
			while(!cin or mark[1]<0 or mark[1]>100)
			{
			cout<<"\nError marks should be between 0 and 100\n";
			cin.clear();
			cin.ignore();
			cin>>mark[1];
		    }
			cout<<"enter marks of sub3:";
			cin>>mark[2];
			while(!cin or mark[2]<0 or mark[2]>100)
			{
			cout<<"\nError marks should be between 0 and 100\n";
			cin.clear();
			cin.ignore();
			cin>>mark[2];	
			}
		}
		void display_result()
		{
			display_student();
			cout<<mark[0]<<"\t|"<<mark[1]<<"\t|"<<mark[2]<<"\t|"<<endl;
		}
	
};
int main()
{
	int n;
	cout<<"Enter no. of students to add:"<<endl;
	cin>>n;
	exam S[n];
	cout<<"Enter students details:"<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<"Studentid:"<<i+1<<endl;
//		S[i].input_student();
		S[i].input_marks();
	}
	system("cls");
	cout<<"Displaying student details:"<<endl;
	cout<<"-------------------------------------------------------------------------"<<endl;
	cout<<"|S.no.|\t\tName\t\t|RollNo.|Course\t|sub1\t|sub2\t|sub3\t|"<<endl;
	cout<<"-------------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t\t\t\t|----------Marks--------|"<<endl;
	for(int i=0; i<n; i++)
	{	
		cout<<"|"<<i+1<<"    |\t";
//		S[i].display_student();
		S[i].display_result();
	}
	cout<<"-------------------------------------------------------------------------"<<endl;
	getch();
	return 0;
}
