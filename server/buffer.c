#include "server.h"

void			write_task(t_list *task, void *arg)
{
  (void)task;
  (void)arg;
  /*write task here on socket*/
}

void			loop_buffer_task(t_list *current_task, void *arg)
{
  (void)arg;
  (void)current_task;
  map_list(current_task, write_task, NULL /* send current_task->fd */);
}

void		        loop_buffer_client(t_list *client_user)
{
  (void)client_user;
  map_list(client_user, loop_buffer_task, NULL);
}
