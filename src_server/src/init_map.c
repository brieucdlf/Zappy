/*
** init_map.c for zappy in /home/combe_r/Documents/rendu/Zappy/server/src
**
** Made by romain combe
** Login   <combe_r@epitech.net>
**
** Started on  Thu May 15 11:52:58 2014 romain combe
** Last update Mon Jun  2 17:58:13 2014 romain combe
*/

#include "user.h"
#include "server.h"

void		fill_rocks(t_map *map, int rock_kind, int nb_rocks)
{
  int		x_rock;
  int		y_rock;
  int		i;

  i = 0;
  srand(time(NULL));
  while (i < nb_rocks)
    {
      x_rock = rand() % (map->width - 1);
      y_rock = rand() % (map->height - 1);
      if (map->map[x_rock][y_rock] == rock_kind)
	i--;
      else
	map->map[x_rock][y_rock] = rock_kind;
      i++;
    }
}
	
void		set_rocks(t_map *map)
{
  srand(time(NULL));
  map->nb_linemate = rand() % ((map->width + map->height) / 20) + 5;
  fill_rocks(map, LINEMATE, map->nb_linemate);
  map->nb_deraumere = rand() % ((map->width + map->height) / 20) + 5;
  fill_rocks(map, DERAUMERE, map->nb_deraumere);
  map->nb_sibur = rand() % ((map->width + map->height) / 20) + 5;
  fill_rocks(map, SIBUR, map->nb_sibur);
  map->nb_mendiane = rand() % ((map->width + map->height) / 20) + 5;
  fill_rocks(map, MENDIANE, map->nb_mendiane);
  map->nb_phiras = rand() % ((map->width + map->height) / 20) + 5;
  fill_rocks(map, PHIRAS, map->nb_phiras);
  map->nb_thystame = rand() % ((map->width + map->height) / 20) + 5;
  fill_rocks(map, THYSTAME, map->nb_thystame);
}

void		fill_empty_map(t_map *map)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i++ < map->height)
    {
      while (j++ < map->width)
      	{
      	  map->map[i][j] = 0;
	  printf("%d.", map->map[i][j]);
	}
      j = 0;
      printf("\n");
      i++;
    }
}

void		fill_map(t_map *map)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  srand(time(NULL));
  while (i++ < map->height)
    {
      while (j++ < map->width)
      	{
      	  map->map[i][j] = rand() % 100 + 50;
	  printf("%d.", map->map[i][j]);
	}
      j = 0;
      printf("\n");
      i++;
    }
}

char		**malloc_tab(int width, int height)
{
  char		**tab;
  int		i;

  i = 0;
  if (((tab = malloc(height * (sizeof(char *) + 1))) == NULL))
    exit(EXIT_FAILURE);
  while (i < height)
    {
      if (((tab[i] = malloc(width)) == NULL))
  	exit(EXIT_FAILURE);
      memset(tab[i], 0, width);
      i++;
    }
  tab[i] = NULL;
  return (tab);
}

void		init_map(t_map *map)
{
  map->width = DEFAULT_WIDTH;
  map->height = DEFAULT_HEIGHT;
  map->map = malloc_tab(map->width, map->height);
  //fill_empty_map(map);
  set_rocks(map);
}
