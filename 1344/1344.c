#include<stdio.h>
#define MAX 50000
static int A[MAX];
int main()
{
	int n;
	long sum=0;
	long temp=0;
	long min=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	for(int j=0;j<n;j++)
	{
		temp=sum+A[j];
		if(min>temp)
			min=temp;
		sum=temp;
	}
	if(min>=0)
		printf("%ld",min);
	else
		printf("%ld",-min);
	return 0;
}

