#include "client.h"

int			main(int argc, char **argv)
{
  t_client		client;

  (void)argc;
  (void)argv;
  if (connect_server(&client, "10.10.253.93", 65510) == -1)
    return (1);
  main_loop_client(&client);
  return (0);
}
