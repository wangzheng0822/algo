//
//  Sort.m
//  test1231231
//
//  Created by Scarlett Che on 2018/12/12.
//  Copyright © 2018 Scarlett Che. All rights reserved.
//

#import "Sort.h"

@implementation Sort
//  冒泡排序
+ (NSArray *)bubbleSortWithArray:(NSArray *)array {
    if (array.count <= 1) {
        return array;
    }
    
    NSMutableArray *aryM = array.mutableCopy;
    
    for (int i = 0; i < aryM.count - 1; i++) {
        BOOL flag = NO; //  提前结束标记
        for (int j = 0; j < aryM.count - i - 1; j++) {
            NSInteger value1 = [aryM[j] integerValue];
            NSInteger value2 = [aryM[j + 1] integerValue];
            
            if (value1 > value2) {
                flag = YES;
                [aryM exchangeObjectAtIndex:j withObjectAtIndex:j+1];
            }
        }
        
        
        if (flag == NO) {
            //  提前结束
            break;
        }
    }
    return aryM.copy;
}

//  插入排序
+ (NSArray *)insertionSortWithArray:(NSArray *)array {
    NSMutableArray *aryU = array.mutableCopy;
    
    for (int i = 1; i < aryU.count; i++) {
        NSInteger value = [aryU[i] integerValue];
        
        for (int j = 0; j < i; j ++) {
            NSInteger sortedValue = [aryU[j] integerValue];
            if (value < sortedValue) {
                id obj = aryU[i];
                [aryU removeObjectAtIndex:i];
                [aryU insertObject:obj atIndex:j];
                break;
            }
        }
    }
    return aryU.copy;
}

//  选择排序
+ (NSArray *)selectionSortWithArray:(NSArray *)array {
    if (array.count <= 1) {
        return array;
    }
    
    NSMutableArray *aryM = array.mutableCopy;
    for (int i = 0; i < array.count - 1; i++) {
        NSInteger minIndex = NSNotFound;
        NSInteger minValue = NSNotFound;
        for (int j = i + 1; j < array.count - 1; j++) {
            NSInteger tmp = [array[j] integerValue];
            if (tmp < minValue) {
                minValue = tmp;
                minIndex = j;
            }
        }
        
        if (minIndex != NSNotFound && minValue != NSNotFound && minValue < [array[i] integerValue]) {
            [aryM exchangeObjectAtIndex:minIndex withObjectAtIndex:i];
        }
        
    }
    return array;
}
@end
