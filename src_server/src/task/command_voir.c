#include "server.h"

void			check_line(t_server *server, t_client *client,
				   int current_level, int *direction_position)
{
  int			number_side;

  number_side = current_level / 2;
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

void			voir_task_function(void *ptr_server,
					   void *ptr_client)
{
  t_server		*server;
  t_client		*client;
  int			direction_position[2];
  int			index_level_client;

  server = ptr_server;
  client = ptr_client;
  memset(direction_position, 0, 2);
  direction_see(client, &direction_position[0], &direction_position[1]);
  for (index_level_client = 0; index_level_client < client->level;
       index_level_client++)
    {
      check_line(server, client, index_level_client, direction_position);
    }
}
