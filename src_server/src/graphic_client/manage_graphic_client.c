/*
** manage_graphic_client.c for zappy in /home/hillai_a/Modules/githubRepo/Zappy/src_server/src/graphic_client
**
** Made by Remi Hillairet
** Login   <hillai_a@epitech.net>
**
** Started on  Tue Jul  1 17:17:49 2014 Remi Hillairet
** Last update Fri Jul  4 15:56:32 2014 Remi Hillairet
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
      add_new_graphic_client(server, client->fd_socket);
      list_remove_with_data(&server->clients, client, match_fd_socket_client);
      init_graphic_client(server);
      return (1);
    }
  return (0);
}

void		content_at_pos(t_server *server, int x, int y, char *command)
{
  t_list	*current_item;
  int		nb_item[7];
  t_item	*item;

  nb_item[0] = 0;
  nb_item[1] = 0;
  nb_item[2] = 0;
  nb_item[3] = 0;
  nb_item[4] = 0;
  nb_item[5] = 0;
  nb_item[6] = 0;
  current_item = server->map.map[y][x];
  while (current_item != NULL)
    {
      if ((item = current_item->data) != NULL)
	++nb_item[item->type];
      current_item = current_item->next;
    }
  memset(command, 0, 100);
  sprintf(command, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
	  nb_item[0], nb_item[1], nb_item[2], nb_item[3],
	  nb_item[4], nb_item[5], nb_item[6]);
}

void	create_map_task(t_server *server, char *command)
{
  int	x;
  int	y;

  y = 0;
  while (y < server->map.height)
    {
      x = 0;
      while (x < server->map.width)
	{
	  content_at_pos(server, x, y, command);
	  create_new_write_task(server->graphic_client, command);
	  x++;
	}
      y++;
    }
}

void	deconnection_graphic_client(t_server *server)
{
  printf("\033[31mDeconnection graphic client [%d]\033[00m\n",
	 server->graphic_client->fd_socket);
  close(server->graphic_client->fd_socket);
  server->fd_max = server->fd_socket;
  map_list(server->clients, update_max_fd_socket, (void *)server);
  server->graphic_client = NULL;
}

int	check_graphic_client_read(t_server *server)
{
  if (server == NULL)
    printf("Server is NULL\n");
  return (0);
}

int		check_graphic_client_write(t_server *server, t_client *client)
{
  t_write_task	*head_task;

  if (client->write_tasks == NULL ||
      (head_task = (t_write_task *)client->write_tasks->data) == NULL)
    return (1);
  if (FD_ISSET(client->fd_socket, &(server->writefd)))
    return (write_task_socket(head_task, client, server));
  return (1);
}

int	manage_graphic_client(t_server *server)
{
  if (server->graphic_client == NULL)
    return (0);
  check_graphic_client_write(server, server->graphic_client);
  return (1);
}
