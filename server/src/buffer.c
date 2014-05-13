#include "server.h"

void			write_task(t_buffer *buffer, int fd_socket)
{
  (void)buffer;
  (void)fd_socket;
  /*write task here on socket*/
}

void			loop_buffer_task(t_list *current_task, void *arg)
{
  t_buffer		*buffer;

  (void)arg;
  (void)current_task;
  buffer = (t_buffer *)current_task->data;
  write_task(buffer, *((int *)arg));
}

void		        loop_write_buffer_client(t_list *client_user)
{
  (void)client_user;
  map_list(((t_client *)client_user)->buffer->buffer_write,
	   loop_buffer_task, (void *)&((t_client *)client_user)->fd_socket);
}
