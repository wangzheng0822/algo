#include <stdio.h>
#include <stdlib.h>

/**
 * 1) 单链表反转
 * 2) 链表中环的检测
 * 3) 两个有序的链表合并
 * 4) 删除链表倒数第 n 个结点
 * 5) 求链表的中间结点
 *
 * Author: Smallfly
 */

typedef struct SinglyLinkedNode {
    int data;
    struct SinglyLinkedNode* next;
} SinglyLinkedNode;

void insertNode(SinglyLinkedNode** head_ref, int data);
void printLinkedList(SinglyLinkedNode* head);

/** 反转单链表 */

void reverse(SinglyLinkedNode** head_ref) {
    if (*head_ref == NULL) return;
    
    SinglyLinkedNode *prev = NULL;
    SinglyLinkedNode *current = *head_ref;
    while (current) {
        SinglyLinkedNode *next = current->next;
        if (!next) {
            // 到达尾结点时，将地址存入 head_ref
            *head_ref = current;
        }
        current->next = prev;
        prev = current;
        current = next;
    }
}

void test_reverse() {
    SinglyLinkedNode* head = NULL;
    insertNode(&head, 3);
    insertNode(&head, 2);
    insertNode(&head, 1);
    
    reverse(&head);
    printLinkedList(head);
}

/** 检测单链表是否有环 */

// 这里使用一级指针也可以
int checkCircle(SinglyLinkedNode** head_ref) {
    if (*head_ref == NULL) return 0;
    SinglyLinkedNode *slow = *head_ref, *fast = *head_ref;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) return 1;
    }
    return 0;
}

void test_checkCircle() {
    SinglyLinkedNode* head = NULL;
    insertNode(&head, 3);
    insertNode(&head, 2);
    insertNode(&head, 1);
    
    int result1 = checkCircle(&head);
    printf("has circle: %d\n", result1);
    
    // make circle linklist
    SinglyLinkedNode* current = malloc(sizeof(SinglyLinkedNode));
    current->data = 0;
    SinglyLinkedNode* h = current;
    for (int i = 1; i < 4; ++i) {
        SinglyLinkedNode* node = malloc(sizeof(SinglyLinkedNode));
        node->data = i;
        current->next = node;
        //reset current node
        current = node;
    }
    current->next = h;
    
    int result2 = checkCircle(&h);
    printf("has circle: %d\n", result2);
}

/** 有序链表合并 */

void moveNode(SinglyLinkedNode** dest_ref, SinglyLinkedNode** src_ref);

SinglyLinkedNode* mergeSortedLinkedList(SinglyLinkedNode* la, SinglyLinkedNode* lb) {
    // 辅助结点，next 指针持有合并后的有序链表
    SinglyLinkedNode dummy;
    
    // 有序链表的尾结点
    SinglyLinkedNode* tail = &dummy;
    
    while (1) {
        // 如果有一个链表为空，直接与另一个链表接起来
        if (!la) {
            tail->next = lb;
            break;
        } else if (!lb) {
            tail->next = la;
            break;
        }
        
        // 将头结点较小的优先添加到 tail
        if (la->data <= lb->data) {
            moveNode(&(tail->next), &la);
        } else {
            moveNode(&(tail->next), &lb);
        }
        tail = tail->next;
    }
    
    return dummy.next;
}

// 将 src_ref 的头结点，添加到 dest_ref 的头部。
void moveNode(SinglyLinkedNode** dest_ref, SinglyLinkedNode** src_ref) {
    if (*src_ref == NULL) return;
    SinglyLinkedNode* new_node = *src_ref;
    
    *src_ref = new_node->next;
    
    new_node->next = *dest_ref;
    *dest_ref = new_node;
}

void test_mergeSortedLinkedList() {
    SinglyLinkedNode* a = NULL;
    insertNode(&a, 10);
    insertNode(&a, 5);
    insertNode(&a, 0);
    
    SinglyLinkedNode* b = NULL;
    insertNode(&b, 8);
    insertNode(&b, 6);
    insertNode(&b, 3);
    
    SinglyLinkedNode* result = mergeSortedLinkedList(a, b);
    printLinkedList(result);
    
    SinglyLinkedNode* result2 = mergeSortedLinkedList(a, NULL);
    printLinkedList(result2);
}

/** 删除倒数第 K 个结点 */

void deleteLastKth(SinglyLinkedNode** head_ref, int k) {
    if (*head_ref == NULL || k == 0) return;
    
    // 快指针向前移动 k-1
    SinglyLinkedNode* fast = *head_ref;
    int i = 1;
    while (i < k && fast != NULL) {
        fast = fast->next;
        ++i;
    }
    
    // 如果快指针为空，说明结点个数小于 k
    if (fast == NULL) return;
    
    SinglyLinkedNode* slow = *head_ref;
    SinglyLinkedNode* prev = NULL;
    while (fast->next != NULL) {
        fast = fast->next;
        prev = slow;
        slow = slow->next;
    }
    
    // 如果 prev 为空，头结点刚好是第 k 个结点
    if (!prev) {
        (*head_ref) = (*head_ref)->next;
    } else {
        prev->next = slow->next;
    }
    free(slow);
}

void test_deleteLastKth() {
    SinglyLinkedNode* head = NULL;
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);
    
    // 1. 删除头结点
    deleteLastKth(&head, 5);
    printLinkedList(head);
    
    // 2. 删除中间结点
    deleteLastKth(&head, 2);
    printLinkedList(head);
    
}

/** 求中间结点  */

SinglyLinkedNode* findMiddleNode(SinglyLinkedNode* head) {
    if (!head) return NULL;
    SinglyLinkedNode* slow = head;
    SinglyLinkedNode* fast = head;
    
    // 1. 慢指针走一步，快指针两步
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

void test_findMiddleNode() {
    SinglyLinkedNode* head = NULL;
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);
    
    SinglyLinkedNode* middleNode = findMiddleNode(head);
    printf("%d\n", middleNode->data);
    printLinkedList(head);
}

/** 工具方法 */

// 插入新结点到链表头部
void insertNode(SinglyLinkedNode** head_ref, int data) {
    SinglyLinkedNode* new_node = malloc(sizeof(SinglyLinkedNode));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// 打印链表
void printLinkedList(SinglyLinkedNode* node) {
    printf("--- start ---\n");
    while (node) {
        printf("data: %d\n", node->data);
        node = node->next;
    }
    printf("--- end ---\n");
}

// 跑测试
void test() {
    
    test_reverse();
    
//    test_checkCircle();
    
//    test_mergeSortedLinkedList();
    
//    test_deleteLastKth();
    
//    test_findMiddleNode();
}
