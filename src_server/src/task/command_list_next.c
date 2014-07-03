#include "task.h"

void		        prend_task_function(t_server *server,
					    t_client *client,
					    char *arg)
{
  /*t_item                *item;
  t_list                *current_item;

  current_item = server->map.map[client->orientation.position.y]
    [client->orientation.position.x];
  while (current_item !=  NULL)
    {
      if (obj = FOOD)
        {
	  
        }
      else
        {
	  
        }
      current_item = current_item->next;
      }*/
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
