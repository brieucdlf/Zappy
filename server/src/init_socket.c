#include "server.h"

void			catch_sigpip(int signal)
{
  (void)signal;
}

int			socket_init(t_server *server)
{
  struct protoent       *pe;
  struct sockaddr_in    sin;

  if (signal(SIGPIPE, catch_sigpip) == SIG_ERR)
    return (-1);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(server->param_server.port);
  sin.sin_addr.s_addr = INADDR_ANY;
  pe = getprotobyname("TCP");
  if (!pe)
    return (-1);
  server->fd_socket = xsocket(AF_INET, SOCK_STREAM, pe->p_proto);
  xbind(server->fd_socket, (const struct sockaddr *)&sin, sizeof(sin));
  xlisten(server->fd_socket, 50);
  return (server->fd_socket);
}
