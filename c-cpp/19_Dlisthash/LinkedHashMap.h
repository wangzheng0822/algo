/*************************************************************************
 > File Name: LinkedHashMap.h
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-11-08
 > Desc:    
 ************************************************************************/


#ifndef __LINKED_HASH_MAP__
#define __LINKED_HASH_MAP__

typedef struct _lisked_hash_map_node
{
	void *key;
	void *data;
	struct _lisked_hash_map_node *next; 
	struct list_head Dlist_node;
}LiskedHashMapNode;

typedef struct _lisked_hash_map
{
	LiskedHashMapNode **hTabs;/*哈希桶*/
	struct list_head header;/*双向循环链表头*/
	int size;
	int nel_max;
	int nel;
    int (*hash_value)(struct _lisked_hash_map *h,const void *key); /*哈希函数*/
    int (*keycmp)(struct _lisked_hash_map *h,const void *key1,const void *key2);/*哈希key比较函数，当哈希数值一致时使用*/
    void (*hash_node_free)(LiskedHashMapNode *node,int flg);

}LinkedHashMap;

typedef int (*hash_value_func)(struct _lisked_hash_map *h,const void *key); /*哈希函数*/
typedef int (*keycmp_func)(struct _lisked_hash_map *h,const void *key1,const void *key2);/*哈希key比较函数，当哈希数值一致时使用*/
typedef void (*hash_node_free_func)(LiskedHashMapNode *node,int flg);

LiskedHashMapNode * LinkedHashMap_delete(LinkedHashMap *h,void *key);
#endif
