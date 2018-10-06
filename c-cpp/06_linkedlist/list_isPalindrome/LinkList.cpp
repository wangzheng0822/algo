#include "LinkList.h"

void CreateListHead(LinkList *&L,ElemType a[],int n)
{
	int i;
	LinkList *s;
	L = (LinkList *)malloc(sizeof(LinkList));
	L->next = NULL;
	for(i = 0;i < n;i++)
	{
		s=(LinkList*)malloc(sizeof(LinkList));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}
void CreateListTail(LinkList *&L,ElemType a[],int n)
{
	int i;
	LinkList * s,* r;
	L = (LinkList *)malloc(sizeof(LinkList));
	r = L;
	for(i = 0;i < n;i++)
	{
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL; 
}
void InitList(LinkList *&L)
{
	L=(LinkList *)malloc(sizeof(LinkList));
	L->next = NULL;
}
void DestroyList(LinkList *&L)
{
	LinkList * pre = L,*p = L->next;
	while(p!=NULL)
	{
		free(pre);
		pre = p;
		p = L->next;
	}
	free(pre);
}
bool ListEmpty(LinkList *L)
{
	return(L->next==NULL); 
}
int ListLength(LinkList *L)
{
	int n = 0;
	LinkList * p = L;
	while(p->next!=NULL)
	{
		n++;
		p=p->next;
	}
	return(n);
}
void ShowList(LinkList *L)
{
	LinkList * p = L->next;//指向开始节点
	while(p!=NULL)
	{
		printf(" %c ",p->data);
		p = p->next; 
	} 
	printf("\n");
}
bool GetListElem(LinkList *L,int i,ElemType &e)
{
	int j = 0;
	LinkList *p = L;
	while(j<i&&p!=NULL)
	{
		j++;
		p=p->next;
	}
	if(p==NULL)
		return false;
	else
	{
		e=p->data;
		return true;
	}
}
int LocateElem(LinkList*L,ElemType e)
{
	int i=1;
	LinkList *p = L->next;
	while(p!=NULL&&p->data!=e){
		p=p->next;
		i++;
	}
	if(p==NULL)
	{
		return(0);
	}
	else
		return(i);
}
bool ListInsert(LinkList *&L,int i,ElemType e)
{
	int j=0;
	LinkList *p =L,*s;
	while(j<i-1&&p!=NULL)
	{
		j++;
		p=p->next;
	}
	if(p==NULL)
	{
		return false;
	}
	else
	{
		s= (LinkList*)malloc(sizeof(LinkList));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}
bool ListDelete(LinkList *&L,int i,ElemType &e)
{
	int j=0;
	LinkList * p =L,*q;
	while(j<i-1&&p!=NULL)
	{
		j++;
		p=p->next;
	}
	if(p==NULL)
		return false;
	else
	{
		q=p->next;
		if(q==NULL)
			return false;
		e=q->data;
		p->next=q->next;
		free(q);
		return true;
	}
}
