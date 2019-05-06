#include<iostream>
//#include<conio.h>
#include<string.h>
using namespace std;
class Account{
	char name[25];
	char Atype[10];
	double balance;
	public:
		char userid[20];
		char pass[20];
		long Ano;
		Account():balance(0){Ano=1503222111;}
		void getLogindetails();
		void Addaccount();
		int Login();
		void Deposit();
		void Withdraw();
		void Brequest();
		void display();
		void add_interest();
		int getname()
		{
			cout<<"Enter name of customer:"<<endl;
			fflush(stdin);
			cin.getline(name,25);
			fflush(stdin);
			for(int i=0; name[i]!='\0'; i++)
			{
				
				if((name[i]<'a' or name[i]>'z') && name[i]!=' ' &&(name[i]<'A' or name[i]>'Z'))
				{
					cout<<"Error! please use enlish alphabates only for name!\n";
					return 0;
				}
					
			}
			if(strlen(name)<3)
			{
				cout<<"\nInvalid name! re-enter please!\n";
				return 0;
			}
		}
		
};
int Account::Login()
{
	char id[20];
	char password[20];
	cout<<"Enter user id:";
	cin>>id;
	cout<<"Enter Password:";
	cin>>password;
	if(!strcmp(id,userid) && !strcmp(password,pass))
	{
		cout<<"Login successfully!"<<endl;
		return 1;
	}
	else 
	{
		cout<<"Login not successfull!"<<endl;
		return 0;
	}
}
void Account::getLogindetails()
{
	char repass[20];
	int flag=0;
	
	do{
	cout<<"Create Password"<<endl;
	cin>>pass;
	cout<<"confirm Password"<<endl;
	cin>>repass;
	if(!strcmp(pass,repass))
	{
		cout<<"Created successfully!"<<endl;
		flag=1;
	}
	else
	cout<<"Enter password again!"<<endl;
	}while(flag==0);
}
void Account::Addaccount()
{
	int flag;
	do{
	flag=getname();
	}while(flag==0);

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
void Account::Brequest()
{
	cout<<"Available balance:"<<balance<<endl;
}
void Account::display()
{
	cout<<"customer details:"<<endl;
	cout<<"Name:"<<name<<endl;
	cout<<"Account number:"<<Ano<<"\n";
	cout<<"Account type:"<<Atype<<endl;
	cout<<"Userid:"<<userid<<endl;
	cout<<"Password:"<<pass<<endl;
}
void Account::add_interest()
{
	float amount,principle,rate,time;
	do{
	cout<<"\nEnter amount to give  interest=\n";
	cin>>principle;
	if(principle<0 or principle>balance)
	cout<<"Invalid amount\n";
	}while(principle<0 or principle>balance);
	
	do{
	cout<<"\nEnter time in (years):\n";
	cin>>time;
	if(time<0)
	cout<<"\ninvalid time\n";
	}while(time<0);
	
	if(!strcmp(Atype,"CA") or !strcmp(Atype,"ca"))
	{
		rate=4;  //in % yearly
		if(time>=5)
		rate=7;
		amount=principle*(((rate*time)/100));
		balance=balance+amount;
	}
	else 
	{
		rate=6;
		if(time>=5)
		rate=9;
		amount=principle*(((rate*time)/100));
		balance=balance+amount;	
	}
}

int main()
{
	Account *A,*B;
	int n=0,option,flag1;
	while(1)
	{
		cout<<"\n-------------------------------main menu-------------------------------"<<endl;
		cout<<"1.create Account(for new user)"<<endl;
		cout<<"2.Login (for existing user)"<<endl;
		cout<<"3.exit"<<endl;
		cout<<"select option:";
		cin>>option;
		switch(option)
		{
			case 1:
				char confirm;
				B=new Account[n];
				if(n>0)
				{
					
					for(int i=0; i<n; i++)
					{
						B[i]=A[i];
						}	
				}
				n++;
				A=new Account[n];
				if(n>1)
				{
					for(int i=0; i<n-1; i++)
						A[i]=B[i];	
				}
				A[n-1].Addaccount();
				A[n-1].Ano=A[n-1].Ano+n;
				do
				{
				cout<<"Create Userid:"<<endl;
				cin>>A[n-1].userid;
				flag1=1;
				if(n>1)
				{
				for(int j=0; j<n-1; j++)
					{
					if(!strcmp(A[j].userid,A[n-1].userid))
						{
						cout<<"\nUser name already exist! try again please!\n";
						flag1=0;
						break;
						}
					}
				}
				}while(flag1==0);
				
				A[n-1].getLogindetails();
				cout<<"\nEnter y or Y to confirm to add account!\n";
				cin>>confirm;
				if(confirm!='y' and confirm!='Y')
				{
					strcpy(A[n-1].userid,"AAAA");
					cout<<"Error:Not created !\n";
					n--;
				}
				else
				{
					cout<<"\nAccount created successfully! thank you!\n";
				}
				system("cls");
				break;
			case 2:
				int i;
				char userid[20],pass[20];
				cout<<"Enter userid:";
				cin>>userid;
				cout<<"Enter password:";
				cin>>pass;
				for(i=0; i<n; i++)
				{
					
				if(!strcmp(userid,A[i].userid) && !strcmp(pass,A[i].pass))
				{
					cout<<"Login successfully!"<<endl;
					break;
				}
				}
				if(i!=n)
				{
					while(1)
					{
						int flag=0;
						cout<<"---------------------------Customer menu------------------------"<<endl;
						cout<<"1.withdraw\t2.deposit money\t\t3.Request balance\t\t4.Display details\t\t5.add interest\n6.quit\nSelect option:"<<endl;
						cin>>option;
						switch(option)
						{
							case 1:
								A[i].Withdraw();
								break;
							case 2:
								A[i].Deposit();
								break;
							case 3:
								A[i].Brequest();
								break;
							case 6:
								flag=1;
								break;
							case 4: 
							 	A[i].display();
							 	break;
							case 5:
								A[i].add_interest();
								break;
							default:cout<<"entere wrong choice re-enter please!"<<endl;
						}
						if(flag==1)
							break;	
					}
				}
				if(i==n)
				{
				cout<<"Login not successful!"<<endl;
				}
				system("cls");
				break;
			case 3:
				exit(0);
				break;
			default:cout<<"option not match with anyone! please re-enter!"<<endl;
		}
	}
	getchar();
	return 0;
}
