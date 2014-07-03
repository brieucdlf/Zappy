#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "task.h"

void			free_task(t_list *task)
{
  free(((t_task *)task->data)->argument);
  free(task->data);
}

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

t_task			*add_function_task(const char *command)
{
  char			*tab_command[11] = {"avance\n", "droite\n", "gauche\n",
					   "voir\n", "inventaire\n",
					   "prend object\n", "pose object\n",
					   "expulse\n", "broadcast texte\n",
					   "incantation\n", "fork\n"};
  unsigned int		index;
  t_task		*new_task;

  new_task = NULL;
  for (index = 0; index < 11; index++)
    {
      if (strcmp((const char *)tab_command[index], command) == 0)
	{
	  if ((new_task = malloc(sizeof(t_task))) == NULL)
	    return (NULL);
	  function_pointer(new_task, index);
	  timer_task(new_task, index);
	  return (new_task);
	}
    }
  return (new_task);
}

t_task			*new_task(const char *command)
{
  return (add_function_task(command));
}
