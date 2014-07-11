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
# include "graphic_client.h"

# define WELCOME_MESSAGE	"BIENVENUE\n"

# define ARGUMENT_PARSE		"p:x:y:n:c:t:"
# define DEFAULT_PORT		65510
# define DEFAULT_WIDTH		20
# define DEFAULT_HEIGHT		100
# define MIN_WIDTH		10
# define MIN_HEIGHT		10
# define MAX_WIDTH		1000
# define MAX_HEIGHT	        1000
# define CLIENT_TEAM		10
# define EXECUTION_TIME		1
# define TIMEOUT_SEC		0
# define TIMEOUT_USEC		1

# define TIMEOUT_CLIENT		25
# define SLEEP_CLIENT		10

# define FOOD_ADD		126
# define FOOD_LIVE		1260

typedef enum
  {
    FOOD = 0,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
  }items;

typedef	struct 		s_param
{
  char			**teams_names;
  int			port;
  int			world_width;
  int			world_height;
  int			nb_client_team;
  int			execution_time;
  int			*number_client;
}			t_param;

typedef struct		s_item
{
  int			type;
  int			posx;
  int			posy;
  int			is_taken;
}			t_item;

typedef struct		s_map
{
  t_list		***map;
  t_list		*items;
  int			width;
  int			height;
  int			nb_rocks;
  int			nb_linemate;
  int			nb_deraumere;
  int			nb_sibur;
  int			nb_mendiane;
  int			nb_phiras;
  int			nb_thystame;
  int			nb_food;
}			t_map;

typedef struct		s_server
{
  t_list		*clients;
  t_client		*graphic_client;
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
int			write_task_socket(t_write_task *head_task,
					  t_client *current_client,
					  t_server *server);
void			deconnection_client(t_server *server,
					    t_client *current_client);
int			match_fd_socket_client(void *client1, void *client2);
void			update_max_fd_socket(t_list *current_client, void *server);

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
void			check_timer(t_server *server);

/*
** ################################################
** # FREE FUNCTIONS
** ################################################
*/
void			free_double_array(char **tab);
void			free_server(t_server *server);
void			free_client(void *arg);

/*
** ################################################
** # init_map.c
** ################################################
*/
void			generate_food(t_server *server);
int			init_map(t_server *server);
void			free_item(void *item);

/*
** ################################################
** # test_map.c
** ################################################
*/

void			add_new_rocks(t_map *map, int nb_rocks, int rock_kind);
void			loop_nb_rocks(t_map *map);
void			check_nb_rocks(t_map *map, int rock_kind);

void			create_new_write_task(t_client *current_client,
					      const char *command);


/*
** TEAM MANAGEMENT
*/
void			manage_teams(t_server *server);
int			get_id_team(t_server *server, const char *team);

int			create_map(t_server *server);

/*
** ################################################
** # PATH FINDER
** ################################################
*/
int			path_finder(char **map, int number_path,
				    t_server *server);
void			find_best_path(t_client *current_client, char **map,
				       t_server *server, char *message);
void		       	init_timer_client(t_client *client);
int		       	check_timeout(t_list *current_item, void *arg);

/*
** ################################################
** # FOOD
** ################################################
*/
void			init_timer_food(t_server *server, t_client *client);
void			add_live_food(t_server *server, t_client *client);

void			check_timer_clients(t_server *server);

void			free_double_array_delimiter(char **tab,
						    unsigned int height);

void			query_first_connection(t_server *server,
					       t_client *current_client);
void			init_position_client(t_client *current_client,
					     t_server *server);
void			free_task(void *task);
void			function_pointer(t_task *task, unsigned int index);

#endif /* !SERVER_H_ */
