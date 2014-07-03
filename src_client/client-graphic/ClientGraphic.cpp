//
// ClientGraphic.cpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Tue Jul  1 09:49:02 2014 Jeremy Peltier
// Last update Wed Jul  2 18:36:07 2014 Jeremy Peltier
//

#include "ClientGraphic.hpp"
#include "IsometricSprite.hpp"
#include <string>

ClientGraphic::ClientGraphic(int width, int height)
{
  this->window.create(sf::VideoMode(width, height, 32), "Client Graphic");
  this->window.clear();
  this->window.display();
  this->x = 0;
  this->y = 0;
}

ClientGraphic::~ClientGraphic() {}

bool	ClientGraphic::isOpen() const
{
  return this->window.isOpen();
}

void	ClientGraphic::getKey()
{
  while (this->window.pollEvent(this->event))
    {
      if (this->event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	this->window.close();
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	this->y += 20;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	this->y -= 20;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	this->x += 20;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	this->x -= 20;
    }
}

void	ClientGraphic::generateMap(int width, int height)
{
  this->window.clear();

  std::cout << "x : " << this->x << " y : " << this->y << std::endl;

  width = width;
  height = height;
  std::string name = "resources/images/floor.tga";

  sf::Texture texture;
  texture.loadFromFile(name);

  IsometricSprite isoSprite(texture);
  IsometricSprite isoSprite2(texture);

  if (width > (int)this->window.getSize().x)
    width -= this->window.getSize().x;
  if (height > (int)this->window.getSize().y)
    height -= this->window.getSize().y;

  for (int i = this->x; i < width - this->x; ++i)
    for (int j = this->y; j < height - this->y; ++j)
      {
	isoSprite.setIsometricPosition(sf::Vector2f(i, j));
	this->window.draw(isoSprite);
      }
  this->window.setView(this->window.getDefaultView());

  this->window.display();
}
