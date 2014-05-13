#include "server.h"

void			map_list(t_list *list,
				 map_function map_fct, void *arg)
{
  t_list		*current_elem;

  if (list == NULL || map_fct == NULL)
    return ;
  current_elem = list;
  while (current_elem != NULL)
    {
      map_fct(current_elem, arg);
      current_elem = current_elem->next;
    }
}

void			map_list_with_match(t_list *list,
					    map_function map_fct,
					    match_function match_fct, void *arg)
{
  t_list		*current_elem;

  if (list == NULL || map_fct == NULL || match_fct == NULL)
    return ;
  current_elem = list;
  while (current_elem != NULL)
    {
      if (match_fct(current_elem->data, arg))
	{
	  map_fct(current_elem, arg);
	  return ;
	}
      current_elem = current_elem->next;
    }
}
