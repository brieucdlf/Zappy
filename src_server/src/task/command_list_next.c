
#include "task.h"
#include "server.h"
#include "user.h"

int			match_item_prendre_task(void *data1, void *data2)
{
  if (data1 == NULL || data2 == NULL)
    return (1);
  if (((t_item *)data1)->type == ((t_item *)data2)->type)
    return (0);
  return (1);
}

void			display_item_list(t_list *item, void *arg)
{
  (void)arg;
  if (item == NULL)
    return ;
  printf("Liste des items : [%d]\n", ((t_item *)item->data)->type);
}

void		        prend_task_function(t_server *server,
					    t_client *client,
					    char *arg)
{
  t_item                *item;
  t_list                *current_item;
  const char            *name_item[7] = {"food\n", "linemate\n", "deraumere\n",
					 "sibur\n", "mendiane\n", "phiras\n",
					 "thystame\n"};

  current_item = server->map.map[client->direction.position_y]
    [client->direction.position_x];
  while (arg != NULL && current_item !=  NULL)
    {
      if ((item = current_item->data) != NULL &&
	  strcmp(arg, name_item[item->type]) == 0)
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
	  create_new_write_task(client, "OK\n");
	  return ;
	}
      current_item = current_item->next;
    }
  return create_new_write_task(client, "KO\n");
}

void			pose_task_function(t_server *server,
					   t_client *client,
					   char *arg)
{
  t_item		*item;
  int			index_item;
  const char            *name_item[7] = {"food\n", "linemate\n",
					 "deraumere\n", "sibur\n",
                                         "mendiane\n", "phiras\n",
					 "thystame\n"};

  if (arg == NULL)
    {
      create_new_write_task(client, "KO\n");
      return ;
    }
  item = NULL;
  for (index_item = 0; index_item < 7 &&
	 strcmp(arg, name_item[index_item]) != 0; index_item++);
  if (index_item >= 7)
    {
      create_new_write_task(client, "KO\n");
      return ;
    }
  if ((item = malloc(sizeof(t_item))) == NULL)
    return ;
  item->posy = client->direction.position_y;
  item->posx = client->direction.position_x;
  item->type = index_item;
  --client->items[index_item];
  list_push(&server->map.map[client->direction.position_y]
	    [client->direction.position_x], (void *)item, free_item);
  return create_new_write_task(client, "OK\n");
}
