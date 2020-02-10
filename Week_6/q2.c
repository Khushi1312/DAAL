#include <stdlib.h>
#include <stdio.h>
int c=0;
int partition(int a[],int l,int r)
{
	int p=a[l];
	int i=l+1;
	int j=r;
	while(i<=j)
	{
		
		while(a[i]<p)
		{	
			i++;
			c++;
		}
		while(a[j]>p)
		{	
			j--;
			c++;
		}
		int temp = a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	int temp = a[i];
	a[i]=a[j];
	a[j]=temp;

	temp = a[l];
	a[l]=a[j];
	a[j]=temp;	

	return j;
}

void quicksort(int a[],int l,int r)
{
	if (l<r)
	{
		int p=partition(a,l,r);
		quicksort(a,l,p-1);
		quicksort(a,p+1,r);
	}
}

void main()
{
	for(int k=0;k<7;k++)
	{
		int n;
		scanf("%d",&n);
		int a[n];
		printf("%d\t",n );
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		
		quicksort(a,0,n-1);
		
		printf("%d\n",c );
	}	
}