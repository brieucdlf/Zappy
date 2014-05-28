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
  char			buffer[512];

  tv.tv_usec = server->param_server.execution_time;
  while (g_server_run == 1)
    {
      init_fd_socket(server);
      map_list(server->clients, map_cycle_action, (void*)server);
      if ((select(server->fd_max + 1, &server->readfd,
		  &server->writefd, server->exceptfd, &tv)) == -1)
	perror("select");
      if (g_server_run == 0)
	return ;
      if (FD_ISSET(0, &server->readfd))
	{
	  memset(buffer, 0, 512);
	  read(0, buffer, 512);
	  if (strcmp(buffer, "/quit\n") == 0)
	    g_server_run = 0;
	}
      else if (FD_ISSET(server->fd_socket, &server->readfd))
	{
	  /* Read sur le client */
	}
      else
	{
	  /* on attends la co d'un client et on read */
	}

    }
}
