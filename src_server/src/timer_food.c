#include "server.h"

void			add_live_food(t_server *server, t_client *client)
{
    struct timeval	current_time;

  gettimeofday(&current_time, NULL);
  if (client->food_timer.tv_usec +
      (((double)FOOD_ADD / server->param_server.execution_time) * 1000) >
      (double)MAX_TIMER_VALUE)
    {
      client->food_timer.tv_sec += FOOD_ADD /
	server->param_server.execution_time;
      client->food_timer.tv_usec += client->food_timer.tv_usec +
	(double)((int)(((double)FOOD_ADD /
			server->param_server.execution_time) * 1000) %
		 (int)MAX_TIMER_VALUE);
    }
  else
    client->food_timer.tv_usec += client->food_timer.tv_usec +
      (double)(((double)FOOD_ADD / server->param_server.execution_time) * 1000);
}

void			init_timer_food(t_server *server, t_client *client)
{
  struct timeval	current_time;

  gettimeofday(&current_time, NULL);
  if (client->food_timer.tv_usec +
      (((double)FOOD_LIVE / server->param_server.execution_time) * 1000) >
      (double)MAX_TIMER_VALUE)
    {
      client->food_timer.tv_sec += FOOD_LIVE /
	server->param_server.execution_time;
      client->food_timer.tv_usec = client->food_timer.tv_usec +
	(double)((int)(((double)FOOD_LIVE /
			server->param_server.execution_time) * 1000) %
		 (int)MAX_TIMER_VALUE);
    }
  else
    client->food_timer.tv_usec = client->food_timer.tv_usec +
      (double)(((double)FOOD_LIVE / server->param_server.execution_time) * 1000);
}
