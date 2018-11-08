#ifndef __SINGLELIST_H__
#define __SINGLELIST_H__

#include <stdlib.h>
#include <stdbool.h>

typedef struct listNode
{
    struct listNode *next;
    void *value;
}listNode;

typedef struct linkedList
{
    listNode *head;
    size_t len;
    size_t typesize;

    void(*dup)(void*, void*);
    int(*match)(void*, void*);
    void(*free)(void*);
}linkedList;

#define listSetDupMethod(l,m) ((l)->dup = (m))
#define listSetFreeMethod(l,m) ((l)->free = (m))
#define listSetMatchMethod(l,m) ((l)->match = (m))

#define listGetDupMethod(l) ((l)->dup)
#define listGetFree(l) ((l)->free)
#define listGetMatchMethod(l) ((l)->match)

linkedList *listCreate();
void listRelease(linkedList *list);
void listEmpty(linkedList *list);
linkedList *listAddNodeHead(linkedList *list, void *value);
linkedList *listAddNodeTail(linkedList *list, void *value);
linkedList *listInsertNode(linkedList *list, listNode *old_node, void *value, bool after);
void listDelNode(linkedList *list, listNode *node);

listNode *listSearchKey(linkedList *list, void *key);
listNode *listIndex(linkedList *list, long index);
linkedList* listRewind(linkedList *list);

size_t listLength(linkedList *list);

#endif // !__SINGLELIST_H__
