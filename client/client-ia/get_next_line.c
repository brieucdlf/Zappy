#include "client.h"

void	decale_buff(char *buff, int nb)
{
  int	indice;
  int	indice_loop;

  indice_loop = 0;
  while (indice_loop != nb)
    {
      indice = 1;
      while (buff[indice] != '\0')
	{
	  buff[indice - 1] = buff[indice];
	  indice = indice + 1;
	}
      indice_loop = indice_loop + 1;
    }
  while (indice < BUFFER_GET_LINE - 1)
    {
      buff[indice] = '\0';
      indice = indice + 1;
    }
}

char	*return_str(char *buff, int *indice_buff)
{
  int	indice_tab;
  int	indice;
  char	*tab;

  indice = 0;
  while (buff != NULL && buff[indice] != '\0' && buff[indice] != '\n')
    indice = indice + 1;
  if (*indice_buff == 0 || (tab = malloc(indice + 1)) == NULL)
    return (NULL);
  indice_tab = 0;
  while (indice_tab != indice && buff[indice_tab] != '\0')
    {
      tab[indice_tab] = buff[indice_tab];
      indice_tab = indice_tab + 1;
    }
  if (*indice_buff == indice)
    *indice_buff = 0;
  else
    *indice_buff = *indice_buff - (indice + 1);
  tab[indice_tab] = '\0';
  decale_buff(buff, indice + 1);
  return (tab);
}

char		*get_next_line(int fd)
{
  static char	buff[BUFFER_GET_LINE];
  static int	indice = 0;
  int		ret;

  ret = BUFFER_GET_LINE - 1;
  if (fd == -1)
    return (NULL);
  while (ret > 0 && ret == BUFFER_GET_LINE - 1 && indice <= BUFFER_GET_LINE - 1)
    {
      if ((ret = read(fd, &buff[indice], BUFFER_GET_LINE - 1 - indice)) == -1)
	return (NULL);
      indice = indice + ret;
      buff[indice] = '\0';
    }
  if (indice == 0)
    return (NULL);
  return (return_str(buff, &indice));
}
