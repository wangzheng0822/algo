/*************************************************************************
 > File Name: bsearch.c
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-10-21
 > Desc:    
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


int mybsearch(int a[],int size,int value)
{
	int mid = 0;
	int left = 0;
	int right = size - 1;

	while(left <= right)
	{
		/*防止size数量太大是，（left + right）数据翻转，导致问题*/
		mid = left + ((right - left)>>1);

		if (a[mid] == value)
		{
			return mid;
		}
		else if (a[mid] < value)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return -1;
}

int helper(int a[], int left,int right,int value)
{
	int mid = 0;

	if (left > right)
	{
		return -1;
	}
	/*防止size数量太大是，（left + right）数据翻转，导致问题*/
	mid = left + ((right - left)>>1);
	if (a[mid] == value)
	{
		return mid;
	}
	else if (a[mid] < value)
	{
		return helper(a,mid + 1,right,value);
	}
	else
	{
		return helper(a,left,mid - 1,value);
	}
    return -1;
}
/*递归实现*/
int mybsearch_2(int a[],int size,int value)
{

	return helper(a,0,size-1,value);
}

int main()
{
	int a[10] = {5,6,8,9,10,11,23,42,53,123};
    int data = 0;
	int res = 0;

	printf("\r\n输入一个整数");
	scanf("%d",&data);
    res = mybsearch(a,10,data);
	printf("data[%d] %s 在数据中，下标是%d",data,(res != -1)?"":"不",res);
	
	printf("\r\n输入一个整数");
	scanf("%d",&data);
    res = mybsearch_2(a,10,data);
	printf("data[%d] %s 在数据中，下标是%d",data,(res != -1)?"":"不",res);
	return;
}
