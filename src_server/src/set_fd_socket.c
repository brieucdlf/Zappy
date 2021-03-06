#include "server.h"

void			set_fd_client(t_list *current_item, void *arg)
{
  t_server		*server;
  t_client		*client;

  server = (t_server *)arg;
  client = (t_client *)current_item->data;
  FD_SET(client->fd_socket, &server->readfd);
  FD_SET(client->fd_socket, &server->writefd);
}

void			init_fd_socket(t_server *server)
{
  FD_ZERO(&server->readfd);
  FD_ZERO(&server->writefd);
  FD_SET(server->fd_socket, &server->readfd);
  FD_SET(server->fd_socket, &server->writefd);
  if (server->graphic_client != NULL)
    {
      FD_SET(server->graphic_client->fd_socket, &server->readfd);
      FD_SET(server->graphic_client->fd_socket, &server->writefd);
    }
  map_list(server->clients, set_fd_client, (void *)server);
}
