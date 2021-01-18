#include <stdio.h>

typedef struct __node {
    int value;
    struct __node *next;
} node_t;

int list_length(node_t *head){
    int count = 0;
    
    while(head){
        ++count;
        head = head->next;
    }
    
    return count;
}

void exchange_nodes(node_t **head, int first_node, int second_node){
    int count = second_node - first_node;
    if(!count)return;
    
    node_t **indirection = head;
    node_t *first_cursor = NULL;
    node_t *second_cursor = NULL;

    while(first_node-1){
        first_cursor = *indirection;
        indirection = &(*indirection)->next;
        --first_node;
    }
    
    node_t *first_node_des = *indirection;
    
    while(count){
        second_cursor = *indirection;
        indirection = &(*indirection)->next;
        --count;
    }

    node_t *second_node_des = *indirection;
    
    if(first_cursor)first_cursor->next = second_node_des;
    second_cursor->next = first_node_des;

    node_t *tmp = second_node_des->next;
    second_node_des->next = first_node_des->next;
    first_node_des->next = tmp;

    if(!first_cursor)*head = second_node_des;
}

void Fisher_Yates_shuffle(node_t **head){
    for(int i = list_length(*head); i>=1; --i){
        int j = rand() % i + 1;
        exchange_nodes(head,j,i); 
    }
}