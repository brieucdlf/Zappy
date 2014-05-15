#include "server.h"

void			free_double_array(char **tab)
{
  int			index;

  if (tab == NULL)
    return ;
  index = 0;
  while (tab[index] != NULL)
    free(tab[index++]);
  free(tab);
}
