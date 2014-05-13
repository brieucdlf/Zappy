#include "server.h"

void			map_list(t_list *list,
				 void (*function)(t_list *, void *), void *arg)
{
  t_list		*current_elem;

  if (list == NULL || function == NULL)
    return ;
  current_elem = list;
  while (current_elem != NULL)
    {
      function(current_elem, arg);
      current_elem = current_elem->next;
    }
}
