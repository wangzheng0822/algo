#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

/* One implementation of hash table with linear probing. */

#define HASH_SHIFT 4
#define HASH_SIZE (1 << HASH_SHIFT)
#define HASH_MASK (HASH_SIZE - 1)

struct hash_table {
	unsigned int  used;
	unsigned long entry[HASH_SIZE];
};

void hash_table_reset(struct hash_table *table)
{
	int i;

	table->used = 0;
	for (i = 0; i < HASH_SIZE; i++)
		table->entry[i] = ~0;
}

unsigned int hash_function(unsigned long value)
{
	return value & HASH_MASK;
}

void dump_hash_table(struct hash_table *table)
{
	int i;

	for (i = 0; i < HASH_SIZE; i++) {
		if (table->entry[i] == ~0)
			printf("%2u:       nil \n", i);
		else
			printf("%2u:%10lu -> %2u\n",
				i, table->entry[i],
				hash_function(table->entry[i]));
	}
}

void hash_function_test()
{
	int i;

	srandom(time(NULL));

	for (i = 0; i < 10; i++) {
		unsigned long val = random();
		printf("%10lu -> %2u\n", val, hash_function(val));;
	}
}

unsigned int next_probe(unsigned int prev_key)
{
	return (prev_key + 1) & HASH_MASK;
}

void next_probe_test()
{
	int i;
	unsigned int key1, key2;

	key1 = 0;
	for (i = 0; i < HASH_SIZE; i++) {
		key2 = next_probe(key1);
		printf("%2u -> %2u\n", key1, key2);
		key1 = key2;
	}
}

void hash_table_add(struct hash_table *table, unsigned long value)
{
	unsigned int key = hash_function(value);

	if (table->used >= HASH_SIZE)
		return;

	while (table->entry[key] != ~0)
		key = next_probe(key);

	table->entry[key] = value;
	table->used++;
}

unsigned int hash_table_slot(struct hash_table *table, unsigned long value)
{
	int i;
	unsigned int key = hash_function(value);

	for (i = 0; i < HASH_SIZE; i++) {
		if (table->entry[key] == value || table->entry[key] == ~0)
			break;
		key = next_probe(key);
	}

	return key;
}

bool hash_table_find(struct hash_table *table, unsigned long value)
{
	return table->entry[hash_table_slot(table, value)] == value;
}

void hash_table_del(struct hash_table *table, unsigned long value)
{
	unsigned int i, j, k;

	if (!hash_table_find(table, value))
		return;

	i = j = hash_table_slot(table, value);

	while (true) {
		table->entry[i] = ~0;

		do {
			j = next_probe(j);
			if (table->entry[j] == ~0)
				return;
			k = hash_function(table->entry[j]);
		} while ((i <= j) ? (i < k && k <= j) : (i < k || k <= j));

		table->entry[i] = table->entry[j];
		i = j;
	}
	table->used++;
}

void hash_table_add_test()
{
	struct hash_table table;

	hash_table_reset(&table);
	hash_table_add(&table, 87645);

	printf("Table has%s 87645\n",
		hash_table_find(&table, 87645) ? "":"n't");
	printf("Table has%s 87647\n",
		hash_table_find(&table, 87647) ? "":"n't");
}

void hash_table_del_test1()
{
	struct hash_table table;

	hash_table_reset(&table);
	hash_table_add(&table, 0x1ff0);
	hash_table_add(&table, 0x2ff0);
	hash_table_add(&table, 0x3ff0);
	dump_hash_table(&table);

	printf("=== Remove 0x1ff0\n");
	hash_table_del(&table, 0x1ff0);
	dump_hash_table(&table);
}

void hash_table_del_test2()
{
	struct hash_table table;

	hash_table_reset(&table);
	hash_table_add(&table, 0x1ff0);
	hash_table_add(&table, 0x1ff1);
	hash_table_add(&table, 0x1ff2);
	hash_table_add(&table, 0x2ff0);
	dump_hash_table(&table);

	printf("=== Remove 0x1ff0\n");
	hash_table_del(&table, 0x1ff0);
	dump_hash_table(&table);
}

int main()
{
	//hash_function_test();
	//next_probe_test();
	//hash_table_add_test();
	hash_table_del_test2();

	return 0;
}
