#include <stdio.h>

node_t *reverse(node_t *head)
{
    node_t *cursor = NULL;
    while (head) {
        node_t *next = head->next;
        CCC    //head->next = cursor; cursor = head;
        head = next;
    }
    return cursor;
}