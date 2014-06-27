/*
** run_server.c for zappy in /home/delafo_b/Projets/Zappy/server/src
**
** Made by Brieuc
** Login   <delafo_b@epitech.net>
**
** Started on  Thu May 15 13:21:25 2014 Brieuc
** Last update Wed May 28 15:51:03 2014 Brieuc de La Fouchardiere
*/

#include "server.h"

int                     g_server_run = 1;

void			server_loop(t_server *server)
{
  struct timeval	tv;
  int			rv;

  while (g_server_run == 1)
    {
      init_fd_socket(server);
      /* map_list(server->clients, map_cycle_action, (void*)server); */
      tv.tv_sec = TIMEOUT_SEC;
      tv.tv_usec = TIMEOUT_USEC;
      rv = select(server->fd_max + 1, &server->readfd, &server->writefd, NULL, &tv);
      if (rv >= 0)
	{
	  map_list_with_stop(server->clients,
			     map_check_read_client, (void *)server);
	  map_list_with_stop(server->clients,
	  		     map_check_write_client, (void *)server);

	  check_connect_client(server);
	}
      if (g_server_run == 0)
	{
	  printf("Timeout ! Connection not established\n");
	  return ;
	}
    }
}
