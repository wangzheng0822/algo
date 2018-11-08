/*************************************************************************
 > File Name: listhash.c
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-11-07
 > Desc:    
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"listhash.h"

#ifdef MEMORY_TEST
#include<mcheck.h>
#endif

hashtab * hashtab_create(int size,hash_key_func hash_value,
		keycmp_func keycmp,hash_node_free_func hash_node_free)
{
	hashtab * h = NULL;
	int i = 0;

	if ((size < 0) || (hash_value == NULL) || (keycmp == NULL))
	{
		return NULL;
	}

	h = (hashtab *)malloc(sizeof(hashtab));
	if (h == NULL)
	{
		return NULL;
	}

	h->htables = (hashtab_node **)malloc(size * sizeof(hashtab_node*));
    if (h->htables == NULL)
	{
		return NULL;
	}

	h->size = size;
	h->nel = 0;
	h->hash_value = hash_value;
	h->keycmp = keycmp;
	h->hash_node_free = hash_node_free;
    
	for (i = 0; i < size; i++)
	{
		h->htables[i] = NULL;
	}

	return h;
}

void hashtab_destory(hashtab *h)
{
	int i = 0;
	hashtab_node * cur = NULL;
	hashtab_node * tmp = NULL;

	if (h == NULL)
	{
		return;
	}

	for (i = 0; i <h->size; i++)
	{
		cur = h->htables[i];
		while (cur != NULL)
		{
			tmp = cur;
			cur = cur->next;
			h->hash_node_free(tmp);
		}
		h->htables[i] = NULL;
	}
	
    free(h->htables);
	free(h);
	return;
}

int hashtab_insert(hashtab * h,void *key,void *data)
{
	unsigned int hvalue = 0;
	int i = 0;
	hashtab_node *cur = NULL; 
	hashtab_node *prev = NULL; 
	hashtab_node *newnode = NULL;

	if ((h == NULL) || (key == NULL) || (data == NULL))
	{
		return 1;
	}

	/*获取hash 数值*/
	hvalue = h->hash_value(h,key);
	cur = h->htables[hvalue];

    /*hash桶中元素是从小到大排列的，找到要插入的位置*/
	while((cur != NULL) && (h->keycmp(h,key,cur->key) > 0))
	{
		prev = cur;
		cur = cur->next;
	}

	/*如果key和当前key比对一致，直接返回，数据已经存在*/
	if ((cur != NULL) && (h->keycmp(h,key,cur->key) == 0))
	{
		return 2;
	}

	newnode = (hashtab_node *)malloc(sizeof(hashtab_node));
	if (newnode == NULL)
	{
		return 3;
	}

    newnode->key = key;
	newnode->data = data;
	if (prev == NULL)
	{
		newnode->next = h->htables[hvalue];
		h->htables[hvalue] = newnode;
	}
	else
	{
		newnode->next = prev->next;
		prev->next = newnode;
	}

	h->nel++;
    return 0;
}

hashtab_node *hashtab_delete(hashtab *h, void *key)
{
	int hvalue = 0;
	int i = 0;
	hashtab_node *cur = NULL; 
	hashtab_node *prev = NULL; 
	
	if ((h == NULL) || (key == NULL))
	{
		return NULL;
	}

	/*获取hash 数值*/
	hvalue = h->hash_value(h,key);
	cur = h->htables[hvalue];
    /*hash桶中元素是从小到大排列的，找到要插入的位置*/
	while((cur != NULL) && (h->keycmp(h,key,cur->key) >= 0))
	{
		if (h->keycmp(h,key,cur->key) == 0)
		{
			if (prev == NULL)
			{
                 h->htables[hvalue] = cur->next;
			}
			else
			{
                prev->next = cur->next;
			}
			return cur;
		}
		prev = cur;
		cur = cur->next;
	}

    return NULL;
}

void *hashtab_search(hashtab*h,void *key)
{
	int hvalue = 0;
	int i = 0;
	hashtab_node *cur = NULL; 
	
	if ((h == NULL) || (key == NULL))
	{
		return NULL;
	}

	/*获取hash 数值*/
	hvalue = h->hash_value(h,key);
	cur = h->htables[hvalue];
    /*hash桶中元素是从小到大排列的，找到要插入的位置*/
	while((cur != NULL) && (h->keycmp(h,key,cur->key) >= 0))
	{
		if (h->keycmp(h,key,cur->key) == 0)
		{
			return cur->data;
		}
		cur = cur->next;
	}

    return NULL;
}

void hashtab_dump(hashtab *h)
{
	int i = 0;
	hashtab_node * cur = NULL;

	if (h == NULL)
	{
		return ;
	}

	printf("\r\n----开始--size[%d],nel[%d]------------",h->size,h->nel);
    for( i = 0; i < h->size; i ++)
	{
		printf("\r\n htables[%d]:",i);
		cur = h->htables[i];
		while((cur != NULL))
		{
		    printf("key[%s],data[%s] ",cur->key,cur->data);	
			cur = cur->next;
		}
	}

	printf("\r\n----结束--size[%d],nel[%d]------------",h->size,h->nel);
}

struct test_node
{
	char key[80];
	char data[80];
};

unsigned int siample_hash(const char *str)
{
	register unsigned int hash = 0;
	register unsigned int seed = 131;

	while(*str)
	{
		hash = hash*seed + *str++;
	}

	return hash & (0x7FFFFFFF);
}

int hashtab_hvalue(hashtab *h,const void *key)
{
	return (siample_hash(key) % h->size);
}

int hashtab_keycmp(hashtab *h,const void *key1,const void *key2)
{
	return strcmp(key1,key2);
}

void hashtab_node_free(hashtab_node*node)
{
    struct test_node * ptmp = NULL;

	ptmp = container(node->key,struct test_node,key);

	free(ptmp);
	free(node);
}

int main ()
{
	
	int i = 0;
	int res = 0;
	char *pres = NULL;
	hashtab_node * node = NULL;
	struct test_node *p = NULL;
    hashtab *h = NULL;
    #ifdef MEMORY_TEST
	setenv("MALLOC_TRACE","1.txt",1);
    mtrace();
    #endif

	h = hashtab_create(5,hashtab_hvalue,hashtab_keycmp,hashtab_node_free);
    assert(h!= NULL);
	while(1)
	{
		p = (struct test_node*)malloc(sizeof(struct test_node));
		assert(p != NULL);
		printf("\r\n 请输入key 和value，当可以等于\"quit\"时退出");
        scanf("%s",p->key);
		scanf("%s",p->data);

		if(strcmp(p->key,"quit") == 0)
		{
			free(p);
			break;
		}

        res = hashtab_insert(h,p->key,p->data);
		if (res != 0)
		{
			free(p);
			printf("\r\n key[%s],data[%s] insert failed %d",p->key,p->data,res);
		}
		else
		{
			printf("\r\n key[%s],data[%s] insert success %d",p->key,p->data,res);
		}
	}

	hashtab_dump(h);

	while(1)
	{
		p = (struct test_node*)malloc(sizeof(struct test_node));
		assert(p != NULL);
		printf("\r\n 请输入key 查询value的数值，当可以等于\"quit\"时退出");
        scanf("%s",p->key);

		if(strcmp(p->key,"quit") == 0)
		{
			free(p);
			break;
		}
        pres = hashtab_search(h,p->key);
		if (pres == NULL)
		{
			printf("\r\n key[%s] search data failed",p->key);
		}
		else
		{
			printf("\r\n key[%s],search data[%s] success",p->key,pres);
		}
		free(p);
	}
	hashtab_dump(h);
	while(1)
	{
		p = (struct test_node*)malloc(sizeof(struct test_node));
		assert(p != NULL);
		printf("\r\n 请输入key 删除节点的数值，当可以等于\"quit\"时退出");
        scanf("%s",p->key);

		if(strcmp(p->key,"quit") == 0)
		{
			free(p);
			break;
		}
        node = hashtab_delete(h,p->key);
		if (node == NULL)
		{
			printf("\r\n key[%s] delete node failed ",p->key);
		}
		else
		{
			printf("\r\n key[%s],delete data[%s] success",node->key,node->data);
		    h->hash_node_free(node);
		}
		free(p);
	    hashtab_dump(h);
	}

	hashtab_destory(h);
    #ifdef MEMORY_TEST
    muntrace();
    #endif
	return 0;

}
