#include<stdio.h>

int size;




void init(int arr[])
{   
    int i;
    for(i = 0; i < size; i++)
        arr[i] = -1;
}

void insert(int arr[],int value)
{   
    int key = value % size;
    
    if(arr[key] == -1)
    {   
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value,key);
    }
    else
    {   
        printf("Collision : arr[%d] has element %d already!\n",key,arr[key]);
        int cur=(key+1)%size;
        while(cur!=value)
        {
        	if(arr[cur]==-1)
        	{   
     		    arr[cur] = value;
        		printf("%d inserted at arr[%d]\n", value,cur);
        		return;
   			}
   			else
   				cur=(cur+1)%size;
        }
        printf("FULL!!\n");
    }
}

void search(int arr[],int value)
{
    int key = value % size;
    if(arr[key] == value)
        printf("Search Found\n");
    else
    {
    	int cur=(key+1)%size;
        while(cur!=key)
        {
        	if(arr[cur]==value)
        	{   
     		    printf("Search Found\n");
        		return;
   			}
   			else
   				cur=(cur+1)%size;
        }
        printf("Search Not Found\n");
    }
}

void print(int arr[])
{
    int i;
    for(i = 0; i < size; i++)
        printf("arr[%d] = %d\n",i,arr[i]);
}

void main()
{
	int key,value;
    printf("Enter value of size\n");
	scanf("%d",&size);
	int arr[size];
	init(arr);
	printf("Enter key values (-1 to stop)\n");
	while(1)
	{
		scanf("%d",&key);
		if(key==-1)
			break;
		value=key%size;
		insert(arr,key);
	}
	printf("Table:\n");
	print(arr);
	printf("Enter element to search\n");
	scanf("%d",&key);
	search(arr,key);
}