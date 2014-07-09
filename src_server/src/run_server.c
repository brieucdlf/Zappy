/*
** run_server.c for zappy in /home/delafo_b/Projets/Zappy/server/src
**
** Made by Brieuc
** Login   <delafo_b@epitech.net>
**
** Started on  Thu May 15 13:21:25 2014 Brieuc
** Last update Fri Jul  4 12:40:41 2014 Remi Hillairet
*/

#include "server.h"

int                     g_server_run = 1;

void			signalHandler(int signal)
{
  if(signal == SIGINT)
    {
      static unsigned short nbSignal = 0;
      nbSignal++;
      if (nbSignal == 1)
	printf("[\033[32m+\033[0m] Handle again to down the server\n");
      if(nbSignal == 2)
	{
	  printf("[\033[31m-\033[0m] Server down\n");
	  g_server_run = 0;
	}
    }
}

void			server_loop(t_server *server)
{
  struct timeval	tv;
  struct sigaction	action, oldAction;
  int			rv;

  while (g_server_run == 1)
    {
      action.sa_handler = signalHandler;
      sigemptyset(&action.sa_mask);
      action.sa_flags = SA_RESTART;
      sigaction(SIGINT, &action, &oldAction);
      init_fd_socket(server);
      tv.tv_sec = TIMEOUT_SEC;
      tv.tv_usec = TIMEOUT_USEC;
      rv = select(server->fd_max + 1, &server->readfd,
		  &server->writefd, NULL, &tv);
      if (rv >= 0)
	{
	  map_list_with_stop(server->clients,
			     map_check_read_client, (void *)server);
	  map_list_with_stop(server->clients,
	  		     map_check_write_client, (void *)server);
	  manage_graphic_client(server);
	  check_connect_client(server);
	  check_timer(server);
	}
      if (g_server_run == 0)
	{
	  printf("[\033[31m-\033[0m] Timeout ! Connection not established\n");
	  return ;
	}
      usleep(100);
    }
}

