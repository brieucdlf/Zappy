/*
** manage_graphic_client.c for zappy in /home/hillai_a/Modules/githubRepo/Zappy/src_server/src/graphic_client
**
** Made by Remi Hillairet
** Login   <hillai_a@epitech.net>
**
** Started on  Tue Jul  1 17:17:49 2014 Remi Hillairet
** Last update Fri Jul  4 11:53:57 2014 Remi Hillairet
*/

#include "graphic_client.h"

int	check_is_graphic_client(t_server *server, t_client *client, char *command)
{
  if (command != NULL && !strcmp("GRAPHIC\n", command))
    {
      server->graphic_client = client;
      list_remove_with_data(&server->clients, client, match_fd_socket_client);
      init_graphic_client(server);
      return (1);
    }
  return (0);
}

void		content_at_pos(t_server *server, int x, int y, char *command)
{
  t_list	*current_list;
  int		nb_item[7];
  t_item	*item;

  memset(nb_item, 0, 7);
  current_list = server->map.map[y][x];
  while (current_list != NULL)
    {
      if ((item = current_item->data) != NULL)
	++nb_item[item->type];
      current_list = current_list->next;
    }
  memset(command, 0, 100);
  sprintf(command, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
	  nb_item[0], nb_item[1],0 nb_item[2], nb_item[3],
	  nb_item[4], nb_item[5], nb_item[6]);
}

void	create_map_task(t_server *server, char *command)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (y < server->map.height)
    {
      while (x < server->map.width)
	{
	  content_at_pos(server, x, y, command);
	  create_new_write_task(server->graphic_client, command);
	  x++;
	}
      y++;
    }
}

void	init_graphic_client(t_server *server)
{
  int	i;
  int	x;
  int	y;
  char	*command;

  x = 0;
  y = 0;
  i = 0;
  if ((command = malloc(100)) == NULL)
    return ;
  memset(command, 0, 100);
  sprintf(command, "msz %d %d\n", server->map.width, server->map.height);
  create_new_write_task(server->graphic_client, command);
  memset(command, 0, 100);
  sprintf(command, "sgt %d\n", server->param_server.execution_time);
  create_map_task(server, command);
  while (teams_names[i] != NULL)
    {
      memset(command, 0, 100);
      sprintf(command, "tna %s\n", teams_names[i]);
      create_new_write_task(server->graphic_client, command);
      i++;
    }
  free(command);
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
  char	buffer[2048];

  if (FD_ISSET(server->graphic_client->fd_socket,
	       &server->graphic_client->readfd))
    {
      memset(buff, 0, 2048);
    }
  return (0);
}

int		check_graphic_client_write(t_server *server, t_client *client)
{
  t_write_task	*head_task;

  ret = 0;
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
