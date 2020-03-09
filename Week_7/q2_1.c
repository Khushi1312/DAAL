#include<stdio.h> 
#include<stdlib.h> 
  
// An AVL tree node 
struct Node 
{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    int key; 
    struct Node *left; 
    struct Node *right; 
    int height; 
}; 
typedef struct Node* NODE;
int height(NODE N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->height; 
} 
  
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 
  
NODE newNode(int key) 
{ 
    NODE node = (NODE) 
                        malloc(sizeof(struct Node)); 
    node->key   = key; 
    node->left   = NULL; 
    node->right  = NULL; 
    node->height = 1;  // new node is initially added at leaf 
    return(node); 
} 
  
NODE rightRotate(NODE y) 
{ 
    NODE x = y->left; 
    NODE T2 = x->right; 
  
    // Perform rotation 
    x->right = y; 
    y->left = T2; 
  
    // Update heights 
    y->height = max(height(y->left), height(y->right))+1; 
    x->height = max(height(x->left), height(x->right))+1; 
  
    // Return new root 
    return x; 
} 
NODE leftRotate(NODE x) 
{ 
    NODE y = x->right; 
    NODE T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    //  Update heights 
    x->height = max(height(x->left), height(x->right))+1; 
    y->height = max(height(y->left), height(y->right))+1; 
  
    // Return new root 
    return y; 
} 
int getBalance(NODE N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
} 
NODE insert(NODE node, int key) 
{ 
    NODE temp,cur,prev;
    temp=newNode(key);
    if(node==NULL)
        node = temp;
    prev=NULL;
    cur=node;
    while(cur!=NULL)
    {
        prev=cur;
        if(key < cur->key)
            cur=cur->left;
        else
            cur=cur->right;
    }
    if(key < prev->key)
        prev->left=temp;
    else
        prev->right=temp;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), 
                           height(node->right)); 
    /* 3. Get the balance factor of this ancestor 
          node to check whether this node became 
          unbalanced */
    int balance = getBalance(node); 
    // If this node becomes unbalanced, then 
    // there are 4 cases 
    // Left Left Case 
    if (balance > 1 && key < node->left->key) 
        return rightRotate(node); 
    // Right Right Case 
    if (balance < -1 && key > node->right->key) 
        return leftRotate(node); 
    // Left Right Case 
    if (balance > 1 && key > node->left->key) 
    { 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    } 
    // Right Left Case 
    if (balance < -1 && key < node->right->key) 
    { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
    return node; 
} 
void preOrder(struct Node *root) 
{ 
    if(root != NULL) 
    { 
        printf("%d ", root->key); 
        preOrder(root->left); 
        preOrder(root->right); 
    } 
} 
int main() 
{ 
  struct Node *root = NULL; 
  int ele,ch;
  while(1)
  {
    printf("1)insert 2)display\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        scanf("%d",&ele);
        root = insert(root, ele);
        break;
        case 2:
        printf("Preorder traversal of the constructed AVL"
         " tree is \n"); 
        preOrder(root); 
        printf("\n");
        break;
        case 3:
        exit(0);
    }  
  }
} 