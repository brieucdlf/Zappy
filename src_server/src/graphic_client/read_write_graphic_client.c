#include "graphic_client.h"

int	check_graphic_client_read(t_server *server)
{
  if (server == NULL)
    printf("Server is NULL\n");
  return (0);
}

void	display_list(t_list *current_item, void *arg)
{
  t_write_task	*task;

  task = (t_write_task *)current_item->data;
  printf("TASK = %s\n", task->buffer);
}

int		check_graphic_client_write(t_server *server, t_client *client)
{
  t_write_task	*head_task;
  static int	number_write = 0;

  if (client->write_tasks == NULL ||
      (head_task = (t_write_task *)client->write_tasks->data) == NULL)
    return (1);
  if (FD_ISSET(client->fd_socket, &(server->writefd)))
    {
      number_write += 1;
      return (write_task_socket(head_task, client, server));
    }
  printf("Can't write on graphic client\n");
  return (1);
}
