#include "server.h"

int		        check_ressource_level(const char *step,
					      t_client *current_client)
{
  int			index;

  for (index = 0; index < 6; index++)
    {
      if (step[index] - '0' != current_client->items[index + 1])
	return (1);
    }
  return (0);
}

int			check_ressoures_incantation(t_client *client)
{
  char			tab_ressource[7][6];

  snprintf(tab_ressource[0], 6, "100000");
  snprintf(tab_ressource[1], 6, "111000");
  snprintf(tab_ressource[2], 6, "201020");
  snprintf(tab_ressource[3], 6, "112010");
  snprintf(tab_ressource[4], 6, "121300");
  snprintf(tab_ressource[5], 6, "123010");
  snprintf(tab_ressource[6], 6, "222221");
  return (check_ressource_level(tab_ressource[client->level], client));
}
