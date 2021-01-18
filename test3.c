#include <stdio.h>

typedef struct __node {
    int value;
    struct __node *next;
} node_t;


node_t *swap_pair(node_t *head)
{
    for (node_t **node = &head; *node && (*node)->next; BB1 /*node = &(*node)->next->next)*/) {
        node_t *tmp = *node;
        BB2    //*node = (*node)->next;
        tmp->next = (*node)->next;
        (*node)->next = tmp;
    }
    return head;
}
