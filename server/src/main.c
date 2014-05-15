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

int			socket_init(t_server *server)
{
  struct protoent       *pe;
  struct sockaddr_in    sin;

  sin.sin_family = AF_INET;
  sin.sin_port = htons(server->param_server.port);
  sin.sin_addr.s_addr = INADDR_ANY;
  pe = getprotobyname("TCP");
  if (!pe)
    exit(EXIT_FAILURE);
  server->fd_socket = xsocket(AF_INET, SOCK_STREAM, pe->p_proto);
  xbind(server->fd_socket, (const struct sockaddr *)&sin, sizeof(sin));
  xlisten(server->fd_socket, 50);
  return (server->fd_socket);
}

int		main(int ac, char **av)
{
  t_server      server;

  init_map(&server.map);
  set_param(ac, av, &server.param_server);
  socket_init(&server);
  free_double_array(server.param_server.teams_names);
  return (0);
}
