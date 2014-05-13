#include "user.h"
#include "server.h"

void			display_the_list(t_list *elem, void *arg)
{
  (void)arg;
  printf("elem list : %s\n", (char *)elem->data);
}

int			match_fction(void *data1, void *data2)
{
  int			ret;

  ret = strcmp((char *)data1, (char *)data2);
  return (ret);
}

void			find_elem(t_list *elem, void *arg)
{
  (void)arg;
  (void)elem;
  printf("find elem : %s", (char *)arg);
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
  list_remove_with_data(&list, (void *)"salut4", match_fction);

  list_push(&list, (void *)"salut2", NULL);

  map_list(list, display_the_list, NULL);
  map_list_with_match(list, find_elem, match_fction, (void *)"salut3");

  list_delete(list);
}
