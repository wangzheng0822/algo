/*************************************************************************
 > File Name: Dlist.c
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-10-07
 > Desc:    
 ************************************************************************/
#include<stdio.h>

typedef struct DlistNode
{
	struct DlistNode *prev;
	struct DlistNode *next;
	int    data;
}stDlistNode;

typedef struct Dlisthead
{
	int size;
	stDlistNode *head;
	stDlistNode *tail;
}stDlistHead;

