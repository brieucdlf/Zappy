#include "user.h"
#include "server.h"

void			free_item(void *data)
{
  free(data);
  data = NULL;
}

void			generate_food(t_server *server)
{
  t_item		*food;

  if ((food = malloc(sizeof(t_item))) == NULL)
    return ;
  food->type = 0;
  food->posx = rand() % (server->map.width);
  food->posy = rand() % (server->map.height);
  food->is_taken = 0;
  list_push(&server->map.map[rand() %
			     server->map.width][rand() %
						server->map.height],
	    (void *)food, free_item);
}

void			generate_item(t_server *server)
{
  t_item		*item;

  if ((item = malloc(sizeof(t_item))) == NULL)
    return ;
  item->type = rand() % 6 + 1;
  item->posx = rand() % (server->map.width);
  item->posy = rand() % (server->map.height);
  item->is_taken = 0;
  list_push(&server->map.map[rand() %
			     server->map.width][rand() %
						server->map.height],
	    (void *)item, free_item);
}

void			display_map(t_server *server)
{
  int			position_x;
  int			position_y;
  t_list		*current_item;
  int			nb;
  int			tab[7];

  printf("\033[30;31mFOOD - ");
  printf("\033[30;32mLINEMATE - ");
  printf("\033[30;33mDERAUMERE - ");
  printf("\033[30;34mSIBUR - ");
  printf("\033[30;35mMENDIANE - ");
  printf("\033[30;36mPHIRAS - ");
  printf("\033[30;37mTHYSTAME \n\n");
  for (position_y = 0; position_y < server->map.height; position_y++)
    {
      for (position_x = 0; position_x < server->map.width; position_x++)
	{
	  nb = 0;
	  current_item = server->map.map[position_y][position_x];
	  tab[0] = 0;
	  tab[1] = 0;
	  tab[2] = 0;
	  tab[3] = 0;
	  tab[4] = 0;
	  tab[5] = 0;
	  tab[6] = 0;
	  while (current_item != NULL)
	    {
	      nb++;
	      tab[((t_item *)current_item->data)->type] += 1;
	      current_item = current_item->next;
	    }
	  printf("[\033[30;31m%d \033[30;32m%d \033[30;33m%d \033[30;34m%d \033[30;35m%d \033[30;36m%d \033[30;37m%d]", tab[0], tab[1], tab[2], tab[3],
		 tab[4], tab[5], tab[6]);
	}
      printf("\n");
    }
}

int			init_map(t_server *server)
{
  int			nb_item;

  server->map.width = server->param_server.world_width;
  server->map.height = server->param_server.world_height;
  if (create_map(server) != 0)
    return (1);
  nb_item = ((server->map.width * server->map.height) * 300) / 100;
  server->map.items = NULL;
  while (nb_item >= 0)
    {
      generate_item(server);
      nb_item--;
    }
  nb_item = ((server->map.width * server->map.height) * 70) / 100;
  while (nb_item >= 0)
    {
      generate_food(server);
      nb_item--;
    }
  //  display_map(server);
  return (0);
}
