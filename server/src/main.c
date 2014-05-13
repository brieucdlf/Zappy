/*
** main.c for zappy in /Users/remihillairet/Epitech/Github/Zappy/server
**
** Made by remi hillairet
** Login   <remihillairet@epitech.net>
**
** Started on  Tue May  13 10:45:33 2014 remi hillairet
** Last update Tue May 13 11:55:05 2014 Brieuc
*/

#include "user.h"
#include "server.h"

void			display_the_list(t_list *elem, void *arg)
{
  (void)arg;
  printf("elem list : %s\n", (char *)elem->data);
}

void		        test_list()
{
  t_list		*list;

  list = NULL;

  list_push(&list, (void *)"salut1", NULL);
  list_push(&list, (void *)"salut2", NULL);
  list_push(&list, (void *)"salut3", NULL);
  list_push(&list, (void *)"salut4", NULL);

  list_pop(&list);

  map_list(list, display_the_list, NULL);

  list_delete(list);
}

int			main()
{
  test_list();
  return (0);
}
