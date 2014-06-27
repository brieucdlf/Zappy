//
// ClientGraphic.hpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic/includes
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Tue Jul  1 09:50:32 2014 Jeremy Peltier
// Last update Tue Jul  1 10:14:23 2014 Jeremy Peltier
//

#ifndef		SFML_HPP_
# define	SFML_HPP_

# include	<SFML/Graphics.hpp>
# include	<SFML/Window.hpp>
# include	<SFML/System.hpp>
# include	<SFML/Audio.hpp>

class		ClientGraphic
{
public:
  ClientGraphic(int, int);
  virtual ~ClientGraphic();

public:
  bool	isOpen() const;
  void	getKey();

private:
  sf::RenderWindow	window;
  sf::Event		event;
};

#endif		/* SFML_HPP_ */
