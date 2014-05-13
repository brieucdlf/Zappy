#ifndef LIST_H
# define LIST_H

typedef struct		s_list
{
  void			*data;
  struct s_list		*next;
}			t_list;

#endif // LIST
