//
//  Sort.h
//  test1231231
//
//  Created by Scarlett Che on 2018/12/12.
//  Copyright © 2018 Scarlett Che. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Sort : NSObject
//  冒泡排序
+ (NSArray *)bubbleSortWithArray:(NSArray *)array;

//  插入排序
+ (NSArray *)insertionSortWithArray:(NSArray *)array;

//  选择排序
+ (NSArray *)selectionSortWithArray:(NSArray *)array;
@end

NS_ASSUME_NONNULL_END
