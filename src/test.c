#include <stdio.h>
#include "map.h"


int main(void){
    HashTable* m = Create_HashTable(10);
    char* x = "x";

    Set(m, "x", "y");
    char* str = (char*)Get(m, x);
    printf("%s\n", str);
}