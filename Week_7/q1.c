#include <stdlib.h>
#include <stdio.h>

struct node
{
	int info;
	struct node *left;
	struct node *right;
};
typedef struct node* NODE;

NODE create(NODE bnode,int x)
{
	
	if(bnode==NULL)
	{
		bnode=(NODE)malloc(sizeof(struct node));
		bnode->info=x;
		bnode->left=bnode->right=NULL;
	}
	else if(x > bnode->info)
		bnode->right=create(bnode->right,x);
	else 
		bnode->left=create(bnode->left,x);
	return bnode;
}

int max(int a, int b){
    return (a>b)?a:b;
}

int getHeight(NODE t){
    if(t == NULL)
        return 0;
    
    return 1 + max(getHeight(t->left), getHeight(t->right));
}

int getBalance(NODE root) 
{ 
    if (root == NULL) 
        return 0; 
    return getHeight(root->left) - getHeight(root->right); 
} 
void inorder(NODE root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d %d\n",root->info,getBalance(root) );
		inorder(root->right);
	}
}

void main()
{
	int n,x,t=1,ch,i;
	NODE root;
	root=NULL;
	while(1)
	{
		printf("1)Insert 2)Inorder 3)Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			scanf("%d",&x);
			root=create(root,x);
			break;
			case 2:
			printf("Inorder traversal\n");
			inorder(root);
			break;
			case 3:
			exit(0);
		}

	}	
}