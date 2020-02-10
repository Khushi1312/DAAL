#include <stdio.h>
#include<stdlib.h>

void printarray(int arr[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(int *arr, int start, int end)
{
    if(start==end)
    {
        printarray(arr, end+1);
    }
    int i;
    for(i=start;i<=end;i++)
    {
        swap((arr+i), (arr+start));
        permutation(arr, start+1, end);
        swap((arr+i), (arr+start));
    }
}

void main()
{
	int n;
	printf("Enter value of n:");
	scanf("%d",&n);
	/*int c[n][n];
	for(int i=0;i<n;i++)
	{
		printf("Enter wages for person %d:",(i+1) );
		for(int j=0;j<n;j++)
		{
			scanf("%d",&c[i][j]);
		}
	}*/
	int arr[n];

	int fact = 1;

	for(int i = 1;i<=n;i++)
		fact = fact*i;

	int mat[fact][n];
	
	for(int i=0;i<n;i++)
		arr[i]=i+1;
	permutation(arr, 0, n-1);
}