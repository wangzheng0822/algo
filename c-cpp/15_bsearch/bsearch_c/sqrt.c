/*************************************************************************
 > File Name: sqrt.c
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-10-31
 > Desc:    
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>


/*求解精度设置*/
#define E 0.000001 
double mybsearch(double num)
{
	double start = 1.0;
	double end = num;
    double mid = 0.0;
	while(1)
	{
	    mid = (start + end)/2;
        if(((mid*mid - num) <= E) && ((mid*mid - num) >= -E))
		{
			return mid;
		}

		if ((mid*mid - num) > E)
		{
			end = mid;
		}
		else
		{
			start = mid;
		}
 	}

	return 0;
}
	

int main()
{
	double num = 0.0;

	/*这里需要注意：double的输入方式*/
	scanf("%lf",&num);
	printf("\r\n num %lf的平方根是%lf",num,mybsearch(num));

	return 0;
}

