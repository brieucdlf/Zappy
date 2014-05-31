#include "client.h"

int			main(int argc, char **argv)
{
  t_client		client;

  (void)argc;
  (void)argv;
  if (connect_server(&client, "127.0.0.1", 65510) == -1)
    return (1);
  main_loop_client(&client);
  return (0);
}
