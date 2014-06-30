#include "task.h"

void			avance_task_function(void *server, void *client)
{
  (void *)server;
  (void *)client;
  printf("avance\n");
}

void			droite_task_function(void *server, void *client)
{
  (void *)server;
  (void *)client;
  printf("droite\n");
}

void			gauche_task_function(void *server, void *client)
{
  (void *)server;
  (void *)client;
  printf("gauche\n");
}

void			voir_task_function(void *server, void *client)
{
  (void *)server;
  (void *)client;
  printf("voir\n");
}

void			inventaire_task_function(void *server, void *client)
{
  (void *)server;
  (void *)client;
  printf("inventaire\n");
}
