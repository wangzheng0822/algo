/*************************************************************************
 > File Name: linklist_stack.h
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-10-12
 > Desc:    
 ************************************************************************/

#ifndef STACK_LINK_LIST_H
#define STACK_LINK_LIST_H

typedef struct _linkliststack
{
	int data;
	struct _linkliststack *next;
}linklist_stack;


#define stack_is_empty(liststack) (liststack->next == NULL)

#endif

