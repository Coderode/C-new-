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
class Queue{
	int *a;
	int r,f,length;  //rear and front
	public:
		Queue(int n)
		{
			a=new int[n];
			r=-1;
			f=-1;
			length=n;
		}
		bool isEmpty();
		int getSize();
		void insert(int x);
		void display();
		int del();
};
bool Queue::isEmpty()
{
	if(r==-1)
	return true;
	else 
	return false;
}
int Queue::getSize()
{
	if(r==-1)
	return 0;
			
	return r-f+1;
}
void Queue::insert(int x)
{
	if(r==length-1)
	{
		throw Exception("Queue is full");
	}
	if(r==-1)
	{
		f=r=0;
	}
	else
	{
		r=r+1;
	}
	a[r]=x;
}
int Queue::del()
{
	if(f==-1)
	{
		throw Exception("Queue is empty");
	}
	int x=a[f];
	if(r==f)
	{
		r=f=-1;
	}
	else
	{
		f++;
	}
	return x;
}
void Queue::display()
{
	if(r==-1)
	throw Exception("queue is empty");
	cout<<"[ ";
	for(int i=f; i<=r; i++)
		cout<<a[i]<<", ";
	cout<<"\b\b]";
	
}
int main()
{
	Queue Q(10);
	int x,option;
	char ans;
		while(1)
		{
			try{
			cout<<"\n1.insert values\t2.display queue\t\t3.isEmpty\t4.size of queue\t\t5.del\t6.exit\nselect option:";
			cin>>option;
			switch(option)
			{
				case 1:
					do{
					cout<<"\nEnter integer to insert in queue: ";
					cin>>x;
					if(!cin)
					{
						throw Exception("Input is not a integer");
					}
					Q.insert(x);
					fflush(stdin);
					cout<<"\nDo you want to insert another number? y or n: ";
					cin>>ans;
					fflush(stdin);
					}while(ans=='y');
					break;
				case 2:
					cout<<"\nThe elements are:\n";
					Q.display();
					break;
				case 3:
					if(Q.isEmpty())
	  					cout<<"\nqueue is empty!";
					else 
						cout<<"\nqueue is not empty!";	
					break;
				case 4:
					cout<<"\nSize of queue is : "<<Q.getSize();
					break;
				case 5:
					cout<<"\nDeleted value is : "<<Q.del();
					break;
				
				case 6:
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

