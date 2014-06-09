#include "server.h"

int			map_check_write_client(t_list *current_client,
					       void *arg)
{
  t_server		*server;
  t_client		*client;

  if ((client = (t_client *)current_client->data) == NULL ||
      current_client->data == NULL || (server = (t_server *)arg) == NULL ||
      client->action.type == NONE)
    return (1);
  if (FD_ISSET(client->fd_socket, &(server->writefd)))
    {
      if ((write(client->fd_socket, "OK\n", 3)) <= 0)
	{
	  printf("\033[31mDeconnection client [%d]\033[00m\n", client->fd_socket);
	  deconnection_client(server, client);
	  printf("new fd max : %d\n", server->fd_max);
	  return (0);
	}
      else
	printf("write client success\n");
    }
  printf("client action none\n");
  client->action.type = NONE;
  return (1);
}
