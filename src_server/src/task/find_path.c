#include "server.h"

void			find_best_start_minus(char **map, int *start_position,
					      t_client *client, int *start_value)
{
  if (client->direction.position_x - 1 >= 0 &&  map[client->direction.position_y]
      [client->direction.position_x - 1] < *start_value)
    {
      *start_position = MAP_DIRECTION_ORIENTATION_WEST;
      *start_value = map[client->direction.position_y]
	[client->direction.position_x - 1];
    }
  if (client->direction.position_y - 1 >= 0 &&
      map[client->direction.position_y - 1][client->direction.position_x] <
      *start_value)
    {
      *start_position = MAP_DIRECTION_ORIENTATION_NORTH;
      *start_value = map[client->direction.position_y - 1]
	[client->direction.position_x];
    }
}

void			find_best_start(char **map, int *start_position,
					t_client *client, t_server *server)
{
  int			start_value;

  start_value = 0x7FFFFFFF;
  find_best_start_minus(map, start_position, client, &start_value);
  if (client->direction.position_x + 1 < server->map.width &&
      map[client->direction.position_y][client->direction.position_x + 1] <
      start_value)
    {
      *start_position = MAP_DIRECTION_ORIENTATION_EAST;
      start_value = map[client->direction.position_y]
	[client->direction.position_x + 1];
    }
  if (client->direction.position_y + 1 < server->map.height &&
      map[client->direction.position_y + 1][client->direction.position_x] <
      start_value)
    {
      *start_position = MAP_DIRECTION_ORIENTATION_SOUTH;
      start_value = map[client->direction.position_y + 1]
	[client->direction.position_x];
    }
}

void			find_best_path(t_client *current_client, char **map,
				       t_server *server, char *message)
{
  int			start_position;
  char			*command;

  if ((command = malloc(1024)) == NULL)
    return ;
  memset(command, 0, 1024);
  start_position = 0;
  find_best_start(map, &start_position, current_client, server);
  start_position = start_position +
    (current_client->direction.orientation - start_position);
  snprintf(command, 1024,
	   "message %d, %s\n", start_position, message);
  create_new_write_task(current_client, command);
  free(command);
}

int			check_path(char **map, int *position,
				   int number_path, t_server *server)
{
  if (position[1] - 1 >= 0 && map[position[1] - 1][position[0]] == 0)
    {
      map[position[1] - 1][position[0]] = number_path + 1;
      position[2] = 1;
    }
  if (position[1] + 1 < server->map.height &&
      map[position[1] + 1][position[0]] == 0)
    {
      map[position[1] + 1][position[0]] = number_path + 1;
      position[2] = 1;
    }
  if (position[0] - 1 >= 0 && map[position[1]][position[0] - 1] == 0)
    {
      map[position[1]][position[0] - 1] = number_path + 1;
      position[2] = 1;
    }
  if (position[0] + 1 < server->map.width &&
      map[position[1]][position[0] + 1] == 0)
    {
      map[position[1]][position[0] + 1] = number_path + 1;
      position[2] = 1;
    }
  return (position[2]);
}

int			path_finder(char **map, int number_path,
				    t_server *server)
{
  int			index_position_y;
  int			index_position_x;
  int			position[3];
  int			find_path;

  find_path = 0;
  for (index_position_y = 0; index_position_y < server->map.height;
       index_position_y++)
    {
      for (index_position_x = 0; index_position_x < server->map.width;
	   index_position_x++)
	{
	  position[0] = index_position_x;
	  position[1] = index_position_y;
	  position[2] = 0;
	  if (map[index_position_y][index_position_x] == number_path &&
	      check_path(map, position, number_path, server) != 0)
	    find_path = 1;
	}
    }
  return (find_path);
}
