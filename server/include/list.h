#ifndef LIST_H
# define LIST_H

typedef void (*free_function)(void *);

typedef struct		s_list
{
  void			*data;
  free_function	        free;
  struct s_list		*next;
}			t_list;

void			list_pop(t_list **list);
void			list_delete(t_list *list);
void		        list_push(t_list **list, void *data,
				  free_function function);
void			map_list(t_list *list, void (*function)(t_list *, void *),
				 void *arg);

#endif // LIST
