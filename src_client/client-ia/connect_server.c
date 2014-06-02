#include "client.h"

void			init_sin(struct sockaddr_in *sin,
				 const int port_server,
				 struct hostent *server)
{
  memcpy(&(sin->sin_addr), server->h_addr_list[0], server->h_length);
  sin->sin_port = htons(port_server);
  sin->sin_family = AF_INET;
}

int			connect_server_socket(t_client *client)
{
  if (connect(client->fd.fd_socket,
	      (const struct sockaddr *)&(client->sin_server),
	     sizeof(client->sin_server)) == -1)
    {
      perror("connect");
      close(client->fd.fd_socket);
      return (-1);
    }
  return (0);
}

int			connect_server(t_client *client,
				       const char *addr_server,
				       int port_server)
{
  struct hostent	*server;

  if ((server = gethostbyname(addr_server)) == NULL)
    {
      fprintf(stderr, "Server not [%s] found\n", addr_server);
      return (EXIT_FAILURE);
    }
  init_sin(&(client->sin_server), port_server, server);
  if ((client->fd.fd_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      perror("socket");
      return (EXIT_FAILURE);
    }
  return (connect_server_socket(client));
}
