#include "rtarray.h"


static void raiseError(char msg[], int errorCode) {
    printf("###\n###  RUNTIME ERROR: %s\n###\n", msg);
    exit(errorCode);
}


void* __rtArray_create_new(int length, size_t segmentSize) {
    size_t* ptr = malloc(sizeof(size_t) * RA_HEADER_LENGTH + segmentSize * length);

    if (ptr == NULL) {
        raiseError("__rtArray_create_new - Memory allocation failed", 1);
    }

    ptr[RA_LENGTH] = length;
    ptr[RA_SEGMENT_SIZE] = segmentSize;

    void* arr = (void*) (ptr + RA_HEADER_LENGTH);

    memset(arr, 0, segmentSize * length);

    return arr;
}

_Bool rtArray_index_exists(void* arr, int index) {
    return (index >= 0 && index < __rtArray_get_header_val(arr, RA_LENGTH));
}

size_t __rtArray_get_header_val(void* arr, int attribute) {
    return ((size_t *)(arr) - RA_HEADER_LENGTH)[attribute];
}

size_t rtArray_memSize(void* arr) {
    return sizeof(size_t)*RA_HEADER_LENGTH + __rtArray_get_header_val(arr, RA_SEGMENT_SIZE) * __rtArray_get_header_val(arr, RA_LENGTH);
}

void rtArray_free(void* arr) {
    size_t* ptr = (size_t*)arr;

    free(ptr - RA_HEADER_LENGTH);
}