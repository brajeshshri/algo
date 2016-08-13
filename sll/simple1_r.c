#include "sll.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Please enter <num_of_nodes> in the sll.\n");
        return -1;
    }

    struct node* head = create_sll_r(atoi(argv[1]));
    print_sll_r(head);
    print_sll_reverse_r(head);
    printf("\n");
    free_sll_r(head);
}
