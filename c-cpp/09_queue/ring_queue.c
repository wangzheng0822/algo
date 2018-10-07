#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct ring_queue {
	int cap;
	int head, tail;
	int *_q;
};

int alloc_queue(struct ring_queue* queue, int cap)
{
	if (!queue || cap < 0)
		return -1;
	if (queue->_q)
		return -1;

	queue->_q = (int *)malloc(cap * sizeof(int));
	if (!queue->_q)
		return -1;

	queue->head = queue->tail = 0;
	queue->cap = cap;
	return 0;
}

void free_queue(struct ring_queue *queue)
{
	queue->cap = 0;
	queue->head = queue->tail = 0;
	free(queue->_q);
}

int _valid_index(int curr, int step, int cap)
{
	return (curr + step) % cap;
}

int _next(int curr, int cap)
{
	return _valid_index(curr, 1, cap);
}

bool is_empty(struct ring_queue *queue)
{
	return (queue->head == queue->tail);
}

bool is_full(struct ring_queue *queue)
{
	int next_tail = _next(queue->tail, queue->cap);
	return (next_tail == queue->head);
}

int enqueue(struct ring_queue* queue, int elem)
{
	if (is_full(queue))
		return -1;

	queue->_q[queue->tail] = elem;
	queue->tail = _next(queue->tail, queue->cap);
	return 0;
}

int dequeue(struct ring_queue* queue, int *elem)
{
	if (is_empty(queue))
		return -1;

	if (elem)
		*elem = queue->_q[queue->head];
	queue->head = _next(queue->head, queue->cap);
	return 0;
}

int size(struct ring_queue* queue)
{
	int size = queue->tail - queue->head;

	if (size < 0)
		size += queue->cap;
	return size;
}

void dump(struct ring_queue* queue)
{
	int i, idx;

	printf("Queue has %d elements with %d capacity\n",
		size(queue), queue->cap);
	for (i = 0; i < size(queue); i++) {
		idx = _valid_index(queue->head, i, queue->cap);
		printf("[%02d]: %08d\n", idx, queue->_q[idx]);
	}
}

int main()
{
	struct ring_queue queue = {0, 0, 0, NULL};
	int i;

	if (alloc_queue(&queue, 8)) {
		printf("Failed to allocate a queue\n");
		return -1;
	}

	printf("A new queue is %s\n", is_empty(&queue)?"empty":"not empty");

	enqueue(&queue, 1);
	printf("After enqueue 1 element, queue is %s\n", is_empty(&queue)?"empty":"not empty");
	dequeue(&queue, NULL);
	printf("After dequeue 1 element, queue is %s\n", is_empty(&queue)?"empty":"not empty");

	for (i = 0; i < 7; i++)
		enqueue(&queue, i);
	printf("After enqueue 7 element, queue is %s\n", is_full(&queue)?"full":"not full");

	for (i = 0; i < 4; i++) {
		dequeue(&queue, NULL);
		enqueue(&queue, i);
	}
	printf("After enqueue/dequeue 4 element, queue is %s\n",
			is_full(&queue)?"full":"not full");
	printf("Head is %d, Tail is %d\n", queue.head, queue.tail);

	dump(&queue);
	free_queue(&queue);
	return 0;
}
