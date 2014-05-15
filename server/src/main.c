/*
** main.c for zappy in /Users/remihillairet/Epitech/Github/Zappy/server
**
** Made by remi hillairet
** Login   <remihillairet@epitech.net>
**
** Started on  Tue May  13 10:45:33 2014 remi hillairet
** Last update Tue May 13 11:55:05 2014 Brieuc
*/

#include "user.h"
#include "server.h"

void		test_list();

int		main(int ac, char **av)
{
  t_param	param_server;

  (void)ac;
  (void)av;
  set_param(ac, av, &param_server);
  free_double_array(param_server.teams_names);
  return (0);
}
