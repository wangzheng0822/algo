#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void dump(int *arr, int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("%08d\n", arr[i]);
}

// content in arr must be positive integer
void counting_sort(int *arr, int size)
{
	int max, i;
	int *count, *tmp;

	if (size <= 1)
		return;

	max = 0;
	// find the biggest integer
	for (i = 0; i < size; i++) {
		if (max < arr[i])
			max = arr[i];
	}

	// init count to 0
	count = (int*)malloc((max+1) * sizeof(int));
	tmp = (int*)malloc(size * sizeof(int));
	if (!count || !tmp)
		return;
	memset(count, 0, (max + 1) * sizeof(int));

	// counting
	for (i = 0; i < size; i++)
		count[arr[i]]++;
	for (i = 1; i < max + 1; i++)
		count[i] = count[i-1] + count[i];

	// iterate arr and put it to the correct index in tmp
	for (i = 0; i < size; i++){
		int index = count[arr[i]] - 1;
		tmp[index] = arr[i];
		count[arr[i]]--;
	}

	// move back to arr
	memcpy(arr, tmp, size * sizeof(int));
}

void counting_sort_test()
{
	int test_data[10] = {3, 23, 98, 1, 27, 36, 52, 89, 76, 44};

	counting_sort(test_data, 10);
	dump(test_data, 10);
}

int main()
{
	counting_sort_test();
	return 0;
}
