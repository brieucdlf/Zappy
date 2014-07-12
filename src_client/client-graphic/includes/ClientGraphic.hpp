//
// ClientGraphic.hpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic/includes
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Tue Jul  1 09:50:32 2014 Jeremy Peltier
// Last update Sat Jul 12 18:28:28 2014 Remi Hillairet
//

#ifndef		CLIENT_GRAPHIC_HPP_
# define	CLIENT_GRAPHIC_HPP_

# include	<SFML/Graphics.hpp>
# include	<SFML/Window.hpp>
# include	<SFML/System.hpp>
# include	<SFML/Audio.hpp>
# include	<iostream>
# include	"TextureManager.hpp"
# include	"Map.hpp"
# include	"Character.hpp"

class		ClientGraphic
{
public:
  ClientGraphic(int, int);
  virtual ~ClientGraphic();

public:
  bool	isOpen() const;
  void	getKey();
  void	generateMenu();
  void	generateItems(Map &);
  void	generateGround(int, int);
  void	generateCharacters(std::map<int, Character> &);
  void	draw(Map &, std::map<int, Character> &);
  void	loading(int);

public:
  void	addFloor(int, int);
  void	addFood(int, int);
  void	addLinemate(int, int);
  void	addDeraumere(int, int);
  void	addSibur(int, int);
  void	addMendiane(int, int);
  void	addPhiras(int, int);
  void	addThystane(int, int);
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
