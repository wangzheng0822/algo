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



void dlist_init(stDlistHead *dlist)
{
	dlist->size = 0;
	dlist->head = NULL;
	dlist->tail = NULL;
	return;
}

void dlist_destory(stDlistHead *dlist)
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

int dlist_insert_head(stDlistHead *dlist,stDlistNode *pNode,int data)
{
   if(pNode == NULL)
   {
	    pNode = (stDlistNode *)malloc(sizeof(stDlistNode));
	    if (pNode == NULL)
	    {
		    return -1;
	    }
    }

    pNode->data = data;
	pNode->prev = NULL;
	pNode->next = NULL;

	if (dlist->size == 0)
	{
		dlist->head = pNode;
		dlist->tail = pNode;
	}
	else
	{
		pNode->next = dlist->head;
		dlist->head->prev = pNode;
		dlist->head = pNode;			
	}

	dlist->size++;
	return 0;
}

stDlistNode * dlist_remove_tail(stDlistHead *dlist)
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

void dlist_remove_node(stDlistHead * dlist,stDlistNode *pNode)
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
		memset(dlist,0,sizeof(stDlistHead));
	}

	return;
}
stDlistNode * dlist_search(stDlistHead * dlist,int data)
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

void dlist_dump(stDlistHead *dlist)
{
	int no = 0;
	stDlistNode *pNode = dlist->head;
	while(pNode != NULL)
	{
		printf("\r\n [%d] = %d",no++,pNode->data);
		pNode = pNode->next;
	}

	return;
}


void Lru_dlist(stDlistHead *dlist,int data)
{
	stDlistNode *pNode = NULL;

	pNode = dlist_search(dlist,data);
	if (pNode != NULL)
	{
		dlist_remove_node(dlist,pNode);
	}
	else if(dlist->size >= 4)
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
