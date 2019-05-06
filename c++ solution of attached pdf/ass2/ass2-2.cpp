#include<iostream>
#include<conio.h>
#include<string.h>
#include<regex>
#include "ass2-2(file).cpp"
#include<ctime>
using namespace std;
class Account{
	char name[25];
	char Atype[10];
	float balance;
	date d1,d2;
	public:	
		char Ano[11];
		Account():balance(0){
			strcpy(Ano,"550326");
		}
		void Addaccount();
		void Deposit();
		void Withdraw();
		void display();
		int add_interest();

};
void Account::Addaccount()
{
	char A[5];
		bool match;
	do{
	cout<<"Enter name:";
	fflush(stdin);
	cin.getline(name,25);
	fflush(stdin);
	regex r1("[a-zA-Z ]+");
	match=regex_match(name,r1);
	if(match==false or strlen(name)<3)
		cout<<"\nError! enter again(characters only!) \n";
	}while(match==false or strlen(name)<3);


	fflush(stdin);
	do{
	cout<<"Enter Account no.:(enter last 4 digits only)"<<endl;
	cin>>A;
	fflush(stdin);
	regex r2("[0-9]+");
	match=regex_match(A,r2);
	for(int i=6; i<11; i++)
	{
		Ano[i]=A[i-6];
	}

	//strcat(Ano,A);
	if(strlen(Ano)!=10 or !match)
	cout<<"\nInvalid accound number length must be of 10 only!\n";
	}while((strlen(Ano)!=10) or !match);

	do{
		cout<<"\nEnter the account creation date:";
	}while(d1.enterdate()==false or validity(d1)==0);
	
	d2=d1;  // d2 is interest updation date

	do{
	cout<<"Enter account type (CA or SA):"<<endl;
	cin>>Atype;
	}while(strcmp(Atype,"ca") && strcmp(Atype,"CA") && strcmp(Atype,"SA") && strcmp(Atype,"sa"));
	do{
	cout<<"Enter initial balance to add:"<<endl;
	cin>>balance;
	if(balance<500)
	cout<<"\nplease provide initial balance greater than 500\n";
	}while(balance<500);


}
void Account::Deposit()
{
	float deposit;
	cout<<"Enter amount to deposit:"<<endl;
	cin>>deposit;
	if(deposit<=0)
	{
		cout<<"Invalid amount! try -again!"<<endl;
	}
	else
	{
	balance=balance+deposit;
	cout<<"Amount depositted succesfully!"<<endl;
	}
}
void Account::Withdraw()
{
	float width;
	cout<<"Enter amount to withdraw:"<<endl;
	cin>>width;
	if(width<=0)
		cout<<"Invalid amount to withdraw! try again!\n";
	else if(width>=balance)
		cout<<"Amount exceeded the existing balance! try again with less amount!"<<endl;
	else
	{
		balance=balance-width;
		cout<<"withdrawn succesfully!"<<endl;
	}
}
void Account::display()
{
	cout<<"customer details:"<<endl;
	cout<<"Name:"<<name<<endl;
	cout<<"Available balance:"<<balance<<endl;
	cout<<"Account opening date:";
	d1.display();
	cout<<"Interest added last date:";
	d2.display();
	cout<<"Account type:"<<Atype<<endl;
}


int Account::add_interest()
{
	float amount,principle,rate,timediff;
	date d;
//	do{
//	cout<<"\nEnter amount to give  interest=\n";
//	cin>>principle;
//	if(principle<0 or principle>balance)
//	cout<<"Invalid amount\n";
//	}while(principle<0 or principle>balance);
	principle=balance;

//	do{
//		cout<<"\nEnter the today's date to add interest:";
//	}while(d.enterdate()==false or validity(d)==0);
	time_t t=time(0);   //get time now
	tm * now=localtime(&t);
	d.y=1900+now->tm_year;
	d.m=1+now->tm_mon;
	d.d=now->tm_mday;
	cout<<"\nToday's date is:";
	d.display();
	

	timediff=difference(d2,d)/365.0;
//	cout<<"\ntime="<<time<<endl;
	if(timediff<=0.0)
	{
		cout<<"\n time gap < or = 0"<<endl;
		return 0;

	}
	
	d2=d;

	if(!strcmp(Atype,"CA") or !strcmp(Atype,"ca"))
	{
		rate=4.0;  //in % yearly
		if(timediff>=5.0)
		rate=7.0;
		amount=principle*(((rate*timediff)/100));
		balance=balance+amount;
	}
	else
	{
		rate=6.0;
		if(timediff>=50)
		rate=9.0;
		amount=principle*(((rate*timediff)/100));
		balance=balance+amount;
	}
	cout<<"\nAmout added by interest is:"<<amount<<endl;
	return 1;
}

int main()
{
	int n,flag=0,flag2=0;
	cout<<"Enter no. of accounts to add:"<<endl;
	cin>>n;
	Account *A=new Account[n];
	for(int i=0; i<n; i++)
	{
		cout<<"For customer:"<<i+1<<endl;
		A[i].Addaccount();
	}
	
	////for banking facility
	do{
	flag2=0;
	system("cls");
	cout<<"\nGo for banking facility using account Number\n";

	char Ano[10];
	int i=0;
	//for matchig account number
	do{
	cout<<"Enter account no.:"<<endl;
	cin>>Ano;
	flag=0;
	for(i=0; i<n; i++)
	{
		if(!strcmp(A[i].Ano,Ano))
		{
			break;
		}
		}
		if(i==n)
		{
			cout<<"Ano. did not match with any existing acc no. please try again!"<<endl;
			flag=1;
		}
	}while(flag==1);

	int option;
	while(flag2==0)
	{
		cout<<"\n----------------------main menu---------------------------"<<endl;
		cout<<"1.deposit"<<endl;
		cout<<"2.withdraw"<<endl;
		cout<<"3.display"<<endl;
		cout<<"4.Add interest"<<endl;
		cout<<"5.Go for another account"<<endl;
		cout<<"6.exit"<<endl;
		cout<<"Select option:"<<endl;
		cin>>option;
		switch(option)
		{
		case 1:
			A[i].Deposit();
			break;
		case 2:
			A[i].Withdraw();
			break;
		case 3:
			A[i].display();
			break;
		case 4:
			if(A[i].add_interest()==1)
			cout<<"\nadded succesfully!\n";
			else
			cout<<"\nnot added!\n";
			break;
		case 5:
			fflush(stdin);
			flag2=1;
			break;
		case 6:
			exit(0);
		default:
			cout<<"Invalid choice re-enter please!";
		}
	}
	}while(flag2==1);
	getch();
	return 0;
}



















//class date{
//	public:
//		int d,m,y;
//		date()
//		{
//			d=0;
//			m=0;
//			y=0;
//		}
//		bool enterdate()
//		{
//			int flag=0;
//
//			cout<<"Enter date (format dd/mm/yyyy):"<<endl;
//			cin>>d;
//			if(cin.get()!='/' or d>31 or d<0){
//				cout<<"Error in format\n";
//				cin.clear();
//				cin.ignore(10000, '\n');
//				flag=1;
//			}
//			else
//			{
//				cin>>m;
//				if(cin.get()!='/' or m<0 or m>12){
//					flag=1;
//					cin.clear();
//					cin.ignore(10000, '\n');
//					cout<<"\nerror in format\n";
//				}
//				else{
//					cin>>y;
//					if(y<0){
//					cin.clear();
//					cin.ignore(10000, '\n');
//					flag=1;
//					cout<<"\nerror in format\n";
//				}
//				}
//			}
//			if(flag==1)
//			{
//				d=m=y=0;
//				cout<<"Date::"<<d<<"/"<<m<<"/"<<y<<endl;
//				return false;
//			}
//			cout<<"Date::"<<d<<"/"<<m<<"/"<<y<<endl;
//			return true;
//
//		}
//
//};
