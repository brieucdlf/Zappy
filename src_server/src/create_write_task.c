#include "server.h"

void			free_write_task(void *data)
{
  free(data);
}

void			create_new_write_task(t_client *current_client,
					      const char *command)
{
  t_write_task		*new_task;

  if ((new_task = malloc(sizeof(t_write_task))) == NULL)
    return ;
  new_task->index = 0;
  memset(new_task->buffer, 0, 10240);
  memcpy(new_task->buffer, command, strlen(command));
  list_push(&current_client->write_tasks, (void *)new_task, free_write_task);
}
