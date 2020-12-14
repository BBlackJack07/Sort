#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void prepend (List ** lst, int val)
{
    if (lst!=NULL) 
    {
        List * new = malloc(sizeof *new);
        new->head = val;
        new->next = *lst;
        *lst = new;
    }
}

void append (List ** lst, int val)
{
    if (lst != NULL)
    {
        if(*lst == NULL)
        {
            *lst = malloc(sizeof **lst);
            (*lst)->head = val;
            (*lst)->next = NULL;
        }
        else
        {
            List * current = *lst;
            while (current->next != NULL)
                current = current->next;
            List * new = malloc(sizeof *new);
            new->head = val;
            new->next = NULL;
            current->next = new;
        }
    }
}

void pop_head(List ** lst) 
{
    if(lst != NULL && *lst != NULL)
    {
        List * old = *lst;
        *lst = (*lst)->next;
        free(old);
    }
}

size_t length(List * lst)
{
    size_t len = 0;
    while (lst != NULL)
    {
        len++;
        lst = lst->next;
    }
    return len;
}

void reverse (List ** lst)
{
    if (lst == NULL)
        return;
    List * current = *lst;
    List * next = NULL;
    List * prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *lst = prev;
}

List * merge (List * a, List * b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    List new;
    List * current = &new;
    while (a!=NULL && b!=NULL)
    {
        if (a->head <= b->head)
        {
            current->next = a;
            a = a->next;
        }
        else
        {
            current->next = b;
            b = b->next;
        }
        current = current->next;
    }
    List * l = a == NULL ? b : a;
    current->next = l;
    return new.next;
}

void split(List * lst, List ** a, List ** b)
{
    size_t len = length(lst);
    List new, * current = &new;
    for (unsigned i = 0; i < len/2; i++)
    {
        
        current->next = lst;
        lst = lst->next;
        current = current->next;
    }
    *a = new.next;
    *b = lst;
    current->next = NULL;
}

List * mergeSort (List * lst)
{
    if(lst == NULL || lst->next == NULL)
        return lst;
    List * a = NULL, * b = NULL;
    split(lst, &a, &b);
    List * ret = merge(mergeSort(a), mergeSort(b));
    return ret;
}
