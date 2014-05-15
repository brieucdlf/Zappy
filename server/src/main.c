/*
** main.c for zappy in /Users/remihillairet/Epitech/Github/Zappy/server
**
** Made by remi hillairet
** Login   <remihillairet@epitech.net>
**
** Started on  Tue May  13 10:45:33 2014 remi hillairet
** Last update Tue May 13 17:48:59 2014 Brieuc
*/

#include "user.h"
#include "server.h"

void		        test_list();

int			socket_init(t_server *server, char **av)
{
  struct protoent       *pe;
  struct sockaddr_in    sin;
  int                   fd;

  server->port = atoi(av[1]);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(server->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  pe = getprotobyname("TCP");
  if (!pe)
    exit(EXIT_FAILURE);
  fd = xsocket(AF_INET, SOCK_STREAM, pe->p_proto);
  xbind(fd, (const struct sockaddr *)&sin, sizeof(sin));
  /* Liste d'attente : a voir*/
  xlisten(fd, 50);
  return (fd);
}

int			main(int ac, char **av)
{
  t_server		*server;
  int			fd;

  if (ac == 2)
    {
      fd = socket_init(server, av);
    }
  test_list();
  return (0);
}
