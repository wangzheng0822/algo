/*************************************************************************
 > File Name: arrayStack.c
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-10-12
 > Desc:   数组实现顺序栈 
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"./arrayStack.h"

/*创建并初始化顺序栈*/
stArrayStack * arrayStack_create(int size)
{
	stArrayStack *parrStack = NULL;

	parrStack = (stArrayStack *)malloc(sizeof(stArrayStack));
	if (parrStack == NULL)
	{
		return NULL;
	}
	
	parrStack->size = size;
	parrStack->pos = -1;
	parrStack->array = (int *)malloc(sizeof(int)*size);
	if(parrStack->array == NULL)
	{
		free(parrStack);
		return NULL;
	}

	return parrStack;
}
/*销毁顺序栈*/
void arrayStack_destory(stArrayStack * parrStack)
{
	if(parrStack == NULL)
	{
		return;
	}

	if (parrStack->array != NULL)
	{
		free(parrStack->array);
	}

	free(parrStack);
	return;
}
/*出栈*/
int arrayStack_pop(stArrayStack *parrStack)
{
	int data = 0;

	if(arrayStack_is_empty(parrStack))
	{
		return -1;
	}
    data = parrStack->array[parrStack->pos];
	parrStack->pos--;

	return data;
}
/*入栈*/
int arrayStack_push(stArrayStack *parrStack,int data)
{
	if(arrayStack_is_full(parrStack))
	{
		return -1;
	}

    parrStack->pos++;
	parrStack->array[parrStack->pos] = data;

	return 0;
}

int arrayStack_push_new(stArrayStack*parrStack,int data)
{
	int *ptmp = NULL;

	/*如果栈不满，直接插入*/
	if(!arrayStack_is_full(parrStack))
	{
		return arrayStack_push(parrStack,data);
	}

	/*如果栈已经满，申请内存*/
    ptmp = (int *)malloc(2*parrStack->size*sizeof(int));
	if (ptmp == NULL)
	{
		return -1;
	}

	memcpy(ptmp,parrStack->array,parrStack->size*sizeof(int));

	free(parrStack->array);

    parrStack->array = ptmp;
	parrStack->size = 2*parrStack->size;
	parrStack->pos++;
    parrStack->array[parrStack->pos] = data;

	return ;
}

void arrayStack_dump(stArrayStack *parrStack)
{
	int i = 0;

	if (arrayStack_is_empty(parrStack))
	{
		printf("\r\n arrayStack is empty.");
		return;
	}
	printf("\r\narrayStack size = %d,pos= %d,",
			parrStack->size,parrStack->pos);
	for(i = 0; i <= parrStack->pos; i++)
	{
		printf("\r\narry[%d] = %d",i,parrStack->array[i]);
	}
}

int main()
{
	int i = 0;
	int ret = 0;
	stArrayStack * parrStack = NULL;

	printf("\r\n create size = 4 arrayStack.");

	parrStack = arrayStack_create(4);
	if (parrStack == NULL)
	{
	    printf("\r\n create size = 4 arrayStack faided.");
		return 0;
	}

	for (i = 0; i < 5; i++)
	{
		ret = arrayStack_push(parrStack,i);
		if(ret != 0)
		{
	        printf("\r\n push size = %d arrayStack faided.",i);

		}
	}
	arrayStack_dump(parrStack);
		
	ret = arrayStack_push_new(parrStack,4);
	if(ret != 0)
	{
	        printf("\r\n push size = %d arrayStack faided.",4);
    }
	arrayStack_dump(parrStack);

	arrayStack_destory(parrStack);
    
	return;
}
