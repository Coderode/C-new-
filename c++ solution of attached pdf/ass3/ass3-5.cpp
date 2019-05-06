#include<iostream>
#include<conio.h>
#include<string.h>
#include<regex>
using namespace std;

class String{
	char *s;
	public:
		void getstring()
		{
			char str[200];
			bool match;
			do{
			cout<<"\nEnter a string:"<<endl;
			fflush(stdin);
//			cin.getline(name,25);
			cin.getline(str,200);
			fflush(stdin);
			regex r1("[a-zA-Z ]+");
			match=regex_match(str,r1);
			if(match==false)
				cout<<"\nError! enter again(characters only!) \n";
			}while(match==false);
	
			int l=strlen(str);
			s=new char[l+1];
			strcpy(s,str);	
		}
		void display()
		{
			cout<<"\nThe string is:\n";
			cout<<s<<endl;
		}
		void operator + (String s2)
		{
			strcat(s,s2.s);
		}
		bool operator == (String s2)
		{
			if(!strcmp(s,s2.s))
				return true;
			else
				return false;
		}
};
int main()
{
	char ans;
	do{
	fflush(stdin);
	String s1,s2;
	cout<<"\nstring 1:\n";
	s1.getstring();
	s1.display();
	cout<<"\nstring 2:\n";
	s2.getstring();
	s2.display();
	cout<<"\nApplying string1==string2:";
	if(s1==s2)
	cout<<"\nsame!\n";
	else 
	cout<<"\nnot same!\n";
	s1+s2;   //  ==(s1+)s2;  s2 is as argument
	cout<<"\nafter string1+string2:\n";
	s1.display();
	cout<<"\nDo you want to continue? (y or n):";
	cin>>ans;
	system("cls");
	}while(ans=='y');
	getch();
	return 0;
}
