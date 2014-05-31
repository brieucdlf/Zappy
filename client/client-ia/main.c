#include "client.h"

int			main(int argc, char **argv)
{
  t_client		client;

  (void)argc;
  (void)argv;
  connect_server(&client, "127.0.0.1", 65510);
  return (0);
}
