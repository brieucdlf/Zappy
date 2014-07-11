#ifndef __CHARACTER_HPP__
# define __CHARACTER_HPP__

# include <string>
# include "Map.hpp"

typedef enum
{
  UNKNOWN = 0,
  NORTH,
  EAST,
  SOUTH,
  WEST
}	Orientation;

class Character
{
public:
  Character();
  Character(int x, int y, Orientation orient, int level, std::string team);
  Character(const Character & character);
  virtual ~Character();

public:
  void setPosition(int x, int y, Orientation orient);
  void setLevel(int level);
  void setInventary(Inventory inventary);

public:
  int getPosX() const;
  int getPosY() const;
  Orientation getOrientation() const;
  int getLevel() const;
  Inventory getInventary() const;
  const std::string & getTeam() const;

private:
  int posX;
  int posY;
  Orientation playerOrientation;
  int playerLevel;
  Inventory playerInventary;
  std::string playerTeam;
};

#endif /* !__CHARACTER_HPP__ */
