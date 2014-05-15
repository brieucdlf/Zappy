/*
** action.h for zappy in /Users/remihillairet/Epitech/Github/toto/Zappy/server/include
**
** Made by remi hillairet
** Login   <remihillairet@epitech.net>
**
** Started on  Thu May  15 11:16:41 2014 remi hillairet
** Last update Thu May  15 11:16:41 2014 remi hillairet
*/

#ifndef ACTION_H
# define ACTION_H

void		        action_broadcast(t_server *server,
t_client *current_client);
void		        action_fork(t_server *server, t_client *current_client);
void			action_incantation(t_server *server,
t_client *current_client);
void			action_push(t_server *server, t_client *current_client);
void			action_move(t_server *server, t_client *current_client);
void			action_rigth(t_server *server,
t_client *current_client);
void		        action_left(t_server *server, t_client *current_client);
void			action_inventary(t_server *server,
t_client *current_client);
void			action_take_object(t_server *server,
t_client *current_client);
void		        action_drop_object(t_server *server,
t_client *current_client);
void			action_see(t_server *server, t_client *current_client);


void			action_connect_nbr(t_server *server,
t_client *current_client);
void			exec_action(t_server *server, t_client *current_client);

#endif /* !ACTION_H_ */
