/*
** graphic_client.h for zappy in /home/hillai_a/Modules/githubRepo/Zappy/src_server/include
**
** Made by Remi Hillairet
** Login   <hillai_a@epitech.net>
**
** Started on  Tue Jul  1 15:56:42 2014 Remi Hillairet
** Last update Fri Jul  4 13:03:05 2014 Remi Hillairet
*/

#ifndef GRAPHIC_CLIENT_H
# define GRAPHIC_CLIENT_H

#include "server.h"

/*
** ################################################
** # manage_graphic_client.c
** ################################################
*/

void	init_graphic_client(t_server *server);
void	add_new_graphic_client(t_server *server, int fd_socket);
int	check_is_graphic_client(t_server *server, t_client *client, char *command);
void	content_at_pos(t_server *server, int x, int y, char *command);
void	create_map_task(t_server *server, char *command);
void	deconnection_graphic_client(t_server *server);
int	check_graphic_client_read(t_server *server);
int	check_graphic_client_write(t_server *server, t_client *client);
int	manage_graphic_client(t_server *server);

#endif /* !GRAPHIC_CLIENT_H */
