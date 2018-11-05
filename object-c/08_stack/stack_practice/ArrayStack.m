#import "ArrayStack.h"

@implementation Stack {
    NSMutableArray *_arr;
    NSUInteger _capacity;
    NSUInteger _count;
}

- (id)initWithCapacity:(NSUInteger)capacity {
    self = [super init];
    _capacity = capacity;
    _arr = [[NSMutableArray alloc] initWithCapacity:capacity];
    return self;
}

- (BOOL)isEmpty {
    return _arr.count == 0;
}

- (BOOL)isFull {
    return _arr.count == _capacity;
}

- (id)top {
    if ([self isEmpty]) return nil;
    NSUInteger index = _arr.count - 1;
    return _arr[index];
}

- (NSUInteger)size {
    return _arr.count;
}

- (BOOL)push:(id)obj {
    if (!obj) return NO;
    if (_arr.count == _capacity) return NO;
    [_arr addObject:obj];
    return YES;
}

- (id)pop {
    if ([self isEmpty]) return nil;
    NSUInteger index = _arr.count - 1;
    id obj = _arr[index];
    [_arr removeLastObject];
    return obj;
}

@end
