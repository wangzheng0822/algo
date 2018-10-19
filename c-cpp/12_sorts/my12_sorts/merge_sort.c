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

    merge(a,middle,left,right);

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
    int a[10] = {30,20,10,15,4,8,40,80,20,9};
    
	merge_sort(a,0,9);

	dump(a,10);

	return 0;
}

