/*************************************************************************
 > File Name: Dlist.c
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-10-07
 > Desc:    
 ************************************************************************/
#include<stdio.h>

typedef struct DlistNode          //双向链表中每一个节点
{				  	
	struct DlistNode *prev;   //节点前项指针
	struct DlistNode *next;   //节点后项指针
	int    data;              //数据
}stDlistNode;

typedef struct Dlisthead          //定义链表总体
{
	int size;                 //链表长度
	stDlistNode *head;        //头指针
	stDlistNode *tail;        //尾部指针
}stDlistHead;

