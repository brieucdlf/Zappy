/*
** server.h for zappy in /Users/remihillairet/Epitech/Github/Zappy/server
**
** Made by remi hillairet
** Login   <remihillairet@epitech.net>
**
** Started on  Tue May  13 10:53:07 2014 remi hillairet
** Last update Tue Jun 10 11:20:41 2014 romain combe
** Last update Thu May 15 14:02:11 2014 Brieuc
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
# include <time.h>
# include "user.h"
# include "list.h"
# include "action.h"

# define ARGUMENT_PARSE		"p:x:y:n:c:t:"
# define DEFAULT_PORT		65510
# define DEFAULT_WIDTH		100
# define DEFAULT_HEIGHT		100
# define MIN_WIDTH		100
# define MIN_HEIGHT		100
# define MAX_WIDTH		1000
# define MAX_HEIGHT		1000
# define CLIENT_START		10
# define EXECUTION_TIME		1
# define TIMEOUT_SEC		0
# define TIMEOUT_USEC		1

typedef enum
  {
    LINEMATE = 1,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
  }rocks;

typedef	struct 		s_param
{
  char			**teams_names;
  int			port;
  int			world_width;
  int			world_height;
  int			nb_client_start;
  int			execution_time;
}			t_param;

typedef struct		s_map
{
  char			**map;
  int			width;
  int			height;
  int			nb_linemate;
  int			nb_deraumere;
  int			nb_sibur;
  int			nb_mendiane;
  int			nb_phiras;
  int			nb_thystame;
}			t_map;

typedef struct		s_server
{
  t_list		*clients;
  t_param		param_server;
  t_map			map;
  t_buffer		buffer;
  void			(*action_ptr[12])();
  char			**client_commands;
  int			fd_socket;
  int			fd_max;
  fd_set		readfd;
  fd_set		writefd;
  fd_set		*exceptfd;
}			t_server;

/*
** ################################################
** # Socket_functions.c
** ################################################
*/
int			map_check_read_client(t_list *current_client, void *arg);
int			map_check_write_client(t_list *current_client,
					       void *arg);
void			deconnection_client(t_server *server,
					    t_client *current_client);

/*
** ################################################
** # INITIALISATION
** ################################################
*/
void			set_param(int argc, char **argv, t_param *param_server);
void			add_new_client(t_server *server,
				       int fd_socket, int id_team);
int			socket_init(t_server *server);
void			init_fd_socket(t_server *server);
int			create_server(t_server *server);

/*
** ################################################
** # run_server.c
** ################################################
*/
void			server_loop(t_server *);
void			check_connect_client(t_server *server);

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
void			free_server(t_server *server);

/*
** ################################################
** # init_map.c
** ################################################
*/

void			init_map(t_map *map);
char			**malloc_tab(int width, int height);
void			fill_map(t_map *map);
int			init_commands(t_server *server);
void			init_action_ptr(t_server *server);
int			get_command(t_server *server, t_client *current_client, char *command);

/*
** ################################################
** # test_map.c
** ################################################
*/

void		add_new_rocks(t_map *map, int nb_rocks, int rock_kind);
void		loop_nb_rocks(t_map *map);
void		check_nb_rocks(t_map *map, int rock_kind);

#endif /* !SERVER_H_ */