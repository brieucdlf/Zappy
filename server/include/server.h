/*
** server.h for zappy in /Users/remihillairet/Epitech/Github/Zappy/server
**
** Made by remi hillairet
** Login   <remihillairet@epitech.net>
**
** Started on  Tue May  13 10:53:07 2014 remi hillairet
** Last update Tue May  13 10:53:07 2014 remi hillairet
*/

#ifndef SERVER_H_
# define SERVER_H_

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <time.h>
# include "user.h"
# include "list.h"

typedef	struct 		s_param
{
  int			port;
  int			world_width;
  int			world_height;
  char			**teams_names;
  int			nb_client_start;
  int			execution_time;
}			t_param;

typedef struct		s_server
{
  t_list		*clients;
  t_param		param_server;
}			t_server;


/*
** ################################################
** # INITIALISATION
** ################################################
*/

void	set_param(int ac, char **av, t_param *param);
void	set_map();

void			add_new_client(t_server *server,
				       int fd_socket, int id_team);

/*
** ################################################
** # TIMER MANAGEMENT for the cycle
** ################################################
*/

void			check_cycle_timer(t_server *server,
					  t_client *current_client);
void			set_timer(t_client *current_client);

#endif /* !SERVER_H_ */
