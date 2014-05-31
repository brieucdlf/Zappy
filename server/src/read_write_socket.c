#include "server.h"

int			map_check_read_client(t_list *current_client,
					      void *arg)
{
  t_server		*server;
  t_client		*client;
  int			ret;
  char			buff[512];

  if (current_client == NULL || current_client->data == NULL || arg == NULL)
    return (1);
  server = (t_server *)arg;
  client = (t_client *)current_client->data;
  if (FD_ISSET(client->fd_socket, &(server->readfd)))
    {
      memset(buff, 0, 512);
      if ((ret = read(client->fd_socket, buff, 511)) <= 0)
	{
	  printf("\033[31mDeconnection client [%d]\033[00m\n", client->fd_socket);
	  deconnection_client(server, client);
	  printf("new fd max : %d\n", server->fd_max);
	  return (0);
	}
      else
	printf("Answer client [%d] : %s\n", client->fd_socket, buff);
    }
  return (1);
}
