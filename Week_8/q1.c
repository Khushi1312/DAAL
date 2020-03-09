#include <stdlib.h>
#include <stdio.h>

struct node
{
	struct node *lchild;
	struct node *rchild;
	int info;
};
typedef struct node* NODE;

