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

t_task			*init_new_task(t_server*server, int index,
				       const char *command)
{
  t_task		*new_task;
  char			*argument;

  if ((new_task = malloc(sizeof(t_task))) == NULL)
    return (NULL);
  new_task->argument = NULL;
  function_pointer(new_task, index);
  timer_task(server, new_task, index);
  if ((argument = strtok((char *)command, " ")) != NULL)
    {
      if ((argument = strtok(NULL, " ")) != NULL)
	new_task->argument = strdup(argument);
    }
  return (new_task);
}

t_task			*add_function_task(t_server *server, const char *command)
{
  char			*tab_command[11] = {"avance\n", "droite\n", "gauche\n",
					    "voir\n", "inventaire\n",
					    "prend", "pose",
					    "expulse\n", "broadcast",
					    "incantation\n", "fork\n"};
  unsigned int		index;
  char			buff[64];

  for (index = 0; index < 11; index++)
    {
      memset(buff, 0, 64);
      memcpy(buff, command, strlen(command));
      if (strcmp_function_task(tab_command[index], buff) == 0)
	return (init_new_task(server, index, command));
    }
  return (NULL);
}

t_task			*new_task(t_server *server, const char *command)
{
  printf("[%s]\n", command);
  if (command == NULL)
    return (NULL);
  return (add_function_task(server, command));
}
