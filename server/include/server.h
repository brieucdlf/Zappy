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

#endif // SERVER
