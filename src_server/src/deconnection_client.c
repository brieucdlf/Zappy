#include "server.h"

int			match_fd_socket_client(void *client1, void *client2)
{
  if (client1 == NULL || client2 == NULL)
    return (1);
  if (((t_client *)client1)->fd_socket == ((t_client *)client2)->fd_socket)
    return (0);
  return (1);
}

void			update_max_fd_socket(t_list *current_client,
					     void *server)
{
  if (current_client == NULL || current_client->data == NULL || server == NULL)
    return ;
  if (((t_server *)server)->fd_max <
      ((t_client *)current_client->data)->fd_socket)
    ((t_server *)server)->fd_max = ((t_client *)current_client->data)
      ->fd_socket;
}

void			deconnection_client(t_server *server,
					    t_client *current_client)
{
  printf("\033[31mDeconnection client [%d]\033[00m\n",
	 current_client->fd_socket);
  close(current_client->fd_socket);
  list_remove_with_data(&server->clients, current_client,
			match_fd_socket_client);
  server->fd_max = server->fd_socket;
  map_list(server->clients, update_max_fd_socket, (void *)server);
  if (server->graphic_client != NULL
      && (server->fd_max < server->graphic_client->fd_socket))
    server->fd_max = server->graphic_client->fd_socket;
}
