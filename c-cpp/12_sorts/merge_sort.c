#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void dump(int *arr, int size)
{
	int idx;

	for (idx = 0; idx < size; idx++)
		printf("%08d\n", arr[idx]);
}

void __merge(int *arr, int p, int q, int r)
{
	int *tmp;
	int i, j, k;

	tmp = (int*)malloc((r - p + 1) * sizeof(int));

	if (!tmp)
		abort();

	for (i = p, j = q + 1, k = 0; i <= q && j <= r;) {
		if (arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}

	if (i == q + 1) {
		for (; j <= r;)
			tmp[k++] = arr[j++];
	} else {
		for (; i <= q;)
			tmp[k++] = arr[i++];
	}

	memcpy(arr + p, tmp, (r - p + 1) * sizeof(int));
	free(tmp);
}

void __merge_sort(int *arr, int p, int r)
{
	int q;

	if (p >= r)
		return;

	q = (p + r) / 2;
	__merge_sort(arr, p, q);
	__merge_sort(arr, q + 1, r);
	__merge(arr, p, q, r);
}

void merge_sort(int *arr, int size)
{
	__merge_sort(arr, 0, size - 1);
}

void merge_verify()
{
	int test[10] = {5, 8, 9, 23, 67, 1, 3, 7, 31, 56};

	__merge(test, 0, 4, 9);

	dump(test, 10);
}

void merge_sort_test()
{
	int test[10] = {5, 8, 9, 23, 67, 1, 3, 7, 31, 56};

	merge_sort(test, 10);

	dump(test, 10);
}

int main()
{
	//merge_verify();
	merge_sort_test();
	return 0;
}
