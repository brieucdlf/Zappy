#ifndef SERVER_H
# define SERVER_H

# include "client.h"
# include "list.h"

typedef struct		s_server
{
  t_list		*clients;
}			t_server;

#endif // SERVER
