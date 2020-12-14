#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

typedef HeapNode Node;

Node* singleton(int x) {
    Node *new = malloc(sizeof *new);
    new->key = x;
    new->rank = 1;
    new->left = NULL;
    new->right = NULL;
    return new;
}

int rank(Node *head) {
    if (head == NULL)
        return 0;
    return head->rank;
}

Node* merge(Node *one, Node *two) {
    if (one == NULL)
        return two;
    if (two == NULL)
        return one;
    if (one->key>two->key)
        return merge(two, one);
    Node *merged = merge(one->right, two);
    int rank_right = rank(merged), rank_left = rank(one->left);
    if (rank_right > rank_left) {
        one->right = one->left;
        one->left = merged;
        one->rank = rank_left+1;
    }
    else {
        one->right = merged;
        one->rank = rank_right+1;
    }
    return one;
}

void free_nodes(Node **head) {
    if (head == NULL || *head == NULL)
        return;
    free_nodes(&((*head)->left));
    free_nodes(&((*head)->right));
    free(*head);
    *head=NULL;
}

void insert(MinHeap *heap, int x) {
    if (heap->head != NULL) {
        Node* new_head = merge(singleton(x), heap->head);
        heap->head = new_head;
    }
    else {
        heap->head = singleton(x);
    }
}

int get_min(MinHeap heap) {
    if (heap.head == NULL) {
        printf("Error, empty heap!\n");
        exit(EXIT_FAILURE);
    }
    return heap.head->key;
}

void delete_min(MinHeap *heap) {
    if (heap->head == NULL) { 
        printf("Error, empty heap!\n");
        exit(EXIT_FAILURE);
    }
    Node *new_head = merge(heap->head->left, heap->head->right);
    free(heap->head);
    heap->head = new_head;
}

int isempty(MinHeap heap) {
    return heap.head == NULL;
}

void clear(MinHeap *heap) {
    free_nodes(&(heap->head));
}

