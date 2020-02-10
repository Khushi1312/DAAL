#include <stdio.h>
typedef struct
{
	char arr[1000];
	int top;
}Stack;

int isEmpty(int top)
{
	if(top == -1)
	{
		return 1;
	}
	return 0;
}

int isFull(int top)
{
	if(top == 999)
	{
		return 1;
	}
	return 0;
}
void push(Stack *s, char ele)
{
	if(isFull(s->top)==1)
	{
		printf("Overflow\n");
	}
	else
	{
		s->top = s->top + 1;
		s->arr[s->top] = ele;
	}
}
void pop(Stack *s)
{
	if(isEmpty(s->top)==1)
	{
		printf("Empty\n");
	}
	else
	{
		s->top = s->top - 1;
	}
}