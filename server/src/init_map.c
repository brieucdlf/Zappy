/*
** init_map.c for zappy in /home/combe_r/Documents/rendu/Zappy/server/src
** 
** Made by romain combe
** Login   <combe_r@epitech.net>
** 
** Started on  Thu May 15 11:52:58 2014 romain combe
** Last update Thu May 15 18:10:05 2014 romain combe
*/

#include "user.h"
#include "server.h"

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
      	  map->map[i][j] = rand() % 7;
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
  fill_map(map);
}

void		print_map(t_map *map)
{  
}
