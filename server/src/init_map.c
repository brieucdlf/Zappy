/*
** init_map.c for zappy in /home/combe_r/Documents/rendu/Zappy/server/src
** 
** Made by romain combe
** Login   <combe_r@epitech.net>
** 
** Started on  Thu May 15 11:52:58 2014 romain combe
** Last update Thu May 15 19:19:43 2014 romain combe
*/

#include "user.h"
#include "server.h"

void		set_rocks(t_map *map)
{
  srand(time(NULL));
  map->nb_linemate = rand() % 10 + 5;
  printf("linemate : %d\n", map->nb_linemate);
  map->nb_deraumere = rand() % 10 + 5;
  printf("linemate : %d\n", map->nb_deraumere);
  map->nb_sibur = rand() % 10 + 5;
  printf("linemate : %d\n", map->nb_sibur);
  map->nb_mendiane = rand() % 10 + 5;
  printf("linemate : %d\n", map->nb_mendiane);
  map->nb_phiras = rand() % 10 + 5;
  printf("linemate : %d\n", map->nb_phiras);
  map->nb_thystame = rand() % 10 + 5;
  printf("linemate : %d\n", map->nb_thystame);
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
  if (((tab = malloc(height * sizeof(char *) + 1)) == NULL))
    exit(EXIT_FAILURE);
  while (i <= width)
    {
      if (((tab[i] = malloc(width * sizeof(char *) + 1)) == NULL))
  	exit(EXIT_FAILURE);
      i++;
    }
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
