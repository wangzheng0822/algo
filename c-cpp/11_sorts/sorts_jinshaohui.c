/*************************************************************************
 > File Name: sorts_jinshaohui.c
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-10-19
 > Desc:    
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SWAP(a,b) \
do{\
	(a) ^= (b);\
	(b) ^= (a);\
	(a) ^= (b);\
}while(0)

/*冒泡排序*/
void bubble_sort(int a[],int size)
{
	int i = 0;
	int j = 0;
	int swap_flg = 0;

	if (size < 1)
	{
		return;
	}

	for (i = size - 1; i > 0; i--)/*排序的趟数*/
	{
		swap_flg = 0;/*每次设置交换标识为0*/
		for (j = 0; j < i; j++)/*本趟排序的遍历元素个数*/
		{
			if (a[j] > a[j + 1])
			{
				SWAP(a[j],a[j+1]);
				swap_flg = 1;
			}
		}
        /*本趟数，无数据交换的话，说明已经有序，直接退出*/
		if (swap_flg == 0)
		{
			break;
		}
	}
	return;
}

/*插入排序*/
void insert_sort(int a[],int size)
{
	int i = 0;
	int j = 0;
	int key = 0;

	for (i = 1; i < size; i ++)/*需要插入的元素个数*/
	{
		key = a[i];/*保存插入的元素数据*/
		j = i - 1;
        /* i 之前的元素都是有序的，找到比key小的插入到他后面，
		 * 比key大的，需要往后挪一个位置*/
		while((j >= 0) && (a[j] > key))
		{
		    a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}

    return;
}
/*选择排序*/
void select_sort(int a[],int size)
{
	int i = 0;
	int j = 0;
	int min = 0;

	for (i = 0; i < size - 1; i++) 
	{
		min = i;
        for (j = i + 1; j < size; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}

		if (min != i)
		{
			SWAP(a[i],a[min]);
		}
	}
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

int main()
{
	int a[10] = {9,11,4,15,16,3,20,44,5,10};

    //bubble_sort(a,sizeof(a)/sizeof(int));
    //insert_sort(a,sizeof(a)/sizeof(int));
    select_sort(a,sizeof(a)/sizeof(int));
    
    dump(a,sizeof(a)/sizeof(int));

	return 0;
}
