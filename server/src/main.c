/*
** main.c for zappy in /Users/remihillairet/Epitech/Github/Zappy/server
**
** Made by remi hillairet
** Login   <remihillairet@epitech.net>
**
** Started on  Tue May  13 10:45:33 2014 remi hillairet
** Last update Thu May 15 17:39:47 2014 romain combe
*/

#include "user.h"
#include "server.h"

int		main(int ac, char **av)
{
  t_server      server;

  init_map(&server.map);
  set_param(ac, av, &server.param_server);
  if (socket_init(&server) == -1)
    return (1);
  if (init_commands(&server) == -1)
    {
      close(server.fd_socket);
      return (1);
    }
  init_action_ptr(&server);
  free_server(&server);
  return (0);
}
