/*************************************************************************
 > File Name: list_queue.h
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-10-13
 > Desc:    
 ************************************************************************/

#ifndef LINK_LIST_QUEUE_H
#define LINK_LIST_QUEUE_H

typedef struct _list_queue_node
{
	void *data;
	struct _list_queue_node *next;
}queue_node;

typedef struct _list_queue
{
	int num;
	queue_node *head;
	queue_node *tail;
}list_queue;

#define list_queue_is_empty(queue) ((queue->num) == 0)
list_queue *list_queue_create();
int list_queue_enqueue(list_queue *queue,void *data);
int list_queue_dequeue(list_queue *queue,void **data);

#endif
