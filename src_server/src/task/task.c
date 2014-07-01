#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "task.h"

void			function_pointer(t_task *task, unsigned int index)
{
  function_task		tab_function[11] = {avance_task_function,
					    droite_task_function,
					    gauche_task_function,
					    voir_task_function,
					    inventaire_task_function,
					    prend_task_function,
					    pose_task_function,
					    expulse_task_function,
					    broadcast_task_function,
					    incantation_task_function,
					    fork_task_function};

  task->function = tab_function[index];
}

void			add_function_task(t_task *task, const char *command)
{
  char			*tab_command[11] = {"avance\n", "droite\n", "gauche\n",
					   "voir\n", "inventaire\n",
					   "prend object\n", "pose object\n",
					   "expulse\n", "broadcast texte\n",
					   "incantation\n", "fork\n"};
  unsigned int		index;

  for (index = 0; index < 11; index++)
    {
      if (strcmp((const char *)tab_command[index], command) == 0)
	{
	  function_pointer(task, index);
	  timer_task(task, index);
	  return ;
	}
    }
}

t_task			*new_task(const char *command)
{
  t_task		*task;

  if ((task = malloc(sizeof(t_task))) == NULL)
    return (NULL);
  task->function = NULL;
  add_function_task(task, command);
  return (task);
}

/* int			main() */
/* { */
/*   t_task		*task; */
/*   struct timeval	tv; */

/*   task = new_task("voir\n"); */
/*   if (task == NULL) */
/*     return (0); */
/*   if (task->function != NULL) */
/*     task->function(NULL, NULL); */

/*   while (1) { */
/*     gettimeofday(&tv, NULL); */
/*     if (tv.tv_sec >= task->timer.tv_sec && tv.tv_usec >= task->timer.tv_usec) */
/*       { */
/* 	printf("Timer done \n"); */
/* 	return (0); */
/*       } */
/*     printf("current time = [%lu / %lu] = [%lu / %lu]\n", tv.tv_sec, tv.tv_usec, */
/* 	   task->timer.tv_sec, task->timer.tv_usec); */
/*   } */

/*   return (0); */
/* } */
