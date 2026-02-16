#include "stdlib.h" /*size_t*/
#include <stdio.h>


struct object {

    size_t reference_counting;

    char value;

};


struct object * object_create(int value) {

    struct object * struct_object = (struct object *)malloc(sizeof * struct_object);

    /*initial owner*/
    (* struct_object).reference_counting = 1;
    (* struct_object).value = value;

    /*%p void **/
    printf("create %p (reference = %d)\n", (void *)struct_object, (* struct_object).value);

    /*
    struct_object = 10;
    error: assignment to ‘struct object *’ from ‘int’ makes pointer from integer without a cast [-Wint-conversion]
    */
    free(struct_object);struct_object = (struct object *)0;





}


int main() {

    struct object * struct_object = object_create(42);



    return 0;

}
