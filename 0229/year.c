#include  <stdio.h>
#include  <string.h>

#define MONTH_SIZE 50
const char MONTH[12][MONTH_SIZE]={"January", "February", "March", "April",
   						"May", "June", "July", "August", "September", 
						"October", "November" , "December"};
int compare(char *month);
long calc(int month_A, int day_A, long year_A,
		  int month_B, int day_B, long year_B);
int main(int argc, char *argv[])
{
	int T;
	char Month_A[MONTH_SIZE];
	char Month_B[MONTH_SIZE];
	int  month_A;
	int month_B;
	int day_A;
	int day_B;
	long year_A;
	long year_B;

	long amount;
	int i;
	scanf("%d",&T);
	for(i=0; i<T; i++)
	{
		scanf("%s %d, %ld", Month_A, &day_A, &year_A);
		scanf("%s %d, %ld", Month_B, &day_B, &year_B);
		month_A = compare(Month_A);
		month_B = compare(Month_B);
		amount = calc(month_A, day_A, year_A,
					  month_B, day_B, year_B);
		printf("Case #%d: %ld\n", i+1, amount);
	}
	return 0;
}
int compare(char *month)
{
	int i;
	for( i=0 ; i<12; i++ )
	{
		if(!strcmp(month, MONTH[i]))
			return i+1;
	}	
}
long calc(int month_A, int day_A, long year_A,
		  int month_B, int day_B, long year_B)
{
	long temp,temp1,temp2;
	long sum = 0;
	temp = year_B-year_A-2;
	if(temp>0)
	{
		temp = year_A;
		temp1 = temp/4-temp/100+temp/400;
		temp = year_B-1;
		temp2 = temp/4-temp/100+temp/400;
		sum = temp2 - temp1;
		/*Judge A*/
		if(year_A%400==0||(year_A%4==0&&year_A%100!=0))
		{
			if(month_A==1||(month_A==2&&day_A<=29))
				sum+=1;
		}
		/*Judge B*/
		if(year_B%400==0||(year_B%4==0&&year_B%100!=0))
		{
			if(month_B>=3||(month_B==2&&day_B==29))
				sum+=1;
		}
	}
	else if(temp==0)
	{
		temp = year_A+1;
		if(temp%400==0||(temp%4==0&&temp%100!=0))
			sum+=1;
		/*Judge A*/
		if(year_A%400==0||(year_A%4==0&&year_A%100!=0))
		{
			if(month_A==1||(month_A==2&&day_A<=29))
				sum+=1;
		}
		/*Judge B*/
		if(year_B%400==0||(year_B%4==0&&year_B%100!=0))
		{
			if(month_B>=3||(month_B==2&&day_B==29))
				sum+=1;
		}
	}
	else if(temp==-1)
	{
		if(year_A%400==0||(year_A%4==0&&year_A%100!=0))
		{
			if(month_A==1||(month_A==2&&day_A<=29))
				sum+=1;
		}
		/*Judge B*/
		if(year_B%400==0||(year_B%4==0&&year_B%100!=0))
		{
			if(month_B>=3||(month_B==2&&day_B==29))
				sum+=1;
		}
	}
	else if(temp==-2)
	{
		/*Judge A*/
		if(year_A%400==0||(year_A%4==0&&year_A%100!=0))
		{
			if (  (month_A==1||(month_A==2&&day_A<=29))
				&& (month_B>=3||(month_B==2&&day_B==29)) )
				sum+=1;
		}

	}
	return sum;
}

