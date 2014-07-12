#include "server.h"

int			match_item_prendre_task(void *data1, void *data2)
{
  if (data1 == NULL || data2 == NULL)
    return (1);
  if (((t_item *)data1)->type == ((t_item *)data2)->type)
    return (0);
  return (1);
}

int		        s_object(char *arg, int index)
{
  const char            *name_item[7] = {"food\n", "linemate\n", "deraumere\n",
					 "sibur\n", "mendiane\n", "phiras\n",
					 "thystame\n"};

  return (strcmp(arg, name_item[index % 7]));
}

void			send_prend_graphic_client(t_server *server,
						  t_client *client,
						  int item_type)
{
  char			*command;

  create_new_write_task(client, "OK\n");
  if (server->graphic_client == NULL || (command = malloc(100)) == NULL)
    return ;
  memset(command, 0, 100);
  snprintf(command, 100, "pgt %d %d\n", client->id_client, item_type);
  create_new_write_task(server->graphic_client, command);
  free(command);
}

void		        prend_task_function(t_server *server,
					    t_client *client,
					    char *arg)
{
  t_item                *item;
  t_list                *current_item;

  current_item = server->map.map[client->direction.position_y]
    [client->direction.position_x];
  while (arg != NULL && current_item !=  NULL)
    {
      if ((item = current_item->data) != NULL && s_object(arg, item->type) == 0)
	{
	  if (item->type == FOOD)
	    {
	      add_live_food(server, client);
	      generate_food(server);
	    }
	  else
	    ++client->items[item->type];
	  list_remove_with_data(&server->map.map[client->direction.position_y]
				[client->direction.position_x], (void *)item,
				match_item_prendre_task);
	  send_prend_graphic_client(server, client, item->type);
	  return ;
	}
      current_item = current_item->next;
    }
  create_new_write_task(client, "KO\n");
}
