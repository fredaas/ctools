#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#include "htable.h"

int test_index = 0;

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

void assert_status(int code, char *test_name)
{
    if (code != HTABLE_SUCCESS)
    {
        printf("[%d] %s: ", test_index, test_name);
        htable_assert(code);
        exit(1);
    }
}


/******************************************************************************
 *
 * Tests
 *
 *****************************************************************************/


void test_htable_init(void)
{
    test_index++;

    Table *table = htable_init(6);

    assert_status(
        table != NULL ? HTABLE_SUCCESS : HTABLE_ENOMEM,
        "htable_init"
    );

    htable_destroy(table);

    printf("[%d] Success\n", test_index);
}

void test_htable_insert(void)
{
    test_index++;

    Table *table = htable_init(6);

    for (int i = 0; i < 8; i++)
    {
        int *value = (int *)malloc(sizeof(int));
        *value = i + 1;
        assert_status(
            htable_insert(table, &i, sizeof(int), value),
            "htable_insert"
        );
    }

    htable_destroy(table);

    printf("[%d] Success\n", test_index);
}

void test_htable_clear(void)
{
    test_index++;

    Table *table = htable_init(6);

    int i = 0;
    for (i = 0; i < 8; i++)
    {
        int *value = (int *)malloc(sizeof(int));
        *value = i + 1;
        htable_insert(table, &i, sizeof(int), value);
    }

    assert_status(
        htable_clear(table),
        "htable_clear"
    );

    htable_destroy(table);

    printf("[%d] Success\n", test_index);
}

void test_htable_remove(void)
{
    test_index++;

    Table *table = setup_table();

    for (int i = 0; i < n_elements; i++)
    {
        assert_status(
            htable_remove(table, &i, sizeof(int)),
            "htable_remove"
        );
    }

    printf("[%d] Success\n", test_index);

    htable_destroy(table);
}

void test_htable_get(void)
{
    test_index++;

    Table *table = setup_table();

    for (int i = 0; i < n_elements; i++)
    {
        int *value;
        assert_status(
            htable_get(table, &i, sizeof(int), (void**)&value),
            "htable_get"
        );
    }

    printf("[%d] Success\n", test_index);

    htable_destroy(table);
}

void test_htable_keys(void)
{
    test_index++;

    Table *table = setup_table();

    int **keys = malloc(n_elements * sizeof(int));

    assert_status(
        htable_keys(table, (void **)keys),
        "htable_keys"
    );

    printf("[%d] Success\n", test_index);

    htable_destroy(table);
}

void test_htable_values(void)
{
    test_index++;

    Table *table = setup_table();

    int **values = malloc(n_elements * sizeof(int));

    assert_status(
        htable_values(table, (void **)values),
        "htable_keys"
    );

    printf("[%d] Success\n", test_index);

    htable_destroy(table);
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
