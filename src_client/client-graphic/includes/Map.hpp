#ifndef		MAP_HPP_
# define	MAP_HPP_

# include	<vector>
# include	<map>

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
  int		getPercentageLoaded() const;
  std::map<int, std::map<int, Inventory> >	&getMap();

private:
  int	width;
  int	height;
  int	percentageLoaded;
  int	timeUnit;
  std::map<int, std::map<int, Inventory> > map;
};

 #endif		/* !MAP_HPP_ */
