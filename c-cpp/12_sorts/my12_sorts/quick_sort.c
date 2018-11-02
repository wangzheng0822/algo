/*************************************************************************
 > File Name: quick_sort.c
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-10-19
 > Desc:    
 ************************************************************************/
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

/* SWAP 使用必须主要，不能是同一个数据进行交换*/
#define SWAP(a,b) \
do{\
	(a) ^= (b);\
	(b) ^= (a);\
	(a) ^= (b);\
}while(0)

int partition2(int a[],int left,int right)
{
   int i = left;
   int j = left;

   for(; j <  right;j++)
   {
	   if (a[j] < a[right])
	   {
		   if(i != j)
		   {
			   SWAP(a[i],a[j]);
		   }
		   i++;
	   }
   }

   if(i != right)
   {
       SWAP(a[i],a[right]);
   }

   return i;
}

int partition(int a[],int left,int right)
{
   int i = left;
   int j = right;
   int key = a[left];

   while(i < j)
   {
	   while((i < j)&& (a[j] >= key))
	   {
		   j--;
	   }
	   if (i < j)
	   {
		   a[i] = a[j];
	   }
	   while((i < j) && a[i] <= key)
	   {
		   i++;
	   }

	   if (i<j)
	   {
		   a[j] = a[i];
	   }
   }
   a[i] = key;

   return i;
}

void quick_sort(int a[],int left,int right)
{
	int q = 0;
	/*递归终止条件*/
	if (left >= right)
	{
		return;
	}

	q = partition2(a,left,right);
	quick_sort(a,left,(q - 1));
	quick_sort(a,(q + 1),right);
	return;
}

void dump(int a[],int size)
{
	int i = 0;

	printf("\r\n");
	for (i = 0; i < size; i++ )
	{
		printf("%d ",a[i]);
	}
	printf("\r\n");
    return;
}

int helper(int a[],int left,int right,int k)
{
	int q = 0;

	q = partition(a,left,right);

	if (q > (k - 1))
	{
		return helper(a,left,q-1,k);
	}
	else if (q < (k - 1))
	{
		return helper(a,q+1,right,k);
	}

	return a[q];
}

/*求无序数组中从小到大第K个元素的数值*/
int findKthlagest(int a[],int size,int k)
{
	return helper(a,0,size-1,k);
}


int main()
{
    int a[10] = {30,20,10,15,4,8,40,80,20,9};
    int k;

	scanf("%d",&k);

	printf("\r\n从小到大排序，第%d个元素数值是%d",k,findKthlagest(a,10,k));

	quick_sort(a,0,9);

	dump(a,10);

	return 0;
}

