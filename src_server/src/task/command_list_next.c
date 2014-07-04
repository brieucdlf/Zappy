#include "task.h"
#include "server.h"
#include "user.h"

int			match_item(void *data1, void *data2)
{
  if (((t_item *)data1)->type == ((t_item *)data2)->type)
    return (0);
  return (1);
}

void		        prend_task_function(t_server *server,
					    t_client *client,
					    char *arg)
{
  t_item                *item;
  t_list                *current_item;
  const char            *name_item[7] = {"food", "linemate", "deraumere", "sibur",
                                         "mendiane", "phiras", "thystame"};

  if (arg == NULL)
    return ;
  current_item = server->map.map[client->direction.position_y]
    [client->direction.position_x];
  while (current_item !=  NULL)
    {
      if ((item = current_item->data) != NULL)
	{
	  if (!strcmp((char *)arg, name_item[item->type]))
	    {
	      if (item->type == FOOD)
		{
		  /* Incrementation de la vie car le user mange */
		}
	      else
		++client->items[item->type];
	      list_remove_with_data(&server->map.map[client->direction.position_y]
				    [client->direction.position_x], (void *)item, match_item);
	    }
	}
      current_item = current_item->next;
    }
}

void			pose_task_function(t_server *server,
					   t_client *client,
					   char *arg)
{
  t_item		*item;
  const char            *name_item[7] = {"linemate", "deraumere", "sibur",
                                         "mendiane", "phiras", "thystame",
                                         "food"};

  if (arg == NULL)
    return ;
  item = NULL;
  if (!strcmp((char *)arg, name_item[item->type]))
    {
      --client->items[item->type];
      list_push(&server->map.map[client->direction.position_y]
		[client->direction.position_x], (void *)arg, NULL);
    }
}

void		        expulse_task_function(t_server *server,
					      t_client *client,
					      char *arg)
{
  (void)server;
  (void)client;
  (void)arg;
  printf("expulse object\n");
}

void			broadcast_task_function(t_server *server,
					        t_client *client,
						char *arg)
{
  (void)server;
  (void)client;
  (void)arg;
  printf("broadcast message\n");
}

void		        incantation_task_function(t_server *server,
						  t_client *client,
						  char *arg)
{
  (void)server;
  (void)client;
  (void)arg;
  printf("incantation\n");
}
