#include<iostream>
#include<conio.h>
using namespace std;
int strcomp(char *str1,char *str2)
{
	int l1,l2;
	for(l1=0; str1[l1]!='\0'; l1++);
	for(l2=0; str2[l2]!='\0'; l2++);
	int max=l1>=l2?l1:l2;
	for(int i=0; i<max; i++)
	{
		if(str1[i]<str2[i])
		{
			return -1;
		}
		else if(str1[i]>str2[i])
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	char ans;
	char str1[20],str2[20];
	do{
	cout<<"\nEnter string 1:";
	fflush(stdin);
	cin.getline(str1,20);
	fflush(stdin);
	cout<<"\nEnter string 2:";
	cin.getline(str2,20);
	cout<<"\n"<<strcomp(str1,str2);	
	cout<<"\nDo you want to continue?(y/n):";
	cin>>ans;
	}while(ans=='y');
	getch();
	return 0;
}
