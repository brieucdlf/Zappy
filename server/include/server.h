/*
** server.h for zappy in /Users/remihillairet/Epitech/Github/Zappy/server
**
** Made by remi hillairet
** Login   <remihillairet@epitech.net>
**
** Started on  Tue May  13 10:53:07 2014 remi hillairet
** Last update Thu May 15 11:25:28 2014 Brieuc
*/

#ifndef SERVER_H_
# define SERVER_H_

# include <sys/types.h>
# include <sys/socket.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <dirent.h>
# include <stdio.h>
# include <errno.h>
# include "user.h"
# include "list.h"
# include "action.h"

# define ARGUMENT_PARSE		"p:x:y:n:c:t:"
# define DEFAULT_PORT		65510
# define DEFAULT_WIDTH		100
# define DEFAULT_HEIGTH		100
# define CLIENT_START		10
# define EXECUTION_TIME		1

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
  int			fd_socket;
  t_param		param_server;
  char			**client_commands;
  void			(*action_ptr[12])();
}			t_server;

/*
** Dans le main pour le moment
*/
int		socket_init(t_server *);

/*
** ################################################
** # Socket_functions.c
** ################################################
*/
int                     xsocket(int, int, int);
int                     xaccept(int, struct sockaddr *, socklen_t *);
int                     xbind(int, const struct sockaddr *, socklen_t);
int                     xlisten(int, int);

/*
** ################################################
** # INITIALISATION
** ################################################
*/
void			set_param(int argc, char **argv, t_param *param_server);
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

/*
** ################################################
** # FREE FUNCTIONS
** ################################################
*/
void			free_double_array(char **tab);

/*
** ################################################
** # INIT CLIENT COMMANDS
** ################################################
*/

int   init_commands(t_server *server);
void  init_action_ptr(t_server *server);
int   get_command(t_server *server, t_client *current_client, char *command);

#endif /* !SERVER_H_ */
