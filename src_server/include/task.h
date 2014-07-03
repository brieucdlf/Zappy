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

typedef struct s_server t_server;
typedef struct s_client t_client;

typedef void		(*function_task)(t_server *, t_client *, char *arg);

typedef struct		s_task
{
  function_task	        function;
  struct timeval	timer;
  int			is_over;
  char			*argument;
}			t_task;

typedef struct		s_write_task
{
  char			buffer[10240];
  int			index;
}			t_write_task;

/*
** LIST TASK
*/
void			avance_task_function(t_server *, t_client *, char *);
void			droite_task_function(t_server *, t_client *, char *);
void		        gauche_task_function(t_server *, t_client *, char *);
void		        voir_task_function(t_server *, t_client *, char *);
void		        inventaire_task_function(t_server *, t_client *, char *);
void		        prend_task_function(t_server *, t_client *, char *);
void		        pose_task_function(t_server *, t_client *, char *);
void		        expulse_task_function(t_server *, t_client *, char *);
void		        broadcast_task_function(t_server *, t_client *, char *);
void		        incantation_task_function(t_server *, t_client *, char *);
void		        fork_task_function(t_server *, t_client *, char *);
void			free_task(t_list *task);

void			timer_task(t_task *task, unsigned int index);
t_task			*new_task(const char *command);

#endif // TASK
