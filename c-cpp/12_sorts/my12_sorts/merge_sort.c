/*************************************************************************
 > File Name: merge_sort.c
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-10-19
 > Desc:    
 ************************************************************************/
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

#define SORT_MAX  (1000000)

void dump(int a[],int size);
void merge_sentry(int a[],int middle,int left,int right)
{
	int *pleft = NULL;
	int *pright = NULL;
	int i = 0;
	int j = 0;
	int k = 0;
	int left_size = middle - left + 1;
	int right_size = right - middle;

	
	pleft = (int *)malloc(sizeof(int)*(left_size + 1));
	assert(pleft != NULL);
	pright = (int *)malloc(sizeof(int)*(right_size + 1));
	assert(pright != NULL);

	for(i = 0; i < left_size; i ++)
	{
		pleft[i] = a[left + i];
	}
	pleft[left_size] = SORT_MAX;
	for(i = 0; i < right_size; i ++)
	{
		pright[i] = a[middle + 1 + i];
	}
	pright[right_size] = SORT_MAX;

    for (k = left,i = 0,j = 0; k <= right; k++)
	{
		if (pleft[i] <= pright[j])
		{
			a[k] = pleft[i++];
		}
		else
		{
			a[k] = pright[j++];
		}
	}

	free(pleft);
	free(pright);

    return;
}

/*两个有序数组合并*/
void merge(int a[],int middle,int left,int right)
{
    int *tmp = NULL;
	int i = 0;
	int j = 0;
	int k = 0;

	tmp = (int*)malloc((right - left + 1)*sizeof(int));
    assert(tmp != NULL);

	i = left;
	j = middle + 1;

	while(1)
	{
	    if((i > middle) || (j > right))
	    {
			break;
	    }

		if (a[i] > a[j])
		{
			tmp[k++] = a[j++];
		}
		else
		{
			tmp[k++] = a[i++];
		}
	}

	if (i > middle)
	{
		while(j <= right)
		{
			tmp[k++] = a[j++];
		}
	}
	else
	{
		while(i <= middle)
		{
			tmp[k++] = a[i++];
		}
	}

	memcpy((a + left),tmp,(right - left + 1)*sizeof(int));

	free(tmp);

	return  ;
}

void merge_sort(int a[],int left,int right)
{
    int middle = 0;

	if(left >= right)
	{
		return;
	}

	middle = (left + right)/2;

	merge_sort(a,left,middle);
	merge_sort(a,middle + 1,right);

    merge_sentry(a,middle,left,right);

	return;
}

void dump(int a[],int size)
{
	int i = 0;

	if(size == 0)
	{
		return;
	}

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
    int a[10] = {30,20,10,15,4,8,40,80,20,9};
    
	merge_sort(a,0,9);

	dump(a,10);

	return 0;
}

