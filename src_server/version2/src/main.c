#include "server.h"

int			main(int argc, char **argv)
{
  t_server		server;

  set_param(argc, argv, &server.param_server);
  if (create_server(&server) != 0)
    {
      printf("Error creation server.\n");
      return (1);
    }
  return (0);
}
