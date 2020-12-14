#ifndef LIST_H_
#define LIST_H_

typedef struct list {
    int head;
    struct list * next;
} List;

void prepend(List ** lst, int val);
void reverse(List ** lst);
void append(List ** lst, int val);
size_t length(List * lst);
void pop_head(List ** lst);
List * merge (List * a, List * b);
void split(List * lst, List ** a, List ** b);
List * mergeSort (List * lst);

#endif