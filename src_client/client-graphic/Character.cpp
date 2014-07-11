#include "Character.hpp"

Character::Character()
{
  posX = 0;
  posY = 0;
  playerOrientation = UNKNOWN;
  playerLevel = 0;
  playerTeam = "";
}

Character::Character(int x, int y, Orientation orient, int level, std::string team)
{
  posX = x;
  posY = y;
  playerOrientation = orient;
  playerLevel = level;
  playerTeam = team;
}

Character::Character(const Character & character)
{
  posX = character.getPosX();
  posY = character.getPosY();
  playerOrientation = character.getOrientation();
  playerLevel = character.getLevel();
  playerTeam = character.getTeam();
}

Character::~Character(){}

void Character::setPosition(int x, int y, Orientation orient)
{
  posX = x;
  posY = y;
  playerOrientation = orient;
}

void Character::setLevel(int level)
{
  playerLevel = level;
}

void Character::setInventary(Inventory inventary)
{
  playerInventary = inventary;
}

int Character::getPosX() const
{
  return posX;
}

int Character::getPosY() const
{
  return posY;
}

Orientation Character::getOrientation() const
{
  return playerOrientation;
}

int Character::getLevel() const
{
  return playerLevel;
}

Inventory Character::getInventary() const
{
  return playerInventary;
}

const std::string & Character::getTeam() const
{
  return playerTeam;
}
