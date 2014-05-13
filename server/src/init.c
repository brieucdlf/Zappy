#include "server.h"

void	set_param(int ac, char **av, t_param *param)
{
  char	optstring[]="p:x:y:n:c:t:";
  int	i;

  while ((i = getopt(argc, argv, optstring)) != EOF)
    {
      if (i == p)
	param->port = atoi(optarg);
      else if (i == x)
	param->world_width = atoi(optarg);
      else if (i == y)
	param->world_height = atoi(optarg);
      else if (i == n)
	printf("%s\n" optarg);

    }
  // on affiche le premier argument.
  printf("%s\n",argv[optind]);

  return 0;
}

void	set_map()
{

}