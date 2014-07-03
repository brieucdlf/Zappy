#include "user.h"
#include "server.h"

void			free_item(void *data)
{
  free(data);
  data = NULL;
}

void			free_food(void *data)
{
  free(data);
  data = NULL;
}

void			generate_food(t_server *server)
{
  t_item		*food;

  if ((food = malloc(sizeof(t_item))) == NULL)
    return ;
  food->type = 8;
  food->posx = rand() % (server->map.width);
  food->posy = rand() % (server->map.height);
  food->is_taken = 0;
  list_push(&server->map.map[food->posy][food->posy],
	    (void *)food, free_item);
}

void			generate_item(t_server *server)
{
  t_item		*item;

  if ((item = malloc(sizeof(t_item))) == NULL)
    return ;
  item->type = rand() % 7 + 1;
  item->posx = rand() % (server->map.width);
  item->posy = rand() % (server->map.height);
  item->is_taken = 0;
  list_push(&server->map.map[item->posy][item->posy],
	    (void *)item, free_item);
}

int			init_map(t_server *server)
{
  int			nb_item;

  server->map.width = server->param_server.world_width;
  server->map.height = server->param_server.world_height;
  if (create_map(server) != 0)
    return (1);
  nb_item = ((server->map.width * server->map.height) * 50) / 100;
  server->map.items = NULL;
  while (nb_item >= 0)
    {
      generate_item(server);
      nb_item--;
    }
  nb_item = ((server->map.width * server->map.height) * 25) / 100;
  while (nb_item >= 0)
    {
      generate_food(server);
      nb_item--;
    }
  return (0);
}
