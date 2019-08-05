/**
 * Author:  TripleZ<me@triplez.cn>
 * Date:    2018-10-10
 * Brief:   Linked list class.
 */

#ifndef _LINKEDLIST_HPP_
#define _LINKEDLIST_HPP_

#include <cstdio>
#include "ListNode.hpp"

class LinkedList {
public:
    int size;
    int length;
    ListNode *head;
    LinkedList();
    LinkedList(int size);
    ~LinkedList();
    ListNode* FindElem(int elemVal);
    bool DeleteElem(ListNode *elem);
    bool DeleteLastElem();
    bool InsertElemAtFront(int elemVal);
    bool InsertElemAtBack(int elemVal);
    void PrintList();
};

LinkedList::LinkedList() {
    this -> head = new ListNode();
    this -> head->next = nullptr;
    this -> head->val = -1;
    this -> size = 10; // default
    this -> length = 0;
}

LinkedList::LinkedList(int size) {
    this -> head = new ListNode();
    this -> head->next = nullptr;
    this -> head->val = -1;
    
    this -> size = size;
    this -> length = 0;
}

LinkedList::~LinkedList() {
    ListNode *p, *q;
    p = this -> head;
    while(p -> next != nullptr) {
        q = p -> next;
        p -> next = p -> next -> next;
        delete q;
    }
    delete head;
    this -> head = nullptr;
    this -> length = 0;
}

ListNode* LinkedList::FindElem(int elemVal) {
    ListNode *p;
    for (p = this -> head -> next; p != nullptr; p = p -> next) {
        if (p -> val == elemVal) {
            return p;
        }
    }
    return nullptr;
}

bool LinkedList::DeleteElem(ListNode *elem) {
    ListNode *prev, *next;
    for (prev = this -> head; prev -> next != elem; prev = prev -> next);
    next = elem -> next;
    prev -> next = next;
    delete elem;
    this -> length --;
    return true;
}

bool LinkedList::DeleteLastElem() {
    ListNode *prev, *elem;
    for (prev = this -> head; prev -> next -> next != nullptr; prev = prev -> next) ;
    elem = prev -> next;
    prev -> next = nullptr;
    delete elem;
    this -> length --;
    return true;
}

bool LinkedList::InsertElemAtFront(int elemVal) {
    ListNode *newNode = new ListNode();
    newNode -> val = elemVal;
    newNode -> next = this -> head -> next;
    this -> head -> next = newNode;
    this -> length ++;
    return true;
}

bool LinkedList::InsertElemAtBack(int elemVal) {
    ListNode *newNode = new ListNode();
    newNode -> val = elemVal;
    ListNode *end;
    for (end = this -> head; end -> next != nullptr; end = end -> next);
    end -> next = newNode;
    newNode -> next = nullptr;
    this -> length ++;
    return true;
}

void LinkedList::PrintList() {
    ListNode *elem;
    printf("List: ");
    for (elem = this -> head -> next; elem -> next != nullptr; elem = elem -> next) {
        printf("%d - ", elem -> val);
    }
    printf("%d\n", elem -> val);
}

#endif
