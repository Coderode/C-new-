#include<iostream>
#include<conio.h>
#include<fstream>
#include<cstring>
#include<string>
#include<cstdio>  
//for rename cstdio
using namespace std;
class person{
	protected:
		char name[30];
		int age;
		int id;
	public:
		void getdata()
		{
			fflush(stdin);
			cout<<"\nEnter name: ";
			fflush(stdin);
			cin.getline(name,30);
			fflush(stdin);
			cout<<"\nEnter age: ";
			cin>>age;
			cout<<"\nid:";
			cin>>id;
		}
		void showdata()
		{
			cout<<"\nName : "<<name;
			cout<<"\nAge: "<<age;
			cout<<"\nId: "<<id<<endl;
		}
		int getid()
		{
			return id;
		}
};
// to modify particular data in the file
void modify()
{
	int id,flag=0;
	person p;
	cout<<"\nEnter id that has to be modified: ";
	cin>>id;
	fstream file("prog8.dat",ios::in|ios::out|ios::binary);
	if(!file)
	{
		cout<<"\nfile not found\n";
		return;
	}
	else{
		file.read((char*)&p,sizeof(p));
		
		while(!file.eof())
		{
			if(id==p.getid())
			{
				cout<<"\nmatch found with id:\n";
				cout<<"\nold record:\n";
				p.showdata();
				file.seekg(0,ios::cur);
				cout<<"\nEnter new record:\n";
				p.getdata();
				file.seekp(file.tellg()-sizeof(p));
				file.write((char*)&p,sizeof(p));
				flag=1;
			}
			file.read((char*)&p,sizeof(p));
		}
	}
	if(flag==0)
	{
		cout<<"\nmatch not found with given id try again\n";
	}
	getch();
	file.close();
	
}

//to delete particular data from the file
void delete_record()
{
	int id;
	int flag=0;
	person p;
	cout<<"\nEnter id that should be deleted : ";
	cin>>id;
	ofstream newfile("newfile.dat",ios::out|ios::binary);
	ifstream file("prog8.dat",ios::binary|ios::in);
	
	if(!file)
	{
		cout<<"\nfile not found\n";
		return;
	}
	else{
		file.read((char*)&p,sizeof(p));
		while(!file.eof())
		{
			if(id!=p.getid())
			{
				newfile.write((char*)&p,sizeof(p));
			}
			else
			 	flag=1;
			file.read((char*)&p,sizeof(p));
		}	
	}
	
	
	if(flag==1)
	cout<<"\nrecord deleted successfully!\n";
	else 
	cout<<"\nrecord not found with this id\n";
	
	
	newfile.close();
	file.close();
	remove("prog8.dat");
	rename("newfile.dat","prog8.dat");
	getch();
	
}
int main()
{
	person p;
	char ans;
	int option;
	char  oldname[50]="prog8.dat";
	char newname[50]="prog8.dat";

	while(1)
	{
		system("cls");
		cout<<"\n-----------------main menu-----------------\n";
		cout<<"1.write data\t2.read data\t3.delete all data\t4.rename file\t5.delete file\t6.modify data\t7.delete record\t8.exit\nselect option:";
		cin>>option;
		
		
			if(option==1){
				do{
					fstream file("prog8.dat",ios::binary|ios::app);
					p.getdata();
					file.write((char*)&p,sizeof(p));
					file.close();
					cout<<"\nDo you want to add more section (y/n):";
					ans=getche();
				}while(ans=='y' or ans=='Y');
			}
			else if(option==2){
				ifstream file("prog8.dat",ios::in|ios::binary);
				file.seekg(0,ios::beg);
		
				while(file.read((char*)&p,sizeof(p))!=NULL)
					p.showdata();
			
				file.close();
				getch();
			}
			else if(option==3){
				ofstream file("prog8.dat",ios::out|ios::trunc);
				file.close();
			}
			else if(option==4)
			{	
				fflush(stdin);
				cout<<"\nEnter the oldname:";
				cin.getline(oldname,50);
				fflush(stdin);
				cout<<"\nEnter new name : ";
				cin.getline(newname,50);
				fflush(stdin);
				//renames the file if exists
				if(rename(oldname,newname)!=0){
					cout<<"\nError renaming file/ file does not exist"<<endl;
				}
				else 
					cout<<"\nFile renamed successfully";
				getch();
			}
			else if(option==5){
				if(remove(newname)!=0)
					cout<<"\nNot deleted / file not exist"<<endl;
				else
					cout<<"\ndeleted successfully\n";
				getch();
			}
			else if(option==6)
			{
				modify();
			}
			else if(option==7)
				delete_record();
			else if(option==8)
				break;
			else
				cout<<"\nentered wrong option try again please\n";
				
		
	}
	getch();
	return 0;
}



//rename  -
//int rename(const char *oldname, const char *newname); return 0 if renamed successfully
// do not take filename as string it should be char array
// using as moving file from one to another place
//char oldname[] = "C:\\Users\\file_old.txt";
//	char newname[] = "C:\\Users\\New Folder\\file_new.txt";
//	
//	/*	Deletes the file if exists */
//	if (rename(oldname, newname) != 0)
//		perror("Error moving file");
//	else
//		cout << "File moved successfully";


//remove or delete a file
//int remove(filename);   //return 0 if deleted successfully

