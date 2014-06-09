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
      if ((write(client->fd_socket, "OK\n", 3)) <= 0)
	{
	  printf("\033[31mDeconnection client [%d]\033[00m\n", client->fd_socket);
	  deconnection_client(server, client);
	  printf("new fd max : %d\n", server->fd_max);
	  return (0);
	}
    }
  return (1);
}

void			map_action_client(t_list *current_client, void *arg)
{
  (void)current_client;
  (void)arg;
}
