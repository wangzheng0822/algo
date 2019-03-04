//
//  main.m
//  BM-Match
//
//  Created by Smallfly on 2018/12/9.
//  Copyright © 2018 Smallfly. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BM.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        BM *bm = [[BM alloc] initWithA:@"abacadc" andB:@"adc"];
        
        [bm startMatchCompeletion:^(NSInteger index) {
            NSLog(@"异步查找到下标：%ld\n", index);
        }];
        
        NSLog(@"同步查找到下标：%ld\n", [bm startMatch]);
    }
    return 0;
}
