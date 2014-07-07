#include "server.h"

void			query_first_connection(t_server *server,
					       t_client *current_client)
{
  char			*command;

  if ((command = malloc(100)) == NULL)
    return ;
  memset(command, 0, 100);
  sprintf(command, "%d\n", current_client->id_client);
  create_new_write_task(current_client, command);
  memset(command, 0, 100);
  sprintf(command, "%d %d\n", server->map.width,
	  server->map.height);
  create_new_write_task(current_client, command);
  free(command);
}

void			init_position_client(t_client *current_client,
					     t_server *server)
{
  current_client->direction.position_x = rand() % server->map.width;
  current_client->direction.position_y = rand() % server->map.height;
  current_client->direction.orientation = MAP_DIRECTION_ORIENTATION_NORTH;
}

int			create_new_task_client(t_client *client,
					       t_server *server)
{
  t_task		*task;

  if (client->is_ready == 1)
    {
      if ((task = new_task(server, client->buffer.buffer_read)) != NULL)
	{
	  printf("[+] ADD Task client[%d] : \033[%dm%s\033[0m\n", client->id_client, 30 + client->fd_socket,
		 client->buffer.buffer_read);
	  list_push(&client->tasks, task, free_task);
	  init_timer_client(client);
	}
    }
  else
    {
      if (((client->id_team = get_id_team(server,
					     client->buffer.buffer_read)) == -1))
	{
	  if (!check_is_graphic_client(server, client,
				       client->buffer.buffer_read))
	    {
	      printf("\033[31mWrong team name[%d] :\033[0m%s\n",
		     client->id_client,
		     client->buffer.buffer_read);
	      deconnection_client(server, client);
	      return (0);
	    }
	  return (1);
	}
      client->is_ready = 1;
      init_position_client(client, server);
      query_first_connection(server, client);
    }
  return (1);
}

int			interpret_buffer_read_client(t_server *server,
						     t_client *client,
						     char *buff)
{
  int			index;

  for (index = 0; index < 2048 &&
       client->buffer.index_read_buffer < 2048 && buff[index] != '\0'; index++)
    {
      client->buffer.buffer_read[client->buffer.index_read_buffer] = buff[index];
      if (buff[index] == '\n')
	{
	  if (create_new_task_client(client, server) == 0)
	    return (0);
	  memset(client->buffer.buffer_read, 0, 2048);
	  index++;
	  memcpy(client->buffer.buffer_read, &buff[index],
		 strlen(&buff[index]) % 2047);
	  client->buffer.index_read_buffer = strlen(&buff[index]);
	  return (1);
	}
      client->buffer.index_read_buffer++;
    }
  return (1);
}

int			map_check_read_client(t_list *current_client, void *arg)
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
	  printf("Error read\n");
	  deconnection_client(server, client);
	  return (0);
	}
      else
	{
	  if (interpret_buffer_read_client(server, client, buff) == 0)
	    return (0);
	}
    }
  usleep(5000);
  return (1);
}
