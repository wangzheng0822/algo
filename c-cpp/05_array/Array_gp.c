#include "Array.h"

#include <string.h>
#include <stdbool.h>

Array* arrayCreate()
{
    struct Array *array = NULL;
    array = malloc(sizeof(*array));
    if (NULL == array)
    {
        return NULL;
    }

    array->p = NULL;

    array->size = 0;
    array->typeSize = 0;
    array->len = 0;

    array->dup = NULL;
    array->free = NULL;
    array->match = NULL;

    return array;
}

void arrayInit(Array *array, int size, int typeSize)
{
    if (NULL == array
        || typeSize <= 0
        || size < 0)
    {
        return;
    }

    void *p = calloc(1, size* typeSize);
    if (NULL == p)
    {
        return;
    }

    array->p = p;
    array->len = 0;
    array->size = size;
    array->typeSize = typeSize;
}

int arrayInsert(Array *array, size_t pos, void *const value)
{
    if (NULL == array)
    {
        return -1;
    }

    if (array->len >= array->size)
    {
        return -2;
    }

    if (pos > array->size || pos <= 0)
    {
        return -3;
    }

    char *pBegin = array->p;
    for (size_t i = array->len; i > pos - 1; --i)
    {
        void *pNew = pBegin + i * array->typeSize;
        void *pOld = pBegin + (i - 1) *array->typeSize;
        if (NULL != array->dup)
        {
            array->dup(pNew, pOld);
        }
        else
        {
            memcpy(pNew, pOld, array->typeSize);
        }
    }

    void *pCopy = (void*)(pBegin + ((pos - 1) * array->typeSize));
    if (NULL != array->dup)
    {
        array->dup(pCopy, value);
    }
    else
    {
        memcpy(pCopy, value, array->typeSize);
    }
    ++array->len;
    return 0;
}

size_t arraySearchValue(Array *array, void* const value)
{
    if (NULL == array)
    {
        return -1;
    }

    char *pBegin = array->p;
    size_t i = 0;
    for (; i < array->len; ++i)
    {
        int nCmp = 0;
        if (NULL != array->match)
        {
            nCmp = array->match(pBegin + i * array->typeSize, value);
        }
        else
        {
            nCmp = memcmp(pBegin + i * array->typeSize, value, array->typeSize);
        }

        if (nCmp == 0)
        {
            break;
        }
    }

    return i;
}

void* arrayIndex(Array *array, size_t index)
{
    if (NULL == array)
    {
        return NULL;
    }

    if (index > array->len
        || index <= 0)
    {
        return NULL;
    }

    char *pBegin = array->p;
    return pBegin + array->typeSize * (index - 1);
}

int arrayModify(Array *array, size_t pos, void *const value)
{
    if (NULL == array)
    {
        return -1;
    }
    if (pos > array->len
        || pos <= 0)
    {
        return -2;
    }

    char *pBegin = array->p;
    void *pOld = pBegin + (pos - 1) * array->typeSize;
    if (NULL != array->dup)
    {
        array->dup(pOld, value);
    }
    else
    {
        memcpy(pOld, value, array->typeSize);
    }

    return 0;
}

size_t arrayLen(Array *array)
{
    if (NULL == array)
    {
        return 0;
    }

    return array->len;
}

size_t arraySize(Array *array)
{
    if (NULL == array)
    {
        return 0;
    }

    return array->size;
}

void arrayEmpty(Array *array)
{
    if (NULL == array)
    {
        return;
    }

    free(array->p);
    array->p = NULL;
    free(array);
    array = NULL;
}

void arrayDelValue(Array *array, void *value)
{
    if (NULL == array)
    {
        return;
    }

    char* pBegin = array->p;
    bool bCopy = false;
    for (size_t i = 0; i < array->len; ++i)
    {
        if (!bCopy)
        {
            int nCmp = 0;
            if (NULL != array->match)
            {
                nCmp = array->match(pBegin + i * array->typeSize, value);
            }
            else
            {
                nCmp = memcmp(pBegin + i * array->typeSize, value, array->typeSize);
            }

            if (0 == nCmp)
            {
                bCopy = true;
                continue;
            }
        }
        else
        {
            void *pOld = pBegin + (i + 1) * array->typeSize;
            void *pNew = pBegin + i * array->typeSize;
            if (NULL != array->dup)
            {
                array->dup(pNew, pOld);
            }
            else
            {
                memcpy(pNew, pOld, array->typeSize);
            }
        }
    }

    if (bCopy)
    {
        --array->len;
    }
}

void arrayDelIndex(Array *array, size_t pos)
{
    if (NULL == array)
    {
        return;
    }

    if (pos > array->len || pos <= 0)
    {
        return;
    }

    char* pBegin = array->p;
    for (size_t i = pos - 1; i < array->len - 1; ++i)
    {
        void *pOld = pBegin + (i + 1) * array->typeSize;
        void *pNew = pBegin + i * array->typeSize;
        if (NULL != array->dup)
        {
            array->dup(pNew, pOld);
        }
        else
        {
            memcpy(pNew, pOld, array->typeSize);
        }
    }

    --array->len;
}