/*************************************************************************
 > File Name: array_queue.c
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-10-12
 > Desc:    
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"./array_queue.h"


array_queue * array_queue_create(int size)
{
	array_queue * queue = NULL;

	queue = (array_queue*)malloc(sizeof(array_queue));
	if (queue == NULL)
	{
		return NULL;
	}
	queue->array = (int *)malloc(sizeof(int)*size);
	if (queue->array == NULL)
	{
        free(queue);
		return NULL;
	}
	queue->size  = size;
	queue->num   = 0;
	queue->head  = 0;
	queue->tail  = 0;

	return queue;
}

void array_queue_destory(array_queue *queue)
{
    if (queue == NULL)
	{
		return;
	}

	if (queue->array != NULL)
	{
		free(queue->array);
	}

	free(queue);
	return;
}

/*入队列 */
int array_queue_enqueue(array_queue *queue,int data)
{
	/*队列为空，或者队列满时，返回-1*/
	if ((queue == NULL) || (array_queue_is_full(queue)))
	{
		return -1;
	}

	queue->num++;
	queue->array[queue->tail] = data;
	queue->tail = (queue->tail + 1) % queue->size;

	return 0;
}

/*出队列*/
int array_queue_dequeue(array_queue * queue,int *data)
{
	/*队列为空，数据存储为空，队列为空时返回-1*/
	if ((queue == NULL) || (data == NULL) || (array_queue_is_empty(queue)))
	{
		return -1;
	}
    *data = queue->array[queue->head];
	queue->num--;
	queue->head = (queue->head + 1) % queue->size;

    return 0;
}

void array_queue_dump(array_queue *queue)
{
	int i = 0;
	int pos = 0;

	if ((queue == NULL) || (array_queue_is_empty(queue)))
	{
		printf("\r\n queue is empty");
		return;
	}

	printf("\r\n size:%d,num:%d,head:%d,tali:%d",
			queue->size,queue->num,queue->head,queue->tail);
	for (i = 0; i < queue->num; i ++)
	{
		pos = (queue->head + i) %queue->size;
		printf("\r\n array[%d] = %d",pos,queue->array[pos]);
	}
    return;
}

int main()
{
	int i = 0;
	int ret = 0;
	int data = 0;
	array_queue * queue = NULL;

	queue = array_queue_create(4);
	if (queue == NULL)
	{
		printf("\r\n queue is create failed.");
		return 0;
	}
	/*队列时空时，出队返回错误*/
	ret = array_queue_dequeue(queue, &data);
	if (ret != 0)
	{
		    printf("\r\n queue %d dequeue failed.",ret);
	}

	/*队列大小是4，入队5个，最后一个报错*/
	for (i = 0; i < 5; i++)
	{
		ret = array_queue_enqueue(queue,i);
		if (ret != 0)
		{
		    printf("\r\n queue %d enqueue failed.",i);

		}
	}

	array_queue_dump(queue);
    
	ret = array_queue_dequeue(queue, &data);
	if (ret != 0)
	{
		    printf("\r\n queue %d dequeue failed.",i);
	}
	printf("\r\n queue %d dequue.",data);
	array_queue_dump(queue);
	data = 5;
	printf("\r\n queue %d enqueue.",data);
	ret = array_queue_enqueue(queue,data);
	if (ret != 0)
	{
		printf("\r\n queue %d enqueue failed.",data);
    }
	array_queue_dump(queue);
    
	array_queue_destory(queue);
	return 0;

}

