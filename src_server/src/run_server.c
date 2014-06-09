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

void			map_cycle_action(t_list *current_item, void *arg)
{
  t_server		*server;
  t_client		*client;

  if (current_item == NULL || current_item->data == NULL || arg == NULL)
    return ;
  server = (t_server *)arg;
  client = (t_client *)current_item->data;
  if (client->action.type == NONE)
    return ;
  check_cycle_timer(server, client);
  if (client->action.is_cycle == 0)
    {
      client->action.action_fct(server, client);
      client->action.is_cycle = 1;
      client->action.type = NONE;
      client->action.action_fct = NULL;
    }
}

void			server_loop(t_server *server)
{
  struct timeval	tv;
  int			rv;

  while (g_server_run == 1)
    {
      init_fd_socket(server);
      map_list(server->clients, map_cycle_action, (void*)server);
      tv.tv_sec = TIMEOUT_SEC;
      tv.tv_usec = TIMEOUT_USEC;
      rv = select(server->fd_max + 1, &server->readfd, &server->writefd, NULL, &tv);
      if (rv >= 0)
	{
	  map_list_with_stop(server->clients,
			     map_check_read_client, (void *)server);
	  /* map_list_with_stop(server->clients, */
	  /* 		     map_check_write_client, (void *)server); */

	  check_connect_client(server);
	}
      if (g_server_run == 0)
	{
	  printf("Timeout ! Connection not established\n");
	  return ;
	}
    }
}
