#include "server.h"

void			free_double_array_delimiter(char **tab,
						    unsigned int height)
{
  unsigned int			index_height;

  if (tab == NULL)
    return ;
  for (index_height = 0; index_height < height; index_height++)
    free(tab[index_height]);
  free(tab);
}

void			free_double_array(char **tab)
{
  int			index;

  if (tab == NULL)
    return ;
  index = 0;
  while (tab[index] != NULL)
    free(tab[index++]);
  free(tab);
}

void			close_client_socket(t_list *current_client, void *arg)
{
  (void)arg;
  close(((t_client *)current_client->data)->fd_socket);
}

void			free_map_server(t_server *server)
{
  int			index_position_x;
  int			index_position_y;

  for (index_position_y = 0; index_position_y < server->map.height;
       index_position_y++)
    {
      for (index_position_x = 0; index_position_x < server->map.width;
	   index_position_x++)
	list_delete(server->map.map[index_position_y][index_position_x]);
      free(server->map.map[index_position_y]);
    }
  free(server->map.map);
}

void			free_server(t_server *server)
{
  free_double_array(server->param_server.teams_names);
  free_double_array(server->client_commands);
  free(server->param_server.number_client);
  if (server->fd_socket != 0)
    close(server->fd_socket);
  map_list(server->clients, close_client_socket, NULL);
  if (server->graphic_client != NULL)
    {
      close(server->graphic_client->fd_socket);
      free_client(server->graphic_client);
    }
  free_map_server(server);
}
