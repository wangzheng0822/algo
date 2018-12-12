/*************************************************************************
 > File Name: skiplist.h
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-10-31
 > Desc:    
 ************************************************************************/
#ifndef __SKIP_LIST_H__
#define __SKIP_LIST_H__


typedef struct _node
{
	int key;    /*key是唯一的*/
	int value;  /*存储的内容*/
	int max_level; /*当前节点最大层数*/
	struct _node *next[0];/*level层链表结构*/
}node;

typedef struct _skiplist
{
	int level;
	int count;
	node *head;
}skiplist;

/*根据当前结构体元素的地址，获取到结构体首地址*/
#define offsetof(TYPE,MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#define container(ptr,type,member) ({\
  const typeof( ((type *)0)->member) *__mptr = (ptr);\
  (type *) ( (char *)__mptr - offsetof(type,member));})

#endif
