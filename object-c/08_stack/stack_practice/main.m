
#import <Foundation/Foundation.h>
#import "FourOperation.h"
#import "BalancedParentheses.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // 测试四则运算
        NSNumber *a = [[FourOperation shared] caculateExpression:@"10 - 4 / 2 * 3 + 3 - 6 / 2"];
        NSNumber *b = [[FourOperation shared] caculateExpression:@"10 - 3"];
        NSNumber *c = [[FourOperation shared] caculateExpression:@"2 * 3"];
        NSLog(@"FourOperation: %ld\t%ld\t%ld\t", a.integerValue, b.integerValue, c.integerValue);
        
        // 测试括号匹配
        BalancedParentheses *balancedCheck = [BalancedParentheses new];
        BOOL result = [balancedCheck checkForParenthessBlanced:@"([{{{}}}])"];
        NSLog(@"BalancedParentheses: %d", result);
    }
    return 0;
}
