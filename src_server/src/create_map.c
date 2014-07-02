#include "server.h"

int			create_map(t_server *server)
{
  int			index_position_x;
  int			index_position_y;

  if ((server->map.map = malloc(sizeof(t_list **) *
				server->map.height)) == NULL)
    return (1);
  for (index_position_y = 0; index_position_y < server->map.height;
       index_position_y++)
    {
      if ((server->map.map[index_position_y] =
	   malloc(sizeof(t_list *) * server->map.width)) == NULL)
	return (1);
      for (index_position_x = 0; index_position_x < server->map.width;
	   index_position_x++)
	{
	  if ((server->map.map[index_position_y][index_position_x] =
	       malloc(sizeof(t_list))) == NULL)
	    return (1);
	  server->map.map[index_position_y][index_position_x] = NULL;
	}
    }
  return (0);
}
