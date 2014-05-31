#ifndef CLIENT_H
#define CLIENT_H

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

typedef struct		s_client
{
  int			fd_socket;
  struct sockaddr_in	sin_server;
}			t_client;

int			connect_server(t_client *client,
				       const char *addr_server,
					 int port_server);

#endif // CLIENT
