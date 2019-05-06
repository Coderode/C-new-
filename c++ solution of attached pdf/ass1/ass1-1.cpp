#include<iostream>
using namespace std;

class Maximum
{
	int x,y,z;
	public:
		int Max();
		void get()
		{
			cout<<"Enter three numbers to find max:"<<endl;
			cin>>x>>y>>z;
		}
};
inline int Maximum::Max()
{
	return x>y ? (x>z? x:z):(y>z?y:z);
}
int main()
{
	
	char ans;
	Maximum obj;
	do
	{
		
	obj.get();
	cout<<"Maximum="<<obj.Max()<<endl;
	
	cout<<"do you want to continue y or n?:"<<endl;
	cin>>ans;
	}while(ans=='y' or ans=='Y');
	getchar();
	return 0;	
}
