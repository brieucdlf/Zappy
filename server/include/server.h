#ifndef SERVER_H
# define SERVER_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "user.h"
# include "list.h"

typedef struct		s_server
  {
    t_list		*clients;
  }			t_server;


typedef	struct 		s_param
  {
    int			port;
    int			world_width;
    int			world_height;
    char		**teams_names;
    int			nb_client_start;
    int			execution_time;
  }			t_param;

#endif // SERVER