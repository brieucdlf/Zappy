#include "server.h"

void			timer_task(t_server *server, t_task *task,
				   unsigned int index)
{
  unsigned int		tab_timer[11] = {TIMER_AVANCE, TIMER_DROITE,
					 TIMER_GAUCHE, TIMER_VOIR,
					 TIMER_INVENTAIRE, TIMER_PREND,
					 TIMER_POSE, TIMER_EXPULSE,
					 TIMER_BROADCAST, TIMER_INVENTAIRE,
					 TIMER_FORK};

  gettimeofday(&task->timer, NULL);
  if (task->timer.tv_usec +
      (((double)tab_timer[index] /
	server->param_server.execution_time) * 1000) > (double)MAX_TIMER_VALUE)
    {
      task->timer.tv_sec += 1;
      task->timer.tv_usec = task->timer.tv_usec +
	(double)((int)(((double)tab_timer[index] /
			server->param_server.execution_time) * 1000) %
		 (int)MAX_TIMER_VALUE);
    }
  else
    task->timer.tv_usec = task->timer.tv_usec +
      (double)(((double)tab_timer[index] /
		server->param_server.execution_time) * 1000);
}
