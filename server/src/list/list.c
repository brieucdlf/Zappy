#include "server.h"

void			free_data_elem(t_list *current_elem)
{
  if (current_elem != NULL &&
      current_elem->free != NULL)
    current_elem->free(current_elem->data);
}

void			remove_elem(t_list **head_list, void *node)
{
  t_list		*current_elem;

  if ((*head_list)->next == NULL)
    {
      *head_list = NULL;
      free_data_elem(*head_list);
      free(node);
      return ;
    }
  if ((*head_list)->data == node)
    {
      free_data_elem(*head_list);
      *head_list = (*head_list)->next;
      free(node);
      return ;
    }
  current_elem = *head_list;
  while (current_elem->next != NULL && current_elem->next->data != node)
    current_elem = current_elem->next;
  free_data_elem(current_elem);
  if (current_elem->next->next == NULL)
    current_elem->next = NULL;
  else
    current_elem->next = current_elem->next->next;
  free(node);
}

void			list_pop(t_list **list)
{
  void			*ptmp;

  if (*list == NULL)
    return ;
  if ((*list)->next == NULL)
    {
      if ((*list)->free != NULL)
	(*list)->free((*list)->data);
      free(*list);
      *list = NULL;
      return ;
    }
  if ((*list)->free != NULL)
    (*list)->free((*list)->data);
  ptmp = *list;
  *list = (*list)->next;
  free(ptmp);
}

void			list_delete(t_list *list)
{
  t_list		*current_elem;
  void			*ptmp;

  if (list == NULL)
    return ;
  current_elem = list;
  while (current_elem != NULL)
    {
      if (current_elem->free != NULL)
	current_elem->free(current_elem->data);
      ptmp = current_elem;
      current_elem = current_elem->next;
      free(ptmp);
    }
}

void		        list_push(t_list **list, void *data,
				  free_function function)
{
  t_list		*current_elem;
  t_list		*new_elem;

  if (*list == NULL)
    {
      if ((*list = malloc(sizeof(t_list))) == NULL)
	return ;
      (*list)->data = data;
      (*list)->free = function;
      (*list)->next = NULL;
      return ;
    }
  if ((new_elem = malloc(sizeof(t_list))) == NULL)
    return ;
  new_elem->data = data;
  new_elem->free = function;
  new_elem->next = NULL;
  current_elem = *list;
  while (current_elem->next != NULL)
    current_elem = current_elem->next;
  current_elem->next = new_elem;
}
