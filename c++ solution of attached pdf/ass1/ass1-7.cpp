#include<iostream>
#include<conio.h>
#include<regex>
#include<iomanip>
#include<string.h>
using namespace std;


class student{
	char name[25];
	char rollno[4];
	int mark[3];
	int total;
	float avg;
	public:
		void getdata();
		void displaydata();
		
};
void student::getdata()
{
	bool match;
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
	cout<<"enter marks of sub1:";
	cin>>mark[0];
	if(mark[0]<0 or mark[0]>100)
	cout<<"\nError marks should be between 0 and 100\n";
	}while(mark[0]<0 or mark[0]>100);
	
	do{
	cout<<"enter marks of sub2:";
	cin>>mark[1];
	if(mark[1]<0 or mark[1]>100)
	cout<<"\nError marks should be between 0 and 100\n";
    }while(mark[1]<0 or mark[1]>100);
	
		
	do{
	cout<<"enter marks of sub3:";
	cin>>mark[2];
	if(mark[2]<0 or mark[2]>100)
	cout<<"\nError marks should be between 0 and 100\n";	
	}while(mark[2]<0 or mark[2]>100);
	
		
	total=mark[0]+mark[1]+mark[2];
	avg=total/3;
}
void student::displaydata()
{
	cout<<setw(20)<<name<<"\t| "<<rollno<<"\t\t| "<<mark[0]<<"\t| "<<mark[1]<<"\t| "<<mark[2]<<"\t| "<<total<<"\t\t| "<<avg<<"    |"<<endl;
//	cout<<setw(15)<<name<<setw(20)<<rollno<<setw(10)<<mark[0]<<setw(10)<<mark[1]<<setw(10)<<mark[2]<<setw(10)<<total<<setw(10)<<avg<<endl;
}
int main()
{
	int n;
	cout<<"Enter no. of students to add:"<<endl;
	cin>>n;
	student S[n];
	cout<<"Enter students details:"<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<"Studentid:"<<i+1<<endl;
		S[i].getdata();
	}
	cout<<"Displaying student details:"<<endl;
	cout<<"-------------------------------------------------------------------------------------------------"<<endl;
	cout<<"|S.no.|\t\tName\t\t|RollNo.\t|sub1\t|sub2\t|sub3\t|Total\t\t|Average|"<<endl;
	cout<<"-------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t\t\t\t|--------------------Marks----------------------|"<<endl;
	for(int i=0; i<n; i++)
	{	
		cout<<"|"<<i+1<<"    |\t";
		S[i].displaydata();
	}
	cout<<"-------------------------------------------------------------------------------------------------"<<endl;
	getch();
	return 0;
}
