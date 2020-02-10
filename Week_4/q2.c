#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct Node* node;

struct Node
{
	int data;
	node next;	
};

typedef struct 
{
	node head;
}List;

typedef struct 
{
	int V;
	List* array;
}Graph;

typedef struct 
{
	int top;
	int arr[MAX];
}Stack;

Stack Push(Stack s, int x)
{
    s.top += 1;
	s.arr[s.top] = x;
	return s;
}

Stack Pop(Stack s)
{
	s.top--;
	return s;
}

int tos(Stack s)
{
    return s.arr[s.top];
}

int Empty(Stack s)
{
	if(s.top == -1)
	    return 1;
    else
        return 0;
}

node newNode(int data)
{
	node new = (node)malloc(sizeof(struct Node));
	new->data = data;
	new->next = NULL;
	return new;
}

Graph* createGraph(int V)
{
	Graph* g = (Graph*)malloc(sizeof(Graph));
	g->V = V;
	g->array = (List*)malloc(V * sizeof(List));
	for(int i = 0; i < V; i++)
		g->array[i].head = NULL;
	return g;
}

void addEdge(Graph* g, int a, int b)
{
	node new = newNode(b);
	new->next = g->array[a].head;
	g->array[a].head = new;
	new = newNode(a);
	new->next = g->array[b].head;
	g->array[b].head = new;
}
  
void DFS_Iterative(Graph* g, int start, int color[])
{
	Stack s;
	s.top = -1;
	s = Push(s, start);
 	while(Empty(s) == 0)
	{
		int a = tos(s);
		s = Pop(s);
		if(color[a] == 0)
		{
			color[a] = 1;
			printf("%d ", a);
		}
		node i;
		for(i = g->array[a].head; i != NULL; i = i->next)
		{
			if(color[i->data] == 0)
				s = Push(s, i->data);
		}
	}
}

void DFS(Graph* g) 
{ 
	int x = g->V;
    int color[x];
    for(int i = 0; i < x; i++)
    	color[i] = 0;
    for (int i = 0; i < x; i++) 
        if (color[i] == 0) 
           DFS_Iterative(g, i, color);
           
} 

int main()
{
	int V, e;
	printf("\n\nEnter the number of vertices:\n\n");
	scanf("%d", &V);
	Graph* g = createGraph(V);
	printf("\n\nEnter the number of edges:\n\n");
	scanf("%d", &e);
	int m, n;
	printf("\n\nEnter the edges:\n\n");
	for(int i = 0; i < e; i++)
	{
		scanf("%d %d", &m, &n);
		addEdge(g, m, n);
	}
	printf("\n\nFollowing is the DFS iterative traversal:\n\n");
	DFS(g);
}
