# Runtime Array
A lightweight fixed length array for C which stores length and can be initialised at runtime

## Features
- Allows for initialisation at runtime
- Has normal malloc array features and isnt a struct
- Stores the length of the array
- Function can check if specific index is within array range

> [!NOTE]
> This is made as a replacement for VLA *(Variable Length Arrays)* in version of c where those are not yet supported *(like c89)*

## Usage
**Step 1** - Download the files [`/src/rtarray.c`](src/rtarray.c) and [`/src/rtarray.h`](src/rtarray.h) to your project

**Step 2** - Include the package
```c
#include "rtarray.h"
```

**Step 3** - Initialise new array 
```c
int* intArr = rtArray_new(10, int);

// another example
char* charArr = rtArray_new(10, char);
```

**Step 4** - Use array
```c
// get length of an array
size_t size = rtArray_size(arr);

// get memory size used by an array
size_t memSize = rtArray_memSize(arr);

// see if an index exists in array
_Bool valid = rtArray_index_exists(array, index);

```

**Step 5** - Free array
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


    // free the array
    rtArray_free(arr);


    return 0;
}
```



## Info
It stores the header information before the list and then returns a pointer to the begining of the list.

```
// Memory layout
+---+---+------+------+------+
| 1 | 2 |         3          |
+---+---+------+------+------+
// 1 - length (size_t) 
// 2 - segment size (size_t)
// 3 - begining of regular pointer list (void *)
```

Header size is only 16 bytes and the list max size is limited only by your computer max malloc size
