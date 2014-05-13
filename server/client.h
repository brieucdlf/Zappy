/*
** client.h for zappy in /Users/remihillairet/Epitech/Github/Zappy/server
**
** Made by remi hillairet
** Login   <remihillairet@epitech.net>
**
** Started on  Tue May  13 10:43:27 2014 remi hillairet
** Last update Tue May  13 10:43:27 2014 remi hillairet
*/

#ifndef CLIENT_H_
# define CLIENT_H_

typedef enum
  {
    NONE = 0,
    RIGTH,
    LEFT,
    MOVE,
    SEE,
    INVENTARY,
    TAKE_OBJECT,
    DROP_OBJECT,
    PUSH,
    BROADCAST_TEXT,
    FORK,
    INCANTATION
  }action;

typedef struct		s_action
  {
    char		current_action;
    action		current_cycle;
  }			t_action;

typedef struct		s_client
  {
    int			level;
    int			items[6];
    t_action		current_action;
  }			t_client;

#endif /* !CLIENT_H_ */
