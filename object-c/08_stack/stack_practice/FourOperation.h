
/**
 整型四则运算
 
 Author: Smallfly
 */

#import <Foundation/Foundation.h>

@interface FourOperation : NSObject

+ (FourOperation *)shared;

/**
 整型四则运算

 @param expression 运算表达式，注意操作数和运算符之间要有空格
 @return 计算结果
 */
- (NSNumber *)caculateExpression:(NSString *)expression;

@end
