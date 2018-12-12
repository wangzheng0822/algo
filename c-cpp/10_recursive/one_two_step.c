/*************************************************************************
 > File Name: one_two_step.c
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-10-19
 > Desc:    
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*爬楼梯的问题，解决重复计算，采用数据保存方法*/

int helper(int n ,int *vlaue)
{

    if(vlaue[n] != 0)
	{
		return vlaue[n];
	}

    vlaue[n] = helper(n - 1,vlaue) + helper(n - 2,vlaue);

	return vlaue[n];
}

int climbStaris(int n)
{
	int *vlaue = NULL;
	int res = 0;

	vlaue = (int *)malloc(sizeof(int)*(n+1));
	if(vlaue == NULL)
	{
		return -1;
	}

	memset(vlaue,0,sizeof(int)*(n + 1));
    vlaue[0] = 0;
	vlaue[1] = 1;
	vlaue[2] = 2;
    res = helper(n,vlaue);
	free(vlaue);

	return res;
}

int main()
{

	printf("\r\nnum%d ,%d",5,climbStaris(5));
	printf("\r\nnum%d ,%d",6,climbStaris(6));
	printf("\r\nnum%d ,%d",7,climbStaris(7));
	return 0;
}


