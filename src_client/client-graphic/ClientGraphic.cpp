//
// ClientGraphic.cpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Tue Jul  1 09:49:02 2014 Jeremy Peltier
// Last update Sat Jul 12 19:26:01 2014 Jeremy Peltier
//

#include "ClientGraphic.hpp"
#include "IsometricSprite.hpp"
#include <string>

ClientGraphic::ClientGraphic(int width, int height)
{
  this->window.create(sf::VideoMode(width, height, 32), "Client Graphic");
  this->window.clear();
  this->window.setKeyRepeatEnabled(false);
  this->x = 0;
  this->y = 0;
  this->zoom = 1;
  this->showMenu = false;

  this->menuView.setSize(width, height);

  this->window.display();
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
	this->x -= 10;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	this->x += 10;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	this->y -= 10;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	this->y += 10;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
	this->zoom -= 0.5;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
	this->zoom += 0.5;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
	  this->showMenu = false;
	}
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	this->showMenu = true;
      if (this->zoom <= 0.5)
	this->zoom = 0.5;
      if (!this->showMenu)
	{
	  this->mapView = this->window.getDefaultView();
	  this->mapView.setCenter((this->window.getSize().x / 3) - this->x, (this->window.getSize().y / 4) - this->y);
	  this->mapView.zoom(this->zoom);
	  this->window.setView(this->mapView);
	}
    }
}

void	ClientGraphic::addFloor(int x, int y)
{
  std::string	pathTexture = "src_client/client-graphic/resources/images/ground-1.png";

  if (x % 2 == 0 || y % 2 == 0)
    pathTexture = "src_client/client-graphic/resources/images/ground-2.png";

  IsometricSprite	floor(textures.getTexture(pathTexture), sf::Vector2f(x, y));
  floor.setIsometricScale();
  floor.setIsometricSize();

  this->window.draw(floor);
}

void	ClientGraphic::addFood(int x, int y)
{
  std::string	pathTexture = "src_client/client-graphic/resources/images/food.png";

  IsometricSprite	food(textures.getTexture(pathTexture), sf::Vector2f(x, y));
  food.setPosition(sf::Vector2f(300 + (x - 0.25) * -60 + (y + 0.75) * 60, (x - 0.25) * 30 + (y + 0.75) * 30));

  food.setScale(1, 1);

  this->window.draw(food);
}

void	ClientGraphic::addLinemate(int x, int y)
{
  std::string	pathTexture = "src_client/client-graphic/resources/images/pierre1.png";

  IsometricSprite	linemate(textures.getTexture(pathTexture), sf::Vector2f(x, y));
  linemate.setPosition(sf::Vector2f(300 + (x - 0.5) * -60 + (y + 0.25) * 60, (x - 0.5) * 30 + (y + 0.25) * 30));

  linemate.setScale(0.5, 0.5);

  this->window.draw(linemate);
}

void	ClientGraphic::addDeraumere(int x, int y)
{
  std::string	pathTexture = "src_client/client-graphic/resources/images/pierre2.png";

  IsometricSprite	deraumere(textures.getTexture(pathTexture), sf::Vector2f(x, y));
  deraumere.setPosition(sf::Vector2f(300 + (x - 0.5) * -60 + (y + 0.5) * 60, (x - 0.5) * 30 + (y + 0.5) * 30));
  deraumere.setScale(0.5, 0.5);

  this->window.draw(deraumere);
}

void	ClientGraphic::addSibur(int x, int y)
{
  std::string	pathTexture = "src_client/client-graphic/resources/images/pierre3.png";

  IsometricSprite	sibur(textures.getTexture(pathTexture));
  sibur.setIsometricPosition(sf::Vector2f(x, y));
  sibur.setPosition(sf::Vector2f(300 + (x - 0.25) * -60 + (y + 0.25) * 60, (x - 0.25) * 30 + (y + 0.25) * 30));
  sibur.setScale(0.5, 0.5);

  this->window.draw(sibur);
}

void	ClientGraphic::addMendiane(int x, int y)
{
  std::string	pathTexture = "src_client/client-graphic/resources/images/pierre4.png";

  IsometricSprite	mendiane(textures.getTexture(pathTexture), sf::Vector2f(x, y));
  mendiane.setPosition(sf::Vector2f(300 + (x - 0.25) * -60 + (y + 0.5) * 60, (x - 0.25) * 30 + (y + 0.5) * 30));
  mendiane.setScale(0.5, 0.5);

  this->window.draw(mendiane);
}

void	ClientGraphic::addPhiras(int x, int y)
{
  std::string	pathTexture = "src_client/client-graphic/resources/images/pierre5.png";

  IsometricSprite	phiras(textures.getTexture(pathTexture), sf::Vector2f(x, y));
  phiras.setPosition(sf::Vector2f(300 + x * -60 + (y + 0.25) * 60, x * 30 + (y + 0.25) * 30));
  phiras.setScale(0.5, 0.5);

  this->window.draw(phiras);
}

void	ClientGraphic::addThystane(int x, int y)
{
  std::string	pathTexture = "src_client/client-graphic/resources/images/pierre6.png";

  IsometricSprite	thystame(textures.getTexture(pathTexture));
  thystame.setIsometricPosition(sf::Vector2f(x, y));
  thystame.setPosition(sf::Vector2f(300 + x * -60 + (y + 0.5) * 60, x * 30 + (y + 0.5) * 30));
  thystame.setScale(0.5, 0.5);

  this->window.draw(thystame);
}

void	ClientGraphic::addCharacter(int x, int y)
{
  std::string	pathTexture = "src_client/client-graphic/resources/images/perso1.png";

  IsometricSprite	character(textures.getTexture(pathTexture), sf::Vector2f(x, y));
  character.setPosition(sf::Vector2f(300 + (x - 1.5) * -60 + (y - 1.5) * 60, (x - 1.5) * 30 + (y - 1.5) * 30));

  character.setScale(0.5, 0.5);

  this->window.draw(character);
}

void	ClientGraphic::generateMenu()
{
  this->menuView = this->window.getView();
  this->menuView.reset(sf::FloatRect(0, 0, this->window.getSize().x, this->window.getSize().y));
  this->window.setView(this->menuView);

  sf::Font	font;
  font.loadFromFile("src_client/client-graphic/resources/fonts/cl.ttf");

  sf::Text text;
  text.setFont(font);
  text.setString("Use [+] and [-] to zoom level");
  text.setCharacterSize(20);
  text.setPosition(this->window.getSize().x / 3, this->window.getSize().y / 2 - 150);
  text.setColor(sf::Color::White);

  this->window.draw(text);

  text.setString("Use arrow keyboard to move the map");
  text.setPosition(this->window.getSize().x / 3, this->window.getSize().y / 2 - 100);

  this->window.draw(text);


  text.setString("Click with the mouse on a case to show the inventory case");
  text.setPosition(this->window.getSize().x / 3, this->window.getSize().y / 2 - 50);

  this->window.draw(text);

  text.setString("Use [ESC] to quit the window");
  text.setPosition(this->window.getSize().x / 3, this->window.getSize().y / 2);

  this->window.draw(text);

  text.setString("Use [Q] to quit this view and return to the map");
  text.setPosition(this->window.getSize().x / 3, this->window.getSize().y / 2 + 100);

  this->window.draw(text);
}

void	ClientGraphic::generateItems(Map &data)
{
  for (int y = 0; y < data.getHeight(); ++y)
    {
      for (int x = 0; x < data.getWidth(); ++x)
	{
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
	  if (data.getMap()[y][x][FOOD] > 0)
	    addFood(x, y);
	}
    }
}

void	ClientGraphic::generateGround(int width, int height)
{
  for (int i = 0; i < width; ++i)
    for (int j = 0; j < height; ++j)
      addFloor(i, j);
}

void	ClientGraphic::generateCharacters(const std::map<int, Character>  & players)
{
  for (std::map<int, Character>::const_iterator it = players.begin() ; it != players.end() ; ++it)
    {
      addCharacter(it->second.getPosX(), it->second.getPosY());
    }
}

void	ClientGraphic::draw(Map &map, const std::map<int, Character> & players)
{
  this->window.clear();

  if (this->showMenu)
    generateMenu();
  else
    {
      this->window.setView(this->mapView);
      generateGround(map.getWidth(), map.getHeight());
      generateItems(map);
      generateCharacters(players);
    }

  this->window.display();
}

void	ClientGraphic::loading(int percent)
{
  this->window.clear();

  this->zoom = 1;

  sf::View	view = this->window.getDefaultView();
  view.zoom(this->zoom);
  this->window.setView(view);

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
