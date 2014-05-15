#include "server.h"

static void		init_action(t_action *action)
{
  action->is_cycle = 0;
  action->type = NONE;
  action->timer_cycle.tv_sec = 0;
  action->timer_cycle.tv_nsec = 0;
}

void			free_client(void *arg)
{
  t_client		*client;

  client = (t_client *)arg;
  free(client->buffer.buffer_read);
  list_delete(client->buffer.buffer_write);
  free(client);
}

void			add_new_client(t_server *server,
				       int fd_socket, int id_team)
{
  t_client		*new_client;

  if ((new_client = malloc(sizeof(t_client))) == NULL)
    return ;
  new_client->fd_socket = fd_socket;
  new_client->id_team = id_team;
  new_client->level = 0;
  new_client->buffer.buffer_write = NULL;
  new_client->buffer.buffer_read = NULL;
  init_action(&new_client->action);
  memset(new_client->items, 0, sizeof(int) * 6);
  list_push(&server->clients, new_client, free_client);
}
