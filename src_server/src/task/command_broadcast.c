#include "server.h"

char			**copy_map(int width, int height)
{
  char			**map;
  int			index_position_y;

  if ((map = malloc(sizeof(char *) * height)) == NULL)
    return (NULL);
  for (index_position_y = 0; index_position_y < height; index_position_y++)
    {
      if ((map[index_position_y] = malloc(sizeof(char) * width)) == NULL)
	return (NULL);
      memset(map[index_position_y], 0, width);
    }
  return (map);
}

void			loop_path_finder(char **map, t_server *server)
{
  int			number_path;

  number_path = 1;
  while (path_finder(map, number_path, server) != 0)
    number_path += 1;
}

void		        fill_copy_map_path(t_client *sender,
					   t_server *server, char **map)
{
  t_list		*current_client;

  if ((current_client = server->clients) == NULL)
    return ;
  map[sender->direction.position_y][sender->direction.position_x] = 1;
  while (current_client != NULL)
    {
      if (((t_client *)(current_client->data))->is_ready == 1 &&
	  ((t_client *)(current_client->data))->id_client != sender->id_client
	  && ((t_client *)(current_client->data))->direction.position_y >= 0 &&
	  ((t_client *)(current_client->data))->direction.position_y <
	  server->map.height &&
	  ((t_client *)(current_client->data))->direction.position_x >= 0 &&
	  ((t_client *)(current_client->data))->direction.position_x <
	  server->map.width)
	map[((t_client *)(current_client->data))->direction.position_y]
	  [((t_client *)(current_client->data))->direction.position_x] = -2;
      current_client = current_client->next;
    }
}

void			send_broadcast_player(t_server *server,
					      t_client *sender, char **map,
					      char *message)
{
  t_list		*current_client;


  if ((current_client = server->clients) == NULL)
    return ;
  map[sender->direction.position_y][sender->direction.position_x] = 1;
  while (current_client != NULL)
    {
      if (((t_client *)(current_client->data))->is_ready == 1 &&
	  ((t_client *)(current_client->data))->id_client != sender->id_client)
	find_best_path(((t_client *)(current_client->data)),
		       map, server, message);
      current_client = current_client->next;
    }
}

void			broadcast_task_function(t_server *server,
					        t_client *client,
						char *arg)
{
  t_list		*current_client;
  char			**map;

  if (arg == NULL || (current_client = server->clients) == NULL ||
      (map = copy_map(server->map.width, server->map.height)) == NULL)
    {
      create_new_write_task(client, "KO\n");
      return ;
    }
  fill_copy_map_path(client, server, map);
  loop_path_finder(map, server);
  send_broadcast_player(server, client, map, arg);
  create_new_write_task(client, "OK\n");
  free_double_array_delimiter(map, server->map.height);
}
