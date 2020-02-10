#include <stdlib.h>
#include <stdio.h>
int c=0;
struct node
{
	int info;
	struct node *lchild;
	struct node *rchild;
};
typedef struct node* NODE;
NODE getNode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	return x;
}

NODE create_BT()
{
	NODE temp;
	int ele;
	printf("Enter element(-1 for no data):\n");
	scanf("%d",&ele);
	if(ele==-1)
		return NULL;
	temp=getNode();
	temp->info=ele;
	printf("Enter left child of %d\n",ele);
	temp->lchild=create_BT();
	printf("Enter right child of %d\n",ele);
	temp->rchild=create_BT();
	return temp;
}


int nodeCount(NODE t)
{
	c++;
	if(t==NULL)
		return 0;
	else
		return nodeCount(t->lchild)+nodeCount(t->rchild)+1;
}

void main()
{
	NODE root;
	root=create_BT();
	printf("Number of nodes = %d\n", nodeCount(root));
	printf("Opcount %d\n",c );
}	