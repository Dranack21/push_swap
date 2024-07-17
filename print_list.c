
#include "push_swap.h"

void print_list(t_double_list *head)
{
    t_double_list *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}