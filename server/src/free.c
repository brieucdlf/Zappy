#include "server.h"

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

}

void			free_server(t_server *server)
{
  free_double_array(server->param_server.teams_names);
  free_double_array(server->client_commands);
  free_double_array(server->map.map);
  if (server->fd_socket == 0)
    close(server->fd_socket);
)
