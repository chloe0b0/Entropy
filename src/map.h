#ifndef MAP_H_
#define MAP_H_

#include <stdlib.h>
#include <string.h>

/*  Implementation of a hashmap to hold arbitrary types */
typedef struct HashTable{
    unsigned int size, occupied_entries;
    void** arr;
}HashTable;

// Hash strings
int CharSumHash(const char* x, unsigned int HashTableSize){
    unsigned int sum, l;
    sum = 0;
    l = strlen(x);

    for (int i = 0; i < l; ++i){
        sum += x[i];
        sum = (sum * x[i]) % HashTableSize;
    }

    return sum;
}

void Set(HashTable* m, const char* x, void* y){
    int ix = CharSumHash(x, m->size);
    // Handle collisions later
    if (!m->arr[ix]){ m->arr[ix] = y; }
    ++m->occupied_entries;
}

void Clear(HashTable* m, const char* x){
    int ix = CharSumHash(x, m->size);
    if (!m->arr[ix]){ return; }
    m->arr[ix] = NULL;
    --m->occupied_entries;
}

void* Get(HashTable* m, const char* x){
    int ix = CharSumHash(x, m->size);
    return m->arr[ix];
}

HashTable* Create_HashTable(unsigned int size){
    HashTable* map = (HashTable*)malloc( sizeof(HashTable) );

    map->arr = calloc(size, sizeof(void*));
    map->size = size;
    map->occupied_entries = 0;

    return map;
}

// Computes the load factor of a hashtable
float load_factor(HashTable* map){
    return map->occupied_entries / map->size;
}

#endif