//
// Map.cpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Wed Jul  9 10:49:21 2014 Jeremy Peltier
// Last update Thu Jul 10 11:00:17 2014 Jeremy Peltier
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

void	Map::setPercentageLoaded(int percentage)
{
  percentageLoaded = percentage;
}

int	Map::getPercentageLoaded() const
{
  return this->percentageLoaded;
}

std::map<int, std::map<int, Inventory> >	&Map::getMap()
{
  return this->map;
}
