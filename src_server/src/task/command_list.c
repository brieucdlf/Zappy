#include "server.h"

void			position_change(t_server *server, t_client *client)
{
  char			*command;

  if (server->graphic_client == NULL || server->index_task_graphic > 0 ||
      (command = malloc(100)) == NULL)
    return ;
  memset(command, 0, 100);
  sprintf(command, "ppo %d %d %d %d\n", client->id_client,
	  client->direction.position_x, client->direction.position_y,
	  client->direction.orientation);
  create_new_write_task(server->graphic_client, command);
  free(command);
}

void			avance_task_function(t_server *server,
					     t_client *client,
					     char *arg)
{
  (void)arg;
  if (client->direction.orientation == MAP_DIRECTION_ORIENTATION_NORTH)
    client->direction.position_y -= 1;
  else if (client->direction.orientation == MAP_DIRECTION_ORIENTATION_SOUTH)
    client->direction.position_y += 1;
  else if (client->direction.orientation == MAP_DIRECTION_ORIENTATION_WEST)
    client->direction.position_x -= 1;
  else
    client->direction.position_x += 1;
  if (client->direction.position_x >= server->map.width)
    client->direction.position_x = 0;
  if (client->direction.position_x < 0)
    client->direction.position_x = server->map.width - 1;
  if (client->direction.position_y >= server->map.height)
    client->direction.position_y = 0;
  if (client->direction.position_y < 0)
    client->direction.position_y = server->map.height - 1;
  create_new_write_task(client, "OK\n");
  position_change(server, client);
}

void			droite_task_function(t_server *server,
					     t_client *client,
					     char *arg)
{
  (void)server;
  (void)arg;
  client->direction.orientation += 1 % 4;
  create_new_write_task(client, "OK\n");
  position_change(server, client);
}

void			gauche_task_function(t_server *server,
					     t_client *client,
					     char *arg)
{
  (void)server;
  (void)arg;
  client->direction.orientation -= 1;
  if (client->direction.orientation < 0)
    client->direction.orientation = 3;
  create_new_write_task(client, "OK\n");
  position_change(server, client);
}

void			inventaire_task_function(t_server *server,
						 t_client *client,
						 char *arg)
{
  char			*inventaire;

  (void)server;
  (void)arg;
  if ((inventaire = malloc(1024)) == NULL)
    return ;
  memset(inventaire, 0, 1024);
  sprintf(inventaire, "{nourriture %d, linemate %d, deraumere %d, sibur %d,\
 mendiane %d, phiras %d, thystane %d}\n", client->items[0], client->items[1],
	  client->items[2], client->items[3], client->items[4],
	  client->items[5], client->items[6]);
  create_new_write_task(client, inventaire);
  free(inventaire);
}
