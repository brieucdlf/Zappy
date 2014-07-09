//
// Map.hpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic/includes
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Wed Jul  9 10:47:14 2014 Jeremy Peltier
// Last update Wed Jul  9 14:32:26 2014 Remi Hillairet
//

#ifndef		MAP_HPP_
# define	MAP_HPP_

# include	<vector>

// enum
//   {
//     FOOD = 0,
//     LINEMATE,
//     DERAUMERE,
//     SIBUR,
//     MENDIANE,
//     PHIRAS,
//     THYSTAME
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
