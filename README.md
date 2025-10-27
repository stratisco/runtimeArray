# Runtime Array
A lightweight fixed length array for C which stores length and can be initialised at runtime.

I made it so that you can make new arrays during runtime that know their length.

*made for versions of c where there VLA is not enabled like c89*

## Usage
Step 1 - Download the two files in `/src` to your project

Step 2 - Include the package
```c
#include "rtarray.h"
```

Step 3 - Initialise new array 
```c
int* intArr = rtArray_new(10, int);

// another example
char* charArr = rtArray_new(10, char);
```

Step 4 - Use array
```c
// get length of an array
size_t size = rtArray_size(arr);

// get memory size used by an array
size_t memSize = rtArray_memSize(arr);

// see if an index exists in array
_Bool valid = rtArray_index_exists(array, index);

```

Step 5 - Free array
```c
rtArray_free(arr);
```


Example
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
It stores the header information before the list and then returns a pointer to the begining of the list.

```
// layout
+---+---+------+------+------+
| 1 | 2 |         3          |
+---+---+------+------+------+
// 1 - length
// 2 - segment size
// 3 - begining of regular pointer list
```

Header size is only 16 bytes and the list max size is limated only by your computer max malloc size