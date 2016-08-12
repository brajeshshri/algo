#include "sll.h"

int main()
{
    struct node* head = create_sll(10);
    print_sll(head);
    update_sll(head, 5, 500);
    print_sll(head);
    free_sll(head);
}
