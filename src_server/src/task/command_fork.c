#include "task.h"

void		        fork_task_function(void *server, void *client)
{
  (void)server;
  (void)client;
  printf("fork\n");
}
