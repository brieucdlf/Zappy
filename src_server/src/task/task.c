#include "server.h"

int			strcmp_function_task(char *command_elem,
					     const char *command)
{
  char			*first_word;

  if ((first_word = strtok((char *)command, " ")) == NULL)
    return (1);
  if (strcmp(command_elem, first_word) == 0)
    return (0);
  if ((first_word = strtok((char *)first_word, "\n")) == NULL)
    return (1);
  if (strcmp(command_elem, first_word) == 0)
    return (0);
  return (1);
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
  char			buff[2048];

  for (index = 0; index < 11; index++)
    {
      memset(buff, 0, 2048);
      strncpy(buff, command, 2048);
      if (strcmp_function_task(tab_command[index], buff) == 0)
	return (init_new_task(server, index, command));
    }
  return (NULL);
}

t_task			*new_task(t_server *server, const char *command)
{
  if (command == NULL)
    return (NULL);
  return (add_function_task(server, command));
}
