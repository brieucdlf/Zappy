/*
** user.h for zappy in /home/delafo_b/Projets/Zappy/server
**
** Made by Brieuc
** Login   <delafo_b@epitech.net>
**
** Started on  Tue May 13 11:54:11 2014 Brieuc
** Last update Tue May 13 11:54:15 2014 Brieuc
*/

#ifndef USER_H_
# define USER_H_

# include "list.h"

typedef enum
  {
    CYCLE_RIGTH = 7,
    CYCLE_LEFT = 7,
    CYCLE_MOVE = 7,
    CYCLE_SEE = 7,
    CYCLE_INVENTARY = 1,
    CYCLE_TAKE_OBJECT = 7,
    CYCLE_DROP_OBJECT = 7,
    CYCLE_PUSH = 7,
    CYCLE_BROADCAST_TEXT = 7,
    CYCLE_FORK = 42,
    CYCLE_INCANTATION = 300
  }cycle_action;

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

typedef struct s_server t_server;
typedef struct s_client t_client;

typedef void (*action_function)(t_server *, t_client *);

/*
** ################################################
** # BUFFER STRUCTURE (read and write)
** # put t_task inside the buffer_write list
** ################################################
*/

typedef struct		s_task
{
  char			*cmd;
  int			current_index;
}			t_task;

typedef struct		s_buffer
{
  t_list	        *buffer_write;
  char			*buffer_read;
}			t_buffer;

/*
** ################################################
** # ACTION STRUCTURE (commands)
** ################################################
*/

typedef struct		s_action
{
  char			is_cycle;
  action		type;
  struct timespec	timer_cycle;
  action_function	action_fct;
}			t_action;

/*
** ################################################
** # CLIENT STRUCTURE whith the informations
** ################################################
*/

typedef struct		s_client
{
  int			level;
  int			id_team;
  int			fd_socket;
  int			items[6];
  t_action	        action;
  t_buffer		buffer;
}			t_client;

#endif /* !USER_H_ */
