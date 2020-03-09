#include <stdio.h>
#include <stdlib.h>
int cnt=0;
void merge(int a[],int l,int m,int r)
{
	int nb= m-l+1;
	int nc= r-m;
	int b[nb],c[nc];
	for(int i=0;i<nb;i++)
		b[i]=a[l+i];
	for (int i=0;i<nc;i++)
		c[i]=a[m+1+i];
	int i=0,j=0,k=l;
	while(i<nb&&j<nc)
	{
		if(b[i]<c[j])
		{
			a[k]=b[i];
			i++;
		}
		else
		{
			a[k]=c[j];
			j++;
			cnt+=nc-i;
		}
		k++;
	}
	while(i<nb)
	{
		a[k]=b[i];
		k++;
		i++;
	}
	while(j<nc)
	{
		a[k]=c[j];
		k++;
		j++;
	}
}

void mergeSort(int a[], int l, int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		mergeSort(a,l,m);
		mergeSort(a,m+1,r);
		merge(a,l,m,r);
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
	mergeSort(a,0,n-1);
	printf("Sorted\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d  ",a[i] );
	}
	printf("Count %d\n",cnt );
}