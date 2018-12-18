/*************************************************************************
 > File Name: binarysearchtree.h
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-11-12
 > Desc:    
 ************************************************************************/
#ifndef __BINARY_SEARCH_TREE__
#define __BINARY_SEARCH_TREE__
typedef int mytype;

typedef struct _bstree_node
{
	mytype data;
	struct _bstree_node *lchild;
	struct _bstree_node *rchild;
}bstree_node;

typedef struct _bstree
{
    int size;
    int (*compare)(mytype key1,mytype key2);
	int (*destory)(mytype data);
	bstree_node *root;
}bstree;

typedef int (*compare_fuc)(mytype key1,mytype key2);
typedef int (*destory_fuc)(mytype data);

#define bstree_is_empty(tree)  (tree->size == 0)

bstree *bstree_create(compare_fuc compare,destory_fuc destory);

#endif
