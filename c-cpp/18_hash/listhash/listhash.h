/*************************************************************************
 > File Name: listhash.h
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-11-06
 > Desc: 根据linux内核模块hashtab编写用户层hashtab接口
         linux-4.19.1\security\selinux\ss\hashtab.c
		 linux-4.19.1\security\selinux\ss\hashtab.h
 ************************************************************************/


#ifndef __HASHTAB_H__
#define __HASHTAB_H__


typedef struct _hashtab_node
{
	void * key;
	void * data;
	struct _hashtab_node *next;
}hashtab_node;

typedef struct _hashtab
{
	hashtab_node **htables; /*哈希桶*/
	int size;              /*哈希桶的最大数量*/
	int nel;               /*哈希桶中元素的个数*/
    int (*hash_value)(struct _hashtab *h,const void *key); /*哈希函数*/
    int (*keycmp)(struct _hashtab *h,const void *key1,const void *key2);/*哈希key比较函数，当哈希数值一致时使用*/
    void (*hash_node_free)(hashtab_node *node);
}hashtab;


#define HASHTAB_MAX_NODES  (0xffffffff)

typedef int (*hash_key_func)(struct _hashtab *h,const void *key); /*哈希函数*/
typedef int (*keycmp_func)(struct _hashtab *h,const void *key1,const void *key2);/*哈希key比较函数，当哈希数值一致时使用*/
typedef void (*hash_node_free_func)(hashtab_node *node);
/*根据当前结构体元素的地址，获取到结构体首地址*/
#define offsetof(TYPE,MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#define container(ptr,type,member) ({\
  const typeof( ((type *)0)->member) *__mptr = (ptr);\
  (type *) ( (char *)__mptr - offsetof(type,member));})


hashtab * hashtab_create(int size,hash_key_func hash_value,
    	keycmp_func keycmp,hash_node_free_func hash_node_free);
void hashtab_destory(hashtab *h);
int hashtab_insert(hashtab * h,void *key,void *data);
hashtab_node *hashtab_delete(hashtab *h, void *key);
void *hashtab_search(hashtab*h,void *key);

#endif
