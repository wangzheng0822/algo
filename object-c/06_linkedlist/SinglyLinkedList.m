//
//  SinglyLinkedList.m
//  algo
//
//  Created by Wenru Dong on 2018/10/6.
//  Copyright © 2018年 Wenru Dong. All rights reserved.
//

#import "SinglyLinkedList.h"

@implementation SinglyLinkedList

- (ListNode*)nodeWithValue:(int)value {
    ListNode* current = _head;
    while (current && current.value != value) {
        current = current.next;
    }
    return current;
}

- (ListNode*)nodeAtIndex:(NSUInteger)index {
    ListNode* current = _head;
    NSUInteger position = 0;
    while (current && position != index) {
        current = current.next;
        position++;
    }
    return current;
}

- (void)insertNodeWithValue:(int)value {
    ListNode* aNode = [ListNode nodeWithValue:value];
    [self insertNode:aNode];
}

- (void)insertNode:(nonnull ListNode *)node {
    node.next = _head;
    _head = node;
}

+ (void)insertNodeWithValue:(int)value afterNode:(nonnull ListNode *)node {
    ListNode* aNode = [ListNode nodeWithValue:value];
    [SinglyLinkedList insertNode:aNode afterNode:node];
}

+ (void)insertNode:(nonnull ListNode *)aNode afterNode:(nonnull ListNode *)node {
    aNode.next = node.next;
    node.next = aNode;
}

- (void)insertNodeWithValue:(int)value beforeNode:(nonnull ListNode *)node {
    ListNode* aNode = [ListNode nodeWithValue:value];
    [self insertNode:aNode beforeNode:node];
}

- (void)insertNode:(nonnull ListNode *)aNode beforeNode:(nonnull ListNode *)node {
    ListNode* fakeHead = [ListNode nodeWithValue:0];
    fakeHead.next = _head;
    ListNode* current = fakeHead;
    while (current.next && current.next != node) {
        current = current.next;
    }
    if (current.next == nil) {
        return;
    }
    aNode.next = node;
    current.next = aNode;
}

- (void)deleteNode:(nonnull ListNode *)node {
    if (node.next) {
        node.value = node.next.value;
        node.next = node.next.next;
        return;
    }
    if (_head == nil) return;
    ListNode* current = _head;
    while (current.next && current.next != node) {
        current = current.next;
    }
    current.next = nil;
}

- (void)deleteNodesWithValue:(int)value {
    ListNode* fakeHead = [ListNode nodeWithValue:value+1];
    fakeHead.next = _head;
    ListNode* prev = fakeHead;
    ListNode* current = _head;
    while (current) {
        if (current.value != value) {
            prev.next = current;
            prev = prev.next;
        }
        current = current.next;
    }
    if (prev.next) {
        prev.next = nil;
    }
    _head = fakeHead.next;
}

- (NSString*)debugDescription {
    NSMutableString* info = [[NSMutableString alloc] init];
    ListNode* current = _head;
    if (current) {
        [info appendString:current.debugDescription];
    }
    current = current.next;
    while (current) {
        [info appendString:@"->"];
        [info appendString:current.debugDescription];
        current = current.next;
    }
    return [NSString stringWithString:info];
}

@end
