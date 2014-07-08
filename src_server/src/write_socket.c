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
      if (server->graphic_client != NULL
	  && server->graphic_client->fd_socket == current_client->fd_socket)
	deconnection_graphic_client(server, current_client);
      else
	deconnection_client(server, current_client);
      return (0);
    }
  printf("[\033[32m+\033[0m] [%d] Write task = %s",
	 current_client->id_client,
	 &head_task->buffer[head_task->index]);
  head_task->index += ret;
  if (head_task->index >= (int)strlen(head_task->buffer))
    list_pop(&current_client->write_tasks);
  return (1);
}

void			loop_write_task(t_client *client, t_server *server)
{
  if (FD_ISSET(client->fd_socket, &(server->writefd)))
    {
      if (client->write_tasks != NULL && client->write_tasks->data != NULL)
	{
	  write_task_socket(((t_write_task *)client->write_tasks->data),
			    client, server);
	  return ;
	}
    }
}

int			map_check_write_client(t_list *current_client,
					       void *arg)
{
  t_server		*server;
  t_client		*client;
  t_write_task		*head_task;

  if ((client = (t_client *)current_client->data) == NULL ||
      (server = (t_server *)arg) == NULL)
    return (1);
  loop_write_task(client, server);
  usleep(5000);
  return (1);
}
