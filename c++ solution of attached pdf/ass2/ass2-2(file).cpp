//program for all date functions
#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
void difference();  //to find difference b/w dates
int leap_year(int);  //to find leap year or not
int power(int,int);  //power function
void day_of_week();  //to find day of date
void format_change(); //to change the format

class date{
	public:
		int d,m,y;
		date()
		{
			d=0;
			m=0;
			y=0;
		}
		bool enterdate()
		{
			int flag=0;

			cout<<"Enter date (format dd/mm/yyyy):"<<endl;
			cin>>d;
			if(cin.get()!='/' or d>31 or d<0){
				cout<<"Error in format\n";
				cin.clear();
				cin.ignore(10000, '\n'); 
				flag=1;
			}
			else
			{
				cin>>m;
				if(cin.get()!='/' or m<0 or m>12){
					flag=1;
					cin.clear();
					cin.ignore(10000, '\n'); 
					cout<<"\nerror in format\n";
				}
				else{
					cin>>y;
					if(y<0){
					cin.clear();
					cin.ignore(10000, '\n'); 
					flag=1;
					cout<<"\nerror in format\n";
				}
				}
			}
			if(flag==1)
			{
				d=m=y=0;
				cout<<"Date::"<<d<<"/"<<m<<"/"<<y<<endl;
				return false;
			}
			cout<<"Date::"<<d<<"/"<<m<<"/"<<y<<endl;
			return true;
					
		}
		void display()
		{
			cout<<"Date::"<<d<<"/"<<m<<"/"<<y<<endl;
		}
				
};


//struct date
//{
//    int d,m,y;
//};
int month[]={31,28,31,30,31,30,31,31,30,31,30,31};

int validity(date);  //to check validity of date

//main()
//{
//    int opt,year;
//    while(1)
//    {
//        //creating menu
//    printf("\n1.to find difference b/w dates\n");
//    printf("2.format change\n");
//    printf("3.to find day of week of the date\n");
//    printf("4.to find leap year or not\n");
//    printf("5.exit\n");
//    printf("select option:\n");
//    scanf("%d",&opt);
//  switch(opt)
//  {
//      case 1:difference(); break;
//      case 2:format_change();break;
//      case 3:day_of_week(); break;
//      case 4:
//      printf("Enter the year:\n");
//      scanf("%d",&year);
//      if(leap_year(year))
//        printf("it is a leap year\n");
//      else
//        printf("it is not a leap year\n");
//      break;
//
//      case 5:exit(0);
//      default :printf("you entered wrong input!!\n");
//  }
//   }
//getch();
//}
int difference(date d1,date d2)
{
//		date d1,d2;
		int diff=0,i;
		//    do
		//    {
		//    printf("Enter first date(dd/mm/yyyy):\n");//first date
		//    scanf("%d/%d/%d",&d3.d,&d3.m,&d3.y);  // /-deliminator
		//    }
		//    while(validity(d3)==0);   //checking validity of date
		//    do
		//    {
		//    printf("Enter second date(dd/mm/yyyy):\n");//second date
		//    scanf("%d/%d/%d",&d4.d,&d4.m,&d4.y);
		//    }
		//    while(validity(d4)==0);
		//for finding smaller and greater of the dates
//		if(d3.y!=d4.y)   //if years are not equal
//		{
//		if(d3.y<d4.y)
//		{
//		    d1=d3;d2=d4;
//		}
//		if(d3.y>d4.y)
//		{
//		    d1=d4;d2=d3;
//		}
//		}
//		
//		if(d3.y==d4.y)     //if years are equal
//		{
//		    if(d3.m<d4.m)
//		    {
//		        d1=d3;d2=d4;
//		    }
//		    if(d3.m>d4.m)
//		    {
//		        d1=d4;d2=d3;
//		    }
//		    if(d3.m==d4.m)  //if months are equal
//		    {
//		        if(d3.d<d4.d)
//		        {
//		            d1=d3;d2=d4;
//		        }
//		        if(d3.d>d4.d)
//		        {
//		            d1=d4;d2=d3;
//		        }
//		    }
//		}

		if(d2.y<d1.y)
		{
			return 0; 
		}
		if(d2.y==d1.y && d2.m<d1.m)
		{
			return 0;
		}
		if(d2.y==d1.y && d2.m==d1.m && d2.d<d1.d)
			return 0;		
		
		//finding difference
	   if(d1.y!=d2.y)     //if years are different (for year and month difference)
	   {
	   for(i=d1.y+1; i<=d2.y-1; i++)
	   {
	       if(leap_year(i))    //if leap year b/w years of two dates
	       {
	           diff=diff+366;
	       }
	       else
	           diff=diff+365;  //normal year
	   }
	
	   for(i=d1.m+1; i<=12; i++)   //for months of smaller date (from that month to dec)
	   {
	       if(i==2)     //for feb month
	        {
	        if(leap_year(d1.y))  //leap year
	        diff=diff+29;
	        else
	        diff=diff+28;   //non leap year
	        }
	       else
	        {
	            diff=diff+month[i-1];  //for other months
	        }
	   }
	   for(i=1; i<=d2.m-1; i++)  //for months of greater date(from jan to less than that month)
	   {
	       if(i==2)  //if feb is in b/w months
	       {
	           if(leap_year(d2.y))
	            diff=diff+29;  //leap year
	           else
	            diff=diff+28;//non leap year
	       }
	       else
	           diff=diff+month[i-1];  //for other months
	   }
	}
	if(d1.y==d2.y&&d1.m!=d2.m)  //if years are equal but month are different (for month difference)
	{
	        for(i=d1.m+1; i<=d2.m-1; i++)  //months b/w the two months
	        {
	            diff=diff+month[i-1];  //no. of days from month array
	        }
	}
	if(d1.y==d2.y&&d1.m==d2.m)   //if years and months both are equal (for days difference)
	{
	    diff=diff+(d2.d-d1.d);   //only day difference here
	}
	if(d1.y!=d2.y||d1.m!=d2.m)    //if year or month are not equal(for days difference)
	{
	   if(d1.m==2)  //for feb month
	   {
	       if(leap_year(d1.y))
	       diff=diff+29-d1.d;  //leap year   given month-date day(of smaller date)
	       else
	       diff=diff+28-d1.d;  //non leap year   given month-date day(of smaller date)
	   }
	   else
	   diff=diff+month[d1.m-1]-d1.d;  // given month-date day  (of smaller date)
	   diff=diff+d2.d;  //(of greater date) direct add the days of date(because start from zero)
	}
	//printf("no. of days b/w these two dates=%d days\n",diff);   //printing diff of dates in days
	return diff;
}
int leap_year(int year)
{
    if(year%400==0) //if divisible by 100 & 400 both then it's leap year
        {return 1;
        exit(0);}
    if(year%4==0&&year%100!=0)  //if divisible by 4 but not divisible by 100 then it's a leap year
        {return 1;
        exit(0);}
    else                     //otherwise it's not a leap year i.e. only divisible by 100 or other
        return 0;             //divisible by 100 but not by 4 and others
}
// to find day of week of the given date
void day_of_week()
{
    date d1;
    int temp,yy,i=0,ycode,mcode,ccode,lycode=0,cen,day; //year code,month code,century code,leap year code
    int m[12]={0,3,3,6,1,4,6,2,5,0,3,5};  //specifying month code
    do
    {
    printf("Enter the date(dd/mm/yyyy):\n");  //entering date
    scanf("%d/%d/%d",&d1.d,&d1.m,&d1.y);
    }
    while(validity(d1)==0);  //checking validity of date
    //for year code
    temp=d1.y;
    yy=0;  //for finding last two digits of the year
    while(i<2)
    {
        yy=yy+(temp%10)*power(10,i);
        temp=temp/10;
        i++;
    }
   ycode=(yy+(yy/4))%7;
   //for month code
   mcode=m[d1.m-1];
   //for century code
   if(d1.y>1600&&d1.y<2400)//for year >=1700  gregorian dates
   {
   cen=d1.y/100;  //cen==hundereth(century number) value of year
   switch(cen)
   {
       case 17: ccode=4; break;
       case 18: ccode=2; break;
       case 19: ccode=0; break;
       case 20: ccode=6; break;
       case 21: ccode=4; break;
       case 22: ccode=2; break;
       case 23: ccode=0; break;
   }
   }
   if(d1.y<1700)  //for year <1700  julean dates
   {
       ccode=(18-(d1.y/100))%7;
   }
   //for leap year code
   /* it is 1 if date is in jan or feb of a leap year otherwise it is 0 */
   if(d1.m==1||d1.m==2)
   {
       lycode=leap_year(d1.y);
   }
   //final calculation
   day=(ycode+mcode+ccode+d1.d-lycode)%7;
   switch(day)
   {
       case 0:printf("\nSunday"); break;
       case 1:printf("\nMonday"); break;
       case 2:printf("\nTuesday"); break;
       case 3:printf("\nWednesday"); break;
       case 4:printf("\nThursday"); break;
       case 5:printf("\nFriday"); break;
       case 6:printf("\nSaturday"); break;
   }
}
//to change the format of the date
void format_change()
{
    date d1;
    int opt;
    char month[12][10]={"January","February","March","April","May","Jun","July","August","September","October","November","December"};
    do
    {
    printf("Enter the date(dd/mm/yyyy):\n");
    scanf("%d/%d/%d",&d1.d,&d1.m,&d1.y);
    }
    while(validity(d1)==0) ;//checking validity
    while(1)
    {
        //creating menu for formats
    printf("\nFormats:\n");
    printf("1.dd month name,yyyy\n");
    printf("2.mm/dd/yyyy\n");
    printf("3.yyyy/mm/dd\n");
    printf("4.yyyy-mm-dd\n");
    printf("5.yyyy month name,dd\n");
    printf("6.exit\n");
    printf("select option:\n");
    scanf("%d",&opt);
    //printing formats
    switch(opt)
    {
        case 1:printf("\n%d %s, %d\n",d1.d,month+d1.m-1,d1.y); break;
        case 2:printf("\n%d/%d/%d\n",d1.m,d1.d,d1.y); break;
        case 3:printf("\n%d/%d/%d\n",d1.y,d1.m,d1.d); break;
        case 4:printf("\n%d-%d-%d\n",d1.y,d1.m,d1.d); break;
        case 5:printf("\n%d %s, %d\n",d1.y,month+d1.m-1,d1.d);break;
        case 6:goto end;
        default :printf("\nInvalid selection\n");
    }
    }
    end:;

}
//for checking the validity of date to be according to date formats of the year
int validity(date d1)
{

    if(d1.d<=0)  //if date is less than zero
    {
        printf("\ninvalid date\n"); return 0;
    }
    if(d1.m<=12&&d1.m>=1)  //for number of months
    {
        //for feb month
    if(d1.m==2)
    {
        if(leap_year(d1.y))
        {
        if(d1.d>29)
            {
                printf("\ninvalid date\n");
                return 0;
            }
        else
            return 1;
        }
        else
            if(d1.d>month[d1.m-1])    //month-global containing number of days in months
            {
            printf("\ninvalid date\n");
            return 0;
            }
            else
            return 1;
    }
    else
    {
    if(d1.d>month[d1.m-1])
    {
        printf("\ninvalid date\n");
        return 0;
    }
    else
    return 1;
    }
    }
    else
        return 0;

}

//power function
int power(int a,int b) //base,exponent
{
    int c,i;
    c=1;
  for(i=1; i<=b; i++)
  {
      c=c*a;
  }
  return c;
}
