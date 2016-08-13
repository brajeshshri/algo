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
        free(temp);
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

struct node* delete_node(struct node* head, int val)
{
    if(!head) {
        return NULL;
    }

    struct node* temp_node = head;
    struct node* prev_node = NULL;

    while(temp_node) {
        if(temp_node->data == val) {
            if(prev_node != NULL) {
               prev_node->next = temp_node->next;
            } else {
               head = temp_node->next;
            }
            free(temp_node);
            printf("Deleted element %d in sll.\n", val);
            return head; 
        }
        prev_node = temp_node;
        temp_node = temp_node->next;
    }

    printf("Didn't find element %d in sll.\n", val);
    return head;
}

struct node* create_sll_r(int num_nodes)
{
    if(num_nodes < 1) {
        return NULL;
    }

    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = num_nodes--;
    temp->next = create_sll_r(num_nodes);
    return temp;
}

void print_sll_r(struct node *head)
{
    if(!head) {
        printf("\n");
        return;
    }
    
    printf("%d  ", head->data);
    print_sll_r(head->next);
}

void print_sll_reverse_r(struct node *head)
{
    if(!head) {
        return;
    }

    print_sll_reverse_r(head->next);
    printf("%d  ", head->data);
}

void free_sll_r(struct node *head)
{
    if(!head) return;

    free_sll_r(head->next);
    printf("Deleting data: %d\n", head->data);
    free(head);
}
