//
//  ListNode.h
//  algo
//
//  Created by Wenru Dong on 2018/10/6.
//  Copyright © 2018年 Wenru Dong. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ListNode : NSObject

@property int value;
@property ListNode *next;

- (instancetype)initWithValue:(int)value;
+ (instancetype)nodeWithValue:(int)value;

@end
