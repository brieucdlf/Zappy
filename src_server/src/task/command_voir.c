#include "server.h"

void			make_request(t_client *client,
				     char *add_command)
{
  static char		*command = NULL;
  static int		index = 0;

  if (client == NULL && add_command == NULL)
    {
      index = 0;
      if ((command = malloc(5120)) != NULL)
	memset(command, 0, 5120);
      return ;
    }
  if (client != NULL && command != NULL)
    {
      create_new_write_task(client, command);
      free(command);
      command = NULL;
      return ;
    }
  if (add_command != NULL && command != NULL)
    {
      if (index + strlen(command) >= 5120)
	return ;
      strncpy(&command[index], add_command,
	      (strlen(add_command) % (5120 - index)));
      index += strlen(add_command) % 5120;
    }
}

void			loop_items_on_case(t_list *current_item,
					   void *marker_space)
{
  t_item		*item;
  const char		*name_item[7] = {" nourriture", " linemate",
					 " deraumere",
					 " sibur", " mendiane", " phiras",
					 " thystame"};
  static int		pass = 0;

  if ((item = current_item->data) == NULL ||
      item->type < 0 || item->type >= 7)
    return ;
  if (*(int *)marker_space == 0 && pass == 0)
    {
      make_request(NULL, (char *)&name_item[item->type][1]);
      pass = 1;
    }
  else if (*(int *)marker_space > 0)
    {
      pass = 0;
      make_request(NULL, (char *)name_item[item->type]);
    }
}

void			check_player_at_position(t_server *server,
						 t_client *client,
						 int position_x,
						 int position_y)
{
  t_list		*current_item;
  t_client		*current_client;
  char			*command;

  if ((current_item = server->clients) == NULL)
    return ;
  while (current_item != NULL)
    {
      if ((current_client = (t_client *)current_item->data) != NULL &&
	  current_client->is_ready == 1 && current_client->id_client !=
	  client->id_client && current_client->direction.position_x ==
	  position_x && current_client->direction.position_y == position_y)
	{
	  if ((command = malloc(strlen(server->param_server.teams_names
				       [current_client->id_team]) + 2)) == NULL)
	    return ;
	  sprintf(command, " %s", server->
		  param_server.teams_names[current_client->id_team]);
	  make_request(NULL, command);
	  free(command);
	}
      current_item = current_item->next;
    }
}

void			check_content_case(t_server *server, t_client *client,
					   int position_x, int position_y)
{
  int			marker;

  marker = 1;
  map_list(server->map.map[position_y][position_x],
	   loop_items_on_case, (void *)&marker);
  check_player_at_position(server, client, position_x, position_y);
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
      if (client->direction.position_x + direction_position[0] -
	  (current_level / 2 + 1) + index_position >= 0 &&
	  client->direction.position_x + direction_position[0] -
	  (current_level / 2 + 1) + index_position < server->map.width &&
	  client->direction.position_y + direction_position[1] >= 0 &&
	  client->direction.position_y + direction_position[1] <
	  server->map.height)
	check_content_case(server, client, client->direction.position_x +
			   direction_position[0] -
			   (current_level / 2 + 1) + index_position,
			   client->direction.position_y +
			   direction_position[1]);
      if (index_position + 1 < current_level * 2 + 1)
	make_request(NULL, ",");
    }
}

void			check_first_line(t_server *server, t_client *client)
{
  int			marker;

  marker = 0;
  map_list(server->map.map[client->direction.position_y]
	   [client->direction.position_x],
	   loop_items_on_case, (void *)&marker);
  check_player_at_position(server, client, client->direction.position_x,
			   client->direction.position_y);
  make_request(NULL, ",");
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
					   t_client *client,
					   char *arg)
{
  int			direction_position[2];
  int			index_level_client;

  (void)arg;
  printf("client position voir : %d %d\n", client->direction.position_x,
	 client->direction.position_y);
  make_request(NULL, NULL);
  direction_position[0] = 0;
  direction_position[1] = 0;
  direction_see(client, &direction_position[0], &direction_position[1]);
  make_request(NULL, "{");
  check_first_line(server, client);
  for (index_level_client = 1; index_level_client <= client->level;
       index_level_client++)
    check_line(server, client, index_level_client, direction_position);
  make_request(NULL, "}\n");
  make_request(client, NULL);
}
