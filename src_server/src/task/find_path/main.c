#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int			player1_1;
int			player1_2;

int			player2_1;
int			player2_2;

char			**create_map(unsigned int width, unsigned int height)
{
  char			**map;
  int			index_position_y;
  int			index_position_x;

  if ((map = malloc(sizeof(char *) * height)) == NULL)
    return (NULL);
  for (index_position_y = 0; index_position_y < height; index_position_y++)
    {
      for (index_position_y = 0; index_position_y < height; index_position_y++)
	{
	  if ((map[index_position_y] = malloc(sizeof(char) * width)) == NULL)
	    return (NULL);
	  memset(map[index_position_y], 0, width);
	}
    }
  return (map);
}

void			display_map(char **map, unsigned int width,
				    unsigned int height)
{
  int			index_position_y;
  int			index_position_x;

  for (index_position_y = 0; index_position_y < height; index_position_y++)
    {
      for (index_position_x = 0; index_position_x < width; index_position_x++)
	{
	  if (map[index_position_y][index_position_x] > 0)
	    printf("[\033[3%dm%2d\033[0m]", map[index_position_y][index_position_x],
		   map[index_position_y][index_position_x]);
	  else if (map[index_position_y][index_position_x] == -2)
	    printf("\033[41m[ #]\033[0m");
	  else
	    printf("[ ]");
	}
      printf("\n");
    }
}

int			check_path(char **map, int position_x,
				   int position_y, int number_path)
{
  int			find;

  find = 0;
  if (position_y - 1 >= 0 && map[position_y - 1][position_x] == 0)
    {
      map[position_y - 1][position_x] = number_path + 1;
      find = 1;
    }
  if (position_y + 1 < 20 &&
	   map[position_y + 1][position_x] == 0)
    {
      map[position_y + 1][position_x] = number_path + 1;
      find = 1;
    }
  if (position_x - 1 >= 0 &&
	   map[position_y][position_x - 1] == 0)
    {
      map[position_y][position_x - 1] = number_path + 1;
      find = 1;
    }
  if (position_x + 1 < 20 &&
	   map[position_y][position_x + 1] == 0)
    {
      map[position_y][position_x + 1] = number_path + 1;
      find = 1;
    }
  return (find);
}

int			path_finder(char **map, int number_path)
{
  int			index_position_y;
  int			index_position_x;
  int			find_path;

  find_path = 0;
  for (index_position_y = 0; index_position_y < 20; index_position_y++)
    {
      for (index_position_x = 0; index_position_x < 20; index_position_x++)
	{
	  if (map[index_position_y][index_position_x] == number_path &&
	      check_path(map, index_position_x,
			 index_position_y, number_path) != 0)
	    find_path = 1;
	}
    }
  return (find_path);
}

void			find_best_start(char **map, int *start_x, int *start_y)
{
  int			start_value;

  start_value = 0x7FFFFFFF;
  if (player2_1 - 1 >= 0 && map[player2_2][player2_1 - 1] < start_value)
    {
      *start_x = player2_1 - 1;
      *start_y = player2_2;
      start_value = map[player2_2][player2_1 - 1];
    }
  if (player2_1 + 1 < 20 && map[player2_2][player2_1 + 1] < start_value)
    {
      *start_x = player2_1 + 1;
      *start_y = player2_2;
      start_value = map[player2_2][player2_1 + 1];
    }
  if (player2_2 - 1 >= 0 && map[player2_2 - 1][player2_1] < start_value)
    {

      *start_x = player2_1;
      *start_y = player2_2 - 1;
      start_value = map[player2_2 - 1][player2_1];
    }
  if (player2_2 + 1 < 2 && map[player2_2 + 1][player2_1] < start_value)
    {
      *start_x = player2_1;
      *start_y = player2_2 + 1;
      start_value = map[player2_2 + 1][player2_1];
    }
  printf("best value = %d\n", start_value);
  printf("%d %d / %d %d\n", player2_1, player2_2, *start_x, *start_y);
  map[*start_y][*start_x] = 99;
}

void			loop_path_finder(char **map)
{
  int			number_path;
  char			**copy_map;
  int			start_x;
  int			start_y;

  number_path = 1;
  if ((copy_map = create_map(20, 20)) == NULL)
    return ;
  copy_map[player1_2][player1_1] = 1;
  copy_map[player2_2][player2_1] = -2;
  copy_map[rand() % 20][rand() % 20] = -2;
  copy_map[rand() % 20][rand() % 20] = -2;
  copy_map[rand() % 20][rand() % 20] = -2;
  while (path_finder(copy_map, number_path) != 0)
    number_path += 1;
  start_x = 0;
  start_y = 0;
  find_best_start(copy_map, &start_x, &start_y);
  printf("respond %d %d\n", start_y, start_x);
  map[start_y][start_x] = 2;
  display_map(copy_map, 20, 20);
  display_map(map, 20, 20);
}

int			main()
{
  char			**map;

  srand(time(NULL));
  map = create_map(20, 20);

  player1_1 = rand() % 20;
  player1_2 = rand() % 20;

  player2_1 = rand() % 20;
  player2_2 = rand() % 20;

  map[player1_1][player1_2] = 1;
  map[player2_1][player2_2] = -2;
  loop_path_finder(map);
  return (0);
}
