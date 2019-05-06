#include<iostream>
#include<conio.h>
using namespace std;
class matrix;
class vector;
class vector{
	int n;//no. of elements in the vector
	int *v;
	public:
		vector(int l){
			n=l;
			v=new int[n];
		}
		friend vector multiply(matrix,vector);
		void getvector()
		{
			cout<<"Enter values for vector:"<<endl;
			for(int i=0; i<n; i++)
			{
				cout<<"v["<<i+1<<"]=";
				cin>>v[i];
			}
		}
		void disvector()
		{
			cout<<"vector v=[";
			for(int i=0; i<n; i++)
			{
				cout<<v[i]<<",";
			}
			cout<<"\b]"<<endl;
		}
	
	
};
class matrix{
	int row;
	int col;
	int **m;
	public:
		matrix(int r,int c)
		{
			row=r;
			col=c;
			m=new int*[row];
			for(int i=0; i<row; i++)
			{
				m[i]=new int[col];
			}	
		}
		friend vector multiply(matrix,vector);
		void getmatrix()
		{
			cout<<"enter values for matrix:"<<endl;	
			for(int i=0; i<row; i++)
			{
				for(int j=0; j<col; j++)
				{
					cout<<"m("<<i+1<<","<<j+1<<")=";
					cin>>m[i][j];
				}
			}
		}
		void dismatrix()
		{
			cout<<"Matrix:"<<endl;
			for(int i=0; i<row; i++)
			{
				for(int j=0; j<col; j++)
				{
					cout<<m[i][j]<<"\t";
				}
				cout<<"\n";
			}
		}
	
};
vector multiply(matrix M,vector V)
{
	vector v2(M.row);
	if(M.col!=V.n)
	{
		cout<<"Multiplication is not possible here!"<<endl;	
	}
	else
	{
		for(int i=0; i<M.row; i++)
		{
			v2.v[i]=0;
			for(int j=0; j<M.col; j++)
			{
				v2.v[i]=v2.v[i]+M.m[i][j]*V.v[j];
			}
		}
	}
	return v2;
}
int main()
{
	char ans;
	matrix m(3,3);
	vector v1(3),v2(3);
	cout<<"Multiplication of vector and matrix"<<endl;
	do{
	m.getmatrix();
	m.dismatrix();
	v1.getvector();
	v1.disvector();
	v2=multiply(m,v1);
	cout<<"\nAfter multiplication result is:\n";
	v2.disvector();
	cout<<"\ndo you want to continue? (y or n):";
	cin>>ans;
	}while(ans=='y' or ans=='Y');
	
	getch();
	return 0;
}
