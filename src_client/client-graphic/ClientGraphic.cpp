//
// ClientGraphic.cpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Tue Jul  1 09:49:02 2014 Jeremy Peltier
// Last update Tue Jul  8 15:31:03 2014 Jeremy Peltier
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
  this->zoom = 1;
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

      sf::View view = this->window.getDefaultView();
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	this->x -= 10;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	this->x += 10;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	this->y -= 10;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	this->y += 10;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
	this->zoom -= 1;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
	this->zoom += 1;
      if (this->zoom < 1)
	this->zoom = 1;
      view.move(this->x, this->y);
      view.zoom(this->zoom);
      this->window.setView(view);
    }
}

void	ClientGraphic::addFloor(int x, int y)
{
  std::string	pathTexture = "src_client/client-graphic/resources/images/grass.png";

  IsometricSprite	floor(textures.getTexture(pathTexture));
  floor.setIsometricPosition(sf::Vector2f(x, y));

  this->window.draw(floor);
}

void	ClientGraphic::addStone(int x, int y)
{
  std::string	pathTexture = "resources/images/stone.tga";

  IsometricSprite	stone(textures.getTexture(pathTexture));
  stone.setIsometricPosition(sf::Vector2f(x, y));

  this->window.draw(stone);
}

void	ClientGraphic::addFood(int x, int y)
{
  std::string	pathTexture = "resources/images/food.tga";

  IsometricSprite	food(textures.getTexture(pathTexture));
  food.setIsometricPosition(sf::Vector2f(x, y));

  this->window.draw(food);
}

void	ClientGraphic::addCharacter(int x, int y)
{
  x = x;
  y = y;
}

void	ClientGraphic::generateItems()
{
}

void	ClientGraphic::generateMap(int width, int height)
{
  for (int i = 0; i < width; ++i)
    for (int j = 0; j < height; ++j)
      addFloor(i, j);
}

void	ClientGraphic::draw(int width, int height)
{
  this->window.clear();
  generateMap(width, height);
  generateItems();
  this->window.display();
}

void	ClientGraphic::loading()
{
  this->window.clear();

  sf::Color	color(230, 126, 34);
  sf::Color	color2(211, 84, 0);

  sf::Font	font;
  font.loadFromFile("src_client/client-graphic/resources/fonts/game_power.ttf");

  sf::Text text;
  text.setFont(font);
  text.setString("Loading...");
  text.setCharacterSize(100);
  text.setPosition(this->window.getSize().x / 4, this->window.getSize().y / 2 - 100);
  text.setColor(color);
  text.setStyle(sf::Text::Bold);
  this->window.draw(text);

  sf::RectangleShape	background;
  background.setFillColor(sf::Color::Transparent);
  background.setOutlineColor(color);
  background.setOutlineThickness(1);
  background.setPosition(this->window.getSize().x / 2 - 152, this->window.getSize().y / 2 + 50);
  background.setSize(sf::Vector2f(304, 29));
  this->window.draw(background);

  sf::RectangleShape	front;
  front.setFillColor(color2);
  front.setPosition(this->window.getSize().x / 2 - 150, this->window.getSize().y / 2 + 52);
  front.setSize(sf::Vector2f(300, 25));
  this->window.draw(front);

  this->window.display();
}
