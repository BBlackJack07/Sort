#include <stdio.h>
#include "heap.h"

int main(void) {
    MinHeap heap;
    heap.head = NULL;
    int x = 0;
    while (scanf("%d", &x)==1)
        insert(&heap, x);
    while (!isempty(heap)) {
        fflush(stdin);
        printf("%d ", get_min(heap));
        delete_min(&heap);
    }
    printf("\n");
    return 0;
}

