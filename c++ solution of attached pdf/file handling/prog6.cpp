#include<iostream>
#include<fstream>
#include<conio.h>
//reading and writing of object in file
using namespace std;
class contestant{
	public:
		string name;
		int age,ratings;
		void input();
		void output_highest_rated();
};
void contestant::input()
{
	ofstream file_obj;
	file_obj.open("prog6.txt",ios::app);
	contestant obj;
	string str="sandeep";
	int age=18,ratings=2500;
	obj.name=str;
	obj.age=age;
	obj.ratings=ratings;
	
	file_obj.write((char*)&obj,sizeof(obj));
	
	str="terry";
	age=21;
	ratings=3200;
	
	obj.name=str;
	obj.age=age;
	obj.ratings=ratings;
	
	file_obj.write((char*)&obj,sizeof(obj));
	
}


void contestant::output_highest_rated()
{
	ifstream file_obj;
	file_obj.open("prog6.txt",ios::in);
	contestant obj;
	file_obj.read((char*)&obj,sizeof(obj));  //first object read
	int max=0;
	
	string highest_rated;
	//checking till we have the feed
	while(!file_obj.eof()){      //eof() return non zero if eof encountered
		if(obj.ratings>max){
			max=obj.ratings;
			highest_rated=obj.name;
		}
		//checking further
		file_obj.read((char*)&obj,sizeof(obj));
	}
	cout<<highest_rated;
}
int main()
{
	contestant object;
	object.input();
	object.output_highest_rated();
	getch();
	return 0;
}

//to write object's data members in a file
//here file obj is an object of ofstream
//file_obj.write((char*)&class_obj,sizeof(class_obj));

//to read file's data members into an object
//here file_obj is an object of ifstream
//file_obj.read((char*)&class_obj,sizeof(class_obj));
