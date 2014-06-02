#ifndef		INCLUDE_H_
# define	INCLUDE_H_


typedef enum
{
  LINEMATE,
  DERAUMERE,
  SIBUR,
  MENDIANE,
  PHIRAS,
  THYSTAME,
}	Stone;

typedef struct	s_position
{
  int		x;
  int		y;
}		t_position;

typedef struct	s_inventory
{
  int		linemate;
  int		deraumere;
  int		sibur;
  int		mendiane;
  int		phiras;
  int		thystame;
}		t_inventory;

typedef struct	s_player
{
  int		level;
  int		vision;
  t_position	position;
  t_inventory	inventory;
}		t_player;

void	eat(void);
void	search(void);
void	move(t_player *);
void	elevation(void);

#endif		/* !INCLUDE_H_ */
