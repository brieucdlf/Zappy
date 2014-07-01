#include "server.h"

void			default_teams(t_server *server)
{
  int			index;

  if ((server->param_server.teams_names = malloc(sizeof(char *) * 9)) == NULL)
    return ;
  for (index = 0; index < 9; index++)
    {
      if ((server->param_server.teams_names[index] = malloc(6)) == NULL)
	{
	  server->param_server.teams_names = NULL;
	  return ;
	}
      sprintf(server->param_server.teams_names[index], "team%d", index);
      printf("current team : %s\n", server->param_server.teams_names[index]);
    }
}

void			manage_teams(t_server *server)
{
  if (server->param_server.teams_names == NULL)
    default_teams(server);
}
