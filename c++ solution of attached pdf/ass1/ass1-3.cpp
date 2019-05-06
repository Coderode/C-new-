#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

class Account{
	char name[25];
	char Atype[10];
	float balance;

	public:
		char Ano[11];
		Account():balance(0){
			strcpy(Ano,"550326");
		}
		void Addaccount();
		void Deposit();
		void Withdraw();
		void display();
		
};
void Account::Addaccount()
{
	char A[5];
	do{
	cout<<"Enter name of customer:"<<endl;
	fflush(stdin);
	cin.getline(name,25);
	if(strlen(name)<3)
	{
		cout<<"\nInvalid name! re-enter please!\n";
	}
	}while((strlen(name)<3));
	fflush(stdin);
	do{
	cout<<"Enter Account no.:(enter last 4 digits only)"<<endl;
	cin>>A;
	for(int i=6; i<11; i++)
	{
		Ano[i]=A[i-6];
	}
	if(strlen(Ano)!=10)
	cout<<"\nInvalid accound number length must be of 10 only!\n";
	}while((strlen(Ano)!=10));
	
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
}

int main()
{
	int n;
	cout<<"Enter no. of accounts to add:"<<endl;
	cin>>n;
	Account **A=new Account*[n];
	for(int i=0; i<n ;i++)
		A[i]=new Account();
	for(int i=0; i<n; i++)
	{
		cout<<"For customer:"<<i+1<<endl;
		A[i]->Addaccount();
	}
	cout<<"\nGo for banking facility using account Number\n";
	
	char Ano[10];
	int i=0,flag=0;
	do{
	cout<<"Enter account no.:"<<endl;
	cin>>Ano;
	flag=0;
	for(i=0; i<n; i++)
	{
		if(!strcmp(A[i]->Ano,Ano))
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
	while(1)
	{
		cout<<"\n----------------------main menu---------------------------"<<endl;
		cout<<"1.deposit"<<endl;
		cout<<"2.withdraw"<<endl;
		cout<<"3.display"<<endl;
		cout<<"4.exit"<<endl;
		cout<<"Select option:"<<endl;
		cin>>option;
		switch(option)
		{
		case 1:
			A[i]->Deposit();
			break;
		case 2:
			A[i]->Withdraw();
			break;		
		case 3:
			A[i]->display();
			break;
		case 4:
			exit(0);
		default:
			cout<<"Invalid choice re-enter please!";
		}		
	}
	getch();
	return 0;
}
