#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void print_sll(struct node *head)
{
    while(head) {
        printf("%d  ", head->data);
        head = head->next;
    }

    printf("\n");
}

void free_sll(struct node *head)
{
    struct node *temp = NULL;
    while(head) {
        temp = head;
        head = head->next;
    }
}

struct node* create_sll(int num_of_nodes)
{
    if (num_of_nodes <= 0) return NULL;

    int i = 1;
    struct node* prev_node = NULL;
    struct node* head = NULL;

    for (int i = 1; i <= num_of_nodes; i++) {
        struct node *new_node  = (struct node*)malloc(sizeof(struct node));
        if(i == 1) head = new_node;
        if(new_node == NULL) {
            printf("Unable to allocate memory for node: %d.\n", i); 
            free_sll(head);
            return NULL;
        }

        new_node->data = i;
        new_node->next = NULL;

        if(prev_node) {
            prev_node->next = new_node;
        }
        prev_node = new_node;
    }   

    return head;
}

void update_sll(struct node *head, int node_num, int val)
{
    struct node *temp = NULL;
    int cnt = 0;

    while(head) {
        cnt++;
        if(cnt == node_num) {
            head->data = val;
        } else {
            head = head->next;
        }
    }
}
