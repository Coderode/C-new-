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
template <class T>
class stack{
	T *a;
	int length,tos;
	public:
		stack(int n)
		{
			length=n;
			a=new T[n];
			tos=-1;
		}
		bool isEmpty();
		int getSize();
		void push(T x);
		T pop();
		T peep(T index);
		void display();
};
template <class T>
bool stack<T>::isEmpty()
{
	if(tos==-1)
		return true;
	else
		return false;
}
template <class T>
int stack<T>::getSize()
{
	return tos+1;
}
template <class T>
void stack<T>::push(T x)
{
	if(tos==length-1)
	{
		throw Exception("stack is full");
	}
	a[++tos]=x;
}
template <class T>
T stack<T>::pop()
{
	if(tos==-1)
	{
		throw Exception("stack is empty already! can't pop'");
	}
	return a[tos--];
}
template <class T>
void  stack<T>::display()
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
template <class T>
T stack<T>::peep(T index)
{
	if(index<0 or index>tos)
	{
		throw Exception("Invalid index");
	}
	return a[tos-index];
}

int main()
{
	stack<int> s(10);
	int option;
	int x;
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
