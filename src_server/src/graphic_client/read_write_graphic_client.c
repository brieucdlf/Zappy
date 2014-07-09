#include "server.h"

int	check_graphic_client_read(t_server *server)
{
  if (server == NULL)
    printf("Server is NULL\n");
  return (0);
}

int		check_graphic_client_write(t_server *server, t_client *client)
{
  t_write_task	*head_task;

  if (client->write_tasks == NULL ||
      (head_task = (t_write_task *)(client->write_tasks->data)) == NULL)
    return (1);
  if (FD_ISSET(client->fd_socket, &(server->writefd)))
    {
      return (write_task_socket(head_task, client, server));
    }
  printf("Can't write on graphic client\n");
  return (1);
}
