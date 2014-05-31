#include "server.h"

void			create_new_task_client(t_client *client)
{
  char			task[2048];
  int			index_new;
  int			index;

  index_new = 0;
  memset(task, 0, 2048);
  for (index = 0; client->buffer.buffer_read[index] != '\0' &&
	 client->buffer.buffer_read[index] != '\n' && index < 2047; index++)
    task[index] = client->buffer.buffer_read[index];
  for (index = 0; client->buffer.buffer_read[index] != '\0' &&
	 client->buffer.buffer_read[index] != '\n' && index < 2047; index++)
    {
      client->buffer.buffer_read[index_new] = client->buffer.buffer_read[index];
      client->buffer.buffer_read[index] = '\0';
      index_new++;
    }
  printf("New task client [%d] : {%s}\n", client->fd_socket, task);
  printf("Stay buffer read {%s}\n", client->buffer.buffer_read);
}

void			interpret_buffer_read_client(t_server *server,
						     t_client *client)
{
  int			index;
  (void)server;

  for (index = 0; client->buffer.buffer_read[index] != '\0' &&
	 client->buffer.buffer_read[index] != '\n' && index < 2047; index++);
  if (client->buffer.buffer_read[index] == '\n')
    create_new_task_client(client);
}

int			map_check_read_client(t_list *current_client,
					      void *arg)
{
  t_server		*server;
  t_client		*client;

  if (current_client == NULL || current_client->data == NULL || arg == NULL)
    return (1);
  server = (t_server *)arg;
  client = (t_client *)current_client->data;
  if (FD_ISSET(client->fd_socket, &(server->readfd)))
    {
      if ((read(client->fd_socket, client->buffer.buffer_read,
		2047 - strlen(client->buffer.buffer_read))) <= 0)
	{
	  printf("\033[31mDeconnection client [%d]\033[00m\n", client->fd_socket);
	  deconnection_client(server, client);
	  printf("new fd max : %d\n", server->fd_max);
	  return (0);
	}
      else
	interpret_buffer_read_client(server, client);
    }
  return (1);
}
