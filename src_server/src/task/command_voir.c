#include "server.h"

void			loop_items_on_case(t_list *current_item, void *arg)
{
  t_item		*item;
  const char		*name_item[7] = {"linemate", "deraumere", "sibur",
					 "mendiane", "phiras", "thystame",
					 "food"};

  if ((item = current_item->data) == NULL)
    return ;
  (void)arg;
  printf("current item : %s\n", name_item[item->type - 1]);
}

void			check_line(t_server *server, t_client *client,
				   int current_level, int *direction_position)
{
  int			index_position;

  direction_position[0] *= current_level + 1;
  direction_position[1] *= current_level;
  for (index_position = 0; index_position < current_level * 2 + 1;
       index_position++)
    {
      if (client->direction.position_y + direction_position[0] >= 0 &&
	  client->direction.position_y + direction_position[0] <=
	  server->map.height && client->direction.position_x +
	  direction_position[1] >= 0 && client->direction.position_x +
	  direction_position[1] <= server->map.width)
	{
	  map_list(server->map.map[client->direction.position_y +
				   direction_position[0]]
		   [client->direction.position_x + direction_position[1]],
		   loop_items_on_case, NULL);
	}
    }
}

void			direction_see(t_client *client, int *direction_x,
				      int *direction_y)
{
  if (client->direction.orientation == MAP_DIRECTION_ORIENTATION_NORTH)
    *direction_y = -1;
  if (client->direction.orientation == MAP_DIRECTION_ORIENTATION_SOUTH)
    *direction_y = 1;
  if (client->direction.orientation == MAP_DIRECTION_ORIENTATION_WEST)
    *direction_x = -1;
  if (client->direction.orientation == MAP_DIRECTION_ORIENTATION_EAST)
    *direction_x = 1;
}

void			voir_task_function(t_server *server,
					   t_client *
client,
					   char *arg)
{
  int			direction_position[2];
  int			index_level_client;

  (void)arg;
  printf("voir function\n");
  memset(direction_position, 0, 2);
  direction_see(client, &direction_position[0], &direction_position[1]);
  for (index_level_client = 1; index_level_client <= client->level;
       index_level_client++)
    {
      check_line(server, client, index_level_client, direction_position);
    }
  create_new_write_task(client, "OK");
}
