//
// ClientGraphic.cpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Tue Jul  1 09:49:02 2014 Jeremy Peltier
// Last update Thu Jul 10 12:20:51 2014 Jeremy Peltier
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

void	ClientGraphic::addFood(int x, int y)
{
  sf::CircleShape	food(10);
  food.setFillColor(sf::Color(243, 156, 18));

  sf::Vector2f	screenPosition = sf::Vector2f(300 + x * -30 + y * 30, x * 15 + y * 15);
  food.setPosition(screenPosition);

  sf::FloatRect rec = food.getLocalBounds();
  food.setScale(food.getScale().x * 20 / rec.width, food.getScale().y * 10 / rec.height);

  this->window.draw(food);
}

void	ClientGraphic::addLinemate(int x, int y)
{
  // std::string	pathTexture = "src_client/client-graphic/resources/images/linemate.tga";

  // IsometricSprite	linemate(textures.getTexture(pathTexture));
  // linemate.setIsometricPosition(sf::Vector2f(x, y));

  sf::CircleShape	linemate(10);
  linemate.setFillColor(sf::Color(231, 76, 60));

  sf::Vector2f	screenPosition = sf::Vector2f(300 + x * -30 + y * 30, x * 15 + y * 15);
  linemate.setPosition(screenPosition);

  sf::FloatRect rec = linemate.getLocalBounds();
  linemate.setScale(linemate.getScale().x * 20 / rec.width, linemate.getScale().y * 10 / rec.height);

  this->window.draw(linemate);
}

void	ClientGraphic::addDeraumere(int x, int y)
{
  // std::string	pathTexture = "src_client/client-graphic/resources/images/deraumere.tga";

  // IsometricSprite	deraumere(textures.getTexture(pathTexture));
  // deraumere.setIsometricPosition(sf::Vector2f(x, y));

  sf::CircleShape	deraumere(10);
  deraumere.setFillColor(sf::Color(52, 73, 94));

  sf::Vector2f	screenPosition = sf::Vector2f(300 + x * -30 + y * 30, x * 15 + y * 15);
  deraumere.setPosition(screenPosition);

  sf::FloatRect rec = deraumere.getLocalBounds();
  deraumere.setScale(deraumere.getScale().x * 20 / rec.width, deraumere.getScale().y * 10 / rec.height);

  this->window.draw(deraumere);
}

void	ClientGraphic::addSibur(int x, int y)
{
  sf::CircleShape	sibur(10);
  sibur.setFillColor(sf::Color(39, 174, 96));

  sf::Vector2f	screenPosition = sf::Vector2f(300 + x * -30 + y * 30, x * 15 + y * 15);
  sibur.setPosition(screenPosition);

  sf::FloatRect rec = sibur.getLocalBounds();
  sibur.setScale(sibur.getScale().x * 20 / rec.width, sibur.getScale().y * 10 / rec.height);

  this->window.draw(sibur);
}

void	ClientGraphic::addMendiane(int x, int y)
{
  sf::CircleShape	mendiane(10);
  mendiane.setFillColor(sf::Color(41, 128, 185));

  sf::Vector2f	screenPosition = sf::Vector2f(300 + x * -30 + y * 30, x * 15 + y * 15);
  mendiane.setPosition(screenPosition);

  sf::FloatRect rec = mendiane.getLocalBounds();
  mendiane.setScale(mendiane.getScale().x * 20 / rec.width, mendiane.getScale().y * 10 / rec.height);

  this->window.draw(mendiane);
}

void	ClientGraphic::addPhiras(int x, int y)
{
  sf::CircleShape	phiras(10);
  phiras.setFillColor(sf::Color(155, 89, 182));

  sf::Vector2f	screenPosition = sf::Vector2f(300 + x * -30 + y * 30, x * 15 + y * 15);
  phiras.setPosition(screenPosition);

  sf::FloatRect rec = phiras.getLocalBounds();
  phiras.setScale(phiras.getScale().x * 20 / rec.width, phiras.getScale().y * 10 / rec.height);

  this->window.draw(phiras);
}

void	ClientGraphic::addThystane(int x, int y)
{
  sf::CircleShape	thystane(10);
  thystane.setFillColor(sf::Color(192, 57, 43));

  sf::Vector2f	screenPosition = sf::Vector2f(300 + x * -30 + y * 30, x * 15 + y * 15);
  thystane.setPosition(screenPosition);

  sf::FloatRect rec = thystane.getLocalBounds();
  thystane.setScale(thystane.getScale().x * 20 / rec.width, thystane.getScale().y * 10 / rec.height);

  this->window.draw(thystane);
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
