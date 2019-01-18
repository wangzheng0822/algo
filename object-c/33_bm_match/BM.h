//
//  BM.h
//  BM-Match
//
//  Created by Smallfly on 2018/12/9.
//  Copyright © 2018 Smallfly. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BM : NSObject
- (instancetype)initWithA:(NSString *)a andB:(NSString *)b;
- (NSInteger)startMatch;
- (void)startMatchCompeletion:(void (^)(NSInteger))completion;
@end

NS_ASSUME_NONNULL_END
