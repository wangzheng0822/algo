#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

enum child_dir {
	left_child,
	right_child,
	root,
};

struct node {
	unsigned long data; 
	struct node *left;
	struct node *right;
};

struct root {
	struct node *r;
};

void dump(struct node *node, int level, enum child_dir dir)
{
	if (!node)
		return;

	dump(node->right, level + 1, right_child);

	if (dir == left_child)
		printf("%*s\n", level*3, "|");

	printf("%*s - %05lu\n", level*3, " ", node->data);

	if (dir == right_child)
		printf("%*s\n", level*3, "|");

	dump(node->left, level + 1, left_child);
}

struct node* find(struct root *root, unsigned long data)
{
	struct node* n = root->r;

	while (n) {
		if (n->data == data)
			return n;
		if (data < n->data)
			n = n->left;
		else
			n = n->right;
	}

	return NULL;
}

struct node* new_node(unsigned long data)
{
	struct node *n;

	n = malloc(sizeof(struct node));

	n->data = data;
	n->left = n->right = NULL;
	return n;
}

void insert(struct root *root, struct node *new)
{
	struct node *parent;

	if (!root->r) {
		root->r = new;
		return;
	}

	parent = root->r;

	while (true) {
		/* Don't support duplicate data */
		if (new->data == parent->data)
			break;

		if (new->data < parent->data) {
			if (!parent->left) {
				parent->left = new;
				break;
			}
			parent = parent->left;
		} else {
			if (!parent->right) {
				parent->right = new;
				break;
			}
			parent = parent->right;
		}
	}
}

struct node* delete(struct root *root, unsigned long data)
{
	struct node *n = root->r, **p = &root->r;
	struct node *child;

	while (n && n->data != data) {
		if (data < n->data) {
			p = &n->left;
			n = n->left;
		} else {
			p = &n->right;
			n = n->right;
		}
	}

	if (!n)
		return NULL;
	
	if (n->left && n->right) {
		struct node *rn = n->right, **rp = &n->right;

		while (rn->left) {
			rp = &rn->left;
			rn = rn->left;
		}

		n->data = rn->data;
		n = rn;
		p = rp;
	}

	child = n->left ? n->left : n->right;
	*p = child;

	return NULL;
}

void insert_test()
{
	struct root tree;
	struct node* n;

	tree.r = NULL;

	insert(&tree, new_node(9));

	insert(&tree, new_node(5));
	insert(&tree, new_node(2));
	insert(&tree, new_node(8));

	insert(&tree, new_node(18));
	insert(&tree, new_node(13));
	insert(&tree, new_node(21));
	insert(&tree, new_node(20));

	dump(tree.r, 0, root);

	n = find(&tree, 18);
	if (n && n->data == 18)
		printf("Get 18\n");

}

void delete_test()
{
	struct root tree;
	struct node* n;

	tree.r = NULL;

	insert(&tree, new_node(9));

	insert(&tree, new_node(5));
	insert(&tree, new_node(2));
	insert(&tree, new_node(8));

	insert(&tree, new_node(18));
	insert(&tree, new_node(13));
	insert(&tree, new_node(21));
	insert(&tree, new_node(20));

	dump(tree.r, 0, root);

	delete(&tree, 20);
	printf("Delete 20\n");
	dump(tree.r, 0, root);

	delete(&tree, 9);
	printf("Delete 9\n");
	dump(tree.r, 0, root);
}

int main()
{
	//insert_test();
	delete_test();
	return 0;
}
