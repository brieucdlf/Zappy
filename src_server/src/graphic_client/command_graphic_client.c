#include "server.h"

void		connect_client_to_graphic(t_list *elem, void *arg)
{
  char		*command;
  t_client	*client;
  t_server	*server;

  client = (t_client*)elem->data;
  server = (t_server*)arg;
  if (server->graphic_client == NULL || (command = malloc(100)) == NULL)
    return ;
  memset(command, 0, 100);
  sprintf(command, "pnw %d %d %d %d %d %s\n", client->id_client,
	  client->direction.position_x,
	  client->direction.position_y,
	  client->direction.orientation,
	  client->level,
	  server->param_server.teams_names[client->id_team]);
  create_new_write_task(server->graphic_client, command);
  free(command);
}

void		content_at_pos(t_server *server, int x, int y, char *command)
{
  t_list	*current_item;
  int		nb_item[7];
  t_item	*item;

  nb_item[0] = 0;
  nb_item[1] = 0;
  nb_item[2] = 0;
  nb_item[3] = 0;
  nb_item[4] = 0;
  nb_item[5] = 0;
  nb_item[6] = 0;
  current_item = server->map.map[y][x];
  while (current_item != NULL)
    {
      if ((item = current_item->data) != NULL)
	++nb_item[item->type];
      current_item = current_item->next;
    }
  memset(command, 0, 100);
  sprintf(command, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
	  nb_item[0], nb_item[1], nb_item[2], nb_item[3],
	  nb_item[4], nb_item[5], nb_item[6]);
}

void	create_map_task(t_server *server, char *command)
{
  int	x;
  int	y;

  y = 0;
  while (y < server->map.height)
    {
      x = 0;
      while (x < server->map.width)
	{
	  content_at_pos(server, x, y, command);
	  create_new_write_task(server->graphic_client, command);
	  x++;
	}
      y++;
    }
}

void	deconnection_graphic_client(t_server *server)
{
  printf("\033[31mDeconnection graphic client [%d]\033[00m\n",
	 server->graphic_client->fd_socket);
  close(server->graphic_client->fd_socket);
  server->fd_max = server->fd_socket;
  map_list(server->clients, update_max_fd_socket, (void *)server);
  free_client(server->graphic_client);
  server->graphic_client = NULL;
}
