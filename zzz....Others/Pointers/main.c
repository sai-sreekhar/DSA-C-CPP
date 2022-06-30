#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

extern int *a;
void fillArray();

int main()
{
    fillArray();
    // for (int i = 0; i < 10; i++)
    // {
    //     printf("%d\n",a[i]);
    // }

    printf("%x\n",a);

    
    return 0;
}
