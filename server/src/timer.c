#include "server.h"

static int		get_cycle_action(action type)
{
  int			cycle[12];

  cycle[0] = CYCLE_RIGTH;
  cycle[1] = CYCLE_LEFT;
  cycle[2] = CYCLE_MOVE;
  cycle[3] = CYCLE_SEE;
  cycle[4] = CYCLE_INVENTARY;
  cycle[5] = CYCLE_TAKE_OBJECT;
  cycle[6] = CYCLE_DROP_OBJECT;
  cycle[7] = CYCLE_PUSH;
  cycle[8] = CYCLE_BROADCAST_TEXT;
  cycle[9] = CYCLE_FORK;
  cycle[10] = CYCLE_INCANTATION;
  if (cycle != NONE)
    return (cycle[type - 1]);
  return (0);
}

void			check_cycle_timer(t_server *server,
					  t_client *current_client)
{
  struct timespec	tmp_timer;
  long			cycle;

  tmp_timer.tv_sec = 0;
  tmp_timer.tv_nsec = 0;
  if ((cycle = get_cycle_action(current_client->action.type)) == 0)
    return ;
  cycle /= (server->param_server.execution_time / 1000);
  if (clock_gettime(CLOCK_MONOTONIC, &tmp_timer) == -1)
    return ;
  if (((double)tmp_timer.tv_sec + 1.0e-9 * tmp_timer.tv_nsec) -
      ((double)current_client->action.timer_cycle.tv_sec +
       1.0e-9 * current_client->action.timer_cycle.tv_nsec) >= cycle)
    current_client->action.is_cycle = 0;
}

void			set_timer(t_client *current_client)
{
  current_client->action.timer_cycle.tv_sec = 0;
  current_client->action.timer_cycle.tv_nsec = 0;
  current_client->action.is_cycle = 0;
  clock_gettime(CLOCK_MONOTONIC, &current_client->action.timer_cycle);
}
