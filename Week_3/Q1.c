#include <stdio.h>
void main()
{
	for(int k=0;k<4;k++)
	{	
		int arr[30],n,count=0,temp;
		//printf("Enter n:\n");
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		for(int i=0;i<n-1;i++)
		{
			for(int j=0;j<n-i-1;j++)
			{
				count++;
				if(arr[j]>arr[j+1])
				{	 
					//count++;
					temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
			}
		}
		//for(int i=0;i<n;i++)
		//	printf("%d ",arr[i]);
		printf("%d ",n);
		printf("%d\n",count );
	}
}
