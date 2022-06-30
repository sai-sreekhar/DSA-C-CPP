#include <stdio.h>
#include <stdbool.h>
#define PI 3.1415

#define USE_BUBBLE_SORT
#ifdef USE_BUBBLE_SORT //we can use of if 1 and if 0 also
#define SORT() \
{\
    for (int i = 0;i < n-1;i++)\
    {\
        bool swapped = false;\
        for(int j =0;j < n-i-1;j++)\
        {\
            if (arr[j] > arr[j + 1])\
            {\
                    int temp = arr[j+1];\
                    arr[j+1] = arr[j];\
                    arr[j] = temp;\
                    swapped = true;\
            }\
        }\
        if (swapped == false)\
        {\
            break;\
        }\
    }\
}
#else
#define SORT() \
{\
    for(int i = 1;i < n;i++)\
    {\
        int key = arr[i];\
        int j;\
        for(j = i-1;j >= 0 && arr[j] > key;j--)\
        {\
            arr[j+1] = arr[j];\
        }\
        arr[j+1] = key;\
    }\
}
#endif


// #define  USE_BUBBLE_SORT

// #ifdef USE_BUBBLE_SORT
// #define SORT(arr,n) bubbleSort(arr,n)
// #else
// #define SORT(arr,n) insertionSort(arr,n)
// #endif

int main()
{
    int arr[7] = {9,10,1,4,100,3,5};
    int n = 7;
    SORT();
    for (int i =0;i < 7;i++) 
    {
        printf("%d\n",arr[i]);
    }

    return 0;
}
