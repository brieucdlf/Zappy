#include "server.h"

int			map_check_write_client(t_list *current_client,
					       void *arg)
{
  t_server		*server;
  t_client		*client;

  if (current_client == NULL || current_client->data == NULL || arg == NULL)
    return (1);
  server = (t_server *)arg;
  client = (t_client *)current_client->data;
  if (FD_ISSET(client->fd_socket, &(server->writefd)))
    {
      printf("write ok client ok\n");
    }
  return (1);
}
