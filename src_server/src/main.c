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

  srand(time(NULL));
  init_server(&server);
  set_param(ac, av, &server.param_server);
  if (init_map(&server) != 0)
    return (1);
  manage_teams(&server);
  if (create_server(&server) == -1)
    return (1);
  printf("Initialisation server completed\n");
  server_loop(&server);
  free_server(&server);
  return (0);
}
