/*
** graphic_client.h for zappy in /home/hillai_a/Modules/githubRepo/Zappy/src_server/include
**
** Made by Remi Hillairet
** Login   <hillai_a@epitech.net>
**
** Started on  Tue Jul  1 15:56:42 2014 Remi Hillairet
** Last update Tue Jul  8 14:50:38 2014 Remi Hillairet
*/

#ifndef GRAPHIC_CLIENT_H
# define GRAPHIC_CLIENT_H

typedef struct s_server	t_server;
typedef struct s_client	t_client;

/*
** ################################################
** # manage_graphic_client.c
** ################################################
*/

void	init_graphic_client(t_server *server);
void	add_new_graphic_client(t_server *server, int fd_socket);
int	check_is_graphic_client(t_server *server, t_client *client, char *command);
int	manage_graphic_client(t_server *server);

/*
** ################################################
** # command_graphic_client.c
** ################################################
*/

void	content_at_pos(t_server *server, int x, int y, char *command);
void	create_map_task(t_server *server, char *command);
void	deconnection_graphic_client(t_server *server);

/*
** ################################################
** # read_write_graphic_client.c
** ################################################
*/

int	check_graphic_client_read(t_server *server);
int	check_graphic_client_write(t_server *server, t_client *client);

#endif /* !GRAPHIC_CLIENT_H */
