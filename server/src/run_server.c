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

  server = (t_server *)arg;
  client = (t_client *)current_item->data;
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

  tv.tv_usec = server->param_server.execution_time;
  while (g_server_run == 1)
    {
      init_fd_socket(server);
      map_list(server->clients, map_cycle_action, (void*)server);
      if ((select(server->fd_max + 1, &server->readfd,
		  &server->writefd, server->exceptfd, &tv)) != -1)
	{
	  //check read socket
	  //check write socket
	  check_connect_client(server);
	}
      if (g_server_run == 0)
	return ;
    }
}
