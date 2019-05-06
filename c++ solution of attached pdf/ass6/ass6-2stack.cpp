#include<iostream>
#include<conio.h>
#include<math.h>
#include<cstring>
#include<string.h>
using namespace std;
class Exception{
	string y;
	public:
		Exception(string s)
		{
			y=s;		
		}
		friend void operator<<(ostream &abc,Exception obj){
		abc << obj.y;
		}
};
class stack{
	int *a;
	int length,tos;
	public:
		stack(int n)
		{
			length=n;
			a=new int[n];
			tos=-1;
		}
		bool isEmpty();
		int getSize();
		void push(int x);
		int pop();
		int peep(int index);
		void display();
};
bool stack::isEmpty()
{
	if(tos==-1)
		return true;
	else
		return false;
}
int stack::getSize()
{
	return tos+1;
}
void stack::push(int x)
{
	if(tos==length-1)
	{
		throw Exception("stack is full");
	}
	a[++tos]=x;
}
int stack::pop()
{
	if(tos==-1)
	{
		throw Exception("stack is empty already! can't pop'");
	}
	return a[tos--];
}
void  stack::display()
{
	if(tos==-1)
	{
		throw Exception("stack is empty!");
	}
	cout<<"[";
	for(int i=tos; i>=0; i--)   ////i=0 to tos i++
	{
		cout<<a[i]<<", ";
	}
	cout<<"\b\b]";
}
int stack::peep(int index)
{
	if(index<0 or index>tos)
	{
		throw Exception("Invalid index!");
	}
	return a[tos-index];
}

int main()
{
	stack s(10);
	int x,option;
	char ans;
		while(1)
		{
			try{
			cout<<"\n1.push values\t2.display stack\t\t3.isEmpty\t4.size of stack\t\t5.pop\t6.peep(index)\t7.exit\nselect option:";
			cin>>option;
			switch(option)
			{
				case 1:
					do{
					cout<<"\nEnter integer to push in stack: ";
					cin>>x;
					if(!cin)
					{
						throw Exception("Input is not a integer");
					}
					s.push(x);
					fflush(stdin);
					cout<<"\nDo you want to push another number? y or n: ";
					cin>>ans;
					fflush(stdin);
					}while(ans=='y');
					break;
				case 2:
					cout<<"\nThe elements are:\n";
					s.display();
					break;
				case 3:
					if(s.isEmpty())
	  					cout<<"\nStack is empty!";
					else 
						cout<<"\nStack is not empty!";	
					break;
				case 4:
					cout<<"\nSize of stack is : "<<s.getSize();
					break;
				case 5:
					cout<<"\nPopped value is : "<<s.pop();
					break;
				case 6:
					int index;
					cout<<"\nEnter index value to get value from stack : ";
					cin>>index;
					cout<<"\npeep("<<index<<") : "<<s.peep(index);
					break;
				case 7:
					exit(0);
					break;
				default:
					cout<<"\nwrong option selected try again!\n";
					
			}
			
			}
			catch(Exception y){
				cout<<y;
			}
			catch(...)
			{
				cout<<"default exception is called!";
			}
			cin.clear();
			cin.ignore();
		}
	
	
	getch();
	return 0;
}



//
////reverse of a number using stack;
//int reverse(int n)
//{
//	int d=floor(log10(n))+1,p=1;
//	stack s(d);
//	while(n)
//	{
//		s.push(n%10);
//		n=n/10;
//	}
//	int rev=0;
//	while(s.isEmpty()==false)
//	{
//		rev=rev+s.pop()*p;
//		p=p*10;
//	}
//	return rev;
//}
