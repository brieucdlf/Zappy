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
    ((t_server *)server)->fd_max =
      ((t_client *)current_client->data)->fd_socket;
}

void				send_dead_to_graphic_client(t_server *server,
							    t_client *client)
{
  char			*command;

  if (server->graphic_client == NULL || (command = malloc(100)) == NULL)
    return ;
  memset(command, 0, 100);
  snprintf(command, 100, "pdi %d\n", client->id_client);
  create_new_write_task(server->graphic_client, command);
  free(command);
}

void			deconnection_client(t_server *server,
					    t_client *current_client)
{
  printf("[\033[31m-\033[0m]Deconnection client [%d]\n",
	 current_client->fd_socket);
  send_dead_to_graphic_client(server, current_client);
  close(current_client->fd_socket);
  list_remove_with_data(&server->clients, current_client,
			match_fd_socket_client);
  server->fd_max = server->fd_socket;
  map_list(server->clients, update_max_fd_socket, (void *)server);
  if (server->graphic_client != NULL
      && (server->fd_max < server->graphic_client->fd_socket))
    server->fd_max = server->graphic_client->fd_socket;
}
