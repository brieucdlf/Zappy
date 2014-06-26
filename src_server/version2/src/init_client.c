#include "server.h"

void			free_client(void *arg)
{
  t_player		*client;

  client = (t_player *)arg;
  free(client);
}

void			add_new_client(t_server *server,
				       int fd_socket, int id_team)
{
  t_player		*new_client;

  if ((new_client = malloc(sizeof(t_player))) == NULL)
    return ;
  new_client->fd_socket = fd_socket;

  new_client->position.x = 0;
  new_client->position.y = 0;

  new_client->id_team = id_team;
  new_client->level = 0;
  list_push(&server->clients, new_client, free_client);
}
