/*************************************************************************
 > Author:  Liu Zhang
 > Mail:    lz-850610@163.com
 > Time:    2019-05-10
 > Desc:    二叉搜索树实现
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef char ElemType;

typedef struct node {
    ElemType data;
    struct node *lchild, *rchild;
} BTree, *BTreePtr;

/**************** 插入 **********************/
Status Insert(BTreePtr *T, ElemType e) {

    BTreePtr p;

    if (*T == NULL) {
        *T = (BTreePtr)malloc(sizeof(BTree));
        (*T)->data = e;

        return TRUE;
    } else {
        p = *T;
        while ( p != NULL) {

            if (e > p->data) {

                if (p->rchild == NULL) {
                    p->rchild = (BTreePtr) malloc (sizeof(BTree));
                    p->rchild->data = e;
                    return TRUE;
                }
                p = p->rchild;
            } else {

                if (p->lchild == NULL)
                {
                    p->lchild = (BTreePtr) malloc (sizeof(BTree));
                    p->lchild->data = e;
                    return TRUE;
                }
                p = p->lchild;
            }
        }
    }

    return FALSE;
}

/**************** 删除 **********************/
Status Delete(BTreePtr T, ElemType e) {
    BTreePtr p, pp, minP, minPP, child;
    child = NULL;
    p = T;
    pp = NULL;

    while ( (p != NULL) && (p->data != e) ) {
        pp = p;

        if (e > p->data) {
            p = p->rchild;
        } else {
            p = p->lchild;
        }
    }

    if (p == NULL) return FALSE;

    //双节点
    if ((p->lchild != NULL) && (p->rchild != NULL))
    {
        minPP = p;
        minP = p->rchild;

        while (minP->lchild != NULL) {
            minPP = minP;
            minP = minP->lchild;
        }
        p->data = minP->data;
        minPP->lchild = minP->rchild;
        free(minP);

        return TRUE;
    }

    //有一个节点
    if ((p->lchild != NULL) || (p->rchild != NULL)) { //应该将原有的pp同child连接在一起

        if (p->lchild) {
            child = p->lchild;
        } else {
           child = p->rchild;
        }
        if(pp->data>p->data)
        {
            pp->lchild=child;
        } else
        {
            pp->rchild=child;
        }
        free(p);
        return TRUE;
    }

    //没有节点
    if (pp->lchild == p) {//这里面临pp除p以外的节点为null的情况
        pp->lchild = child;
    } else {
        pp->rchild = child;
    }

    return TRUE;
}

/**************** 查找 **********************/

Status Find(BTreePtr T, ElemType e) {

    if (T == NULL) return FALSE;

    while ((T != NULL) && (T->data != e)) {

        if (e > T->data) {
            T = T->rchild;
        } else {
            T = T->lchild;
        }
    }

    if (T) {
        return TRUE;
    } else {
        return FALSE;
    }
}


/**************** 最大值 **********************/
ElemType FindMax(BTreePtr T) {
    ElemType max;

    while(T != NULL) {
        max = T->data;
        T = T->rchild;
    }
    return max;
}


/**************** 最小值 **********************/
ElemType FindMin(BTreePtr T) {
    ElemType min;

    while(T != NULL) {
        min = T->data;
        T = T->lchild;
    }
    return min;
}


void PreOrderTraverse(BTreePtr T)//前序遍历二叉树
{
    if (T == NULL) return;

    if(T)
    {
        printf("%d ",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}


void DestroyTree(BTreePtr T) {
    if (T)
    {
        if (T->lchild)
        {
            DestroyTree(T->lchild);
        }

        if(T->rchild)
        {
            DestroyTree(T->rchild);
        }

        free(T);
        T = NULL;
    }
}

/***************** 执行测试 *************************/
int main(int argc, char const *argv[])
{
    BTreePtr T;
    T = NULL;
    int a[] = {33, 16, 50, 13, 18, 34, 58, 15, 17, 25, 51, 66, 19, 27, 55};
    int i;
    for (i = 0; i < 15; i++) {
        Insert(&T, a[i]);
    }
    printf("Max is %d\n", FindMax(T));
    printf("Min is %d\n", FindMin(T));
    Delete(T, 18);
    Delete(T, 13);
    PreOrderTraverse(T);
    DestroyTree(T);

    return 0;
}
