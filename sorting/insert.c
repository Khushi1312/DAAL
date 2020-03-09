#include <stdio.h>
#include <stdlib.h>
void insertSort(int a[],int n)
{
	for (int i = 1; i < n; i++)
	{
		int p=a[i];
		int j=i-1;
		while(j>=0 && a[j]>p)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=p;
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
	insertSort(a,n);
	printf("Sorted\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d  ",a[i] );
	}
}