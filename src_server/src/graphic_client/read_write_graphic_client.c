#include "server.h"

int	check_graphic_client_read(t_server *server, t_client *client)
{
  char	buff[2048];

  if (client == NULL)
    return (1);
  if (FD_ISSET(client->fd_socket, &(server->readfd)))
    {
      memset(buff, 0, 2048);
      if ((read(client->fd_socket, buff, 2047)) <= 0)
	{
	  deconnection_graphic_client(server);
	  return (0);
	}
      else
	{
	  return (0);
	}
    }
  return (1);
}

int		check_graphic_client_write(t_server *server, t_client *client)
{
  t_write_task	*head_task;
  int		ret;

  if (client == NULL)
    return (1);
  if (client->write_tasks == NULL ||
      (head_task = (t_write_task *)(client->write_tasks->data)) == NULL)
    return (1);
  if (FD_ISSET(client->fd_socket, &(server->writefd)))
    {
      if ((ret = write_task_socket(head_task, client, server)) == 0)
	return (ret);
      if (ret == 2)
	server->index_task_graphic -= 1;
    }
  return (1);
}
