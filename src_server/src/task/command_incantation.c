#include "server.h"

int			get_number_client_requirement(unsigned int level)
{
  int			requirement[7];

  requirement[0] = 1;
  requirement[1] = 2;
  requirement[2] = 2;
  requirement[3] = 4;
  requirement[4] = 4;
  requirement[5] = 6;
  requirement[6] = 6;
  return (requirement[level]);
}

int			check_requirement_number_client(t_list *clients,
							t_client *current_client)
{
  t_list		*current_item;
  t_client		*client;
  int			number_client;

  number_client = 0;
  if ((current_item = clients) == NULL)
    return (1);
  while (current_item != NULL)
    {
      if ((client = (t_client *)current_item->data) != NULL &&
	  client->direction.position_x == current_client->direction.position_x &&
	  client->direction.position_y == current_client->direction.position_y &&
	  client->level == current_client->level)
	number_client += 1;
      if (number_client >= get_number_client_requirement(current_client->level))
	return (0);
      current_item = current_item->next;
    }
  return (1);
}

void			send_task_answer(t_client *client)
{
  char			*command;

  if ((command = malloc(100)) == NULL)
    return ;
  memset(command, 0, 100);
  snprintf(command, 100, "niveau actuel : %d\n", client->level);
  create_new_write_task(client, command);
  free(command);
}

void		        incantation_task_function(t_server *server,
						  t_client *client,
						  char *arg)
{
  (void)arg;
  if (client->level >= 8)
    {
      send_task_answer(client);
      return ;
    }
  if (check_requirement_number_client(server->clients, client) == 0 &&
      check_ressoures_incantation(client) == 0)
    client->level += 1;
  send_task_answer(client);
  printf("incantation\n");
}
