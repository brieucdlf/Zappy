#include "server.h"

int			write_task_socket(t_write_task *head_task,
					  t_client *current_client,
					  t_server *server)
{
  int			ret;

  ret = 0;
  if ((ret = write(current_client->fd_socket,
		   &head_task->buffer[head_task->index],
		   strlen(&head_task->buffer[head_task->index]))) <= 0)
    {
      printf("\033[31mDeconnection client [%d]\033[00m\n",
	     current_client->fd_socket);
      deconnection_client(server, current_client);
      printf("new fd max : %d\n", server->fd_max);
      return (0);
    }
  head_task->index += ret;
  if (head_task->index >= (int)strlen(head_task->buffer))
    list_pop(&current_client->write_tasks);
  return (1);
}

int			map_check_write_client(t_list *current_client,
					       void *arg)
{
  t_server		*server;
  t_client		*client;
  t_write_task		*head_task;

  if ((client = (t_client *)current_client->data) == NULL ||
      (server = (t_server *)arg) == NULL || client->write_tasks == NULL ||
      (head_task = (t_write_task *)client->write_tasks->data) == NULL)
    return (1);
  if (FD_ISSET(client->fd_socket, &(server->writefd)))
    return (write_task_socket(head_task, client, server));
  return (1);
}
