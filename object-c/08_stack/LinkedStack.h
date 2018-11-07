//
//  LinkedStack.h
//  algo
//
//  Created by Wenru Dong on 2018/10/8.
//  Copyright © 2018年 Wenru Dong. All rights reserved.
//
//  Stack based upon linked list
//  基于链表实现的栈

#import <Foundation/Foundation.h>

@interface LinkedStack : NSObject

- (BOOL)isEmpty;
- (void)push:(int)value;
- (int)pop;

@end
