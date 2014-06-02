#include "server.h"

void			create_new_task_client(t_client *client)
{
  //creer plusieurs task suivant le nombre de commande recu;
  printf("New task client : %s\n", client->buffer.buffer_read);
}

void			interpret_buffer_read_client(t_client *client,
						     char *buff)
{
  int			index;

  for (index = 0; index < 2048 &&
       client->buffer.index_read_buffer < 2048 && buff[index] != '\0'; index++)

    {
      client->buffer.buffer_read[client->buffer.index_read_buffer] = buff[index];
      if (buff[index] == '\n')
	{
	  create_new_task_client(client);
	  memset(client->buffer.buffer_read, 0, 2048);
	  index++;
	  memcpy(client->buffer.buffer_read, &buff[index],
		 strlen(&buff[index]));
	  client->buffer.index_read_buffer = strlen(&buff[index]);
	  return ;
	}
      client->buffer.index_read_buffer++;
    }
}

int			map_check_read_client(t_list *current_client,
					      void *arg)
{
  t_server		*server;
  t_client		*client;
  char			buff[2048];

  if (current_client == NULL || current_client->data == NULL || arg == NULL)
    return (1);
  server = (t_server *)arg;
  client = (t_client *)current_client->data;
  if (FD_ISSET(client->fd_socket, &(server->readfd)))
    {
      memset(buff, 0, 2048);
      if ((read(client->fd_socket, buff, 2047)) <= 0)
	{
	  printf("\033[31mDeconnection client [%d]\033[00m\n", client->fd_socket);
	  deconnection_client(server, client);
	  printf("new fd max : %d\n", server->fd_max);
	  return (0);
	}
      else
	interpret_buffer_read_client(client, buff);
    }
  return (1);
}
