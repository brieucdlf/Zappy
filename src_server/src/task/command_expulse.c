#include "server.h"

void		        request_expulse(t_client *client, int type)
{
  static int		current_stat = 0;

  if (type == 0)
    {
      current_stat = 0;
      return ;
    }
  else if (type == 1)
    {
      current_stat = 1;
      return ;
    }
  else if (client != NULL)
    {
      if (current_stat == 1)
	create_new_write_task(client, "OK\n");
      else
	create_new_write_task(client, "KO\n");
    }
}

void			map_expulse_player(t_list *current_client, void *player)
{
  char			*command;

  if (current_client == NULL || current_client->data == NULL || player == NULL ||
      (command = malloc(16)) == NULL)
    return ;
  if (((t_client *)current_client->data)->id_client !=
      ((t_client *)player)->id_client &&
      ((t_client *)current_client->data)->direction.position_x ==
      ((t_client *)player)->direction.position_x &&
      ((t_client *)current_client->data)->direction.position_y ==
      ((t_client *)player)->direction.position_y)
    {
      sprintf(command, "direction :%d\n",
	      ((t_client *)player)->direction.orientation);
      create_new_write_task(((t_client *)current_client->data), command);
      request_expulse(NULL, 1);
    }
  free(command);
}

void		        expulse_task_function(t_server *server,
					      t_client *client,
					      char *arg)
{
  (void)arg;
  request_expulse(NULL, 0);
  map_list(server->clients, map_expulse_player, (void *)client);
  request_expulse(client, 2);
}
