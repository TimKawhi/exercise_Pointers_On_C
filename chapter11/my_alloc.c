#include<stdlib.h>
#include<stdio.h>

void *
my_calloc( size_t n_elements, size_t element_size )
{
    char *new_memory;
    n_elements *= element_size;
    new_memory = malloc( n_elements );

    if(new_memory != NULL){
        char *ptr;
        ptr = new_memory;
        //如果写成  while( --n_elements >= 0)  就会报错
        while( n_elements-- > 0)
            *ptr++ = '\0';
    }
    return new_memory;
}


