/*
** main.c for zappy in /Users/remihillairet/Epitech/Github/Zappy/server
**
** Made by remi hillairet
** Login   <remihillairet@epitech.net>
**
** Started on  Tue May  13 10:45:33 2014 remi hillairet
** Last update Thu May 15 11:18:12 2014 Brieuc
*/

#include "user.h"
#include "server.h"

int		main(int ac, char **av)
{
  t_server      server;

  set_param(ac, av, &server.param_server);
  socket_init(&server);
  if (init_commands(&server) == -1)
    {
      close(server.fd_socket);
      return (1);
    }
  init_action_ptr(&server);
  server.fd_socket = socket_init(&server);
  free_double_array(server.param_server.teams_names);
  return (0);
}
