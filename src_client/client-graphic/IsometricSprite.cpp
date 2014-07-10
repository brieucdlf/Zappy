//
// IsometricSprite.cpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Tue Jul  1 15:22:10 2014 Jeremy Peltier
// Last update Thu Jul 10 11:56:01 2014 Jeremy Peltier
//

#include	<iostream>
#include	"IsometricSprite.hpp"

IsometricSprite::IsometricSprite() : sf::Sprite()
{
  this->mapPosition = sf::Vector2f(0, 0);
}

IsometricSprite::IsometricSprite(const sf::Texture &texture, const sf::Vector2f &position) : sf::Sprite(texture)
{
  this->mapPosition = position;
  this->zPosition = 0;

  sf::Vector2f screenPosition = sf::Vector2f(300 + this->mapPosition.x * -30 + this->mapPosition.y * 30, this->mapPosition.x * 15 + this->mapPosition.y * 15);
  setPosition(screenPosition);

  sf::FloatRect rec = getLocalBounds();
  setScale(getScale().x * 60 / rec.width, getScale().y * 30 / rec.height);
}

IsometricSprite::~IsometricSprite() {}

void	IsometricSprite::setIsometricPosition(sf::Vector2f point)
{
  this->mapPosition = point;

  sf::Vector2f screenPosition = sf::Vector2f(300 + this->mapPosition.x * -30 + this->mapPosition.y * 30, this->mapPosition.x * 15 + this->mapPosition.y * 15);
  setPosition(screenPosition);
}

sf::Vector2f	IsometricSprite::getIsometricPosition(void) const
{
  return this->mapPosition;
}

void	IsometricSprite::setIsometricZ(float zPosition)
{
  this->zPosition = zPosition;

  sf::Vector2f screenPosition = sf::Vector2f(this->mapPosition.x, this->mapPosition.y * 2);
  setPosition(screenPosition);
}

float	IsometricSprite::getIsometricZ(void) const
{
  return this->zPosition;
}
