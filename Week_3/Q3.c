#include<stdio.h>
#include<stdlib.h>

int PartitionFunc(int arr[],int index,int sum,int total)
{
    //sum*2 = total then we are successful
    int len = 0,i = 0;
    while(arr[i] != '\0')
    {
        len++;
        i++;
    }
    if(sum * 2 ==  total)
        return 1;
    if(sum > total/2 || index >= len)
        return 0;
    return PartitionFunc(arr,index+1,sum,total) || PartitionFunc(arr,index+1,sum + arr[index],total);
    //basically 1st case corresponds to not taking the current number and the 2nd case corresponds to taking the number in the set
}

int main()
{
    printf("Enter the number of elements: ");
    int N;
    scanf("%d",&N);

    int arr[N];

    printf("Enter the elements: ");

    for(int i = 0;i<N;i++)
        scanf("%d",&arr[i]);

    int total = 0;

    for(int i = 0;i<N;i++)
        total += arr[i];
    
    if(total%2 != 0)
    {
        printf("Cannot be partitioned\n");
        exit(0);
    }
    
    else
    {
        if(PartitionFunc(arr,0,0,total))
            printf("Partition sets exists\n");

        else
            printf("Partition set does not exist\n");
    }

    return 0;     
}