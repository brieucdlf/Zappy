//
// IsometricSprite.hpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic/includes
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Tue Jul  1 15:15:54 2014 Jeremy Peltier
// Last update Thu Jul  3 15:39:12 2014 Jeremy Peltier
//

#ifndef		ISOMETRIC_SPRITE_HPP_
# define	ISOMETRIC_SPRITE_HPP_

# include	<SFML/Graphics.hpp>

class		IsometricSprite : public sf::Sprite
{
public:
  IsometricSprite(void);
  IsometricSprite(const sf::Texture &, const sf::Vector2f &position = sf::Vector2f(0, 0));
  virtual ~IsometricSprite();

public:
  void	setIsometricPosition(sf::Vector2f);
  sf::Vector2f	getIsometricPosition() const;
  void	setIsometricZ(float);
  float	getIsometricZ(void) const;

protected:
  sf::Vector2f	mapPosition;
  float		zPosition;
};

#endif		/* ISOMETRIC_SPRITE_HPP_ */
