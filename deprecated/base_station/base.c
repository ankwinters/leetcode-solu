#include  <stdio.h>
#include  <stdlib.h>
#define MAX 100
#define INFINITE 100000000
long calc(long M, long N, long A, long B);
int main(int argc, char *argv[])
{
	long N,M;
	long A,B;
	long T;
	long i;
	long amount;
	scanf("%d",&T);
	for( i=0 ; i<T ; i++ )
	{
		scanf("%ld %ld %ld %ld",&N, &M, &A, &B);
		amount = calc(M, N, A, B);
		printf("Case #%ld: %ld\n", i+1, amount);
	}
	return 0;
	
}
long calc(long M, long N, long A, long B)
{
	long i,j,x,y;
	long sum = INFINITE;
	long temp;
	long temp1,temp2,temp3;
	long Alist[MAX][2]={0};
	long Blist[MAX][2]={0};
	for( i=0 ; i<A ; i++ )
	{
		scanf("%ld %ld", &Alist[i][0], &Alist[i][1]);
	}
	for( j=0 ; j<B ; j++ )
	{
		scanf("%ld %ld", &Blist[j][0], &Blist[j][1]);
	}
	for( x=1 ; x<=M ; x++ )
	{
		for( y=1 ; y<=N ; y++ )
		{
			temp = 0;
			temp3 = INFINITE;
			for(i=0;i<A;i++)
			{
				temp1 = x - Alist[i][0];
				temp2 = y - Alist[i][1];
				temp = temp+temp1*temp1+temp2*temp2;
			}
			for(j=0;j<B;j++)
			{
				temp1 = x - Blist[j][0];
				if(temp1<0)
					temp1=-temp1;
				temp2 = y - Blist[j][1];
				if(temp2<0)
					temp2=-temp2;
				if(temp3>temp1+temp2)
					temp3 = temp1+temp2;
			}
			temp = temp+temp3;
			if(sum>temp)
				sum=temp;
		}
		
	}
	return sum;
}
	
