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

# define BUFFER_GET_LINE        8192

typedef struct		s_fd
{
  int			fd_socket;
  fd_set		readfd;
  fd_set		writefd;
}			t_fd;

typedef struct		s_client
{
  struct sockaddr_in	sin_server;
  int			is_connected;
  t_fd			fd;
}			t_client;

int			connect_server(t_client *client,
				       const char *addr_server,
					 int port_server);
void			main_loop_client(t_client *client);
char			*get_next_line(int fd);

#endif // CLIENT
