/*
** command.c for zappy in /Users/remihillairet/Epitech/Github/Zappy/server
**
** Made by remi hillairet
** Login   <remihillairet@epitech.net>
**
** Started on  Tue May  13 11:54:47 2014 remi hillairet
** Last update Tue May  13 11:54:47 2014 remi hillairet
*/

#include "server.h"

int	init_commands(t_server *server)
{
  if ((server->client_commands = malloc(13 * sizeof(char *))) == NULL)
    return (-1);
  server->client_commands[0] = strdup("avance\n");
  server->client_commands[1] = strdup("droite\n");
  server->client_commands[2] = strdup("gauche\n");
  server->client_commands[3] = strdup("voir\n");
  server->client_commands[4] = strdup("inventaire\n");
  server->client_commands[5] = strdup("prend objet\n");
  server->client_commands[6] = strdup("pose objet\n");
  server->client_commands[7] = strdup("expulse\n");
  server->client_commands[8] = strdup("broadcast texte\n");
  server->client_commands[9] = strdup("incantation\n");
  server->client_commands[10] = strdup("fork\n");
  server->client_commands[11] = strdup("connect_nbr\n");
  server->client_commands[12] = NULL;
  return (0);
}

void 	init_action_ptr(t_server *server)
{
  server->action_ptr[0] = action_move;
  server->action_ptr[1] = action_rigth;
  server->action_ptr[2] = action_left;
  server->action_ptr[3] = action_see;
  server->action_ptr[4] = action_inventary;
  server->action_ptr[5] = action_take_object;
  server->action_ptr[6] = action_drop_object;
  server->action_ptr[7] = action_push;
  server->action_ptr[8] = action_broadcast;
  server->action_ptr[9] = action_incantation;
  server->action_ptr[10] = action_fork;
  server->action_ptr[11] = action_connect_nbr;
}

void		init_action_client(t_server *server, t_client *current_client,
				   int current_action)
{

  current_client->action.type = current_action + 1;
  current_client->action.action_fct = server->action_ptr[current_action];
  set_timer(current_client);
}


int	get_command(t_server *server, t_client *current_client, char *command)
{
  int   i;

  i = 0;
  while (server->client_commands[i])
    {
      if (strcmp(server->client_commands[i], command) == 0)
	{
	  init_action_client(server, current_client, i);
	  return (0);
	}
      i++;
    }
  return (0);
}
