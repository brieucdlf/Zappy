//
// Map.cpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Wed Jul  9 10:49:21 2014 Jeremy Peltier
// Last update Wed Jul  9 14:33:45 2014 Remi Hillairet
//

#include	"Map.hpp"

Map::Map()
{
  width = 0;
  height = 0;
  timeUnit = 0;
}

Map::~Map()
{
  this->map.clear();
}

void	Map::add(Inventory inventory, int x, int y)
{
  this->map[y][x] = inventory;
}

Inventory	Map::get(int x, int y)
{
  return this->map[x][y];
}

void	Map::setWidth(int width)
{
  this->width = width;
}

int	Map::getWidth() const
{
  return this->width;
}

void	Map::setHeight(int height)
{
  this->height = height;
}

int	Map::getHeight() const
{
  return this->height;
}

void	Map::setTimeUnit(int timeUnit)
{
  this->timeUnit = timeUnit;
}

int	Map::getTimeUnit() const
{
  return this->timeUnit;
}
