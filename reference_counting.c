#include "stdlib.h" /*size_t*/
#include <stdio.h>


struct object {

    size_t reference_count;

    char value;

};


/*constructor*/
struct object * object_create(int value) {

    struct object * struct_object = (struct object *)malloc(sizeof * struct_object);

    /*initial owner*/
    (* struct_object).reference_count = 1;
    (* struct_object).value = value;

    /*%p void **/
    printf("create struct object pointer at %p (reference = %zu)\n", (void *)struct_object, (* struct_object).reference_count);

   return struct_object;

}


void object_keep(struct object * struct_object_alias) {

    (* struct_object_alias).reference_count++;

    printf("keep   struct object pointer at %p (reference = %ld)\n", (void *)struct_object_alias, (* struct_object_alias).reference_count);

    /*
    struct_object = 10;
    error: assignment to ‘struct object *’ from ‘int’ makes pointer from integer without a cast [-Wint-conversion]
    */
    free(struct_object_alias);struct_object_alias = (struct object *)0;







}











int main() {

    /*initial owner*/
    struct object * struct_object = object_create(42);

    /*second reference*/
    struct object * struct_object_alias = struct_object;

    object_keep(struct_object_alias);














    return 0;

}
