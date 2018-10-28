/*************************************************************************
 > File Name: linklist_stack.c
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-10-12
 > Desc:    
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "./linklist_stack.h"

linklist_stack * stack_create()
{
	linklist_stack * stack = NULL;

	stack = (linklist_stack *)malloc(sizeof(linklist_stack));
	if (stack == NULL)
	{
		return NULL;
	}

	stack->next = NULL;

	return stack;
}

void stack_destory(linklist_stack* stack)
{
	linklist_stack * ptmp = NULL;

	while(!stack_is_empty(stack))
	{
		ptmp = stack->next;
		stack->next = stack->next->next;

		free(ptmp);
	}

	free(stack);

	return;
}

int stack_push(linklist_stack *stack,int data)
{
	linklist_stack * ptmp = NULL;

	ptmp = (linklist_stack *)malloc(sizeof(linklist_stack));
	if (ptmp == NULL)
	{
		return -1;
	}

	ptmp->data = data;
	ptmp->next = stack->next;
	stack->next = ptmp;

	return 0;
}

int stack_pop(linklist_stack*stack,int *data)
{
	linklist_stack *ptmp = NULL;
	if (data == NULL)
	{
		return -1;
	}
	if(stack_is_empty(stack))
	{
		return -1;		
	}
	*data = stack->next->data;
    ptmp = stack->next;
	stack->next = ptmp->next;
	free(ptmp);

    return 0;
}


void stack_dump(linklist_stack *stack)
{
	linklist_stack * ptmp = stack->next;
	
	while(ptmp != NULL)
	{
		printf("\r\n data = %d",ptmp->data);
		ptmp = ptmp->next;
	}
	return;
}

int main()
{
	int i = 0;
	int ret = 0;
	int data = 0;
	linklist_stack * stack = NULL;

    stack = stack_create();
	if (stack == NULL)
	{
		printf("\r\n stack create falied.");
        return 0;			
	}
    
	for (i = 0; i < 4; i++)
	{
		ret = stack_push(stack,i);
		if(ret != 0)
		{
		    printf("\r\n stack push %d falied.",i);
		}
	}

    stack_dump(stack);

	for (i = 0; i < 5; i++)
	{
		ret = stack_pop(stack,&data);
		if(ret != 0)
		{
		    printf("\r\n stack pop%d falied.", i);
		}
		else
		{
		    printf("\r\n data = %d,",data);
		}
	}

	stack_destory(stack);

	return 0;

}
