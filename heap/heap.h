#ifndef MIN_HEAP_H_
#define MIN_HEAP_H_

typedef struct heap_node {
    struct heap_node *left;
    int key;
    struct heap_node *right;
    int rank;
} HeapNode;

typedef struct {
    HeapNode *head;
} MinHeap;

// HeapNode Functions
HeapNode* singleton(int x);
int rank(HeapNode *head);
HeapNode* merge(HeapNode *one, HeapNode *two);
void free_nodes(HeapNode **head);

// MinHeap Functions
void insert(MinHeap *heap, int x);
int get_min(MinHeap heap);
void delete_min(MinHeap *heap);
int isempty(MinHeap heap);

#endif
