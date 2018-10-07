#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdlib.h>
#include <stdio.h>
typedef char ElemType;
typedef struct LNode 
{
	ElemType data;
	struct LNode*next;
}LinkList;

void CreateListHead(LinkList *&L,ElemType a[],int n);
void CreateListTail(LinkList *&L,ElemType a[],int n);
void InitList(LinkList *&L);
void DestroyList(LinkList *&L);
bool ListEmpty(LinkList *L);
int ListLength(LinkList *L);
void ShowList(LinkList *L);
bool GetListElem(LinkList *L,int i,ElemType &e);
int LocateElem(LinkList*L,ElemType e);
bool ListInsert(LinkList *&L,int i,ElemType e);
bool ListDelete(LinkList *&L,int i,ElemType &e);
#endif
