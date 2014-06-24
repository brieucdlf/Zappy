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

# include "list.h"

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

typedef	struct			s_param
{
  char				**teams_names;
  int				port;
  int				world_width;
  int				world_height;
  int				nb_client_start;
  int				execution_time;
}				t_param;

typedef struct			s_server
{
  int				fd_socket;
  int				fd_max;
  fd_set			readfd;
  fd_set			writefd;
  t_param			param_server;
}				t_server;

int			create_server(t_server *server);
void			set_param(int argc, char **argv, t_param *param_server);
void			free_double_array(char **tab);
void			close_client_socket(t_list *current_client, void *arg);
void			free_server(t_server *server);

#endif /* !SERVER_H_ */
