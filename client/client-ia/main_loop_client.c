#include "client.h"

void			init_fd_socket(t_client *client)
{
  FD_ZERO(&client->fd.readfd);
  FD_ZERO(&client->fd.writefd);
  FD_SET(client->fd.fd_socket, &client->fd.readfd);
  FD_SET(client->fd.fd_socket, &client->fd.writefd);
}

void			main_loop_client(t_client *client)
{
  int			ret_select;

  client->is_connected = 1;
  while (client->is_connected == 1)
    {
      init_fd_socket(client);
      if ((ret_select = select(client->fd.fd_socket + 1, &client->fd.readfd,
		  &client->fd.writefd, NULL, NULL)) != -1)
	{
	  if (FD_ISSET(client->fd.fd_socket, &(client->fd.readfd)))
	    {
	      printf("read server\n");
	    }
	  if (FD_ISSET(client->fd.fd_socket, &(client->fd.writefd)))
	    {
	      printf("write server\n");
	    }
	}
      if (ret_select == EBADF)
	return ;
    }
}
