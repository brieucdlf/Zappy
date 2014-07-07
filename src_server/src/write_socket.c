#include "server.h"

int			write_task_socket(t_write_task *head_task,
					  t_client *current_client,
					  t_server *server)
{
  int			ret;

  ret = 0;
  printf("\033[31m[+]try to write = \033[0m%s\n",
	 &head_task->buffer[head_task->index]);
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
  printf("[+] Write task success %d\n", ret);
  head_task->index += ret;
  if (head_task->index >= (int)strlen(head_task->buffer))
    list_pop(&current_client->write_tasks);
  return (1);
}

void			loop_write_task(t_client *client, t_server *server)
{
  t_list		*current_task;

  if ((current_task = client->write_tasks) == NULL)
    return ;
  while (current_task != NULL &&
	 FD_ISSET(client->fd_socket, &(server->writefd)))
    {
      if (current_task->data != NULL)
	write_task_socket(((t_write_task *)current_task->data), client, server);
      current_task = current_task->next;
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
  return (1);
}
