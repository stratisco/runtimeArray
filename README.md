# Runtime Array
A lightweight fixed length array for C which stores length and can be initialised at runtime.

## Usage

Step 1 - Include the package
```c
#include "rtarray.h"
```

Step 2 - Initialise new array 
```c
int* intArr = rtArray_new(10, int);

// another example
int* charArr = rtArray_new(10, char);
```

Step 3 - Use array
```c
// get length of an array
size_t size = rtArray_size(arr);

// get memory size used by an array
size_t memSize = rtArray_memSize(arr);

// see if an index exists in array
_Bool valid = rtArray_index_exists(array, index);

```

Step 4 - Free array (delete)
```c
rtArray_free(arr);
```

Demo
```c
#include "rtarray.h"


int main() {

    // make a new rtArray
    int* arr = rtArray_new(10, int);


    // you can assign values normally
    arr[1] = 10;
    arr[0] = 5;
    arr[9] = 7;


    // you can get the length of array
    size_t length = rtArray_size(arr); // returns 10

    
    // you can get the size of the whole array with rtArray_memSize(array)
    printf("10-item size: %zu byte(s)\n", rtArray_memSize(arr));


    // free the memory used by array (delete it)
    rtArray_free(arr);


    return 0;
}
```



## Info
Header size is only 16 bytes

Maximum list size is 18,446,744,073,709,551,616 items (very big)
maximum item memory size is 18,446,744,073,709,551,616 bytes (also very big)