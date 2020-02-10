#include <stdio.h>
#include <stdlib.h>

void main()
{
	int v;
	printf("Enter number of vertices\n");
	scanf("%d",&v);
	int ad[v][v];
	printf("Enter adjacency matrix\n");
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			scanf("%d",&ad[i][j]);
		}
	}
	printf("\nAdjacency matrix is:\n");
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			printf("%d  ",ad[i][j]);
		}
		printf("\n");
	}
	printf("Adjacency list:\n");
	for(int i=0;i<v;i++)
	{
		printf("%d--",i);
		for(int j=0;j<v;j++)
		{
			if(ad[i][j]==1)
			{
				printf("%d,",j );
			}
		}
		printf("\n");
	}
}