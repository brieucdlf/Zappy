//
// ClientGraphic.cpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Tue Jul  1 09:49:02 2014 Jeremy Peltier
// Last update Thu Jul 10 11:32:18 2014 Jeremy Peltier
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

void	ClientGraphic::addLinemate(int x, int y)
{
  std::string	pathTexture = "src_client/client-graphic/resources/images/linemate.tga";

  IsometricSprite	linemate(textures.getTexture(pathTexture));
  linemate.setIsometricPosition(sf::Vector2f(x, y));

  this->window.draw(linemate);
}

void	ClientGraphic::addDeraumere(int x, int y)
{
  std::string	pathTexture = "src_client/client-graphic/resources/images/deraumere.tga";

  IsometricSprite	deraumere(textures.getTexture(pathTexture));
  deraumere.setIsometricPosition(sf::Vector2f(x, y));

  this->window.draw(deraumere);
}

void	ClientGraphic::addSibur(int x, int y)
{
  std::string	pathTexture = "src_client/client-graphic/resources/images/sibur.tga";

  IsometricSprite	sibur(textures.getTexture(pathTexture));
  sibur.setIsometricPosition(sf::Vector2f(x, y));

  this->window.draw(sibur);
}

void	ClientGraphic::addMendiane(int x, int y)
{
  std::string	pathTexture = "src_client/client-graphic/resources/images/mendiane.tga";

  IsometricSprite	mendiane(textures.getTexture(pathTexture));
  mendiane.setIsometricPosition(sf::Vector2f(x, y));

  this->window.draw(mendiane);
}

void	ClientGraphic::addPhiras(int x, int y)
{
  std::string	pathTexture = "src_client/client-graphic/resources/images/phiras.tga";

  IsometricSprite	phiras(textures.getTexture(pathTexture));
  phiras.setIsometricPosition(sf::Vector2f(x, y));

  this->window.draw(phiras);
}

void	ClientGraphic::addThystane(int x, int y)
{
  std::string	pathTexture = "src_client/client-graphic/resources/images/thystane.tga";

  IsometricSprite	thystane(textures.getTexture(pathTexture));
  thystane.setIsometricPosition(sf::Vector2f(x, y));

  this->window.draw(thystane);
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

void	ClientGraphic::generateItems(Map &data)
{
  for (int y = 0; y < data.getHeight(); ++y)
    {
      for (int x = 0; x < data.getWidth(); ++x)
	{
	  if (data.getMap()[y][x][FOOD] > 0)
	    addFood(x, y);
	  if (data.getMap()[y][x][LINEMATE] > 0)
	    addLinemate(x, y);
	  if (data.getMap()[y][x][DERAUMERE] > 0)
	    addDeraumere(x, y);
	  if (data.getMap()[y][x][SIBUR] > 0)
	    addSibur(x, y);
	  if (data.getMap()[y][x][MENDIANE] > 0)
	    addMendiane(x, y);
	  if (data.getMap()[y][x][PHIRAS])
	    addPhiras(x, y);
	  if (data.getMap()[y][x][THYSTAME])
	    addThystane(x, y);
	}
    }
}

void	ClientGraphic::generateGround(int width, int height)
{
  for (int i = 0; i < width; ++i)
    for (int j = 0; j < height; ++j)
      addFloor(i, j);
}

void	ClientGraphic::draw(Map &map)
{
  this->window.clear();
  generateGround(map.getWidth(), map.getHeight());
  generateItems(map);
  this->window.display();
}

void	ClientGraphic::loading(int percent)
{
  this->window.clear();

  int		percentDraw = percent * 3;

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
  front.setPosition(background.getSize().x + 48, this->window.getSize().y / 2 + 52);
  front.setSize(sf::Vector2f(percentDraw, 25));
  this->window.draw(front);

  this->window.display();
}
