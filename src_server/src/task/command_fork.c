#include "server.h"

void		        fork_task_function(t_server *server,
					   t_client *client,
					   char *arg)
{
  (void)server;
  (void)client;
  (void)arg;
  printf("fork\n");
  create_new_write_task(client, "OK\n");
}
