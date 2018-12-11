#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// https://www.youtube.com/watch?v=2g9OSRKJuzM&t=17s

#define MAX_LEVEL 15

struct node {
	int val;
	int max_level;
	struct node *forward[MAX_LEVEL];
};

struct skip_list {
	struct node head;
	int max_level;
	int max_level_nodes;
};

void node_init(struct node* node)
{
	memset(node, 0, sizeof(struct node));
}

void skip_list_init(struct skip_list* sl)
{
	node_init(&sl->head);
	sl->max_level = 0;
	sl->max_level_nodes = 0;
}

void random_init()
{
	static bool done = false;

	if (done)
		return;

	srandom(time(NULL));
	done = true;
}

int random_level(void)
{
    int i, level = 1;

    random_init();

    for (i = 1; i < MAX_LEVEL; i++)
	    if (random() % 2 == 1)
		    level++;

    return level;
}

void random_level_test()
{
	printf("random level %d\n", random_level());
	printf("random level %d\n", random_level());
	printf("random level %d\n", random_level());
	printf("random level %d\n", random_level());
	printf("random level %d\n", random_level());
}

void insert(struct skip_list *sl, int val)
{
	int level = random_level();
	struct node *update[MAX_LEVEL];
	struct node *new, *p;
	int i;

	new = (struct node*)malloc(sizeof(struct node));
	if (!new)
		return;

	new->max_level = level;
	new->val = val;

	for (int i = 0; i < MAX_LEVEL; i++)
		update[i] = &sl->head;

	p = &sl->head;
	for (i = level - 1; i >= 0; i--) {
		while(p->forward[i] && p->forward[i]->val < val)
			p = p->forward[i];

		update[i] = p;
	}

	for (i = 0; i < level; i++) {
		new->forward[i] = update[i]->forward[i];
		update[i]->forward[i] = new;
	}

	if (sl->max_level < level) {
		sl->max_level = level;
		sl->max_level_nodes = 1;
	} else if (sl->max_level == level)
		sl->max_level_nodes++;
}

struct node *find(struct skip_list* sl, int val)
{
	struct node *node = &sl->head;
	int i;

	for (i = sl->max_level - 1; i >= 0; i--) {
		while (node->forward[i] && node->forward[i]->val < val)
			node = node->forward[i];
	}

	if (node->forward[0] && node->forward[0]->val == val) {
		return node->forward[0];
	}
	else
		return NULL;
}

void delete(struct skip_list* sl, int val)
{
	struct node *update[MAX_LEVEL];
	struct node *p;
	int i;

	p = &sl->head;

	for (i = sl->max_level; i >= 0; i--) {
		while (p->forward[i] && p->forward[i]->val < val)
			p = p->forward[i];

		update[i] = p;
	}

	if (p->forward[0] == NULL || p->forward[0]->val != val)
		return;

	if (p->forward[0]->max_level == sl->max_level)
		sl->max_level_nodes--;

	for (i = sl->max_level-1; i >= 0; i--) {
		if (update[i]->forward[i] && update[i]->forward[i]->val == val)
			update[i]->forward[i] = update[i]->forward[i]->forward[i]; 
	}

	// fixup max_level and max_level_nodes
	if (sl->max_level_nodes == 0) {
		//sl->max_level--;
		p = &sl->head;
		// skip (max_level - 1), direct test (max_level - 2)
		// since no nodes on (max_level - 1)
		for (i = sl->max_level - 2; i >= 0; i--) {
			while (p->forward[i]) {
				sl->max_level_nodes++;
				p = p->forward[i];
			}

			if (sl->max_level_nodes) {
				sl->max_level = i + 1;
				break;
			} else
				sl->max_level = i;
		}
	}
}


void print_sl(struct skip_list* sl)
{
	struct node *node;
	int level;

	printf("%d level skip list with %d nodes on top\n",
		sl->max_level, sl->max_level_nodes);
	
	for (level = sl->max_level - 1; level >= 0; level--) {
		node = &sl->head;
		printf("Level[%02d]:", level);
		while (node->forward[level]) {
			printf("%4d", node->forward[level]->val);
			node = node->forward[level];
		}
		printf("\n");
	}
}

int main()
{
	struct skip_list sl;
	struct node *node = NULL;
	int i;

	skip_list_init(&sl);
	print_sl(&sl);

	for (i = 0; i < 10; i++)
		insert(&sl, i);
	print_sl(&sl);

	node = find(&sl, 8);
	if (node)
		printf("find 8 in sl %d\n", node->val);
	else
		printf("8 not in sl\n");

	for (i = 0; i < 10; i++) {
		delete(&sl, i);
		print_sl(&sl);
	}

	return 0;
}
