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

/*
** ################################################
** # BUFFER STRUCTURE
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
  char		current_action;
  action		current_cycle;
}			t_action;

/*
** ################################################
** # CLIENT STRUCTURE whith the informations
** ################################################
*/

typedef struct		s_client
{
  int			level;
  int			fd_socket;
  int			items[6];
  t_action		current_action;
}			t_client;

#endif /* !USER_H_ */
