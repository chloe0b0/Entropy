#ifndef MAP_H_
#define MAP_H_

#include <stdlib.h>


/*  Implementation of a hashmap to hold arbitrary types */
typedef struct HashTable{
    void* arr;
    unsigned int size, occupied_entries;
}HashTable;


// Hash Function for abitrary type

int Hash(const char* x){

}

HashTable* Create_HashTable(unsigned int size){
    HashTable* map = (HashTable*)malloc( sizeof(HashTable) );
    
    map->arr = malloc( sizeof(void*) * size );
    map->size = size;
    map->occupied_entries = 0;

    return map;
}

// Computes the load factor of a hashtable
float load_factor(HashTable* map){
    return map->occupied_entries / map->size;
}

#endif