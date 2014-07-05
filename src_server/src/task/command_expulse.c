#include "server.h"

void			map_expulse_player(t_list *current_client, void *player)
{
  char			*command;

  if (current_client == NULL || current_client->data == NULL || player == NULL ||
      (command = malloc(16)) == NULL)
    return ;
  if (((t_client *)current_client->data)->direction.position_x ==
      ((t_client *)player)->direction.position_x &&
      ((t_client *)current_client->data)->direction.position_y ==
      ((t_client *)player)->direction.position_y)
    {
      sprintf(command, "direction :%d\n",
	      ((t_client *)player)->direction.orientation);
      create_new_write_task(((t_client *)current_client->data), command);
    }
  free(command);
}

void		        expulse_task_function(t_server *server,
					      t_client *client,
					      char *arg)
{
  (void)arg;
  map_list(server->clients, map_expulse_player,
(void *)client);
}
