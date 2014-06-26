#ifndef PLAYER_H
# define PLAYER_H

# include "list.h"

typedef struct		s_position
{
  int			x;
  int			y;
}			t_position;

typedef struct		s_player
{
  int			level;
  int			id_team;
  t_position		position;
  int			fd_socket;
  fd_set		readfd;
  fd_set		writefd;
}			t_player;

#endif // PLAYER
