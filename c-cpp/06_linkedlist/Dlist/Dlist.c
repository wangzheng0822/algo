/*************************************************************************
 > File Name: Dlist.c
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-10-07
 > Desc:    
 ************************************************************************/
#include<stdio.h>
#include <stdbool.h>
#include "./Dlist.h"



void dlist_init(stDlistHead *dlist)		//链表初始化
{
	dlist->size = 0;
	dlist->head = NULL;
	dlist->tail = NULL;
	return;
}

void dlist_destory(stDlistHead *dlist)		//删除链表
{
	stDlistNode *pNode = NULL;
	
	while(dlist->size > 0)
	{
		pNode = dlist->head;
		dlist->head = dlist->head->next;
		free(pNode);
		dlist->size--;
	}

	memset(dlist,0,sizeof(stDlistHead));

	return;
}

int dlist_insert_head(stDlistHead *dlist,stDlistNode *pNode,int data)		//插入头结点，操作的链表，操作的节点，数据
{
   if(pNode == NULL)		//当只传递一个数据时
   {
	    pNode = (stDlistNode *)malloc(sizeof(stDlistNode));		//新建节点，为节点分配空间（malloc（）可能需要#include<malloc.h>）
	    if (pNode == NULL)
	    {
		    return -1;
	    }
    }

    pNode->data = data;			
	pNode->prev = NULL;
	pNode->next = NULL;

	if (dlist->size == 0)		//如果链表长度为0，即链表当前无节点，
	{
		dlist->head = pNode;
		dlist->tail = pNode;
	}
	else                           //如果链表已有节点，则令新插入节点为头节点
	{
		pNode->next = dlist->head;
		dlist->head->prev = pNode;
		dlist->head = pNode;			
	}

	dlist->size++;		//每成功调用一次，链表长度+1
	return 0;
}

stDlistNode * dlist_remove_tail(stDlistHead *dlist)		//删除尾部节点,并返回删除节点
{
	stDlistNode *pNode = NULL;

	if(dlist->size == 0)
	{
		return NULL;
	}

    pNode = dlist->tail;
	if(dlist->size > 1)
	{
		dlist->tail = dlist->tail->prev;
		dlist->tail->next = NULL;
	}
	else
	{
		dlist->head = NULL;
		dlist->tail = NULL;
	}
	dlist->size--;
	return pNode;
}

void dlist_remove_node(stDlistHead * dlist,stDlistNode *pNode) 		//删除指定节点
{
	if ((dlist == NULL)||(pNode == NULL))
	{
		return;
	}

	if (dlist->head == pNode)
	{
		dlist->head = dlist->head->next;
	}
	else if (dlist->tail == pNode)
	{
		dlist->tail = pNode->prev;

		dlist->tail->next = NULL;
	}
	else
	{
		pNode->prev->next = pNode->next;
		pNode->next->prev = pNode->prev;
	}
	dlist->size--;
	pNode->prev = NULL;
	pNode->next = NULL;
	
	if (dlist->size == 0)
	{
		memset(dlist,0,sizeof(stDlistHead)); 		//将dlist占用内存块的所有值置为0，也就是清空head,tail指针内容
	}

	return;
}
stDlistNode * dlist_search(stDlistHead * dlist,int data) 		//根据值搜索节点，并返回
{
	stDlistNode *pNode = dlist->head;
	while(pNode != NULL)
	{
		if (pNode->data == data)
		{
			return pNode;
		}
		pNode = pNode->next;

    }
	return NULL;
}

void dlist_dump(stDlistHead *dlist)		//显示链表中的数据
{
	int no = 0;
	stDlistNode *pNode = dlist->head;
	while(pNode != NULL)		
	{
		printf("\r\n [%d] = %d",no++,pNode->data);
		pNode = pNode->next;		//将pNode的下一个节点赋值给pNode，推进循环
	}

	return;
}


void Lru_dlist(stDlistHead *dlist,int data) 		//LRU（最近最少使用）缓存淘汰算法
{
	stDlistNode *pNode = NULL;

	pNode = dlist_search(dlist,data);		
	if (pNode != NULL) 				//如果在链表中找到这个值，则删除储存这个值的节点，之后吧这个节点放在头部
	{
		dlist_remove_node(dlist,pNode);
	}
	else if(dlist->size >= 4)			//没在链表中找到，且链表长度大于4，则从链表中删除尾部节点，将新数据放在头部
	{
		pNode = dlist_remove_tail(dlist);

	}
	
	dlist_insert_head(dlist ,pNode,data);

	return;
}

int main()
{
	stDlistHead dlist = {0};
    stDlistNode * pNode = NULL;

	dlist_init(&dlist);

	printf("\r\n inset 1,2,3");
	dlist_insert_head(&dlist,NULL,1);
	dlist_insert_head(&dlist,NULL,2);
	dlist_insert_head(&dlist,NULL,3);

	dlist_dump(&dlist);

	pNode = dlist_remove_tail(&dlist);
	if(pNode != NULL)
	{
		printf("\r\n remove %d",pNode->data);
	}
	dlist_insert_head(&dlist,pNode,4);
	dlist_dump(&dlist);

    Lru_dlist(&dlist,5);
	dlist_dump(&dlist);
    Lru_dlist(&dlist,6);
	dlist_dump(&dlist);
    Lru_dlist(&dlist,7);
	dlist_dump(&dlist);
    Lru_dlist(&dlist,5);
	dlist_dump(&dlist);



	while(dlist.size > 0)
	{
	    pNode = dlist_remove_tail(&dlist);
	    if(pNode != NULL)
	    { 
		    printf("\r\n remove %d",pNode->data);
	    	free (pNode);
    	}
	}

	return 0;
}
