#include "server.h"

int			get_id_team(t_server *server, const char *team)
{
  int			index;
  char			*team_name;

  if (team_name == NULL || (team_name = strtok(team, "\n")) == NULL)
    return (-1);
  for (index = 0; server->param_server.teams_names[index] != NULL; index++)
    {
      if (strcmp(server->param_server.teams_names[index], team) == 0)
	{
	  printf("[+]\033[42mTeam player :\033[0m%s\n",
		 server->param_server.teams_names[index]);
	  return (index);
	}
    }
  return (-1);
}

void			default_teams(t_server *server)
{
  int			index;

  if ((server->param_server.teams_names = malloc(sizeof(char *) * 10)) == NULL)
    return ;
  for (index = 0; index < 9; index++)
    {
      if ((server->param_server.teams_names[index] = malloc(7)) == NULL)
	{
	  server->param_server.teams_names = NULL;
	  return ;
	}
      sprintf(server->param_server.teams_names[index], "team%d", index);
    }
  server->param_server.teams_names[index] = NULL;
}

void			display_team_tab(char **map)
{
  int			index;

  for (index = 0; map[index] != NULL; index++)
    {
      printf("team = [%s]\n", map[index]);
    }
}

void			manage_teams(t_server *server)
{
  if (server->param_server.teams_names == NULL)
    default_teams(server);
  display_team_tab(server->param_server.teams_names);
}
