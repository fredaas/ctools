#ifndef HTABLE_H
#define HTABLE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct TableBucket TableBucket;
typedef struct Table Table;

#define HTABLE_SUCCESS 0
#define HTABLE_ENOMEM  1
#define HTABLE_EEXISTS 2
#define HTABLE_ENOITEM 3
#define HTABLE_ENULL   4

enum {
    HTABLE_POLY_NORMAL,
    HTABLE_POLY_REVERSED,
    HTABLE_POLY_RECIPROCAL,
    HTABLE_POLY_REVERSED_RECIPROCAL
};

struct TableBucket {
    TableBucket *next;
    void *key;
    int key_size;
    void *value;
    int value_type;
};

struct Table {
    TableBucket **buckets;
    int num_buckets;
    int size;
};

Table * htable_init(int num_buckets);
TableBucket *htable_bucket(Table *self, int index);
int htable_get(Table *self, void *key, int key_size, void **value);
int htable_insert(Table *self, void *key, int key_size, void *value);
int htable_destroy(Table *self);
int htable_values(Table *self, void **values);
int htable_clear(Table *self);
int htable_remove(Table *self, void *key, int key_size);
int htable_keys(Table *self, void **keys);
void htable_assert(int code);

void crc32_generate(int type);
void crc32_dump(char *dst);
uint32_t crc32_hash(void *key, int key_size);

#endif /* HTABLE_H */