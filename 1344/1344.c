#include<stdio.h>
#include<stdlib.h>
#define MAX 50000
#define LINE 1000
static int A[MAX];
void readline();
int main()
{
	int n;
	long sum=0;
	long temp=0;
	long min=0;
	//scanf("%d",&n);
	readline(&n);
	if(n<1 || n>50000)
		exit(-1);
	for(int i=0;i<n;i++)
	{
		//scanf("%d",&A[i]);
		if(A[i]<-1000000000 || A[i]>1000000000)
			exit(-1);
		temp=sum+A[i];
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
void readline(int *n)
{
		FILE *a;
    a=fopen("./1344data","r");
    int temp;
    int i=0;
    fscanf(a,"%d",&temp);
	*n=temp;
    while(fscanf(a,"%d",&temp)==1)
    {
        A[i++]=temp;
    }
}
