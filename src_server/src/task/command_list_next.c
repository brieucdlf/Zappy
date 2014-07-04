#include "task.h"
#include "server.h"
#include "user.h"

int			match_item_prendre_task(void *data1, void *data2)
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
  const char            *name_item[7] = {"food\n", "linemate\n", "deraumere\n",
					 "sibur\n", "mendiane\n", "phiras\n",
					 "thystame\n"};

  if (arg == NULL)
    return ;
  current_item = server->map.map[client->direction.position_y]
    [client->direction.position_x];
  while (current_item !=  NULL)
    {
      if ((item = current_item->data) != NULL &&
	  strcmp(arg, name_item[item->type]) == 0)
	{
	  if (item->type == FOOD)
	    {
	      printf("food incrementation vie\n");
	    }
	  else
	    ++client->items[item->type];
	  list_remove_with_data(&current_item, (void *)item,
				match_item_prendre_task);
	  create_new_write_task(client, "ok");
	  return ;
	}
      current_item = current_item->next;
    }
  return create_new_write_task(client, "ko");
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
    return ;
  item = NULL;
  for (index_item = 0; index_item < 7 &&
	 strcmp(arg, name_item[index_item]) != 0; index_item++);
  if (index_item == 7)
    {
      create_new_write_task(client, "ko");
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
  return create_new_write_task(client, "ok");
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
