#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @left: The node to swap with the next node
 * @right: The next node to swap with the left node
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
  if (left->prev)
    left->prev->next = right;
  else
    *list = right;
  
  if (right->next)
    right->next->prev = left;
  
  left->next = right->next;
  right->prev = left->prev;
  left->prev = right;
  right->next = left;

  print_list(*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
  int swapped = 1;
  listint_t *start = *list;
  listint_t *end = NULL;

  if (!list || !*list)
    return;

  while (swapped)
  {
    swapped = 0;
    
    while (start->next != end)
    {
      if (start->n > start->next->n)
      {
        swap_nodes(list, start, start->next);
        swapped = 1;
      }
      start = start->next;
    }

    if (!swapped)
      break;

    swapped = 0;
    end = start;
    start = start->prev;

    while (start->prev != NULL)
    {
      if (start->n < start->prev->n)
      {
        swap_nodes(list, start->prev, start);
        swapped = 1;
      }
      start = start->prev;
    }
  }
}
