#include "sll.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Please enter <num_of_nodes> in the sll.\n");
        return -1;
    }

    struct node* head = create_sll(atoi(argv[1]));
    print_sll(head);
}
