#include <stdio.h>
void main()
{
	int arr[]={25,15,17,29,31,47},count[6];
	for(int i=0;i<6;i++)
		count[i]=0;
	for(int i=0;i<6;i++)
	{
		for(int j=i+1;j<6;j++)
		{
			if(arr[i]<arr[j])
				count[j]++;
			else
				count[i]++;
		}	
	}
	printf("INITIAL\n");
	for(int i=0;i<6;i++)
		printf("%d ",arr[i] );
	printf("\nCOUNTER\n");
	for(int i=0;i<6;i++)
		printf("%d ",count[i] );

	int m,res[6];
	for(int i=0;i<6;i++)
	{
		m=count[i];
		res[m]=arr[i];
	}
	printf("\nSORTED\n");
	for(int i=0;i<6;i++)
		printf("%d ",res[i] );
	printf("\n");
}