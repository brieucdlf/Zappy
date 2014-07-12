#include "server.h"

int			create_map(t_server *server)
{
  int			index_position_x;
  int			index_position_y;

  if ((server->map.map = (t_list ***)malloc(sizeof(t_list **) *
					    (server->map.height + 1))) == NULL)
    return (1);
  for (index_position_y = 0; index_position_y < server->map.height;
       index_position_y++)
    {
      if ((server->map.map[index_position_y] =
	   (t_list **)malloc(sizeof(t_list *) *
			     (server->map.width + 1))) == NULL)
	return (1);
      for (index_position_x = 0; index_position_x < server->map.width;
	   index_position_x++)
	server->map.map[index_position_y][index_position_x] = NULL;
      server->map.map[index_position_y][index_position_x] = NULL;
    }
  server->map.map[index_position_y] = NULL;
  return (0);
}
