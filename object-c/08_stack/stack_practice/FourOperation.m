#import "FourOperation.h"
#import "ArrayStack.h"

const NSDictionary *operationPriorityDict() {
    return @{@"*": @1, @"/": @1, @"+": @0, @"-": @0};
}

@implementation FourOperation {
    @private
    Stack *_optStack;
    Stack *_numStack;
    NSNumberFormatter *_numFormatter;
}

+ (FourOperation *)shared {
    static FourOperation* single = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        single = [FourOperation new];
    });
    return single;
}

- (instancetype)init {
    self = [super init];
    _optStack = [[Stack alloc] initWithCapacity:100];
    _numStack = [[Stack alloc] initWithCapacity:100];
    _numFormatter = [NSNumberFormatter new];
    return self;
}

- (id)caculateExpression:(NSString *)expression {
    NSArray *elements = [expression componentsSeparatedByString:@" "];
    
    for (NSString *obj in elements) {
        NSNumber *numb = [_numFormatter numberFromString:obj];
        if (numb) { // 运算数
            [_numStack push:numb];
        } else { // 操作符
            
            // 如果栈顶操作符优先级大于等于当前操作符
            while ([self _topOperationPriorityIsHigherOrEqualToOperation:obj]) {
                
                // 取出栈顶的操作符和两个操作数做一次运算
                NSNumber *res = [self _excuteOnceCaculate];
                
                // 计算结果存入栈
                [_numStack push:res];
            }
            
            [_optStack push:obj];
        }
    }
    
    // 如果操作符存在栈中，依次取出做运算
    NSNumber *res = nil;
    while ([_optStack top]) {
        res = [self _excuteOnceCaculate];
        [_numStack push:res];
    }
    return res;
}

- (NSInteger)_getPriority:(NSString *)opt {
    return [[operationPriorityDict() objectForKey:opt] integerValue];
}

- (BOOL)_topOperationPriorityIsHigherOrEqualToOperation:(NSString *)opt {
    NSString *topOpt = [_optStack top];
    if (!topOpt) return NO;
    NSInteger curPriority = [self _getPriority:opt];
    NSInteger topPriority = [self _getPriority:topOpt];
    return curPriority <= topPriority;
}

- (NSNumber *)_excuteOnceCaculate {
    NSNumber *numRight = [_numStack pop];
    NSNumber *numLeft = [_numStack pop];
    NSString *topOpt = [_optStack pop];
    NSInteger result = [self _caculeteWithNumberLeft:numLeft numberRight:numRight operation:topOpt];
    NSNumber *res = [NSNumber numberWithInteger:result];
    return res;
}

- (NSInteger)_caculeteWithNumberLeft:(NSNumber *)numLeft numberRight:(NSNumber *)numRight operation:(NSString *)opt {
    if (!numLeft || !numRight || !opt) return 0;
    NSInteger left = [numLeft integerValue];
    NSInteger right = [numRight integerValue];
    if ([opt isEqualToString:@"+"]) {
        return left + right;
    } else if ([opt isEqualToString:@"-"]) {
        return left - right;
    } else if ([opt isEqualToString:@"*"]) {
        return left * right;
    } else if ([opt isEqualToString:@"/"]) {
        return left / right;
    } else {
        return 0;
    }
}

@end
