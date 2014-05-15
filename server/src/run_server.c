/*
** run_server.c for zappy in /home/delafo_b/Projets/Zappy/server/src
** 
** Made by Brieuc
** Login   <delafo_b@epitech.net>
** 
** Started on  Thu May 15 13:21:25 2014 Brieuc
** Last update Thu May 15 13:33:24 2014 Brieuc
*/

#include "server.h"

int                     g_server_run = 1;

void			server_loop(t_server *server)
{
  /* Ici select */
  while (g_server_run)
    {
      if (g_server_run == 0)
	return ;
    }
}
