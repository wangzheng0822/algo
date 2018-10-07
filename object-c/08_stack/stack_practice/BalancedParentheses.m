
#import "BalancedParentheses.h"
#import "ArrayStack.h"

const NSDictionary *parenthesesDict() {
    return @{@"(": @")", @"{": @"}", @"[": @"]"};
}

@implementation BalancedParentheses {
    Stack *_stack;
}

- (instancetype)init {
    self = [super init];
    _stack = [[Stack alloc] initWithCapacity:100];
    return self;
}

- (BOOL)checkForParenthessBlanced:(NSString *)express {
    NSInteger midIndex = express.length / 2;
    for (int i = 0; i < express.length; ++i) {
        NSString *ele = [express substringWithRange:NSMakeRange(i, 1)];
        if (i < midIndex) {
            // 前半部分把与 ele 匹配的括号加入栈
            [_stack push:parenthesesDict()[ele]];
        } else {
            // 后半部分检查栈顶的元素与当前元素是否相同
            NSString *topEle = [_stack pop];
            if (![topEle isEqualToString:ele]) {
                return NO;
            }
        }
    }
    return YES;
}

@end
