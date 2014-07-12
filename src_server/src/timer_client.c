#include "server.h"

void				init_timer_client(t_client *client)
{
  struct timeval		current_time;

  gettimeofday(&current_time, NULL);
  client->timeout.tv_sec = current_time.tv_sec + TIMEOUT_CLIENT;
  client->timeout.tv_usec = current_time.tv_usec;
}

void				send_dead_to_graphic_client(t_server *server,
							    t_client *client)
{
  char			*command;

  if (server->graphic_client == NULL || (command = malloc(100)) == NULL)
    return ;
  memset(command, 0, 100);
  snprintf(command, 100, "pdi %d\n", client->id_client);
  create_new_write_task(server->graphic_client, command);
  free(command);
}

int				check_timeout_client(t_list *current_item,
						     void *arg)
{
  t_client			*current_client;
  struct timeval		current_time;

  if (arg == NULL || current_item == NULL ||
      (current_client = (t_client *)current_item->data) == NULL)
    return (1);
  gettimeofday(&current_time, NULL);
  if (current_client->timeout.tv_sec < current_time.tv_sec)
    {
      printf("[\033[31m-\033[0m] TimeOut client [%d]\n",
	     current_client->id_client);
      deconnection_client((t_server *)arg, current_client);
      return (0);
    }
  if (current_client->food_timer.tv_sec < current_time.tv_sec)
    {
      printf("[\033[31m-\033[0m] Client dead, no food [%d]\n",
	     current_client->id_client);
      send_dead_to_graphic_client((t_server *)arg, current_client);
      deconnection_client((t_server *)arg, current_client);
      return (0);
    }
  return (1);
}

void			        check_timer_clients(t_server *server)
{
  map_list_with_stop(server->clients, check_timeout_client, (void *)server);
}
