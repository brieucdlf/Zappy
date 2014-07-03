#include "task.h"

void		        fork_task_function(t_server *server,
					   t_client *client,
					   char *arg)
{
  (void)server;
  (void)client;
  (void)arg;
  printf("fork\n");
}
