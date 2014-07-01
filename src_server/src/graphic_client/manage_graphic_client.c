/*
** manage_graphic_client.c for zappy in /home/hillai_a/Modules/githubRepo/Zappy/src_server/src/graphic_client
**
** Made by Remi Hillairet
** Login   <hillai_a@epitech.net>
**
** Started on  Tue Jul  1 17:17:49 2014 Remi Hillairet
** Last update Tue Jul  1 17:39:19 2014 Remi Hillairet
*/

#include "graphic_client.h"

void	init_graphic_fd_socket(t_server *server)
{
  FD_ZERO();

}

int	manage_graphic_client(t_server *server)
{
  init_graphic_fd_socket();
  select();
  return (0);
}
