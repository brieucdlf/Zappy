/*
** main.c for zappy in /Users/remihillairet/Epitech/Github/Zappy/server
**
** Made by remi hillairet
** Login   <remihillairet@epitech.net>
**
** Started on  Tue May  13 10:45:33 2014 remi hillairet
** Last update Mon Jun  2 18:26:57 2014 romain combe
*/

#include "user.h"
#include "server.h"

void		aff_map(t_map *map)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i < map->width)
    {
      while (j < map->height)
	{
	  printf("%d", map->map[i][j]);
	  j++;
	}
      printf("\n");
      j = 0;
      i++;
    }
}

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
  init_map(&server.map);
  printf("toto\n");
  aff_map(&server.map);
  exit(1);
  set_param(ac, av, &server.param_server);
  if (create_server(&server) == -1)
    return (1);
  if (init_commands(&server) == -1)
    {
      close(server.fd_socket);
      return (1);
    }
  init_action_ptr(&server);
  server_loop(&server);
  free_server(&server);
  return (0);
}
