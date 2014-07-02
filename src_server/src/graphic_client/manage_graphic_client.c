/*
** manage_graphic_client.c for zappy in /home/hillai_a/Modules/githubRepo/Zappy/src_server/src/graphic_client
**
** Made by Remi Hillairet
** Login   <hillai_a@epitech.net>
**
** Started on  Tue Jul  1 17:17:49 2014 Remi Hillairet
** Last update Wed Jul  2 16:42:54 2014 Remi Hillairet
*/

#include "graphic_client.h"

int	check_graphic_client_read(t_server *server)
{
  char	buffer[2048];

  if (FD_ISSET(server->graphic_client->fd_socket, &server->graphic_client->readfd))
    {
      memset(buff, 0, 2048);
    }
  return (0);
}

int	check_graphic_client_write(t_server *server)
{

  return (0);
}
