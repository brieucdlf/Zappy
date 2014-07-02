/*
** main.c for zappy in /Users/remihillairet/Epitech/Github/Zappy/server
**
** Made by remi hillairet
** Login   <remihillairet@epitech.net>
**
** Started on  Tue May  13 10:45:33 2014 remi hillairet
** Last update Tue Jun 10 10:50:36 2014 romain combe
*/

#include "user.h"
#include "server.h"

void		init_server(t_server *server)
{
  server->clients = NULL;
  server->client_commands = NULL;
  server->fd_max = 0;
}

int		main(int ac, char **av)
{
  t_server      server;

  init_server(&server);
  set_param(ac, av, &server.param_server);
  init_map(&server);
  manage_teams(&server);
  if (create_server(&server) == -1)
    return (1);
  printf("Initialisation server completed\n");
  server_loop(&server);
  free_server(&server);
  return (0);
}
