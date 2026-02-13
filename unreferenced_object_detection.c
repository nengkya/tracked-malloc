#include "stdlib.h" /*malloc*/
#include <stdio.h>


void * tracked_malloc(size_t bytes_size) {

    /*
    int    is a      sign integer; 4 bytes on x64
    size_t is an unsigned integer; 8 bytes on x64

    int            is general-purpose integer arithmetic
    size_t purpose is to represents sizes, array indices, and results of sizeof
    */

    printf("sizeof(int   )   signed integer = %d bytes \n", sizeof(int   ));
    printf("sizeof(size_t) unsigned integer = %d bytes with %% d print format specifier \n", sizeof(size_t));

    /*
    printf("%modifier:format_specifier");
    printf("%size_t:unsigned");
    printf("%zu");
    */
    printf("sizeof(size_t) unsigned integer = %zu bytes with %%zu print format specifier\n", sizeof(size_t));

    void * allocated_memory = (void *)malloc(bytes_size);

    free(allocated_memory);
    allocated_memory = NULL;

}


int main() {

    int * a = (int *)tracked_malloc(sizeof(int));

    return 0;

}
