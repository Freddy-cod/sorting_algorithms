#include "sort.h"

/**
 * swap_nodes - swaps two adjacent nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @left: pointer to the left node
 * @right: pointer to the right node
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
  if (!list || !left || !right || left == right)
    return;

  left->next = right->next;
  if (right->next)
    right->next->prev = left;

  right->prev = left->prev;
  if (left->prev)
    left->prev->next = right;
  else
    *list = right;

  right->next = left;
  left->prev = right;
}

/**
 * cocktail_sort_list - sorts a doubly linked list
 * @list: pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
  int swapped = 1;
  listint_t *start, *end = NULL;

  if (!list || !*list || !(*list)->next)
    return;

  while (swapped)
  {
    swapped = 0;
    start = *list;

    while (start->next != end)
    {
      if (start->n > start->next->n)
      {
        swap_nodes(list, start, start->next);
        swapped = 1;
      }
      else
      {
        start = start->next;
      }
    }

    end = start;
    if (!swapped)
      break;
    swapped = 0;
    while (start->prev != NULL)
    {
      if (start->n < start->prev->n)
      {
        swap_nodes(list, start->prev, start);
        swapped = 1;
      }
      else
      {
        start = start->prev;
      }
    }
  }
}
