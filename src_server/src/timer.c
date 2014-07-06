#include "server.h"

int			match_delete_task_function(void *data1, void *data2)
{
  (void)data2;
  if (((t_task *)data1)->is_over == 1)
    return (0);
  return (1);
}

void			check_timer_client(t_list *item, void *server)
{
  struct timeval	tv;
  t_list		*current_item;
  t_client		*current_client;

  if (item == NULL || (current_client = item->data) == NULL ||
      current_client->tasks == NULL)
    return ;
  gettimeofday(&tv, NULL);
  current_item = current_client->tasks;
  while (current_item != NULL)
    {
      if (tv.tv_sec >= ((t_task *)current_item->data)->timer.tv_sec &&
	  tv.tv_usec >= ((t_task *)current_item->data)->timer.tv_usec)
	{
	  init_timer_client(current_client);
	  ((t_task *)current_item->data)->is_over = 1;
	  ((t_task *)current_item->data)->function(server, current_client,
						   ((t_task *)current_item->
						    data)->argument);
	  list_remove_with_data(&current_client->tasks, NULL,
				match_delete_task_function);
	  return ;
	}
      current_item = current_item->next;
    }
}

void			check_timer(t_server *server)
{
  check_timer_clients(server);
  map_list(server->clients, check_timer_client, (void *)server);
}
