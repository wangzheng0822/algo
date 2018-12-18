/*************************************************************************
 > File Name: binarytree.c
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-11-12
 > Desc:    
 ************************************************************************/
#include<assert.h>

#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include"list_queue.h"

typedef struct _treenode
{
	int data;
	struct _treenode *lchild;
	struct _treenode *rchild;
}Tnode,Tree;

void binarytree_create(Tree **Root)
{
	int a = 0;
	printf("\r\n输入节点数值((当输入为100时，当前节点创建完成))):");
	scanf("%d",&a);


	if (a == 100)
	{
		*Root = NULL;
	}
	else
	{
		*Root = (Tnode *)malloc(sizeof(Tnode));
		if (*Root == NULL)
		{
			return;
		}

		(*Root)->data = a;
		printf("\r\n create %d 的左孩子:",a);
		binarytree_create(&((*Root)->lchild));
		printf("\r\n create %d 的右孩子:",a);
		binarytree_create(&((*Root)->rchild));
	}

	return ;
}

void binarytree_destory(Tree *root)
{
	if (root == NULL)
	{
		return;
	}

	binarytree_destory(root->lchild);
	binarytree_destory(root->rchild);
	free(root);
}

/*先序遍历:根结点--》左子树---》右子树*/
void binarytree_preorder(Tree *root)
{
	if (root == NULL)
	{
		return;
	}
	printf(" %d ",root->data);
	binarytree_preorder(root->lchild);
	binarytree_preorder(root->rchild);
    return;
}
/*中序遍历:左子树--》跟节点---》右子树*/
void binarytree_inorder(Tree *root)
{
	if (root == NULL)
	{
		return;
	}
	binarytree_inorder(root->lchild);
	printf(" %d ",root->data);
	binarytree_inorder(root->rchild);
    return;
}
/*后序遍历:左子树---》右子树-》根节点*/
void binarytree_postorder(Tree *root)
{
	if (root == NULL)
	{
		return;
	}
	binarytree_postorder(root->lchild);
	binarytree_postorder(root->rchild);
	printf(" %d ",root->data);
    return;
}

void binarytree_levelorder(Tree * root)
{
	list_queue *queue = NULL;
	Tnode * node = NULL;

	if(root == NULL)
	{
		return;
	}

	queue = list_queue_create();

	/*根节点先入队*/
	list_queue_enqueue(queue,(void *)root);

	while(!list_queue_is_empty(queue))
	{
		list_queue_dequeue(queue,(void *)&node);
		printf(" %d ",node->data);

		if(node->lchild != NULL)
		{
			list_queue_enqueue(queue,(void *)node->lchild);
		}

		if(node->rchild != NULL)
		{
			list_queue_enqueue(queue,(void *)node->rchild);
		}
	}

	free(queue);

}
/*打印叶子节点*/
void binarytree_printfleaf(Tree *root)
{
	if (root == NULL)
	{
		return;
	}

	if ((root->lchild == NULL) && (root->rchild == NULL))
	{
		printf(" %d ",root->data);
	}
	else
	{
		binarytree_printfleaf(root->lchild);
		binarytree_printfleaf(root->rchild);
	}
}
/*打印叶子的个数*/
int binarytree_getleafnum(Tree*root)
{
	if (root == NULL)
	{
		return 0;
	}

	if ((root->lchild == NULL) && (root->rchild == NULL))
	{
		return 1;
	}
	
	return binarytree_getleafnum(root->lchild) + binarytree_getleafnum(root->rchild);

}
/*打印数的高度*/
int binarytree_gethigh(Tree *root)
{
	int lhigh = 0;
	int rhigh = 0;
	
	if (root == NULL)
	{
		return 0;
	}

	lhigh = binarytree_gethigh(root->lchild);
	rhigh = binarytree_gethigh(root->rchild);

	return ((lhigh > rhigh)?(lhigh + 1):(rhigh + 1));
}

int main()
{
	Tree *root = NULL;

	setenv("MALLOC_TRACE","1.txt",1);
    mtrace();
	
	printf("\r\n创建二叉树:");
	binarytree_create(&root);
	printf("\r\n先序遍历二叉树:");
	binarytree_preorder(root);
	printf("\r\n中序遍历二叉树:");
	binarytree_inorder(root);
	printf("\r\n后序遍历二叉树:");
	binarytree_postorder(root);
	printf("\r\n层次遍历二叉树:");
	binarytree_levelorder(root);

	printf("\r\n打印二叉树叶子节点:");
	binarytree_printfleaf(root);
	printf("\r\n打印二叉树叶子节点个数:%d",binarytree_getleafnum(root));
	printf("\r\n打印二叉树高度:%d",binarytree_gethigh(root));

	binarytree_destory(root);

    muntrace();
	return 0;
}

