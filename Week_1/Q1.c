#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
};
typedef struct Node* NODE;
NODE newNode(int value)
{
	NODE temp = (NODE)malloc(sizeof(struct Node));
	temp->key = value;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

NODE insert(NODE Node,int key)
{
	if(Node == NULL) return newNode(key);

	if(key<Node->key)
		Node->left = insert(Node->left,key);

	else if(key>Node->key)
		Node->right = insert(Node->right,key);

	return Node;
}

int search(NODE root,int val)
{
	while(root!=NULL)
	{
		if(val>root->key)
			root = root->right;
		else if(val<root->key)
			root = root->left;
		else
			return 1;
	}

	return 0;
}

void Inorder(NODE root)
{
	if(root!=NULL)
	{
		Inorder(root->left);
		printf("%d ", root->key);
		Inorder(root->right);
	}
}

void Preorder(NODE root)
{
	if(root!=NULL)
	{
		printf("%d ",root->key);
		Preorder(root->left);
		Preorder(root->right);
	}
}

void Postorder(NODE root)
{
	if(root!=NULL)
	{
		Postorder(root->left);
		Postorder(root->right);
		printf("%d ",root->key);
	}
}

int main()
{
	NODE root = NULL;

	char choice;

	do
	{
		int data;

		printf("Enter an integer node: ");
		scanf("%d",&data);

		root = insert(root,data);

		printf("Press Y to continue or N to stop: ");
		scanf(" %c",&choice);

	}
	while(choice != 'N');

	printf("\n");
	printf("The Inorder Traversal is: ");
	Inorder(root);
	printf("\n");

	printf("\n");
	printf("The Preorder Traversal is: ");
	Preorder(root);
	printf("\n");

	printf("\n");
	printf("The Postorder Traversal is: ");
	Postorder(root);
	printf("\n");

	printf("\n");
	int node;
	printf("Enter the node to be searched: ");
	scanf("%d",&node);

	if(search(root,node) == 1)
		printf("Key found\n");
	else
	{
		printf("Key not found\n");
		root = insert(root,node);
		printf("After insertion ");
	Inorder(root);
	printf("\n");
	}

	return 0;
}