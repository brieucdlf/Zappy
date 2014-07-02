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

void			generate_food(t_map *map)
{
  t_item		*food;

  if ((food = malloc(sizeof(t_item))) == NULL)
    return ;
  food->type = 8;
  food->posx = rand() % (map->width);
  food->posy = rand() % (map->height);
  food->is_taken = 0;
  list_push(&map->items, (void *)food, free_food);
}

void			generate_item(t_map *map)
{
  t_item		*item;

  if ((item = malloc(sizeof(t_item))) == NULL)
    return ;
  item->type = rand() % 7 + 1;
  item->posx = rand() % (map->width);
  item->posy = rand() % (map->height);
  item->is_taken = 0;
  list_push(&map->items, (void *)item, free_item);
}

void			init_map(t_server *server)
{
  int			nb_item;

  server->map.width = server->param_server.world_width;
  server->map.height = server->param_server.world_height;
  nb_item = ((server->map.width * server->map.height) * 50) / 100;
  server->map.items = NULL;
  while (nb_item >= 0)
    {
      generate_item(&server->map);
      nb_item--;
    }
  nb_item = ((server->map.width * server->map.height) * 25) / 100;
  while (nb_item >= 0)
    {
      generate_food(&server->map);
      nb_item--;
    }
}
