#ifndef CLIENT_H
# define CLIENT_H

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
  char			current_action;
  action		current_cycle;
}			t_action;

typedef struct		s_client
{
  int			level;
  int			items[6];
  t_action		current_action;
}			t_client;

#endif /* CLIENT */
