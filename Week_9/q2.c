#include <stdio.h>
#include <stdlib.h>

int count=0;

struct node 
{
	int data;
	struct node *link;
};
typedef struct node* NODE;

NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("OUT OF MEMORY\n");
		exit;
	}
	return x;
}

NODE insert_r(NODE first, int ele)
{
	NODE new,cur;
	new=getnode();
	new->data=ele;
	new->link=NULL;
	if(first==NULL)
		return new;
	cur=first;
	while(cur->link!=NULL)
	{
		cur=cur->link;
	}
	cur->link=new;
	return first;
}

int search(NODE first, int key)
{
	NODE cur;
	if(first==NULL)
	{
		count++;
		return 0;
	}
	else
	{
		cur=first;
		while(cur!=NULL)
		{
			count++;
			if(cur->data==key)
				return 1;
			cur=cur->link;
		}
	}
}


void main()
{
	for(int l=0;l<5;l++)
	{
		count=0;
		int m,key,value;
		//printf("Enter value of m\n");
		scanf("%d",&m);
		NODE arr[m];
		for(int i=0;i<m;i++)
			arr[i]=NULL;
		//printf("Enter key values (-1 to stop)\n");
		while(1)
		{
			scanf("%d",&key);
			if(key==-1)
				break;
			value=key%m;
			arr[value]=insert_r(arr[value],key);
		}
		//for(int i=0;i<m;i++)
		//{
		//	printf("%d : ",i );
		//	display(arr[i]);
		//}
		//printf("Enter key to search:\n");
		scanf("%d",&key);
		int flag=0;
		value=key%m;
		flag=search(arr[value],key);
		//if(flag)
			//printf("FOUND!!\n");
		//else
		//	printf("NOT FOUND!!\n");
		printf("%d %d\n",m,count );
	}
}
