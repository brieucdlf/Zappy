#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "task.h"

void			free_task(void *task)
{
  free(((t_task *)task)->argument);
  free(task);
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

int			strcmp_function_task(char *command_elem,
					     const char *command)
{
  char			*first_word;

  if ((first_word = strtok((char *)command, " ")) == NULL)
    return (1);
  return (strcmp(command_elem, first_word));
}

t_task			*init_new_task(int index, const char *command)
{
  t_task		*new_task;
  char			*argument;

  if ((new_task = malloc(sizeof(t_task))) == NULL)
    return (NULL);
  new_task->argument = NULL;
  function_pointer(new_task, index);
  timer_task(new_task, index);
  if ((argument = strtok((char *)command, " ")) != NULL)
    new_task->argument = strtok((char *)command, " ");
  return (new_task);
}

t_task			*add_function_task(const char *command)
{
  char			*tab_command[11] = {"avance\n", "droite\n", "gauche\n",
					   "voir\n", "inventaire\n",
					   "prend object\n", "pose object\n",
					   "expulse\n", "broadcast texte\n",
					   "incantation\n", "fork\n"};
  unsigned int		index;

  for (index = 0; index < 11; index++)
    {
      if (strcmp_function_task(tab_command[index], command) == 0)
	return (init_new_task(index, command));
    }
  return (NULL);
}

t_task			*new_task(const char *command)
{
  if (command == NULL)
    return (NULL);
  return (add_function_task(command));
}
