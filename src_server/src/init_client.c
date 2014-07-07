#include "server.h"

void			free_client(void *arg)
{
  t_client		*client;

  client = (t_client *)arg;
  free(client->write_tasks);
  free(client->tasks);
  free(client);
}

void			init_position_default_client(t_client *client)
{
  client->direction.orientation = MAP_DIRECTION_ORIENTATION_NORTH;
  client->direction.position_x = 0;
  client->direction.position_y = 0;
}

void			add_new_client(t_server *server,
				       int fd_socket, int id_team)
{
  t_client		*new_client;
  static unsigned int	id_client = 0;

  if ((new_client = malloc(sizeof(t_client))) == NULL)
    return ;
  new_client->tasks = NULL;
  new_client->write_tasks = NULL;
  new_client->fd_socket = fd_socket;
  new_client->id_team = id_team;
  new_client->id_client = id_client;
  new_client->level = 2;
  new_client->is_ready = 0;
  memset(new_client->buffer.buffer_read, 0, 2048);
  new_client->buffer.index_read_buffer = 0;
  memset(new_client->items, 0, sizeof(int) * 6);
  list_push(&server->clients, new_client, free_client);
  create_new_write_task(new_client, WELCOME_MESSAGE);
  id_client += 1;
  init_timer_client(new_client);
  init_timer_food(server, new_client);
  init_position_default_client(new_client);
}
