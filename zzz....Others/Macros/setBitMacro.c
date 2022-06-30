#include <stdio.h>
#include <stdlib.h>

#define bitset(byte,n)   ((byte) |=  (1<<(n)))
#define GET_SET_BIT_COUNt(byte) \
for(int i =0; i<sizeof(int)*8 ;i++)\
{\
    if ((byte>>i)&(1) == 1)\
    {\
        count++;\
    }\
}


int main()
{
    int n = 0xf;
    int count = 0;
    GET_SET_BIT_COUNt(n);

    printf("No of ones in %d is %d\n",n,count);
    return 0;
}