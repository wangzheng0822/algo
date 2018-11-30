/*************************************************************************
 > File Name: lisklist.c
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-10-07
 > Desc:    
 ************************************************************************/
#include<stdio.h>


struct stlistNode
{
	int val;
	struct listNode *next;
}listNode;

/*反转链表*/
listNode reverseList(listNode *head)
{
	listNode *prev = NULL;
	listNode *next = NULL;

	while(head != NULL)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}

	return prev;
}

/*判断链表是否有环*/
int hasCycle(listNode *head)
{
	listNode * fast = head;
	listNode * low = head;

	while(fast != NULL && fast->next != NULL)
	{
		low = low->next;
		fast = fast->next->next;
		if (low == fast)
		{
			return 1;
		}
	}

	return 0;
}
/*合并有序链表*/
listNode *mergeTwoLists(listNode *l1,listNode *l2)
{
	listNode head = {0};
	listNode *pRes = &head;

	while(1)
	{
		if(l1 == NULL)
		{
			pRes->next = l2;
		}

		if (l2 == NULL)
		{
			pRes->next = l1;
		}

		if(l1->val < l2->val)
		{
			pRes->next = l1;
			l1 = l1->next;
		}
		else
		{
			pRes->next = l2;
			l2 = l2->next;
		}
		pRes = pRes->next;
	}

	return head;
}
/*
 *删除链表倒数第n个节点，并返回链表头节点 */

listNode * removeNthFromEnd(listNode*headi,int n)
{
	listNode *fast = head;
	listNode *prev = NULL;
	listNpde *next = head;
	int k = n;
	
	/*快指针往后移动k-1*/
	while((k > 1) && (fast != NULL))
	{
		fast = fast->next;
		k--;
	}
	
	/*说明链表数目不足n个*/
	if (fast == NULL)
	{
		return head;
	}

	while (fast->next != NULL)
	{
		fast = fast->next;
		prev = next;
		next = next->next;
	}

	if(prev == NULL)
	{
		head = head->next;
	}
	else
	{
		prev->next = prev->next->next;
	}

	return head;
}
/*求链表的中间节点*/
listNode *middleNode(listNode *head)
{
	listNode * fast = head;
	listNode * low = head;

	while(fast != NULL && fast->next != NULL)
	{
		low = low->next;
		fast = fast->next->next;
	}

	return low;
}
