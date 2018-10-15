/*************************************************************************
 > File Name: arrayStack.h
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-10-12
 > Desc:    
 ************************************************************************/

#ifndef ARRAY_STACJ_H
#define ARRAY_STACJ_H

typedef struct _array_stack
{
	int size;/*栈的大小*/
	int pos;/*当前存储元素的个数，即栈顶元素下表*/
	int *array;/*数据存储区*/
}stArrayStack;

#define arrayStack_size(arrayStack) (arrayStack->size)
#define arrayStack_is_empty(arrayStack) (arrayStack->pos == -1)
#define arrayStack_is_full(arrayStack)  (arrayStack->pos == (arrayStack->size-1))

#endif
