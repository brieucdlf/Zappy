/*
** list.h for zappy in /home/combe_r/Documents/rendu/Zappy/server
** 
** Made by romain combe
** Login   <combe_r@epitech.net>
** 
** Started on  Thu May 15 11:24:51 2014 romain combe
** Last update Thu May 15 11:24:54 2014 romain combe
*/

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct s_list t_list;

typedef void (*free_function)(void *);
typedef int (*match_function)(void *, void *);
typedef void (*map_function)(t_list *, void *);

typedef struct		s_list
{
  void			*data;
  free_function	        free;
  struct s_list		*next;
}			t_list;

void		        list_remove_with_data(t_list **head_list, void *node,
					      match_function match_fct);
void			list_pop(t_list **list);
void			list_delete(t_list *list);
void		        list_push(t_list **list, void *data,
				  free_function function);
void			map_list(t_list *list, map_function map_fct, void *arg);
void			map_list_with_match(t_list *list,
					    map_function map_fct,
					    match_function match_fct, void *arg);

#endif // LIST
