#include <stdio.h>
#include <stdlib.h>

int partition(int a[],int l,int r)
{
	int pivot=a[l];
	int i=l+1, j=r;
	while(i<=j)
	{	
		while(a[i]<pivot)
			i++;
		while(a[j]>pivot)
			j--;
		if(i<j)
		{
			int temp;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}	
	}
	int temp;
	temp=a[l];
	a[l]=a[j];
	a[j]=temp;
	return j;
}

void quickSort(int a[],int l,int r)
{
	if(l<r)
	{
		int p=partition(a,l,r);
		quickSort(a,l,p-1);
		quickSort(a,p+1,r);
	}
}
void main()
{
	int n;
	printf("Enter n:");
	scanf("%d",&n);
	int a[n];
	printf("Enter eles\n");
	for (int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	quickSort(a,0,n-1);
	printf("Sorted\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d  ",a[i] );
	}
}