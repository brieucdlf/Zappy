#include "server.h"

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
