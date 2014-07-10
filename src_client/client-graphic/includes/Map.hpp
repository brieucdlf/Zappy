//
// Map.hpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic/includes
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Wed Jul  9 10:47:14 2014 Jeremy Peltier
// Last update Thu Jul 10 10:17:11 2014 Jeremy Peltier
//

#ifndef		MAP_HPP_
# define	MAP_HPP_

# include	<vector>

typedef enum
  {
    FOOD = 0,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
  }		Item;

typedef	std::vector<int>	Inventory;

class		Map
{
public:
  Map();
  virtual ~Map();

public:
  void		add(Inventory, int, int);
  Inventory	get(int, int);

public:
  void		setWidth(int);
  int		getWidth() const;
  void		setHeight(int);
  int		getHeight() const;
  void		setTimeUnit(int);
  int		getTimeUnit() const;
  void		setPercentageLoaded(int);
  std::vector<std::vector<Inventory> >	&getMap();

private:
  int	width;
  int	height;
  int	percentageLoaded;
  int	timeUnit;
  std::vector<std::vector<Inventory> >	map;
};

#endif		/* !MAP_HPP_ */
