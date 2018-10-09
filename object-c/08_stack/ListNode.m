//
//  ListNode.m
//  algo
//
//  Created by Wenru Dong on 2018/10/6.
//  Copyright © 2018年 Wenru Dong. All rights reserved.
//

#import "ListNode.h"

@implementation ListNode

- (instancetype)initWithValue:(int)value {
    if (self = [super init]) {
        _value = value;
    }
    return self;
}

+ (instancetype)nodeWithValue:(int)value {
    return [[self alloc] initWithValue:value];
}

- (NSString*)debugDescription {
    return [NSString stringWithFormat:@"%d", _value];
}

@end
