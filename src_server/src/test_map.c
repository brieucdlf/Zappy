/*
** test_map.c for zappy in /home/combe_r/Documents/rendu/Zappy/src_server/src
** 
** Made by romain combe
** Login   <combe_r@epitech.net>
** 
** Started on  Tue Jun 10 10:06:00 2014 romain combe
** Last update Tue Jun 10 11:24:27 2014 romain combe
*/

#include "user.h"
#include "server.h"

void		add_new_rocks(t_map *map, int nb_rocks, int rock_kind)
{
  int		x_rock;
  int		y_rock;

  x_rock = 0;
  y_rock = 0;
  while (nb_rocks < ((map->width + map->height) / 2))
    {
      x_rock = rand() % (map->width - 1);
      y_rock = rand() % (map->height - 1);
      if (map->map[x_rock][y_rock] != 0)
	nb_rocks--;
      else
	map->map[x_rock][y_rock] = rock_kind;
      nb_rocks++;
    }
}

void		loop_nb_rocks(t_map *map)
{
  int		i;

  i = 0;
  while (i < 6)
    {
      check_nb_rocks(map, i);
      i++;
    }
}

void		check_nb_rocks(t_map *map, int rock_kind) // Appeller cette fonction à chaque tour de boucle
{
  int		i;
  int		j;
  int		compt_rocks;

  i = 0;
  j = 0;
  compt_rocks = 0;
  while (i < map->width)
    {
      while (j < map->height)
	{
	  if (map->map[i][j] == rock_kind)
	    compt_rocks++;
	  j++;
	}
      i++;
    }
  if (compt_rocks <= 30)
    add_new_rocks(map, compt_rocks, rock_kind);
}
