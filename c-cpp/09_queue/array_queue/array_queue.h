/*************************************************************************
 > File Name: array_queue.h
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-10-12
 > Desc:    
 ************************************************************************/
#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

typedef struct _array_queue
{
	int size;/*队列的大小*/
	int num; /*当前存储数据的大小*/
	int head;/*队列的头*/
	int tail;/*队列的尾*/
	int *array;/*数据存储区*/
}array_queue;

#define array_queue_is_empty(array_queue) (array_queue->num == 0)
#define array_queue_is_full(array_queue)  ((array_queue->num) == (array_queue->size))

#endif

