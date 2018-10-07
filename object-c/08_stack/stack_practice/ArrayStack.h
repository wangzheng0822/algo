
/**
 栈实现
 
 Author: Smallfly
 */

#import <Foundation/Foundation.h>

@interface Stack : NSObject

- (id)initWithCapacity:(NSUInteger)count;

- (BOOL)isEmpty;
- (id)top;
- (NSUInteger)size;

- (BOOL)push:(id)obj;
- (id)pop;

@end
