#ifndef rtArray_C_H
#define rtArray_C_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// structure:
//    size_t  length (number of items)
//    size_t  segmentSize (size of each item in bytes)
//    void*   contents (the contents)

enum {
    RA_LENGTH,
    RA_SEGMENT_SIZE,

    RA_HEADER_LENGTH
};


void* __rtArray_create_new(int length, size_t segmentSize);
size_t __rtArray_get_header_val(void* arr, int attribute);


_Bool rtArray_index_exists(void* arr, int index);
size_t rtArray_memSize(void* arr);
void rtArray_free(void* arr);


#define rtArray_new(size, type) __rtArray_create_new((size), sizeof(type))
#define rtArray_size(arr) __rtArray_get_header_val((arr), RA_LENGTH)


#endif // rtArray_C_H

// Features:
//    Stores any values
//    Records the size of the arr
//
//
// Methods:
//
//    _Bool  rtArray_index_exists(void* arr, int index)
//       -returns if the index is within array bounds
//
//    size_t  rtArray_memSize(void* arr)
//       -returns the size of whole arr
//
//    void  rtArray_free(void* arr)
//       -frees the array from memory (deletes it)
//
//
// Macro methods:
//
//    void*  rtArray_new($number size, $variable type)
//       -returns pointer to start of new arr contents
//
//    size_t  rtArray_size($void* arr)
//       -returns the number of items in arr
//

