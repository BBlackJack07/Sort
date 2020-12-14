#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void)
{
    List * lst = NULL;
    int x = 0;
    while(scanf("%d", &x)==1)
    {
        prepend(&lst, x);
    }
    lst = mergeSort(lst);
    while (lst != NULL)
    {
        printf("%d ", lst->head);
        pop_head(&lst);
    }
}