#include "task.h"
#include "server.h"
#include "user.h"

int			s_object_pose(char *arg, int index)
{
  const char            *name_item[7] = {"food\n", "linemate\n",
					 "deraumere\n", "sibur\n",
                                         "mendiane\n", "phiras\n",
					 "thystame\n"};

  return (strcmp(arg, name_item[index % 7]));
}

void			send_pose_graphic_client(t_server *server,
						 t_client *client,
						 int index_item)
{
  char			*command;

  create_new_write_task(client, "OK\n");
  if (server->graphic_client == NULL || server->index_task_graphic > 0 ||
      (command = malloc(100)) == NULL)
    return ;
  memset(command, 0, 100);
  snprintf(command, 100, "pdr %d %d\n", client->id_client, index_item);
  create_new_write_task(server->graphic_client, command);
  free(command);
}

void			pose_task_function(t_server *server,
					   t_client *client,
					   char *arg)
{
  t_item		*item;
  int			index_item;

  if (arg == NULL)
    {
      create_new_write_task(client, "KO\n");
      return ;
    }
  item = NULL;
  for (index_item = 0; index_item < 7 && s_object_pose(arg, index_item) != 0;
       index_item++);
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
  send_pose_graphic_client(server, client, index_item);
}
