#include "task.h"

void		        prend_task_function(t_server *server,
					    t_client *client,
					    char *arg)
{
  (void)server;
  (void)client;
  (void)arg;
  printf("porend object\n");
}

void			pose_task_function(t_server *server,
					   t_client *client,
					   char *arg)
{
  (void)server;
  (void)client;
  (void)arg;
  printf("pose object\n");
}

void		        expulse_task_function(t_server *server,
					      t_client *client,
					      char *arg)
{
  (void)server;
  (void)client;
  (void)arg;
  printf("expulse object\n");
}

void			broadcast_task_function(t_server *server,
					        t_client *client,
						char *arg)
{
  (void)server;
  (void)client;
  (void)arg;
  printf("broadcast message\n");
}

void		        incantation_task_function(t_server *server,
						  t_client *client,
						  char *arg)
{
  (void)server;
  (void)client;
  (void)arg;
  printf("incantation\n");
}
