#include "client.h"

void			init_fd_socket(t_client *client)
{
  FD_ZERO(&client->fd.readfd);
  FD_ZERO(&client->fd.writefd);
  FD_SET(client->fd.fd_socket, &client->fd.readfd);
  FD_SET(client->fd.fd_socket, &client->fd.writefd);
}

void			random_command(t_client *client)
{
  char			*command[12] = {"avance\n", "droite\n", "gauche\n", "voir\n",
					"inventaire\n", "prend objet\n", "pose objet\n",
					"expulse\n", "broadcast texte\n",
					"incantation\n", "fork\n", "connect_nbr\n"};
  int			index = rand() % 12;
  int			ret;

  ret = 0;
  while ((ret = write(client->fd.fd_socket, command[index],
		      strlen(&command[index][ret]))) != (int)strlen(command[index]));
}

void			read_answer_server(t_client *client)
{
  char			*s;

  s = get_next_line(client->fd.fd_socket);
  printf("answer client : %s\n", s);
  free(s);
}

void			main_loop_client(t_client *client)
{
  int			ret_select;
  int			index = 0;

  client->is_connected = 1;
  while (client->is_connected == 1 && index < 100000)
    {
      init_fd_socket(client);
      if ((ret_select = select(client->fd.fd_socket + 1, &client->fd.readfd,
		  &client->fd.writefd, NULL, NULL)) != -1)
	{
	  if (FD_ISSET(client->fd.fd_socket, &(client->fd.readfd)))
	    {
	      read_answer_server(client);
	      //call get_next_line with client->fd.fd_socket
	      //	      printf("read server\n");
	    }
	  if (FD_ISSET(client->fd.fd_socket, &(client->fd.writefd)))
	    {
	      random_command(client);
	      //printf("write server\n");
	    }
	}
      if (ret_select == EBADF)
	return ;
      index++;
      /* sleep(3); */
    }
}
