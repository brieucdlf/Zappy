#include "server.h"

void			server_loop(t_server *server)
{
  struct timeval	tv;
  int			rv;

  server->is_run = 0;
  while (server->is_run)
    {
      init_fd_socket(server);
      tv.tv_sec = TIMEOUT_SEC;
      tv.tv_usec = TIMEOUT_USEC;
      rv = select(server->fd_max + 1, &server->readfd, &server->writefd, NULL, &tv);
      if (rv >= 0)
	{
	}
    }
}
