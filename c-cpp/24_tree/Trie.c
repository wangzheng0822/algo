/*************************************************************************
 > Author:  Liu Zhang
 > Mail:    lz-850610@163.com
 > Time:    2019-05-10
 > Desc:    字典树实现
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef struct Node {
    char data;
    struct Node *children[26];
    Status end;
} Trie, *TriePtr;

void Init(TriePtr *T)
{
    (*T) = (TriePtr)malloc(sizeof(Trie));
    (*T)->data = '/';
    (*T)->end = FALSE;
}

void Insert(TriePtr T, char *str) {

    int index;
    char c;

    while(c = *str++)
    {
        index = c - 'a';
        if (T->children[index] == NULL)
        {
            TriePtr Node;
            Node = (TriePtr)malloc(sizeof(Trie));
            Node->data = c;
            Node->end = FALSE;
            T->children[index] = Node;
        }

        T = T->children[index];
    }

    T->end = TRUE;
}


Status Search(TriePtr T, char *str) {

    int index;
    char c;

    while(c = *str++)
    {
        index = c - 'a';
        if (T->children[index] == NULL)
        {
            return FALSE;
        }

        T = T->children[index];
    }

    if (T->end) {
        return TRUE;
    } else {
        return FALSE;
    }
}


int main(int argc, char const *argv[])
{
    TriePtr T;
    Init(&T);
    char *str = "hello";
    char *str2 = "hi";

    Insert(T, str);

    printf("str is search %d\n", Search(T, str));
    printf("str2 is search %d\n", Search(T, str2));
    return 0;
}