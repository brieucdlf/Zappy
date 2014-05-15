#include "server.h"

static void		init_default_param(t_param *param_server)
{
  param_server->port = DEFAULT_PORT;
  param_server->world_width = DEFAULT_WIDTH;
  param_server->world_height = DEFAULT_HEIGTH;
  param_server->teams_names = NULL;
  param_server->nb_client_start = CLIENT_START;
  param_server->execution_time = EXECUTION_TIME;
}

static void		fill_team(t_param *param_server, char **argv)
{
  int			index;
  int			i;

  if (param_server->teams_names != NULL)
    free_double_array(param_server->teams_names);
  for (index = optind - 1; argv[index] != NULL &&
	 argv[index][0] != '-'; index++);
  if (((index - optind) + 1) == 0 ||
      (param_server->teams_names =
       malloc(sizeof(char *) * ((index - optind) + 2))) == NULL)
    return ;
  i = 0;
  for (index = optind - 1; argv[index] != NULL &&
	 argv[index][0] != '-'; index++)
    param_server->teams_names[i++] = strdup(argv[index]);
  param_server->teams_names[i] = NULL;
}

static void		fill_param(char caracter,
				   t_param *param_server, char **argv)
{
  if (caracter == 'p' && optarg != NULL)
    param_server->port = atoi(optarg);
  else if (caracter == 'x' && optarg != NULL)
    param_server->world_width = atoi(optarg);
  else if (caracter == 'y' && optarg != NULL)
    param_server->world_height = atoi(optarg);
  else if (caracter == 'c' && optarg != NULL)
    param_server->nb_client_start = atoi(optarg);
  else if (caracter == 't' && optarg != NULL)
    param_server->execution_time = atoi(optarg);
  else
    fill_team(param_server, argv);
}

void			set_param(int argc, char **argv, t_param *param_server)
{
  int			caracter;

  init_default_param(param_server);
  while ((caracter = getopt(argc, argv, ARGUMENT_PARSE)) != EOF)
    fill_param(caracter, param_server, argv);
}
