#include "server.h"

void			check_connect_client(t_server *server)
{
  int			fd_socket_client;
  struct sockaddr_in    sin_client;
  socklen_t             size_sin_client;

  if (FD_ISSET(server->fd_socket, &server->readfd))
    {
      memset(&(sin_client), 0, sizeof(sin_client));
      size_sin_client = 0;
      if ((fd_socket_client = accept(server->fd_socket,
				     (struct sockaddr *)&(sin_client),
				     &size_sin_client)) == -1)
	{
	  perror("accept");
	  return ;
	}
      add_new_client(server, fd_socket_client, 0);
      if (fd_socket_client > server->fd_socket)
	server->fd_max = fd_socket_client;
      printf("\033[32mConnection client [%d]\033[0m\n", fd_socket_client);
    }
}
