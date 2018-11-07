//
//  SinglyLinkedList.h
//  algo
//
//  Created by Wenru Dong on 2018/10/6.
//  Copyright © 2018年 Wenru Dong. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ListNode.h"

@interface SinglyLinkedList : NSObject

@property ListNode* head;

- (ListNode*)nodeWithValue:(int)value;
- (ListNode*)nodeAtIndex:(NSUInteger)index;

- (void)insertNodeWithValue:(int)value;
- (void)insertNode:(nonnull ListNode*)node;
+ (void)insertNodeWithValue:(int)value afterNode:(nonnull ListNode*)node;
+ (void)insertNode:(nonnull ListNode*)aNode afterNode:(nonnull ListNode*)node;
- (void)insertNodeWithValue:(int)value beforeNode:(nonnull ListNode*)node;
- (void)insertNode:(nonnull ListNode*)aNode beforeNode:(nonnull ListNode*)node;

- (void)deleteNode:(nonnull ListNode*)node;
- (void)deleteNodesWithValue:(int)value;

@end
