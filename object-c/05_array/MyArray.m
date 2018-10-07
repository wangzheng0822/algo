//
//  MyArray.m
//  algo
//
//  Created by Wenru Dong on 2018/10/3.
//  Copyright © 2018年 Wenru Dong. All rights reserved.
//

#import "MyArray.h"

@implementation MyArray
{
    @private
    NSMutableArray *_data;
    NSUInteger _capacity;
    NSUInteger _count;
}

- (instancetype)initWithCapacity:(NSUInteger)capacity {
    self = [super init];
    if (self) {
        _data = [NSMutableArray arrayWithCapacity:capacity];
        _capacity = capacity;
        _count = 0;
    }
    return self;
}

- (id)objectAtIndexedSubscript:(NSUInteger)index {
    if (index >= _count) return nil;
    return _data[index];
}

- (void)removeObjectAtIndex:(NSUInteger)index {
    if (index >= _count) {
        [NSException raise:NSRangeException format:@"Index out of range."];
    }
    for (NSUInteger i = index + 1; i < _data.count; i++) {
        _data[i-1] = _data[i];
    }
    _count--;
}

- (void)insertObject:(nonnull id)anObject atIndex:(NSUInteger)index {
    if (index >= _count || _count == _capacity) {
        [NSException raise:NSRangeException format:@"Index out of range."];
    }
    for (NSUInteger i = _count - 1; i >= index; i--) {
        _data[i+1] = _data[i];
    }
    _data[index] = anObject;
    _count++;
}

// insertToTail
- (void)addObject:(nonnull id)anObject {
    if (_count == _capacity) {
        [NSException raise:NSRangeException format:@"Array is full."];
    }
    [_data addObject:anObject];
    _count++;
}

- (void)printAll {
    for (id obj in _data) {
        NSLog(@"%@", obj);
    }
}

@end
