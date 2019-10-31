#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
	int data;
	struct element *prev;
}element;

element *cree_new_element()
{
	element *new_element = malloc(sizeof(element));
	return new_element;
}

void push(element **top, int data)
{
	element *new_top = malloc(sizeof(element));
	new_top->data = data;
	new_top->prev = *top;
	*top = new_top;
}

int is_it_empty(element *top)
{
	if(top == NULL)
	{
		return 1;
	}
	return 0;
}

element *pop(element **top)
{
	if(is_it_empty(*top) == 1)
	{
		exit(1);
	}
	element *new_top = *top;
	*top = (*top)->prev;
	return new_top;
}

void peek(element *top)
{
	printf("[%d]\n",top->data);
}

void main()
{
	element *top = malloc(sizeof(element)), *popped;
	top->prev = NULL;
	top->data = 0;
	for(int i = 1; i < 10; i++)
	{
		push(&top,i);
	}
	while(top != NULL)
	{
		popped = pop(&top);
		printf("%d\n",popped->data);
	}
	printf("\n%d\n",is_it_empty(top));
}