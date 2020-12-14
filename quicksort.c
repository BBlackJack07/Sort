#include <stdio.h>

#define MAX_SIZE 1000000

void swap(int *restrict a, int *restrict b);
int part(int * arr, int first, int last, int pivot);
void quicksort(int * arr, int first, int last);

int main(void)
{
    int array[MAX_SIZE];
    int i = 0;
    while (scanf("%d", array+i)==1)
        i++;
    quicksort(array, 0, i-1);
    for (int j = 0; j < i; j++)
        printf("%d ", array[j]);
    printf("\n");
    return 0;
}

void swap(int *restrict a, int *restrict b)
{
    if (a != b && a != NULL && b != NULL)
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

int part(int * arr, int first, int last, int pivot)
{
    swap(arr+pivot, arr+last);
    int j = first;
    for (unsigned int i = first; i<last; i++)
    {
        if(arr[i]<arr[last])
        {
            swap(arr+i, arr+j);
            j++;
        }
    }
    swap(arr+last, arr+j);
    return j;
}

void quicksort(int * arr, int first, int last)
{
    if (first < last)
    {
        int pivot = first;
        pivot = part(arr, first, last, pivot);
        quicksort(arr, first, pivot-1);
        quicksort(arr, pivot+1, last);
    }
}
