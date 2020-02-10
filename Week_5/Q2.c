#include <stdlib.h>
#include <stdio.h>
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

int max(int a, int b){
    return (a>b)?a:b;
}

int getHeight(NODE t){
    if(t == NULL)
        return 0;
    
    return 1 + max(getHeight(t->lchild), getHeight(t->rchild));
}

int getDiam(NODE t){
    if(t == NULL)
        return 0;

    int l_h = getHeight(t->lchild);
    int r_h = getHeight(t->rchild);
    int l_d = getDiam(t->lchild);
    int r_d = getDiam(t->rchild);
    return max(l_h + r_h + 1, max(l_d, r_d));
}

void main()
{
	NODE root;
	root=create_BT();
	printf("Diam = %d\n", getDiam(root));
}	