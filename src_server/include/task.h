#ifndef TASK_H
# define TASK_H

# include <stdio.h>
# include <sys/time.h>

# define TIMER_AVANCE		7
# define TIMER_DROITE		7
# define TIMER_GAUCHE		7
# define TIMER_VOIR		7
# define TIMER_INVENTAIRE	1
# define TIMER_PREND		7
# define TIMER_POSE		7
# define TIMER_EXPULSE		7
# define TIMER_BROADCAST	7
# define TIMER_INCANTATION	300
# define TIMER_FORK		42

# define MAX_TIMER_VALUE	999999

typedef void		(*function_task)(void *, void *);

typedef struct		s_task
{
  function_task	        function;
  struct timeval	timer;
  int			is_over;
}			t_task;

/*
** LIST TASK
*/
void			avance_task_function(void *server, void *client);
void			droite_task_function(void *server, void *client);
void		        gauche_task_function(void *server, void *client);
void		        voir_task_function(void *server, void *client);
void		        inventaire_task_function(void *server, void *client);
void		        prend_task_function(void *server, void *client);
void		        pose_task_function(void *server, void *client);
void		        expulse_task_function(void *server, void *client);
void		        broadcast_task_function(void *server, void *client);
void		        incantation_task_function(void *server, void *client);
void		        fork_task_function(void *server, void *client);

void			timer_task(t_task *task, unsigned int index);
t_task			*new_task(const char *command);

#endif // TASK
