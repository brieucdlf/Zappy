#include "server.h"

int	check_graphic_client_read(t_server *server, t_client *client)
{
  char	buff[2048];

  if (client == NULL)
    return (1);
  if (FD_ISSET(client->fd_socket, &(server->readfd)))
    {
      printf("Try to read\n");
      memset(buff, 0, 2048);
      if ((read(client->fd_socket, buff, 2047)) <= 0)
	{
	  printf("Try deconnection\n");
	  deconnection_graphic_client(server);
	  return (0);
	}
      else
	{
	  printf("Read command\n");
	  return (0);
	}
    }
  printf("Nothing to read\n");
  return (1);
}

int		check_graphic_client_write(t_server *server, t_client *client)
{
  t_write_task	*head_task;

  printf("Enter in writing function\n");
  if (client == NULL)
    return (1);
  if (client->write_tasks == NULL ||
      (head_task = (t_write_task *)(client->write_tasks->data)) == NULL)
    return (1);
  if (FD_ISSET(client->fd_socket, &(server->writefd)))
    {
      printf("Try to write\n");
      return (write_task_socket(head_task, client, server));
    }
  printf("Can't write on graphic client\n");
  return (1);
}
