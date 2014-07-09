//
// Map.hpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic/includes
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Wed Jul  9 10:47:14 2014 Jeremy Peltier
// Last update Wed Jul  9 12:14:05 2014 Jeremy Peltier
//

#ifndef		MAP_HPP_
# define	MAP_HPP_

# include	<vector>

// enum
//   {
//     FOOD = 0,
//     LINEMATE = 1,
//     DERAUMERE = 2,
//     SIBUR = 3,
//     MENDIANE = 4,
//     PHIRAS = 5,
//     THYSTAME = 6,
//   }		item;

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
  void	setWidth(int);
  int	getWidth() const;
  void	setHeight(int);
  int	getHeight() const;
  void	setTimeUnit(int);
  int	getTimeUnit() const;

private:
  int	width;
  int	height;
  int	timeUnit;
  std::vector<std::vector<Inventory> >	map;
};

#endif		/* !MAP_HPP_ */
