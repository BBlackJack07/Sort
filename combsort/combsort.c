#include <stddef.h>
#include "combsort.h"

void swap(int *restrict a, int *restrict b) 
{
    if (a != b && a != NULL && b != NULL)
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

void combsort(int * arr, int length)
{
    int inter = length;
    bool had_swap = true;
    while (inter>1 || had_swap)
    {
        inter = inter/REDUCT;
        had_swap = false;
        if (inter<1)
            inter = 1;
        for (int i = inter; i<length; i++)
        {
            if(arr[i-inter]>arr[i])
            {
                swap(arr+i-inter, arr+i);
                had_swap = true;
            }
        }
    }
}
