#ifndef SERVER_H
# define SERVER_H

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

# include "user.h"
# include "list.h"

typedef struct		s_server
{
  t_list		*clients;
  int			port;
  
}			t_server;

int		socket_init(t_server *, char **);

/*
** socket_functions.c 
*/
int                     xsocket(int, int, int);
int                     xaccept(int, struct sockaddr *, socklen_t *);
int                     xbind(int, const struct sockaddr *, socklen_t);
int                     xlisten(int, int);
void                    xport(t_server *);


#endif // SERVER
