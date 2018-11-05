#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct Array
{
    // p指针的空间大小
    size_t size;
    // p指针已经使用的空间大小
    size_t len;
    // 数据类型的大小
    size_t typeSize;
    // 值复制函数
    void(*dup)(void *ptr, void *key);
    // 值释放函数
    void(*free)(void *ptr);
    // 值比较函数
    int(*match)(void *ptr, void *key);
    // 存放数据的指针
    void   *p;
}Array;

#define arraySetDupMethod(a, m) ((a)->dup = (m))
#define arraySetFreeMethod(a, m) ((a)->free = (m))
#define arraySetMatchMethod(a, m) ((a)->match = (m))

#define arrayGetDupMethod(a) ((a)->dup)
#define arrayGetFree(a) ((a)->free)
#define arrayGetMatchMethod(a) ((a)->match)

Array* arrayCreate();
void arrayInit(Array *array, int size, int typeSize);

int arrayInsert(Array *array, size_t pos, void *const value);
size_t arraySearchValue(Array *array, void* const value);
void* arrayIndex(Array *array, size_t index);
int arrayModify(Array *array, size_t pos, void *const value);

size_t arrayLen(Array *array);
size_t arraySize(Array *array);

void arrayEmpty(Array *array);
void arrayDelValue(Array *array, void *value);
void arrayDelIndex(Array *array, size_t pos);

#endif // !__ARRAY_H__