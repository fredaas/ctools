#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#include "htable.h"

int n_elements = 12;


/******************************************************************************
 *
 * Utils
 *
 *****************************************************************************/


void print_values(Table *table)
{
    int **values = (int **)malloc(table->size * sizeof(int *));
    htable_values(table, (void **)values);
    for (int i = 0; i < table->size; i++)
        printf("%d\n", *((int *)values[i]));
    free(values);
}

void print_bucket_values(Table *table)
{
    for (int i = 0; i < table->num_buckets; i++)
    {
        TableBucket *bucket = htable_bucket(table, i);
        printf("[%d] ", i);
        while (bucket != NULL)
        {
            printf("%d ", *((int *)bucket->value));
            bucket = bucket->next;
        }
        printf("-> %p\n", bucket);
    }
}

Table * setup_table(void)
{
    Table *table = htable_init(6);

    for (int i = 0; i < n_elements; i++)
    {
        int *value = (int *)malloc(sizeof(int));
        *value = i + 1;
        htable_insert(table, &i, sizeof(int), value);
    }

    return table;
}

void _print_status(const char *fname, int errors)
{
    if (errors)
        printf("[ \e[0;91mfail\e[0m    ] %s\n", fname);
    else
        printf("[ \e[0;92msuccess\e[0m ] %s\n", fname);
}

#define print_status(errors) do { \
    _print_status(__func__, errors); \
} while (0)


/******************************************************************************
 *
 * Tests
 *
 *****************************************************************************/


void test_htable_init(void)
{
    Table *table = htable_init(6);
    print_status(table != NULL ? 0 : 1);
    htable_destroy(table);
}

void test_htable_insert(void)
{
    int errors = 0;

    Table *table = htable_init(6);

    int values[8];
    for (int i = 0; i < 8; i++)
    {
        values[i] = i + 1;
        errors += htable_insert(table, &i, sizeof(int), &(values[i]));
    }

    print_status(errors);

    htable_destroy(table);
}

void test_htable_clear(void)
{
    Table *table = htable_init(6);

    int values[8];
    for (int i = 0; i < 8; i++)
    {
        values[i] = i + 1;
        htable_insert(table, &i, sizeof(int), &(values[i]));
    }

    print_status(htable_clear(table));

    htable_destroy(table);
}

void test_htable_remove(void)
{
    int errors = 0;

    Table *table = setup_table();

    for (int i = 0; i < n_elements; i++)
        errors += htable_remove(table, &i, sizeof(int));

    print_status(errors);

    htable_destroy(table);
}

void test_htable_get(void)
{
    int errors = 0;

    Table *table = setup_table();

    for (int i = 0; i < n_elements; i++)
    {
        int *value;
        errors += htable_get(table, &i, sizeof(int), (void**)&value);
    }

    print_status(errors);

    htable_destroy(table);
}

void test_htable_keys(void)
{
    Table *table = setup_table();

    int **keys = (int **)malloc(n_elements * sizeof(int *));

    print_status(htable_keys(table, (void **)keys));

    htable_destroy(table);

    free(keys);
}

void test_htable_values(void)
{
    Table *table = setup_table();

    int **values = malloc(n_elements * sizeof(int *));

    print_status(htable_values(table, (void **)values));

    htable_destroy(table);

    free(values);
}

int main(void)
{
    test_htable_init();
    test_htable_insert();
    test_htable_clear();
    test_htable_remove();
    test_htable_get();
    test_htable_keys();
    test_htable_values();

    return 0;
}
