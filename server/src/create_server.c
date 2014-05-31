#include "server.h"

void			init_struct_addr(struct sockaddr_in *sin,
					 int port)
{
  sin->sin_family = AF_INET;
  sin->sin_port = htons(port);
  sin->sin_addr.s_addr = INADDR_ANY;
}

int			listen_socket(t_server *server)
{
  if (listen(server->fd_socket, 10) == -1)
    {
      perror("listen");
      close(server->fd_socket);
      return (-1);
    }
  return (0);
}

void			sigpipe(int signal)
{
  (void)signal;
}

int			create_server(t_server *server)
{
  struct sockaddr_in	sin;
  struct protoent	*p;

  if ((p = getprotobyname("TCP")) == NULL)
    {
      perror("getprotobyname");
      return (-1);
    }
  if ((server->fd_socket = socket(AF_INET, SOCK_STREAM, p->p_proto)) == -1)
    {
      perror("socket");
      return (-1);
    }
  signal(SIGPIPE, sigpipe);
  init_struct_addr(&sin, server->param_server.port);
  server->fd_max = server->fd_socket;
  if (bind(server->fd_socket, (const struct sockaddr *)(&sin),
		       sizeof(sin)) == -1)
    {
      perror("bind");
      close(server->fd_socket);
      return (-1);
    }
  return (listen_socket(server));
}
