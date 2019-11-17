#include <stdio.h>
#include <stdbool.h>

struct single_list {
	struct single_list *next;
	int val;
};

struct single_list_head {
	struct single_list *head;
};

bool is_empty(struct single_list_head *head)
{
	return head->head == NULL;
}

void dump(struct single_list_head *head)
{
	struct single_list *tmp = head->head;
	int idx = 0;

	while (tmp) {
		printf("[%02d]: %08d\n", idx++, tmp->val);
		tmp = tmp->next;
	}
}

void insert(struct single_list **prev, struct single_list *elem)
{
	if (!prev)
		return;

	elem->next = *prev;
	*prev = elem;
}

void insert_head(struct single_list_head *head, struct single_list *elem)
{
	insert(&head->head, elem);
}

struct single_list* del(struct single_list **prev)
{
	struct single_list *tmp;

	if (!prev)
		return NULL;
	if (*prev == NULL)
		return NULL;
	tmp = *prev;
	*prev = (*prev)->next;
	tmp->next = NULL;

	return tmp;
};

struct single_list* delete_head(struct single_list_head* head)
{
	return del(&head->head);
};

struct single_list** search(struct single_list_head* head, int target)
{
	struct single_list **prev, *tmp;

	for (prev = &head->head, tmp = *prev;
	     tmp && (tmp->val < target);
	     prev = &tmp->next, tmp = *prev)
		;

	return prev;
};

void reverse(struct single_list_head* head)
{
	struct single_list_head tmp = {NULL};
	struct single_list *elem;

	while (!is_empty(head)) {
		elem = delete_head(head);
		insert_head(&tmp, elem);
	}

	head->head = tmp.head;
}

bool is_cyclic(struct single_list_head* head)
{
	struct single_list *s1, *s2;

	s1 = s2 = head->head;

	while(s1 && s2) {
		s1 = s1->next;
		s2 = s2->next ? s2->next->next:s2->next;

		if (s1 == s2)
			return true;
	}
	return false;
}

struct single_list* middle(struct single_list_head* head)
{
	struct single_list *s1, *s2;
	struct single_list pseudo_head;

	pseudo_head.next = head->head;
	s1 = s2 = &pseudo_head;

	while (true) {
		if (!s2 || !s2->next)
			return s1;
		s1 = s1->next;
		s2 = s2->next->next;
	}

	return NULL;
};

int main()
{
	struct single_list_head head = {NULL};
	struct single_list lists[10];
	struct single_list **prev;
	int idx;

	for (idx = 0; idx < 10; idx++) {
		lists[idx].val = idx;
		lists[idx].next = NULL;
	}

	insert_head(&head, &lists[6]);
	insert_head(&head, &lists[5]);
	insert_head(&head, &lists[4]);
	insert_head(&head, &lists[1]);
	insert_head(&head, &lists[0]);

	printf("=== insert 0, 1, 4, 5, 6\n");
	dump(&head);

	prev = search(&head, 2);
	insert(prev, &lists[2]);
	printf("=== insert 2\n");
	dump(&head);

	printf("middle elem is %d\n", middle(&head)->val);

	prev = search(&head, 2);
	if ((*prev) && ((*prev)->val == 2))
		printf("The list contains 2\n");
	else
		printf("The list not contains 2\n");

	del(prev);
	prev = search(&head, 2);
	printf("After remove 2\n");
	if ((*prev) && ((*prev)->val == 2))
		printf("The list contains 2\n");
	else
		printf("The list not contains 2\n");
	dump(&head);

	printf("After reverse \n");
	reverse(&head);
	dump(&head);

	printf("middle elem is %d\n", middle(&head)->val);

	lists[0].next = &lists[6];
	printf("list is%s cyclic\n", is_cyclic(&head)?"":" not");

	return 0;
}
