/*
** t_list.h for zappy in /Users/remihillairet/Epitech/Github/Zappy/server
**
** Made by remi hillairet
** Login   <remihillairet@epitech.net>
**
** Started on  Tue May  13 10:53:47 2014 remi hillairet
** Last update Tue May  13 10:53:47 2014 remi hillairet
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct		s_list
{
  void			*data;
  struct s_list		*next;
}			t_list;

#endif /* !LIST_H_ */