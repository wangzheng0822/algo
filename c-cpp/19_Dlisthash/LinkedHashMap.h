/*************************************************************************
 > File Name: LinkedHashMap.h
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-11-08
 > Desc:    
 ************************************************************************/


#ifndef __LINKED_HASH_MAP__
#define __LINKED_HASH_MAP__

/*数据存放节点*/
typedef struct _lisked_hash_map_node
{
	void *key; /*键*/
	void *data; /*数据*/ZZ
	struct _lisked_hash_map_node *next; /*哈希冲突时，用来挂接后续节点*/
	struct list_head Dlist_node;/*用来挂接双向链表*/
}LiskedHashMapNode;

typedef struct _lisked_hash_map
{
	LiskedHashMapNode **hTabs;/*哈希桶*/
	struct list_head header;/*双向循环链表头*/
	int size; /**/
	int nel_max; /*支持最大节点数*/
	int nel;   /*当前节点数*/
    int (*hash_value)(struct _lisked_hash_map *h,const void *key); /*哈希函数*/
    int (*keycmp)(struct _lisked_hash_map *h,const void *key1,const void *key2);/*哈希key比较函数，当哈希数值一致时使用*/
    void (*hash_node_free)(LiskedHashMapNode *node,int flg);/*用来释放节点内存*/

}LinkedHashMap;

typedef int (*hash_value_func)(struct _lisked_hash_map *h,const void *key); /*哈希函数*/
typedef int (*keycmp_func)(struct _lisked_hash_map *h,const void *key1,const void *key2);/*哈希key比较函数，当哈希数值一致时使用*/
typedef void (*hash_node_free_func)(LiskedHashMapNode *node,int flg);

LiskedHashMapNode * LinkedHashMap_delete(LinkedHashMap *h,void *key);
#endif
