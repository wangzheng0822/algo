// https://www.youtube.com/watch?v=2g9OSRKJuzM&t=17s
// note: 层数从0开始算，非空跳表的最低level是0，空跳表的level是-1。
// note: 因为randomization的关系，跳表允许的最大层数需要事先设定，
// 当n足够大时，跳表的层数（即节点索引的最大层数）将约等于log2(n)。
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define SKIPLIST_P 0.5
#define INVALID_KEY -1

typedef int ktype;

typedef struct node_
{
	// dtype data;
	ktype key;
	int level;
	struct node_ **forward;
} node;

typedef struct
{
	node *head;
	int level; // 跳表的当前层数，允许的最大层数是head->level
	int nodes;
} skip_list;

skip_list *make_skip_list(int max_level)
{
	skip_list *sl = (skip_list *)malloc(sizeof(skip_list));
	sl->level = -1;
	sl->head = (node *)malloc(sizeof(node));
	sl->head->key = INVALID_KEY;
	sl->head->level = max_level;
	sl->head->forward = (node **)malloc(sizeof(node *) * max_level); // 注意头节点的指针数量不等于sl的max_level
	memset(sl->head->forward, 0, sizeof(node *) * max_level);
	return sl;
}

int random_level(int max_level)
{
	static const int threshold = SKIPLIST_P * RAND_MAX;
	int level = 0;
	while (random() < threshold) //在0.5概率下循环平均执行次数趋于2，因此max_level的比较放外面会更快
		level++;
	return (level < max_level) ? level : max_level;
}

node *search(skip_list *sl, ktype key)
{
	node *cur = sl->head;
	for (int i = sl->level; i >= 0; i--)
	{
		while (cur->forward[i] != NULL && cur->forward[i]->key <= key)
			cur = cur->forward[i];
		if (cur->key == key)
			return cur;
	}
	return NULL;
}

node *insert(skip_list *sl, ktype key)
{
	// 构造新节点
	int level = random_level(sl->head->level);
	if (level > sl->level)
		sl->level = level;
	node *new_node = (node *)malloc(sizeof(node));
	new_node->key = key;
	new_node->level = level;
	new_node->forward = (node **)malloc(sizeof(node *) * level);
	// 插入
	node *cur = sl->head;
	for (int i = sl->level; i >= 0; i--)
	{
		while (cur->forward[i] != NULL && cur->forward[i]->key <= key) //同样键值的情况插入到后面
			cur = cur->forward[i];
		if (level >= i)
		{
			new_node->forward[i] = cur->forward[i];
			cur->forward[i] = new_node;
		}
	}
	sl->nodes++;
	return new_node;
}

void delete(skip_list *sl, ktype key)
{
	node *cur = sl->head;
	node *target = NULL;
	for (int i = sl->level; i >= 0; i--)
	{
		while (cur->forward[i] != NULL && cur->forward[i]->key < key) //同样键值的情况删除最前面者
			cur = cur->forward[i];
		if (cur->forward[i] != NULL && cur->forward[i]->key == key) //删除该层的链接
		{
			target = cur->forward[i];
			cur->forward[i] = target->forward[i];
		}
	}
	if (target != NULL)
	{
		if (target->level == sl->level)
		{
			while (sl->head->forward[sl->level] == NULL)
				sl->level--;
		}
		free(target->forward);
		free(target);
		sl->nodes--;
	}
}

void print_sl(skip_list *sl)
{
	printf("%d level skip list with %d nodes\n", sl->level, sl->nodes);
	for (int i = sl->level; i >= 0; i--)
	{
		node *cur = sl->head;
		printf("Level[%02d]:", i);
		while (cur->forward[i])
		{
			cur = cur->forward[i];
			printf("%4d", cur->key);
		}
		printf("\n");
	}
}

int main(int argc, char* argv[])
{
	srandom(1689859321);
	skip_list *sl = make_skip_list(15);
	print_sl(sl);

	ktype a[] = {4, 3, 6, 9, 7, 1, 2, 5, 8};
	const int n = sizeof(a) / sizeof(ktype);
	for (int i = 0; i < n; i++)
		insert(sl, a[i]);
	print_sl(sl);

	node *cur = search(sl, 8);
	if (cur)
		printf("find 8 in sl: %d\n", cur->key);
	else
		printf("8 not in sl\n");

	for (int i = 0; i < n; i++)
	{
		delete(sl, a[i]);
		printf("delete %d\n", a[i]);
		print_sl(sl);
	}

	return 0;
}