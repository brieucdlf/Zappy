#include "server.h"

void			query_first_connection(t_server *server,
					       t_client *current_client)
{
  char			*command;

  if ((command = malloc(100)) == NULL)
    return ;
  memset(command, 0, 100);
  sprintf(command, "%d\n", current_client->id_client);
  create_new_write_task(current_client, command);
  memset(command, 0, 100);
  sprintf(command, "%d %d\n", server->map.width,
	  server->map.height);
  create_new_write_task(current_client, command);
  free(command);
}

void			init_position_client(t_client *current_client,
					     t_server *server)
{
  char			*command;

  current_client->direction.position_x = rand() % server->map.width;
  current_client->direction.position_y = rand() % server->map.height;
  current_client->direction.orientation = MAP_DIRECTION_ORIENTATION_NORTH;
  if (server->graphic_client == NULL || (command = malloc(100)) == NULL)
    return ;
  memset(command, 0, 100);
  sprintf(command, "pnw %d %d %d %d %d %s\n", current_client->id_client,
	  current_client->direction.position_x,
	  current_client->direction.position_y,
	  current_client->direction.orientation,
	  current_client->level,
	  server->param_server.teams_names[current_client->id_team]);
  create_new_write_task(server->graphic_client, command);
  free(command);
}
