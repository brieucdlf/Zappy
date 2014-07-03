//
// ClientGraphic.hpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic/includes
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Tue Jul  1 09:50:32 2014 Jeremy Peltier
// Last update Thu Jul  3 17:13:51 2014 Jeremy Peltier
//

#ifndef		CLIENT_GRAPHIC_HPP_
# define	CLIENT_GRAPHIC_HPP_

# include	<SFML/Graphics.hpp>
# include	<SFML/Window.hpp>
# include	<SFML/System.hpp>
# include	<SFML/Audio.hpp>
# include	<iostream>
# include	"TextureManager.hpp"

class		ClientGraphic
{
public:
  ClientGraphic(int, int);
  virtual ~ClientGraphic();

public:
  bool	isOpen() const;
  void	getKey();
  void	generateItems();
  void	generateMap(int, int);
  void	draw(int, int);

public:
  void	addFloor(int, int);
  void	addStone(int, int);
  void	addFood(int, int);
  void	addCharacter(int, int);

private:
  sf::RenderWindow	window;
  sf::RenderTexture	map;
  sf::Event		event;
  int			x;
  int			y;
  float			zoom;
  TextureManager	textures;
};

#endif		/* !CLIENT_GRAPHIC_HPP */
