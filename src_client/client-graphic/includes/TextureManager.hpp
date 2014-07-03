//
// ImageManager.hpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic/includes
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Tue Jul  1 20:00:30 2014 Jeremy Peltier
// Last update Thu Jul  3 15:39:33 2014 Jeremy Peltier
//

#ifndef		TEXTURE_MANAGER_HPP_
# define	TEXTURE_MANAGER_HPP_

# include	<SFML/Graphics.hpp>
# include	<map>
# include	<string>

class		TextureManager
{
public:
  TextureManager();
  virtual ~TextureManager();

public:
  void		clear();
  sf::Texture	&getTexture(std::string &);

protected:
  std::map<std::string, sf::Texture> textures;
};

#endif		/* TEXTURE_MANAGER_HPP_ */
