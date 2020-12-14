#include <stdio.h>
#include "combsort.h"

#define LENGTH 1000000

int main(void)
{
    int array[LENGTH];
    int i = 0;
    while (scanf("%d", array+i) == 1)
        i++;
    combsort(array, i);
    for (int j = 0; j<i; j++)
        printf("%d ", array[j]);
    printf("\n");
    
    return 0;
}
