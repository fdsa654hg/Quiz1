#include <stdio.h>

typedef struct __node {
    int value;
    struct __node *next;
} node_t;

void add_entry(node_t **head, int new_value)
{
    node_t **indirect = head;

    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = new_value;
    new_node->next = NULL;

    AA1;    //assert(new_node);
    while (*indirect)
        indirect = &(*indirect)->next;
    AA2    //*indirect = new_node;
}
