#include <stdio.h>
#include "map.h"


int main(void){
    HashTable* m = Create_HashTable(10);
    Set(m, "x", (int*)8);
    Set(m, "yy", (int*)9);
    int* str = (int*)Get(m, "x");
    printf("%d\n", str);
}