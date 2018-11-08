/*************************************************************************
 > File Name: sort.c
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-10-20
 > Desc:    
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>

void dump(int a[],int size)
{
	int i = 0;

	printf("\r\n");

	for(i = 0; i <size; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\r\n");
}

/*计数排序，时间复杂度0（n)，非原地排序
 *计数排序也是利用桶排序的解决方式
 * 如果数组最大值max比数组大小size大很多不适合；
 * 计数排序要求时非负整数
 * */
void count_sort(int a[],int size)
{
	int i = 0;
	int max = 0;
	int *count = 0;
	int *res = 0;

	/*找到最大数*/
	for (i = 0 ; i< size; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}

	count = (int *)malloc(sizeof(int)*(max + 1));
	assert(count != NULL);

	memset(count,0,sizeof(int)*(max + 1));

	/*计数*/
	for (i = 0; i < size;i++)
	{
		count[a[i]]++;
	}
	
	/*依次累加*/
	for(i = 1 ;i <= max; i ++)
	{
		count[i] += count[i-1];
	}

	res = (int *)malloc(sizeof(int)*(size));
	assert(res != NULL);
    /*核心代码，count[a[i] - 1]就是排序好的下标*/
	for (i = size-1;i >= 0; i--)
	{
		res[count[a[i]] -1] = a[i];
		count[a[i]]--;
	}
    
	memcpy(a,res,size*(sizeof(int)));

	free(res);
	free(count);
	return;
}


int count_sort_test()
{
	int a [10]={1,5,6,8,10,9,3,1,2,1};
    printf("\r\n conunt sort test ....");
	count_sort(a,10);
	dump(a,10);

	return 0;
}

#define NUM_OF_POS(a,pval) ((a)/pval)%10
void radix_sort(int a[],int size,int num_count)
{
	int count[10] = {0}; /*计数*/
	int *pres = NULL;
	int i = 0;
	int j = 0;
	int pval = 10;
	int index = 0;
	int break_flg = 0;

	pres = (int *)malloc(sizeof(int)*size);
	assert(pres != NULL);

	for (i = 0; i < num_count; i ++)
	{
		memset(count,0,sizeof(int)*10);

		/*求当前的基数*/
        pval = pow(10,i);

	    /*计数*/
		for (j = 0; j < size; j++)
		{
			index = NUM_OF_POS(a[j],pval);
			count[index]++;
		}

		/*小的优化，可能位数最大的就1，其他的位数差很多*/
		if(count[0] == 9)
		{
			break_flg++;
		}

		if(break_flg >=2)
		{
			printf("\r\n %i",i);
			break;
		}

		/*累加*/
		for(j = 1; j < 10; j ++)
		{
			count[j] += count[j-1];
		}

		/*排序必须从后往前，否则不是稳定排序*/
		for(j = size -1; j >= 0; j--)
		{
			index = NUM_OF_POS(a[j],pval);
            pres[count[index] - 1] = a[j];
			count[index]--;
		}
        /*本轮排序好的，拷贝到a中*/
		memcpy(a,pres,sizeof(int)*size);
	}

	return;
}

void radix_sort_test()
{
	int a[10] = {123,12341,1232134,124,236,128,1112313129,98,9,8989};
    printf("\r\n radix sort test.....");
	radix_sort(a,10,10);
	dump(a,10);
	return;
}

struct barrel {   
    int node[10];   
    int count;/* the num of node */  
};   
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

	q = partition(a,left,right);
	quick_sort(a,left,(q - 1));
	quick_sort(a,(q + 1),right);
	return;
}
  
void bucket_sort(int data[], int size)   
{   
    int max, min, num, pos;   
    int i, j, k;   
    struct barrel *pBarrel;   
  
    max = min = data[0];   
    for (i = 1; i < size; i++) {   
        if (data[i] > max) {   
            max = data[i];   
        } else if (data[i] < min) {   
            min = data[i];   
        }   
    }   
    num = (max - min + 1) / 10 + 1;   
    pBarrel = (struct barrel*)malloc(sizeof(struct barrel) * num);   
    memset(pBarrel, 0, sizeof(struct barrel) * num);   
  
    /* put data[i] into barrel which it belong to */  
    for (i = 0; i < size; i++) {   
        k = (data[i] - min + 1) / 10;/* calculate the index of data[i] in barrel */  
        (pBarrel + k)->node[(pBarrel + k)->count] = data[i];   
        (pBarrel + k)->count++;   
    }   
       
    pos = 0;   
    for (i = 0; i < num; i++) {
		if ((pBarrel + i)->count != 0)
		{
            quick_sort((pBarrel+i)->node, 0, ((pBarrel+i)->count)-1);/* sort node in every barrel */  
  
            for (j = 0; j < (pBarrel+i)->count; j++) {   
                data[pos++] = (pBarrel+i)->node[j];   
            }
		}
    }   
    free(pBarrel);   
}

void bucket_sort_test()
{
	int a[] = {78, 17, 39, 26, 72, 94, 21, 12, 23, 91};   
    int size = sizeof(a) / sizeof(int);   
	printf("\r\n bucket sort test ...");
    bucket_sort(a, size); 
	dump(a,size);
	
}

int main()
{
    count_sort_test();

	radix_sort_test();

	bucket_sort_test();
	return 0;
}
