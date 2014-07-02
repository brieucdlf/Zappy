/*
** user.h for zappy in /home/delafo_b/Projets/Zappy/server
**
** Made by Brieuc
** Login   <delafo_b@epitech.net>
**
** Started on  Tue May 13 11:54:11 2014 Brieuc
** Last update Wed Jul  2 16:42:55 2014 Remi Hillairet
*/

#ifndef USER_H_
# define USER_H_

# include "list.h"
# include "task.h"

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
    NONE,
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

typedef enum
  {
    MAP_DIRECTION_ORIENTATION_NORTH,
    MAP_DIRECTION_ORIENTATION_EAST,
    MAP_DIRECTION_ORIENTATION_SOUTH,
    MAP_DIRECTION_ORIENTATION_WEST
  }orientation;

typedef struct		s_direction
{
  int			getx;
  int			gety;
  int			get_orientation;
}			t_direction;


typedef struct s_server t_server;
typedef struct s_client t_client;

typedef void (*action_function)(t_server *, t_client *);

/*
** ################################################
** # BUFFER STRUCTURE (read and write)
** # put t_task inside the buffer_write list
** ################################################
*/

typedef struct		s_buffer
{
  char			buffer_read[2048];
  int			index_read_buffer;
}			t_buffer;

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
  t_list		*tasks;
  t_list		*write_tasks;
  t_buffer		buffer;
}			t_client;

#endif /* !USER_H_ */
