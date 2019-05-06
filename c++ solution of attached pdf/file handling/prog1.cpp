#include<fstream>
#include<iostream>
#include<conio.h>
// using ifstream and ofstream classes
using namespace std;

int main()
{
	
	// writing in the file
	cout<<"\nwriting on the file\n";
	ofstream fout;   //ofstream class object   only for writing file object
	string line;
	//bydefault ios::out mode, automatically deletes the content of file
	//to append content open in ios::app
	//fout.open("prog1.txt",ios::app);   //append mode read and write both
	fout.open("prog1.txt");    // write only mode
	
	while(fout){     // loop if file successfully opened
	   // read a line from standard input
		getline(cin,line);
		
		// press -1 to exit
		if(line=="-1")
			break;
		
		//write line in file
		fout<<line<<endl;
		
	}
	//close the file
	fout.close();
	
	
	
	
	
	// reading from the file
	
	cout<<"\nreading from the file\n";
	//ifstream class object to read the file
	ifstream fin;    // only for reading
	
	//by default open mode= ios::in mode
	fin.open("prog1.txt");
	//fin.open("prog1.txt",ios::app);
	// loop until eof (end of file)
	while(fin)
	{
		//read a line from file
		getline(fin,line);
		
		//print line in console
		cout<<line<<endl;
	}
	//close the file
	fin.close();
	getch();
	return 0;
	
}
