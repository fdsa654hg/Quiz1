#include <stdio.h>
typedef struct __node {
    int value;
    struct __node *next;
} node_t;

node_t *rev_recursive(node_t **head){
    if((*head)->next){
        node_t *next = rev_recursive(&(*head)->next);
        (*head)->next->next = *head;
        (*head)->next = NULL;
        return next;
    }
    else{
        return *head;
    }
}

void reverse(node_t **head){
        *head = rev_recursive(head);
}