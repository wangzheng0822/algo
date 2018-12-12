//
//  BM.m
//  BM-Match
//
//  Created by Smallfly on 2018/12/9.
//  Copyright © 2018 Smallfly. All rights reserved.
//

#import "BM.h"

#define SIZE 256

@interface BM()
@property (nonatomic, strong) NSString *a; // 主串
@property (nonatomic, strong) NSString *b; // 匹配串

@property (nonatomic, strong) NSMutableArray *bc; // 匹配串，哈希表，存储字符在匹配串中的下标

@property (nonatomic, strong) NSMutableArray *suffix;
@property (nonatomic, strong) NSMutableArray *prifix;

@end

@implementation BM

- (instancetype)initWithA:(NSString *)a andB:(NSString *)b {
    self = [super init];
    if (!self) return nil;
    _a = a;
    _b = b;
    _bc = [NSMutableArray new];
    _suffix = [NSMutableArray new];
    _prifix = [NSMutableArray new];
    [self generateBC];
    [self generateGS];
    return self;
}

// 构建坏字符哈希表，记录每个字符在匹配串中最后出现的位置
- (void)generateBC {
    for (int i = 0; i < SIZE; ++i) {
        [_bc addObject:@-1];
    }
    for (int i = 0; i < _b.length; ++i) {
        int ascii = (int)[_b characterAtIndex:i]; // char to ASCII
        _bc[ascii] = [NSNumber numberWithInteger:i]; // save b's char index
    }
}

- (NSInteger)bm {
    NSInteger i = 0; // 主串和匹配串对齐的第一个字符
    NSUInteger n = _a.length;
    NSUInteger m = _b.length;
    while (i <= n - m) {
        NSInteger j;
        // 从后往前匹配
        for (j = m - 1; j >= 0; --j) {
            int aValue = (int)[_a characterAtIndex:(i + j)];
            int bValue = (int)[_b characterAtIndex:j];
            if (aValue != bValue) break; // 找到坏字符下标 j 停止
        }
        if (j < 0) {
            return i; // 匹配成功，返回所在的位置
        }
        
        // 坏字符在匹配串中最后出现的位置
        id numberInHashTableBC = _bc[(int)[_a characterAtIndex:(i + j)]];
        NSInteger x = j - [numberInHashTableBC integerValue];
        NSInteger y = 0;
        if (j < m - 1) {
            y = [self moveByGSBy:j];
        }
        i = i + MAX(x, y);
        
        // 这一步比较难理解，不直接滑到过 j，是因为在 j 之前可能存在于坏字符相同的字符
        // 这个于坏字符相同的字符，在匹配串中的最大下标是 numberInHashTableBC
//        i = i + (j - [numberInHashTableBC integerValue]);
    }
    
    return -1;
}

// 好后缀匹配移动
- (NSInteger)moveByGSBy:(NSInteger)j {
    NSUInteger m = _b.length;
    NSInteger k = m - 1 - j; // 好后缀的长度
    NSInteger t = [_suffix[k] integerValue];
    if (t != -1) return j - t + 1; // 匹配串的前缀，是否匹配好后缀，关键
    for (NSInteger r = j+1; r <= m-1; ++r) {
        if ([_prifix[m-r] boolValue]) { // 关键
            return r;
        }
    }
    return m;
}

- (void)generateGS {
    NSUInteger m = _b.length;
    for (NSInteger i = 0; i < m; ++i) {
        _prifix[i] = @(NO);
        _suffix[i] = @(-1);
    }
    for (NSInteger i = 0; i < m - 1; ++i) { // 从 b 中取两个字符对比
        NSInteger j = i;
        NSInteger k = 0; // 公共后缀的长度
        int jValue = (int)[_b characterAtIndex:j];
        int bmValue = (int)[_b characterAtIndex:(m-1-k)];
        while (j >= 0 && jValue == bmValue) { // 与 b[0, m-1] 求公共子串
            ++k;
            --j;
            _suffix[k] = [NSNumber numberWithInteger:(j+1)]; //j+1 代表公共子串在 b 中的起始下标
        }
        if (j == -1) _prifix[k] = @(YES);
    }
}

#pragma mark -

// 同步
- (NSInteger)startMatch {
    return [self bm];
}

// 异步
- (void)startMatchCompeletion:(void (^)(NSInteger))completion {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        completion([self bm]);
    });
}

@end
