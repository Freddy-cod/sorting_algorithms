#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail Shaker Sort algorithm
 * @list: A pointer to a pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *curr;

    if (list == NULL || *list == NULL)
        return;

    while (swapped)
    {
        swapped = 0;
        for (curr = *list; curr->next != NULL; curr = curr->next)
        {
            if (curr->n > curr->next->n)
            {
                swap_nodes(curr, &(curr->next), list);
                swapped = 1;
                print_list(*list);
            }
        }
        if (!swapped)
            break;

        swapped = 0;
        for (; curr->prev != NULL; curr = curr->prev)
        {
            if (curr->n < curr->prev->n)
            {
                swap_nodes(curr->prev, &curr, list);
                swapped = 1;
                print_list(*list);
            }
        }
    }
}
