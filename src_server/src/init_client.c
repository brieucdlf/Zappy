#include "server.h"

void			free_client(void *arg)
{
  t_client		*client;

  client = (t_client *)arg;
  free(client);
}

void			add_new_client(t_server *server,
				       int fd_socket, int id_team)
{
  t_client		*new_client;

  if ((new_client = malloc(sizeof(t_client))) == NULL)
    return ;
  new_client->fd_socket = fd_socket;
  new_client->id_team = id_team;
  new_client->level = 0;
  memset(new_client->buffer.buffer_read, 0, 2048);
  new_client->buffer.index_read_buffer = 0;
  memset(new_client->items, 0, sizeof(int) * 6);
  list_push(&server->clients, new_client, free_client);
}
