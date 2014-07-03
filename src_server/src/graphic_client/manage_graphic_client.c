/*
** manage_graphic_client.c for zappy in /home/hillai_a/Modules/githubRepo/Zappy/src_server/src/graphic_client
**
** Made by Remi Hillairet
** Login   <hillai_a@epitech.net>
**
** Started on  Tue Jul  1 17:17:49 2014 Remi Hillairet
** Last update Thu Jul  3 16:03:31 2014 Remi Hillairet
*/

#include "graphic_client.h"

int	check_is_graphic_client(t_server *server, t_client *client, char *command)
{
  if (command != NULL && !strcmp("GRAPHIC\n", command))
    {
      server->graphic_client = client;
      list_remove_with_data(&server->clients, client, match_fd_socket_client);
      return (1);
    }
  return (0);
}

void	content_at_pos(t_server *server, int x, int y, char *command)
{
  memset(command, 0, 100);
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
  int	x;
  int	y;
  char	*command;

  x = 0;
  y = 0;
  if ((command = malloc(100)) == NULL)
    return ;
  memset(command, 0, 100);
  sprintf(command, "msz %d %d\n", server->map.width, server->map.height);
  create_new_write_task(server->graphic_client, command);
  memset(command, 0, 100);
  sprintf(command, "sgt %d\n", server->param_server.execution_time);
  create_map_task(server, command);
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

int	check_graphic_client_write(t_server *server)
{

  return (0);
}

int	manage_graphic_client(t_server *server)
{
  if (server->graphic_client == NULL)
    return (0);

  return (1);
}
