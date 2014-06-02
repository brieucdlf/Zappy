/*
** buffer.c for zappy in /home/delafo_b/tek2/repo/Zappy/server/src
**
** Made by Brieuc de La Fouchardiere
** Login   <delafo_b@epitech.net>
**
** Started on  Mon May 26 11:09:50 2014 Brieuc de La Fouchardiere
** Last update Mon May 26 13:20:53 2014 Brieuc de La Fouchardiere
*/

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
  map_list(((t_client *)client_user)->buffer.buffer_write,
	   loop_buffer_task, (void *)&((t_client *)client_user)->fd_socket);
}
