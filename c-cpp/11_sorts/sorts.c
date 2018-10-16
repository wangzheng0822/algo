#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct array {
	int size;
	int used;
	int *arr;
};

void dump(struct array *array)
{
	int idx;
	
	for (idx = 0; idx < array->used; idx++)
		printf("[%02d]: %08d\n", idx, array->arr[idx]);
}

void alloc(struct array *array)
{
	array->arr = (int *)malloc(array->size * sizeof(int));
}

void bubble_sort(struct array *array)
{
	int i, j;

	if (array->used <= 1)
		return;

	for (i = 0; i < array->used; i++) {
		bool has_swap = false;
		for (j = 0; j < array->used - i - 1; j++) {
			if (array->arr[j] > array->arr[j+1]) {
				int tmp;
				tmp = array->arr[j];
				array->arr[j] = array->arr[j+1];
				array->arr[j+1] = tmp;
				has_swap = true;
			}

		}
		if (!has_swap)
			break;
	}
}

void bubble_sort_test()
{
	int idx;
	struct array ten_int = {10, 0, NULL};

	alloc(&ten_int);
	for (idx = 0; idx < 10; idx++)
		ten_int.arr[idx] = 30 - idx;
	ten_int.used = 10;
	dump(&ten_int);
	bubble_sort(&ten_int);
	dump(&ten_int);
}

void insertion_sort(struct array *array)
{
	int i, j;

	if (array->used <= 1)
		return;

	for (i = 1; i < array->used; i++) {
		int val = array->arr[i];

		for (j = i - 1; j >= 0; j--) {
			if (val < array->arr[j])
				array->arr[j+1] = array->arr[j]; 
			else
				break;
		}
		array->arr[j+1] = val;
	}
}

void insertion_sort_test()
{
	int idx;
	struct array ten_int = {10, 0, NULL};

	alloc(&ten_int);
	for (idx = 0; idx < 10; idx++)
		ten_int.arr[idx] = 30 - idx;
	ten_int.used = 10;
	dump(&ten_int);
	insertion_sort(&ten_int);
	dump(&ten_int);
}

void selection_sort(struct array *array)
{
	int i, j;

	if (array->used <= 1)
		return;

	for (i = 0; i < array->used - 1; i++) {
		int tmp, idx = i;

		for (j = i + 1; j < array->used; j++)
			if (array->arr[j] < array->arr[idx])
				idx = j;

		if (idx == i)
			continue;

		tmp = array->arr[i];
		array->arr[i] = array->arr[idx];
		array->arr[idx] = tmp;
	}
}

void selection_sort_test()
{
	int idx;
	struct array ten_int = {10, 0, NULL};

	alloc(&ten_int);
	for (idx = 0; idx < 10; idx++)
		ten_int.arr[idx] = 30 - idx;
	ten_int.used = 10;
	dump(&ten_int);
	selection_sort(&ten_int);
	dump(&ten_int);
}

int main()
{
	//bubble_sort_test();
	//selection_sort_test();
	insertion_sort_test();
	return 0;
}
