#ifndef REQUEST_H
# define REQUEST_H

typedef struct		s_task
{
  char			*request;
  int			index;
}			t_task;

typedef struct		s_request
{
  t_list		requests;
}			t_request;

#endif /* REQUEST */
