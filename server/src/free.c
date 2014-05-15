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

void			free_server(t_server *server)
{
  free_double_array(server->param_server.teams_names);
  free_double_array(server->client_commands);
  free_double_array(server->map.map);
  close(server->fd_socket);
}
