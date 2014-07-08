/*
** manage_graphic_client.c for zappy in /home/hillai_a/Modules/githubRepo/Zappy/src_server/src/graphic_client
**
** Made by Remi Hillairet
** Login   <hillai_a@epitech.net>
**
** Started on  Tue Jul  1 17:17:49 2014 Remi Hillairet
** Last update Mon Jul  7 19:11:04 2014 Remi Hillairet
*/

#include "graphic_client.h"

void	init_graphic_client(t_server *server)
{
  int	i;
  char	*command;

  i = 0;
  if ((command = malloc(100)) == NULL)
    return ;
  memset(command, 0, 100);
  sprintf(command, "msz %d %d\n", server->map.width, server->map.height);
  create_new_write_task(server->graphic_client, command);
  memset(command, 0, 100);
  sprintf(command, "sgt %d\n", server->param_server.execution_time);
  create_new_write_task(server->graphic_client, command);
  create_map_task(server, command);
  while (server->param_server.teams_names[i] != NULL)
    {
      memset(command, 0, 100);
      sprintf(command, "tna %s\n", server->param_server.teams_names[i]);
      create_new_write_task(server->graphic_client, command);
      i++;
    }
  free(command);
}

void		add_new_graphic_client(t_server *server, int fd_socket)
{
  t_client	*new_client;

  if ((new_client = malloc(sizeof(t_client))) == NULL)
    return ;
  new_client->tasks = NULL;
  new_client->write_tasks = NULL;
  new_client->fd_socket = fd_socket;
  new_client->id_team = -1;
  new_client->id_client = -1;
  new_client->level = -1;
  new_client->is_ready = 1;
  memset(new_client->buffer.buffer_read, 0, 2048);
  new_client->buffer.index_read_buffer = 0;
  memset(new_client->items, 0, sizeof(int) * 6);
  server->graphic_client = new_client;
  FD_SET(server->graphic_client->fd_socket, &(server->readfd));
  FD_SET(server->graphic_client->fd_socket, &(server->writefd));
}

int	check_is_graphic_client(t_server *server, t_client *client, char *command)
{
  if (command != NULL && !strcmp("GRAPHIC\n", command))
    {
      printf("add new client graphic\n");
      add_new_graphic_client(server, client->fd_socket);
      list_remove_with_data(&server->clients, client, match_fd_socket_client);
      init_graphic_client(server);
      return (1);
    }
  return (0);
}

int	manage_graphic_client(t_server *server)
{
  if (server->graphic_client == NULL)
    return (0);
  check_graphic_client_write(server, server->graphic_client);
  return (1);
}
